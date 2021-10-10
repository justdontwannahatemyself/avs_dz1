//
// Created by sasha on 10.10.2021.
//

//------------------------------------------------------------------------------
// animal.cpp - содержит процедуры связанные с обработкой животного
// и создания произвольного животного.
//------------------------------------------------------------------------------

#include "animals.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
Animal* In(FILE* file) {
    Animal *animal;
    int k;
    fscanf(file, "%d", &k);
    switch (k) {
        case 1:
            animal = new Animal;
            animal->kk = Animal::FISH;
            In(animal-> fish, file);
            return animal;
        case 2:
            animal = new Animal;
            animal->kk = Animal::BEAST;
            In(animal-> beast, file);
            return animal;
        case 3:
            animal = new Animal;
            animal->kk = Animal::BIRD;
            In(animal-> bird, file);
            return animal;
        default:
            return nullptr;
    }
}
Animal* InRnd() {
    Animal *animal;
    auto k = rand() % 3 + 1;
    switch (k) {
        case 1:
            animal = new Animal;
            animal->kk = Animal::FISH;
            InRnd(animal->fish);
            return animal;
        case 2:
            animal = new Animal;
            animal->kk = Animal::BEAST;
            InRnd(animal->beast);
            return animal;
        case 3:
            animal = new Animal;
            animal->kk = Animal::BIRD;
            InRnd(animal->bird);
            return animal;
        default:
            return nullptr;
    }
}
void Out(Animal &animal, FILE* file) {
    switch (animal.kk) {
        case Animal::FISH:
            Out(animal.fish, file);
            break;
        case Animal::BEAST:
            Out(animal.beast, file);
            break;
        case Animal::BIRD:
            Out(animal.bird, file);
            break;
        default:
            throw std::invalid_argument("Incorrect animal!\n");
    }
}
double Fraction(Animal &animal) {
    switch(animal.kk) {
        case Animal::FISH:
            return Fraction(animal.bird);
        case Animal::BEAST:
            return Fraction(animal.beast);
        case Animal::BIRD:
            return Fraction(animal.bird);
        default:
            return 0.0;
    }
}
