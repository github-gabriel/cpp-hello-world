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

void Bank::addKunden(const std::vector<Kunde*> &kunden_) { // const Referenz, da Referenz nicht geändert wird
    for(auto i = kunden_.begin(); i != kunden_.end(); i++){
        kunden.push_back(**i);// 1 Sternchen dereferenziert den Iterator, das 2 Sternchen dereferenziert das Element in der Liste
    }
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

void Bank::ueberweisen(Kunde& kunde1, Kunde& kunde2, float betrag) { // Referenzen übergeben, da die Werte auch geupdated werden sollen
    if(kunde1.verify()){
        kunde1.setKontostand(-betrag);
        kunde2.setKontostand(+betrag);
    }
    std::cout << "Ueberweisung war erfolgreich!" << std::endl << kunde1.toString() << std::endl << kunde2.toString() << std::endl;
}
