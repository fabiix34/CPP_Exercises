#pragma once
#include <iostream>
#include "PC.h"

// A person that captures Pokemons and makes them fight.
class Trainer
{
public:
    Trainer(const std::string& name , PC pc);

    const std::string& name() const;

private:
    std::string _name;
    PC _pc;
};
