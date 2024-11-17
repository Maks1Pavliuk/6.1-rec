#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

const int SIZE = 21;
const int LOWER_BOUND = 15;
const int UPPER_BOUND = 85;

// Рекурсивна функція для генерації масиву sp
void generateArray(int arr[], int index) {
    if (index == SIZE) return;
    arr[index] = LOWER_BOUND + rand() % (UPPER_BOUND - LOWER_BOUND + 1);
    generateArray(arr, index + 1);
}

// Рекурсивна функція для виведення масиву
void printArray(int arr[], int index) {
    if (index == SIZE) {
        std::cout << std::endl;
        return;
    }
    std::cout << std::setw(4) << arr[index];
    printArray(arr, index + 1);
}

// Рекурсивна функція для обчислення кількості і суми елементів, що відповідають критерію
void calculateAndReplace(int arr[], int index, int& count, int& sum) {
    if (index == SIZE) return;

    if (arr[index] % 2 != 0 && index % 13 != 0) {  // Умови для критерія
        sum += arr[index];
        count++;
        arr[index] = 0;  // Заміняємо на нуль
    }

    calculateAndReplace(arr, index + 1, count, sum);
}

int main() {
    srand(time(0));  // Ініціалізуємо генератор випадкових чисел
    int arr[SIZE];
    int count = 0, sum = 0;

    generateArray(arr, 0);
    std::cout << "Original array:\n";
    printArray(arr, 0);

    calculateAndReplace(arr, 0, count, sum);

    std::cout << "\nCount: " << count << ", Sum: " << sum << std::endl;
    std::cout << "Modified array:\n";
    printArray(arr, 0);

    return 0;
}
