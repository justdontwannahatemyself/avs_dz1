//
// Created by sasha on 10.10.2021.
//

#ifndef MAIN_BIRD_H
#define MAIN_BIRD_H

//------------------------------------------------------------------------------
// bird.h - содержит описание птицы
//------------------------------------------------------------------------------
#include <fstream>
#include "rnd.h"
struct Bird {
    bool migration;
    int weight;
    char* name;
};

void In(Bird& bird, FILE* file);

void InRnd(Bird& bird);

void Out(Bird& bird, FILE* file);

double Fraction(Bird& bird);

#endif //MAIN_BIRD_H
