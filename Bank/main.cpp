#include "Bank.hpp"
#include "Kunde.hpp"

int main() {
    Bank bank("Bank A");

    Kunde a(std::string("Peter"), 412.38, 1234, false, &bank);
    Kunde b(std::string("Hans"), 980.38, 1234, true, &bank);

    return 0;
}
