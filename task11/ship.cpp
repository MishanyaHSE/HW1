//------------------------------------------------------------------------------
// train.cpp - содержит функции обработки поезда
//------------------------------------------------------------------------------

#include "ship.h"

//------------------------------------------------------------------------------
// Ввод параметров поезда из потока
void In(ship &sh, ifstream &ifst) {
    ifst >> sh.displacement;
    int k;
    ifst >> k;
    switch(k) {
        case 1:
            sh.type = ship::LINEAR;
            break;
        case 2:
            sh.type = ship::TUGBOAT;
            break;
        case 3:
            sh.type = ship::TANKER;
            break;
        default: ;
    }
}

// Случайный ввод параметров поезда
void InRnd(ship &sh) {
    sh.displacement = Random() % 3000 + 500;
    int m = Random() % 3 + 1;
    switch(m) {
        case 1:
            sh.type = (ship::ship_type)1;
            break;
        case 2:
            sh.type = (ship::ship_type)2;
            break;
        case 3:
            sh.type = (ship::ship_type)3;
            break;
        default: ;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров поезда в поток
void Out(ship &sh, ofstream &ofst) {
    ofst << "It is Ship: Displacement = " << sh.displacement
         << ". Ship type: " << printType(sh)
         << ". Perfect time = " << getPerfectTime(sh) << "\n";
}

string printType(ship sh) {
    switch (sh.type) {
        case 1:
            return "LINEAR";
        case 2:
            return "TUGBOAT";
        case 3:
            return "TANKER";
        default:;
    }
}