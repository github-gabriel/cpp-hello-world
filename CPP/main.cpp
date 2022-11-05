#include <iostream>
#include <unordered_map>
#include <string>

class Car {
public:
    int ps;
    int baujahr;
    bool spoiler;

    Car(int ps, int baujahr, bool spoiler)
        : ps(ps), baujahr(baujahr), spoiler(spoiler){

    }
    friend bool operator==(const Car &c1, const Car &c2){ // Wichtig für unordered Varianten
        return c1.ps == c2.ps && c1.baujahr == c2.baujahr && c1.spoiler && c2.spoiler;
    }
};

namespace std{
    template<> struct hash<Car>{
        size_t operator()(const Car &car)const{
            hash<int> intHash;
            hash<bool> boolHash;

            return intHash(car.ps) + intHash(car.baujahr) * 7 + boolHash(car.spoiler);
        }
    };
}

int main(){

    std::unordered_map<Car, std::string> owners;

    Car c(500, 2012, true);

    owners.insert(std::pair<Car, std::string>(c, "Peter"));

    std::cout << owners.find(c)->second << std::endl;

    system("pause");

    return 0;
}
