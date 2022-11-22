//
// Created by gabriel on 06.11.2022.
//
#include <vector>
#include <string>

#ifndef BANK_BANK_HPP
#define BANK_BANK_HPP

class Kunde;

// Deklaration
class Bank {
private:
    std::string name;
    std::vector<Kunde> kunden;
public:
    Bank(std::string name);

    void addKunde(const Kunde &kunde);
    void addKunden(const std::vector<Kunde*> &kunden_);
    const std::vector<Kunde>& getKunden() const;
    int getAnzahlKunden() const;
    std::string getName() const;

    void ueberweisen(Kunde& kunde1, Kunde& kunde2, float betrag);
};

#endif //BANK_BANK_HPP
