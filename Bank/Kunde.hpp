//
// Created by gabriel on 06.11.2022.
//
#include <string>

#include "Bank.hpp"

#ifndef BANK_KUNDE_HPP
#define BANK_KUNDE_HPP

// Deklaration
class Kunde {
private:
    std::string name;
    float kontostand;
    int pin;
    Bank *bank;
    bool minus;
public:
    Kunde(std::string name, float kontostand, int pin, bool minus, Bank *bank);

    std::string getName() const; // const, da nichts verändert wird
    float getKontostand() const; // const, da nichts verändert wird
    void setKontostand(float betrag);
    bool verify();
    Bank& getBank(); // Referenz zurückgeben, keine Kopie
    void changeBank(Bank *bank_);
    std::string toString();
};

#endif //BANK_KUNDE_HPP
