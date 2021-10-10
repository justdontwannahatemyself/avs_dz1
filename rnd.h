//
// Created by sasha on 10.10.2021.
//

#ifndef MAIN_RND_H
#define MAIN_RND_H

#include <cstdlib>

//------------------------------------------------------------------------------
// rnd.h - содержит генератор случайных чисел в диапазоне от 1 до 20
//------------------------------------------------------------------------------

inline auto Random(int a, int b) {
    return a + (rand() % (abs((a - b)) + 1));
}


#endif //MAIN_RND_H
