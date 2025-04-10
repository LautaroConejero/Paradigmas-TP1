#ifndef POCION_HPP
#define POCION_HPP

#include "../item_magicos.hpp"

class pocion : public Item_magicos {
    public:
        pocion(int d, int dm, float c);
};

#endif