#include "Trainer.h"

Trainer::Trainer(const std::string &name, PC& pc)
    : _name{name}, _pc{pc}
{
    std::cout << name << " has become a trainer !" << std::endl;
}

const std::string& Trainer::name() const
{
    return _name;
}

const PC& Trainer::pc() const
{
    return _pc;
}