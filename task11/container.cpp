//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    for(int i = 0; i < c.len; i++) {
        ////???? delete c.cont[i];
        DeleteTransport(c.cont[i]);
    }
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void In(container &c, ifstream &ifst) {
    while(!ifst.eof()) {
        if((c.cont[c.len] = In(ifst)) != 0) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRnd(container &c, int size) {
    while(c.len < size) {
        if((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container &c, ofstream &ofst) {
    ofst << "Container contains " << c.len << " elements." << endl;
    for(int i = 0; i < c.len; i++) {
        ofst << i << ": ";
        Out(*(c.cont[i]), ofst);
    }
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического по общей функции и перемещение в конец элементов его превышающего
double MoveToTheEnd(container &c) {
    double average = 0.0;
    for(int i = 0; i < c.len; i++) {
        average += getPerfectTime(*(c.cont[i]));
    }
    average = average / c.len;
    transport* container_for_sort[container::max_len];
    int index = 0;
    for (int i=0; i < (c.len); i++) {
        if (getPerfectTime(*c.cont[i]) <= average) {
            container_for_sort[index] = c.cont[i];
            ++index;
        }
    }

    for (int i=0; i < (c.len); i++) {
        if (getPerfectTime(*c.cont[i]) > average) {
            container_for_sort[index] = c.cont[i];
            ++index;
        }
    }

    for (int i = 0; i < c.len; i++) {
        c.cont[i] = container_for_sort[i];
    }

    return average;
}
