//------------------------------------------------------------------------------
// train.cpp - содержит функции обработки поезда
//------------------------------------------------------------------------------

#include "train.h"

//------------------------------------------------------------------------------
// Ввод параметров поезда из потока
void In(train &tr, ifstream &ifst) {
    ifst >> tr.wagons_number;
}

// Случайный ввод параметров поезда
void InRnd(train &tr) {
    tr.wagons_number = Random() % 91 + 10;
}

//------------------------------------------------------------------------------
// Вывод параметров поезда в поток
void Out(train &tr, ofstream &ofst) {
    ofst << "It is Train: Amount of wagons = " <<  tr.wagons_number
         << ". Perfect time = " << getPerfectTime(tr) << "\n";
}
