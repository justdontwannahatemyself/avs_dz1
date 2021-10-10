//
// Created by sasha on 10.10.2021.
//

#ifndef MAIN_ANIMALS_H
#define MAIN_ANIMALS_H

//------------------------------------------------------------------------------
// animal.h - содержит описание животного
//------------------------------------------------------------------------------
#include "bird.h"
#include "beast.h"
#include "fish.h"
//------------------------------------------------------------------------------
// Структура, обобщающая все имеющиеся фигуры
//------------------------------------------------------------------------------
struct Animal {
    enum key{FISH = 1, BEAST = 2, BIRD = 3};
    key kk;
    union {
        Fish fish;
        Beast beast;
        Bird bird;
    };
};

Animal *In(FILE* file);
Animal *InRnd();
void Out(Animal &animal, FILE* file);
double Fraction(Animal &animal);
#endif //MAIN_ANIMALS_H