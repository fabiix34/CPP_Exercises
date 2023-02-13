#include "PC.h"

PC::PC()
{
    std::cout << "PC created !" << std::endl;
}

bool PC::empty()
{
    return _pokemons.size() == 0;
}

void PC::transfer(PokemonPtr pokemon)
{
    // il faut mettre std::move pour faire le
    // changement ? Pourquoi ?
    // _pokemons.push_back(std::move(pokemon));
    std::cout << pokemon->name() << std::endl;
}

const std::vector<PokemonPtr> &PC::pokemons() const
{
    return _pokemons;
}