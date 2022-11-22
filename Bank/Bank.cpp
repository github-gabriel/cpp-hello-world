//
// Created by gabriel on 06.11.2022.
//
#include <iostream>
#include "Bank.hpp"
#include "Kunde.hpp"

Bank::Bank(std::string name)
    : name(name){}

void Bank::addKunde(const Kunde &kunde) { // const Referenz, da Referenz nicht geändert wird
    kunden.push_back(kunde);
}

std::string Bank::getName() const { // const, da nichts verändert wird
    return name;
}

int Bank::getAnzahlKunden() const { // const, da nichts verändert wird
    return kunden.size();
}

const std::vector<Kunde>& Bank::getKunden() const { // const Referenz
    return kunden;
}
