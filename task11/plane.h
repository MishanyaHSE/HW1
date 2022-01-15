#ifndef __plane__
#define __plane__

//------------------------------------------------------------------------------
// plane.h - содержит описание самолёта  и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
# include "transport.h"

// Самолёт
struct plane: transport {
    int range, lifting_capacity; // дальность полета, грузоподъемность
};

// Ввод параметров самолёта из файла
void In(plane &r, ifstream &ifst);

// Случайный ввод параметров самолёта
void InRnd(plane &r);

// Вывод параметров самолёта в форматируемый поток
void Out(plane &r, ofstream &ofst);

#endif //__plane__
