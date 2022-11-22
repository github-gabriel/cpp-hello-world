//
// Created by gabriel on 06.11.2022.
//
#include <iostream>

#include "Kunde.hpp"

Kunde::Kunde(std::string name, float kontostand, int pin, bool minus, Bank *bank)
    : name(name), kontostand(kontostand), pin(pin), minus(minus), bank(bank) {}

std::string Kunde::getName() const { // const, da nichts verändert wird
    return name;
}

float Kunde::getKontostand() const { // const, da nichts verändert wird
    return kontostand;
}

bool Kunde::verify() {
    int input;
    std::cout << "Bitte PIN fuer " << name << " eingeben" << std::endl;
    std::cin >> input;
    return input == pin;
}

Bank& Kunde::getBank() {
    return *bank;
}

void Kunde::setKontostand(float betrag) {
    if(minus || (kontostand - betrag) > 0){
        kontostand += betrag;
    }else if((kontostand - betrag) < 0){
        std::cout << "Überweisung nicht möglich!" << std::endl;
    }
}

void Kunde::changeBank(Bank *bank_) {
    bank = bank_;
}

std::string Kunde::toString() {
    return this->getName() + " ist Kunde der Bank \"" + this->getBank().getName() + "\", Kontostand: " + std::to_string(this->getKontostand());
}

