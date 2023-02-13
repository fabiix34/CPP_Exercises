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

    PC(const PC& other);

    bool empty();

    void transfer(PokemonPtr pokemon);

    std::vector<PokemonPtr> &pokemons();

private:
    std::vector<PokemonPtr> _pokemons;
};
