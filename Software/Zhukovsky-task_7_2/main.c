#include <stdio.h>
#include <locale.h>
#include <windows.h> // Для коректного відображення тексту в Windows-консолі

#define SIZE 14 // Кількість елементів у масиві

/**
 * Функція підраховує кількість додатних чисел у масиві.
 * @param arr Вхідний масив чисел.
 * @param size Розмір масиву.
 * @return Кількість додатних чисел.
 */
int count_positive_numbers(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            count++;
        }
    }
    return count;
}

/**
 * Функція обчислює суму додатних чисел у масиві.
 * @param arr Вхідний масив чисел.
 * @param size Розмір масиву.
 * @return Сума додатних чисел.
 */
int sum_positive_numbers(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }
    return sum;
}

/**
 * Функція заповнює масив введеними користувачем числами.
 * @param arr Масив для збереження введених чисел.
 * @param size Розмір масиву.
 */
void input_array(int arr[], int size) {
    printf("Введіть %d чисел:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Число №%d: ", i + 1);
        while (scanf("%d", &arr[i]) != 1) { // Перевірка введення
            printf("Помилка! Введіть ціле число: ");
            while (getchar() != '\n'); // Очищення буфера вводу
        }
    }
}

/**
 * Головна функція програми.
 * Отримує масив чисел від користувача, обробляє його та виводить результати.
 * @return 0 при успішному виконанні.
 */
int main() {
    // Встановлення правильного кодування для Windows-консолі
    setlocale(LC_ALL, "uk_UA.UTF-8");
    SetConsoleCP(65001);       // Встановлює кодування UTF-8 для введення
    SetConsoleOutputCP(65001); // Встановлює кодування UTF-8 для виводу

    int numbers[SIZE]; // Оголошення масиву
    input_array(numbers, SIZE); // Заповнення масиву

    // Обчислення кількості та суми додатних чисел
    int positive_count = count_positive_numbers(numbers, SIZE);
    int positive_sum = sum_positive_numbers(numbers, SIZE);

    // Вивід результатів
    printf("\nКількість додатних чисел: %d\n", positive_count);
    printf("Сума додатних чисел: %d\n", positive_sum);

    // Очікування Enter перед закриттям
    printf("\nНатисніть Enter для виходу...\n");
    getchar();
    getchar();

    return 0;
}

