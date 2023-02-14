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

    const Pokemon& pokemon() const;

private:
    PokemonPtr _pokemon = nullptr;
};
