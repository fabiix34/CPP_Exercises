#include "PC.h"

bool PC::empty()
{
    return _pokemons.size() == 0;
}

void PC::transfer(PokemonPtr pokemon)
{
    _pokemons.emplace_back(std::move(pokemon));
    std::cout << pokemon->name() << std::endl;
}

const std::vector<PokemonPtr> &PC::pokemons() const
{
    return _pokemons;
}