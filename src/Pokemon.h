#pragma once

#include <string>
#include <iostream>
#include <utility>

// A creature that is cute and can fight other ones.
class Pokemon
{
public:
    typedef const std::unique_ptr<Pokemon> PokemonPtr;

    Pokemon(const std::string &name);

    // pour faire un constructeur de copy
    // il faut également redéfinir l'operator =

    Pokemon(const Pokemon &poke);

    Pokemon &operator=(const Pokemon &other);

    const std::string &name() const;

    int id() const;

private:
    std::string _name;
    int _id;
    // inline permet de faire croire au compilateur
    // que la variable existe deja
    static inline int idGlobal;
};
