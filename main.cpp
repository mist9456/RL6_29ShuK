// #include "array_info.h"
// #include <iostream>
//
// void printArray(int* arr, int size) {
//     if (arr == nullptr) {
//         std::cout << "Array is null!" << std::endl;
//         return;
//     }
//
//     for (int i = 0; i < size; ++i) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;
// }
//
// int main() {
//     // Тест 1: Создание пустого массива
//     int* arr1 = CreateAr(5);
//     std::cout << "Test 1: Uninitialized array (should contain garbage values):" << std::endl;
//     printArray(arr1, 5);
//     delete[] arr1;  // Освобождаем память
//
//     // Тест 2: Создание массива, заполненного одним числом
//     int* arr2 = CreateAr(7, 42);
//     std::cout << "\nTest 2: Array filled with number 42:" << std::endl;
//     printArray(arr2, 7);
//     delete[] arr2;  // Освобождаем память
//
//     // Тест 3: Создание массива со случайными числами в диапазоне
//     int* arr3 = CreateAr(10, 10, 20);
//     std::cout << "\nTest 3: Array with random numbers between 10 and 20:" << std::endl;
//     printArray(arr3, 10);
//     delete[] arr3;  // Освобождаем память
//
//     // Тест 4: Проверка на некорректные входные данные
//     int* arr4 = CreateAr(0);  // Некорректный размер
//     std::cout << "\nTest 4: Invalid size (should be null):" << std::endl;
//     printArray(arr4, 0);
//
//     int* arr5 = CreateAr(5, 20, 10);  // min > max
//     std::cout << "\nTest 5: Invalid range (min > max, should be null):" << std::endl;
//     printArray(arr5, 5);
//
//     return 0;
// }
