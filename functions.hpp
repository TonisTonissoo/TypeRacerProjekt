#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <vector>
#include <string>

std::vector<std::string> loeLaused(const std::string& failiNimi);
double arvutaTäpsus(const std::string& originaal, const std::string& sisestus);
double arvutaWPM(const std::string& sisestus, double kestusSekundites);
void salvestaTulemus(const std::string& nimi, double wpm);
void kuvaScoreboard();
std::string analyysiTekst(const std::string& originaal, const std::string& sisestus);
double arvutaSõnaTäpsus(const std::string& originaal, const std::string& sisestus);  // uus funktsioon

#endif
