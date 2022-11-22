#include <iostream>
#include "Bank.hpp"
#include "Kunde.hpp"

int main() {
    Bank bank("Bank A");

    Kunde a(std::string("Peter"), 412.38, 1234, false, &bank);
    Kunde b(std::string("Hans"), 980.38, 1234, true, &bank);

    std::vector<Kunde*> kunden{&a, &b};

    bank.addKunden(kunden);

    bank.ueberweisen(*kunden[0], *kunden[1], 500); // Ergebnis: a: 412.38 - 500; b: 980.38 + 500

    Kunde c(std::string("Günter"), 76.53, 1234, true, &bank);

    bank.addKunde(c);

    return 0;
}
