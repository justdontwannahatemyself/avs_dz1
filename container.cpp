//
// Created by sasha on 10.10.2021.
//

#include "container.h"

// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    for (int i = 0; i < c.len; ++i) {
        delete c.container[i];
    }
    c.len = 0;
}
void In(container &c, FILE* file) {
    while (!feof(file)) {
        if ((c.container[c.len] = In(file)) != nullptr) {
            c.len++;
        }
    }
}
void InRnd(container &c, int size){
    while(c.len < size) {
        if((c.container[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
}
void Out(container &c, FILE* file) {
    fprintf(file, "Container contains %d elements.\n", c.len);
    for (int i = 0; i < c.len; ++i) {
        fprintf(file, "%d :", i+1);
        Out(*(c.container[i]), file);
    }
}

// Сортировка контейнера алгоритмом Шелла
void ShellSort(container &c){
    int d = c.len / 2;
    while (d != 0){
        for (int i = d; i < c.len; i += d) {
            int j = i;
            while (j > 0 && Fraction(*c.container[j - d]) > Fraction(*c.container[j])){
                std::swap(c.container[j - d], c.container[j]);
                j -= d;
            }
        }
        d /= 2;
    }
}
