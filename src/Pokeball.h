#pragma once
#include <iostream>

// A ball where a Pokemon sleeps.
class Pokeball
{
    public:
    Pokeball()
    {
        std::cout << "pokeball created !" << std::endl;
    }

    bool empty() const
    {
        return _empty;
    }

    private:
    bool _empty = true;
};
