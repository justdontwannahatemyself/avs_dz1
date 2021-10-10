//
// Created by sasha on 10.10.2021.
//

#ifndef MAIN_FISH_H
#define MAIN_FISH_H

//------------------------------------------------------------------------------
// fish.h - содержит описание рыбы
//------------------------------------------------------------------------------
#include "rnd.h"
#include <fstream>
struct Fish {
    enum area { RIVER = 0, SEA, LAKE };
    int area_index, weight;
    char* name;
};
void In(Fish& fish, FILE* file);

void InRnd(Fish& fish);

void Out(Fish& fish, FILE* file);

double Fraction(Fish& fish);


#endif //MAIN_FISH_H
