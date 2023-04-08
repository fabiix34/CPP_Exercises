#pragma once

#include <iostream>

class Plush{
    public :
        Plush(int cost)
        : _cost(cost)
        {
            std::cout << "Plush created" << std::endl;
        }

        int get_cost() const
        {
            return _cost;
        }

        void set_cost(int cost)
        {
            _cost = cost;
        }

    private :
        int _cost = 0;
};
