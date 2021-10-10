//
// Created by sasha on 10.10.2021.
//

#include "beast.h"
#include "stdio.h"

void In(Beast& beast, FILE* file) {
    char name[1000];
    fscanf_s(file, "%s", name, sizeof(name));
    fscanf(file, "%d", &beast.meal_index);
    fscanf(file, "%d", &beast.weight);
    beast.name = new char[1000];
    for (int i = 0; i < 1000; ++i) {
        beast.name[i] = name[i];
    }
    if (beast.weight <= 0 || beast.weight >= 1000000) {
        throw std::invalid_argument("Incorrect input. Check name and weight.");
    }
}
void InRnd(Beast& beast) {
    beast.weight = Random(1, 1000000);
    beast.meal_index = Random(0, 3);
    // Не знаю, как генерить имя, так что имя у нас будет состоять из 5 случайных чаров.
    beast.name = new char[10];
    for (int i = 0; i < 10; ++i) {
        beast.name[i] = ((char) Random(97,122));
    }
}
void Out(Beast& beast, FILE* file) {
    std::string meal;
    switch (beast.meal_index) {
        case beast.predators:
            meal = "predator";
            break;
        case beast.herbivores:
            meal = "herbivores";
            break;
        case beast.insectivores:
            meal = "insectivores";
            break;
        default:
            meal = "none";
    }
    std::string name = "";
    for (int i = 0; i < 10; ++i) {
        name+=beast.name[i];
    }
    fprintf(file, "It's beast. Name is %s Meal is %s, weight is %d, fraction is %f \n", name.c_str(), meal.c_str(), beast.weight, Fraction(beast));
}
double Fraction(Beast& beast) {
    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        cnt += (int)beast.name[i];
    }
    return cnt / (double)beast.weight;
}
