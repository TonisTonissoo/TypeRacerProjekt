# TypeRacerProjekt

**TypeRacerProjekt** on C++/Qt-põhine rakendus, mis võimaldab kasutajal testida oma kirjutamiskiirust ja täpsust. Mäng esitab juhuslikke lauseid, mida tuleb õigesti sisestada, ning hindab tulemusi (WPM, täpsus). Parimad tulemused talletatakse edetabelisse.

## Funktsionaalsus

- Kasutaja sisestab oma nime stardiaknas.
- Kuvatakse suvaline lause, mille kasutaja peab õigesti sisestama.
- Arvutatakse ja kuvatakse:
  - Tähemärgitäpsus (%)
  - Sõnatäpsus (%)
  - Sisestusaeg ja WPM (Words Per Minute)
- Edetabel (leaderboard):
  - Kuvab 5 parimat tulemust
  - Kui mängija nimi on juba olemas, asendatakse tulemus ainult juhul, kui uus on parem
  - Kui tulemus ei mahu edetabelisse, seda ei salvestata

## Failid

| Fail | Kirjeldus |
|------|-----------|
| `main.cpp` | Programmi käivitamine |
| `startwindow.ui/.cpp/.h` | Nime sisestamise ja mängu käivitamise aken |
| `mainwindow.ui/.cpp/.h` | Mängu loogika ja tulemuste arvutamine |
| `leaderboard.ui/.cpp/.h` | Edetabeli kuvamine |
| `functions.hpp` / `functions.cpp` | Loogika (täpsus, WPM, failide lugemine/kirjutamine) |
| `style.qss` | Rakenduse visuaalne kujundus (QSS-stiilis CSS) |

## Salvestusfailid

- `pikemad_laused.txt` – Sisaldab lauseid, mida kasutatakse mängus.
- `scoreboard.txt` – Talletab TOP 5 tulemused järgmises formaadis:
- 
    Nimi;WPM;Aeg;Kuupäev
    Peeter;31.20;10.55;25.05.2025

## Käivitamine

1. Ava projekt Qt Creatoris
2. Veendu, et failid `pikemad_laused.txt` ja `style.qss` on projekti juurkaustas
3. Koosta (Build) ja käivita projekt

## Kujundus

Rakendus kasutab CSS-laadset QSS-faili (`style.qss`), et pakkuda ühtset ja selget visuaalset kujundust.

## Nõuded

- Qt 6.x (testitud Qt 6.9.0 MinGW)
- C++17

## Märkused

- Edetabelisse salvestatakse ainult parimad 5 tulemust.
- Kasutajaliides toetab reamurdmist ja automaatset sisestuse analüüsi.
