#include "Pokeball.h"

Pokeball::Pokeball()
{
    std::cout << "pokeball created !" << std::endl;
}

bool Pokeball::empty() const
{
    return _empty;
}

void Pokeball::store(Pokemon::PokemonPtr pokemon)
{
    *_pokemon = *pokemon;
}

Pokemon Pokeball::pokemon()
{
    return *_pokemon;
}
