#pragma once
#include <string>
#include "Lebewesen.hpp"

class Mensch : public Lebewesen { // Prototyp
public:
    static int anzahlMenschen;
    std::string name;
    int alter;
    int *daten = new int[1000];
public:
    Mensch(int alter_, std::string name_); // Ohne Rumpf, da Prototyp
    Mensch();
    ~Mensch(); // Destruktor
    static int getAnzahlMenschen();
    std::string getName() const;
    int getAlter() const;
    void makeSound() override;
};