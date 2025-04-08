#include "brujo.hpp"

brujo::brujo(string n):
    Magos(10, 20, 90, 90, 35, n),
    estado_frenesi(false) {}

string brujo::Get_grupo() const {
    return "Brujo";
}