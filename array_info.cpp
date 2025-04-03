#include "array_info.h"
#include <cstdlib>  // для rand() и srand()
#include <ctime>    // для time() (чтобы rand() давал разные значения при каждом запуске)

namespace {
    bool rand_initialized = []() {
        std::srand(std::time(nullptr));  // Инициализация временем
        return true;
    }();
}

int* CreateAr(int size){
    if (size <=0) {
        return nullptr;
    }
    int* array = new int[size];
    return array;
}
int* CreateAr(int size, int number){
    if (size <=0) {
        return nullptr;
    }
     int* array = new int[size];
     for( int i=0; i<size; i++) {
         array[i]=number;
    }
    return array;
}
int* CreateAr(int size, int min, int max){
    if ((size <= 0) || (min >= max)) {
        return nullptr;
    }
    int* array = new int[size];

    for( int i=0; i<size; i++) {
        array[i] = min + std::rand() % (max - min + 1);
    }
    return array;
}
