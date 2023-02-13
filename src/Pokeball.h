#pragma once
#include <iostream>
#include "Pokemon.h"

// A ball where a Pokemon sleeps.
class Pokeball
{
public:
    Pokeball();

    bool empty() const;

    void store(PokemonPtr pokemon);

    Pokemon pokemon();

private:
    bool _empty = true;
    PokemonPtr _pokemon = nullptr;
};
