#pragma once
#include <iostream>
#include <string>
#include <optional>
#include "Plush.hpp"

class PlushStore
{
public:
    PlushStore(const std::string &name)
        : _name(name), _debt(0), _wealth(0), _stock_size(0)
    {
        std::cout << "PlushStore created" << std::endl;
    }

    const std::string &get_name() const
    {
        return _name;
    }

    int get_wealth_amount() const
    {
        return _wealth < 0 ? 0 : _wealth;
    }

    int get_stock_size() const
    {
        return _stock_size;
    }

    void loan(int amount)
    {
        _debt += amount * 1.1;
        _wealth += amount;
    }

    int get_debt_amount() const
    {
        return _debt;
    }

    int make_plush(int price)
    {
        if (_wealth > 0)
        {
            _stock_size++;
            _wealth -= price;
            _experience++;

            return price + _experience;
        }

        return 0;
    }

    int get_experience() const
    {
        return _experience;
    }

    std::optional<Plush> buy(int value)
    {
        if(value > 0)
        {
            std::cout << "value" << std::endl;
        }

        return std::nullopt;
    }

private:
    std::string _name;
    int _debt;
    int _wealth;
    int _stock_size;
    int _experience = 0;
};
