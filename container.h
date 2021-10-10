//
// Created by sasha on 10.10.2021.
//

#ifndef MAIN_CONTAINER_H
#define MAIN_CONTAINER_H

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------
#include "animals.h"

struct container {
    enum {max_len = 10001}; // максимальная длина
    int len; // текущая длина
    Animal *container[max_len];
};
// Инициализация контейнера
void Init(container &c);

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c);

// Ввод содержимого контейнера из указанного потока
void In(container &c, FILE* file);

// Случайный ввод содержимого контейнера
void InRnd(container &c, int size);

// Вывод содержимого контейнера в указанный поток
void Out(container &c, FILE* file);

// Сортировка контейнера алгоритмом Шелла
void ShellSort(container &c);



#endif //MAIN_CONTAINER_H
