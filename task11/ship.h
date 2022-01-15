#ifndef __ship__
#define __ship__

//------------------------------------------------------------------------------
// ship.h - содержит описание корабля и его интерфейса
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
# include "transport.h"

// Корабль
struct ship: transport {
    int displacement; // водоизмещение

    // Все виды кораблей
    enum ship_type {
        LINEAR = 1, TUGBOAT, TANKER
    };

    // Тип корабля
    ship_type type;
};

// Ввод параметров корабля из файла
void In(ship &sh, ifstream &ifst);

// Случайный ввод параметров корабля
void InRnd(ship &sh);

// Вывод параметров корабля в форматируемый поток
void Out(ship &sh, ofstream &ofst);

// Перевод в строку типа корабля
string printType(ship sh);

#endif //__ship__
