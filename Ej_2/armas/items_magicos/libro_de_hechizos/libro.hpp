#ifndef LIBRO_HPP
#define LIBRO_HPP

#include "../item_magicos.hpp"

class libro_de_hechizos : public Item_magicos {
    public:
        libro_de_hechizos(int d, int dm, float c);
};

#endif