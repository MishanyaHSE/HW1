#ifndef __train__
#define __train__

//------------------------------------------------------------------------------
// train.h - содержит описание поезда
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
# include "transport.h"

//------------------------------------------------------------------------------
// Поезд
struct train: transport {
    int wagons_number; // количество вагонов
};

// Ввод параметров поезда из файла
void In(train &t, ifstream &ifst);

// Случайный ввод параметров поезда
void InRnd(train &е);

// Вывод параметров поезда в форматируемый поток
void Out(train &t, ofstream &ofst);

#endif //__train__
