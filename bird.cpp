//
// Created by sasha on 10.10.2021.
//

#include "bird.h"
#include "stdio.h"

void In(Bird& bird, FILE* file) {
    char name[10000];
    fscanf_s(file, "%s", name, sizeof(name));
    fscanf_s(file, "%d", &bird.migration);
    fscanf_s(file, "%d", &bird.weight);
    bird.name = new char[10000];
    for (int i = 0; i < 10000; ++i) {
        bird.name[i] = name[i];
    }
    if (bird.weight <= 0 || bird.weight >= 1000000) {
        throw std::invalid_argument("Incorrect input. Check name and weight.");
    }

}
void InRnd(Bird& bird) {
    bird.weight = Random(1, 100000);
    bird.migration = Random(0, 2);
    // Не знаю, как генерить имя, так что имя у нас будет состоять из 5 случайных чаров.
    bird.name = new char[5];
    for (int i = 0; i < 5; ++i) {
        bird.name[i] = ((char) Random(97,122));
    }
}
void Out(Bird& bird, FILE* file) {
    std::string migration;
    if (bird.migration) {
        migration = "has";
    }
    else {
        migration = "hasn't";
    }
    std::string name = "";
    for (int i = 0; i < 10; ++i) {
        name+=bird.name[i];
    }
    fprintf(file, "It's a bird. Name is %s, %s ability migrate, weight is %d, fraction is %f \n", name.c_str(), migration.c_str(), bird.weight, Fraction(bird));
}
double Fraction(Bird& bird) {
    int cnt = 0;
    for (int i = 0; i < 18; i++)
    {
        cnt += (int)bird.name[i];
    }
    return cnt / (double)bird.weight;
}
