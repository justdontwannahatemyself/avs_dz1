//
// Created by sasha on 10.10.2021.
//

#include "fish.h"
#include "stdio.h"

void In(Fish& fish, FILE* file) {
    char name[10000];
    fscanf_s(file, "%s", name, sizeof(name));
    fscanf_s(file, "%d", &fish.area_index);
    fscanf_s(file, "%d", &fish.weight);
    fish.name = new char[10000];
    for (int i = 0; i < 10000; ++i) {
        fish.name[i] = name[i];
    }
    if (fish.weight <= 0 || fish.weight >= 1000000) {
        throw std::invalid_argument("Incorrect input. Check name and weight.");
    }
}
void InRnd(Fish& fish) {
    fish.weight = Random(1, 1000000);
    fish.area_index = Random(0, 3);
    // Не знаю, как генерить имя, так что имя у нас будет состоять из 10 случайных чаров.
    fish.name = new char[10];
    for (int i = 0; i < 10; ++i) {
        fish.name[i] = ((char) Random(97,122));
    }
}
void Out(Fish& fish, FILE* file) {
    std::string area;
    switch (fish.area_index)
    {
        case fish.LAKE:
            area = "lake";
            break;
        case fish.SEA:
            area = "sea";
            break;
        case fish.RIVER:
            area = "river";
            break;
        default:
            area = "none";
    }
    std::string name = "";
    for (int i = 0; i < 10; ++i) {
        name+=fish.name[i];
    }
    fprintf(file, "It's fish. Name is %s Area is %s, weight is %d, fraction is %f \n",name.c_str(), area.c_str(), fish.weight, Fraction(fish));
}
double Fraction(Fish& fish) {
    int cnt = 0;
    for (int i = 0; i < 18; i++)
    {
        cnt += (int)fish.name[i];
    }
    return cnt / (double)fish.weight;
}
