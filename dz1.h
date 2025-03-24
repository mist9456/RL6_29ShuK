#ifndef MY_FUNCTIONS_H // Защита от повторного включения
#define MY_FUNCTIONS_H
#include <cstddef>

// Объявление функции для подсчета одинаковых байт
int CountSimilarBytes(long long int byte);

// Объявление функции для обмена байтов в unsigned short
void SwapBytes(unsigned short* byte);

// Объявление функции для поиска максимального байта в массиве
unsigned char GetMaxByte(const unsigned int* ar, size_t size);

#endif // MY_FUNCTIONS_H
