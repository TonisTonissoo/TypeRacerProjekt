#include "functions.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>

std::vector<std::string> loeLaused(const std::string& failiNimi) {
    std::vector<std::string> laused;
    std::ifstream fail(failiNimi);
    std::string rida;
    while (std::getline(fail, rida)) {
        if (!rida.empty()) {
            laused.push_back(rida);
        }
    }
    return laused;
}

double arvutaTäpsus(const std::string& originaal, const std::string& sisestus) {
    int õiged = 0;
    int pikkus = std::min(originaal.size(), sisestus.size());
    for (int i = 0; i < pikkus; ++i) {
        if (originaal[i] == sisestus[i]) {
            õiged++;
        }
    }
    return (double)õiged / originaal.size() * 100.0;
}

double arvutaWPM(const std::string& sisestus, double kestusSekundites) {
    int sõnadeArv = 1;
    for (char c : sisestus) {
        if (c == ' ') sõnadeArv++;
    }
    double minutites = kestusSekundites / 60.0;
    return sõnadeArv / minutites;
}

// Abifunktsioon tühikute eemaldamiseks
std::string trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end = s.find_last_not_of(" \t\n\r");
    return (start == std::string::npos || end == std::string::npos) ? "" : s.substr(start, end - start + 1);
}

void salvestaTulemus(const std::string& nimiOrig, double wpm, double aegSekundites) {
    std::ifstream sisend("scoreboard.txt");
    std::vector<std::tuple<std::string, double, double, std::string>> tulemused;
    std::string rida;

    std::string nimi = trim(nimiOrig);

    // Loeme olemasolevad tulemused, kuid jätame samanimelise mängija välja
    while (std::getline(sisend, rida)) {
        std::istringstream iss(rida);
        std::string nimiFailist, wpmStr, aegStr, kuupäev;

        std::getline(iss, nimiFailist, ';');
        std::getline(iss, wpmStr, ';');
        std::getline(iss, aegStr, ';');
        std::getline(iss, kuupäev);

        nimiFailist = trim(nimiFailist);

        // Jätame vana tulemuse eemaldamiseks välja kõik selle mängija kirjed
        if (nimiFailist == nimi) continue;

        double vanaWPM = std::stod(wpmStr);
        double vanaAeg = std::stod(aegStr);
        tulemused.emplace_back(nimiFailist, vanaWPM, vanaAeg, kuupäev);
    }
    sisend.close();

    // Uue tulemuse lisamise tingimus (kas väärib top 5 kohta)
    bool lisaUus = false;
    if (tulemused.size() < 5 || wpm > std::get<1>(*std::min_element(
                                    tulemused.begin(), tulemused.end(),
                                    [](const auto& a, const auto& b) {
                                        return std::get<1>(a) < std::get<1>(b);
                                    }))) {
        lisaUus = true;
    }

    if (lisaUus) {
        // Loome kuupäeva
        time_t nüüd = time(nullptr);
        tm* local = localtime(&nüüd);
        char kuupäevStr[11];
        strftime(kuupäevStr, sizeof(kuupäevStr), "%d.%m.%Y", local);

        // Lisa uus tulemus
        tulemused.emplace_back(nimi, wpm, aegSekundites, std::string(kuupäevStr));

        // Sorteeri tulemused WPM alusel
        std::sort(tulemused.begin(), tulemused.end(),
                  [](const auto& a, const auto& b) {
                      return std::get<1>(a) > std::get<1>(b);
                  });

        // Salvesta top 5
        std::ofstream väljund("scoreboard.txt", std::ios::trunc);
        int count = 0;
        for (const auto& t : tulemused) {
            if (count++ >= 5) break;
            väljund << std::get<0>(t) << ";" << std::fixed << std::setprecision(4)
                    << std::get<1>(t) << ";" << std::get<2>(t) << ";" << std::get<3>(t) << "\n";
        }
    }
}




std::string analyysiTekst(const std::string& originaal, const std::string& sisestus) {
    std::ostringstream väljund;
    std::istringstream origSS(originaal);
    std::istringstream sisSS(sisestus);

    std::string origSõna, sisSõna;
    int õiged = 0, valed = 0, kokku = 0;

    while (origSS >> origSõna) {
        if (sisSS >> sisSõna) {
            if (origSõna == sisSõna) {
                õiged++;
            } else {
                valed++;
                väljund << "VALE: '" << sisSõna << "' peaks olema '" << origSõna << "'\n";
            }
        } else {
            valed++;
            väljund << "PUUDUB: '" << origSõna << "' jäi sisestamata\n";
        }
        kokku++;
    }

    while (sisSS >> sisSõna) {
        valed++;
        väljund << "LISA: '" << sisSõna << "' ei olnud originaalis\n";
        kokku++;
    }

    väljund << "\n=== Sõnavõrdlus ===\n";
    väljund << "Õiged: " << õiged << ", Valed: " << valed << ", Kokku: " << kokku << "\n";
    return väljund.str();
}

double arvutaSõnaTäpsus(const std::string& originaal, const std::string& sisestus) {
    std::istringstream origSS(originaal);
    std::istringstream sisSS(sisestus);

    std::string origSõna, sisSõna;
    int õiged = 0, kokku = 0;

    while (origSS >> origSõna) {
        if (sisSS >> sisSõna) {
            if (origSõna == sisSõna) {
                õiged++;
            }
        }
        kokku++;
    }

    while (sisSS >> sisSõna) {
        kokku++;
    }

    return (kokku == 0) ? 0.0 : ((double)õiged / kokku) * 100.0;
}
