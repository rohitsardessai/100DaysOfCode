#include <iostream>
#include <list>
#include <map>
#include <string>

int main()
{
    std::map<std::string, std::list<std::string>> pokedex;

    std::list<std::string> pikachuAttacks{"thunder shock", "tail whip", "quick attack"};
    std::list<std::string> charmanderAttacks{"flame thrower", "scary face"};
    std::list<std::string> chikoritaAttacks{"razor leaf", "poison powder"};

    pokedex.insert(std::pair<std::string, std::list<std::string>>("Pikachu", pikachuAttacks));
    pokedex.insert(std::pair<std::string, std::list<std::string>>("Charmander", charmanderAttacks));
    pokedex.insert(std::pair<std::string, std::list<std::string>>("Chikorita", chikoritaAttacks));

    for (auto it = pokedex.begin(); it != pokedex.end(); it++) {
        std::cout << it->first << " - ";
        for (auto attack : it->second) {
            std::cout << attack << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}