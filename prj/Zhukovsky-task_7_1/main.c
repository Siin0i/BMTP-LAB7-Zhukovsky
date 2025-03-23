#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h> // Для правильного відображення тексту в Windows

// Функція підрахунку символу 'й'
int count_yi(const char *text) {
    int count = 0;
    while (*text) {
        if (*text == 'й') {
            count++;
        }
        text++;
    }
    return count;
}

// Функція видалення голосних з речення
void remove_vowels(char *text) {
    const char *vowels = "аеєиіїоуюяAEIOUaeiou";
    char result[256]; // Гарантуємо достатньо місця для нового тексту
    int j = 0;

    for (int i = 0; text[i] != '\0' && j < 255; i++) { // Обмеження для безпеки
        if (!strchr(vowels, text[i])) {
            result[j++] = text[i];
        }
    }
    result[j] = '\0';
    strcpy(text, result);
}

// Функція перевірки закінчення речення
int has_valid_ending(const char *text) {
    size_t len = strlen(text);
    if (len < 2) return 0; // Мінімальна довжина для "//"

    return (len >= 2 && strcmp(&text[len - 2], "//") == 0) ||
           (len >= 1 && (text[len - 1] == '-' || text[len - 1] == ';'));
}

// Функція видалення роздільних символів
void remove_ending(char *text) {
    size_t len = strlen(text);
    if (len >= 2 && strcmp(&text[len - 2], "//") == 0) {
        text[len - 2] = '\0';
    } else if (len >= 1 && (text[len - 1] == '-' || text[len - 1] == ';')) {
        text[len - 1] = '\0';
    }
}

int main() {
    // Встановлення правильного кодування для Windows-консолі
    setlocale(LC_ALL, "");
    SetConsoleCP(65001);       // Встановлює кодування UTF-8 для введення
    SetConsoleOutputCP(65001); // Встановлює кодування UTF-8 для виводу

    char input[256]; // Буфер для вводу
    printf("Введіть речення: ");

    if (!fgets(input, sizeof(input), stdin)) { // Перевірка на NULL (EOF)
        printf("Помилка зчитування введення!\n");
        return 1;
    }

    // Видалення символу нового рядка (якщо є)
    input[strcspn(input, "\n")] = 0;

    // Перевірка коректності вводу
    if (!has_valid_ending(input)) {
        printf("Некоректний формат вводу!\n");
        return 1;
    }

    // Видалення роздільного символу
    remove_ending(input);

    // Обробка речення
    int yi_count = count_yi(input);
    if (yi_count > 0) {
        printf("Кількість 'й': %d\n", yi_count);
    } else {
        remove_vowels(input);
        printf("Модифіковане речення: %s\n", input);
    }

    return 0;
}
