#include "dz1.h"
#include <iostream> // Для std::cout
#include <iomanip>  // Для std::hex

void main() {
    // /////////////////////////////////////////////////////////////
    // // Тестируем CountSimilarBytes (сколько раз один байт встречается)
    // /////////////////////////////////////////////////////////////
    // long long int test1 = 0x1122334455667788; // Все байты разные (кроме 0x00 и 0xFF)
    // long long int test2 = 0xAAAAAAAABBBBBBBB; // Байты 0xAA (4 раза), 0xBB (4 раза)
    // long long int test3 = 0xFF00FF00FF00FF00; // Только 0xFF и 0x00 → результат 0
    //
    // std::cout << "=== Test CountSimilarBytes ===\n";
    // std::cout << "Test1 (vse raznue): " << CountSimilarBytes(test1) << " (ojidau 1)\n";
    // std::cout << "Test2 (4 AA i 4 BB): " << CountSimilarBytes(test2) << " (ojidau 4)\n";
    // std::cout << "Test3 (tolko 0xFF/0x00): " << CountSimilarBytes(test3) << " (ojidau 0)\n\n";
    //
    // /////////////////////////////////////////////////////////////
    // // Тестируем SwapBytes (меняем байты местами)
    // /////////////////////////////////////////////////////////////
    // unsigned short chislo1 = 0xABCD; // До: 0xABCD → После: 0xCDAB
    // unsigned short chislo2 = 0x1234; // До: 0x1234 → После: 0x3412
    //
    // std::cout << "=== Test SwapBytes ===\n";
    // SwapBytes(&chislo1);
    // SwapBytes(&chislo2);
    // std::cout << "Test1 (0xABCD -> 0x" << std::hex << chislo1 << ")\n";
    // std::cout << "Test2 (0x1234 -> 0x" << std::hex << chislo2 << ")\n\n";
    //
    // /////////////////////////////////////////////////////////////
    // // Тестируем GetMaxByte (ищем самый большой байт в массиве)
    // /////////////////////////////////////////////////////////////
    // unsigned int massiv1[] = {0x01ABCDEF, 0x8899AABB}; // Максимум 0xEF (239)
    // unsigned int massiv2[] = {0x00000000, 0xFFFFFFFF}; // Все байты 0x00 или 0xFF → вернёт 0
    //
    // std::cout << "=== Test GetMaxByte ===\n";
    // std::cout << "Test1 (max 0xEF): 0x" << std::hex << static_cast<int>(GetMaxByte(massiv1, 2)) << "\n";
    // std::cout << "Test2 (vse 0x00/0xFF): 0x" << std::hex << static_cast<int>(GetMaxByte(massiv2, 2)) << "\n";
    //
    // return 0;
}
