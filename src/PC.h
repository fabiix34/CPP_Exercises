#pragma once
#include <iostream>
#include "Pokemon.h"
#include <vector>

// A PC is the place where Pokemons get automagically sent when the trainer's pockets are full.
// When a Pokemon is transferred to the PC, this one takes ownership.
class PC
{
public:
    PC()
    {
        std::cout << "PC created !" << std::endl;
    }

    bool empty()
    {
        return _pokemons.size() == 0;
    }

    void transfer(const PokemonPtr& pokemon)
    {
        _pokemons.emplace_back(pokemon);
    }   

    std::vector<PokemonPtr> pokemons()
    {
        return _pokemons;
    }

private:
    std::vector<PokemonPtr> _pokemons;
};

