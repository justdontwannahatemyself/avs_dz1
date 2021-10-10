//
// Created by sasha on 10.10.2021.
//

#ifndef MAIN_BEAST_H
#define MAIN_BEAST_H

//------------------------------------------------------------------------------
// beast.h - содержит описание рыбы
//------------------------------------------------------------------------------
#include <fstream>
#include "rnd.h"
struct Beast {
    enum meal { predators = 0, herbivores, insectivores };
    int meal_index, weight ;
    char* name;
};
void In(Beast& beast, FILE* file);

void InRnd(Beast& beast);

void Out(Beast& beast, FILE* file);

double Fraction(Beast& beast);

#endif //MAIN_BEAST_H

