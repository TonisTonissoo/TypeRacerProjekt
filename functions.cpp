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

void salvestaTulemus(const std::string& nimi, double wpm) {
    std::ofstream fail("scoreboard.txt", std::ios::app);
    if (fail.is_open()) {
        fail << nimi << " - " << static_cast<int>(wpm) << " WPM" << std::endl;
    }
}

struct Tulemus {
    std::string nimi;
    int wpm;
};

void kuvaScoreboard() {
    std::ifstream fail("scoreboard.txt");
    std::string rida;
    std::vector<Tulemus> tulemused;

    if (fail.is_open()) {
        while (std::getline(fail, rida)) {
            std::istringstream iss(rida);
            Tulemus t;
            std::getline(iss, t.nimi, '-');
            std::string wpmStr;
            std::getline(iss, wpmStr);

            wpmStr.erase(0, wpmStr.find_first_not_of(" "));
            t.wpm = std::stoi(wpmStr);

            tulemused.push_back(t);
        }

        std::sort(tulemused.begin(), tulemused.end(), [](const Tulemus& a, const Tulemus& b) {
            return a.wpm > b.wpm;
        });

        std::cout << "\n=== Edetabel ===" << std::endl;
        for (const auto& t : tulemused) {
            std::cout << t.nimi << " - " << t.wpm << " WPM" << std::endl;
        }
        std::cout << "================\n" << std::endl;
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
