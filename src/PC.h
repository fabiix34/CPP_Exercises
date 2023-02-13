#pragma once
#include <iostream>
#include "Pokemon.h"
#include <vector>

// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.
class PC
{
public:
    PC();

    bool empty();

    void transfer(Pokemon::PokemonPtr pokemon);

    const std::vector<Pokemon::PokemonPtr> &pokemons() const;

private:
    std::vector<Pokemon::PokemonPtr> _pokemons;
};
