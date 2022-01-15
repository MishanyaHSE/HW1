//------------------------------------------------------------------------------
// transport.cpp - содержит процедуры связанные с обработкой обобщенного транспорта
// и создания произвольного транспорта
//------------------------------------------------------------------------------

#include "plane.h"
#include "train.h"
#include "ship.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенного транспорта из файла
transport* In(ifstream &ifst) {
    int k, speed;
    double distance;
    ifst >> k;
    ifst >> speed;
    ifst >> distance;
    switch(k) {
        plane *pl;
        train  *tr;
        ship *sh;
        case 1:
            pl = new plane;
            pl->k = transport::PLANE;
            In(*pl, ifst);
            pl->speed = speed;
            pl->distance = distance;
            return pl;
        case 2:
            tr = new train;
            tr->k = transport::TRAIN;
            In(*tr, ifst);
            tr->speed = speed;
            tr->distance = distance;
            return tr;
        case 3:
            sh = new ship;
            sh->k = transport::SHIP;
            In(*sh, ifst);
            sh->speed = speed;
            sh->distance = distance;
            return sh;
        default:
            return 0;
    }
}

// Случайный ввод обобщенного транспорта
transport *InRnd() {
    auto k = Random() % 3 + 1;
    switch(k) {
        plane *pl;
        train  *tr;
        ship *sh;
        int speed;
        double distance;
        case 1:
            pl = new plane;
            pl->k = transport::PLANE;
            InRnd(*pl);
            speed = Random() % 1000 + 500;
            distance = (double)(Random())/RAND_MAX * 1000 + 1;
            pl->speed = speed;
            pl->distance = distance;
            return pl;
        case 2:
            tr = new train;
            tr->k = transport::TRAIN;
            InRnd(*tr);
            speed = Random() % 300 + 100;
            distance = (double)(Random())/RAND_MAX * 1000 + 1;
            tr->speed = speed;
            tr->distance = distance;
            return tr;
        case 3:
            sh = new ship;
            sh->k = transport::SHIP;
            InRnd(*sh);
            speed = Random() % 200 + 50;
            distance = (double)(Random())/RAND_MAX * 1000 + 1;
            sh->speed = speed;
            sh->distance = distance;
            return sh;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущего транспорта в поток
void Out(transport &s, ofstream &ofst) {
    switch(s.k) {
        case transport::PLANE:
            Out(*((plane*)&s), ofst);
            break;
        case transport::TRAIN:
            Out(*((train*)&s), ofst);
            break;
        case transport::SHIP:
            Out(*((ship*)&s), ofst);
            break;
        default:
            ofst << "Incorrect transport!" << endl;
    }
}

//------------------------------------------------------------------------------
// Вычисление идеального времени прохождения пути
double getPerfectTime(transport &s) {
    return s.distance / (float)s.speed;
}

//------------------------------------------------------------------------------
// Удаление обобщенного транспорта
void DeleteTransport(transport *s) {
    switch(((plane*)s)->k) {
        case transport::PLANE:
            delete (plane*)s;
            break;
        case transport::TRAIN:
            delete (train*)s;
            break;
        case transport::SHIP:
            delete (ship*)s;
            break;
        default:
            break;
    }
}
