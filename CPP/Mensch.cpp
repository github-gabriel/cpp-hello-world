#pragma once
#include "Mensch.hpp"
#include <iostream>

int Mensch::anzahlMenschen = 0;

Mensch::Mensch(int alter, std::string name)
    : alter(alter), name(name)
{
    anzahlMenschen++;
}

Mensch::~Mensch() { // Destruktor implementieren
    std::cout << "Destruktor" << std::endl;
    anzahlMenschen--;
    delete[] daten;
}

Mensch::Mensch() : alter(-1), name("N/A"){
    anzahlMenschen++;
}

std::string Mensch::getName() const {
    return name;
}

int Mensch::getAlter() const {
    return alter;
}

int Mensch::getAnzahlMenschen() {
    return anzahlMenschen;
}

void Mensch::makeSound() {
    std::cout << "Hallo!" << std::endl;
}