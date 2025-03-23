#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h> // ��� ����������� ����������� ������ � Windows

// ������� ��������� ������� '�'
int count_yi(const char *text) {
    int count = 0;
    while (*text) {
        if (*text == '�') {
            count++;
        }
        text++;
    }
    return count;
}

// ������� ��������� �������� � �������
void remove_vowels(char *text) {
    const char *vowels = "��賿����AEIOUaeiou";
    char result[256]; // ��������� ��������� ���� ��� ������ ������
    int j = 0;

    for (int i = 0; text[i] != '\0' && j < 255; i++) { // ��������� ��� �������
        if (!strchr(vowels, text[i])) {
            result[j++] = text[i];
        }
    }
    result[j] = '\0';
    strcpy(text, result);
}

// ������� �������� ��������� �������
int has_valid_ending(const char *text) {
    size_t len = strlen(text);
    if (len < 2) return 0; // ̳������� ������� ��� "//"

    return (len >= 2 && strcmp(&text[len - 2], "//") == 0) ||
           (len >= 1 && (text[len - 1] == '-' || text[len - 1] == ';'));
}

// ������� ��������� ��������� �������
void remove_ending(char *text) {
    size_t len = strlen(text);
    if (len >= 2 && strcmp(&text[len - 2], "//") == 0) {
        text[len - 2] = '\0';
    } else if (len >= 1 && (text[len - 1] == '-' || text[len - 1] == ';')) {
        text[len - 1] = '\0';
    }
}

int main() {
    // ������������ ����������� ��������� ��� Windows-������
    setlocale(LC_ALL, "");
    SetConsoleCP(65001);       // ���������� ��������� UTF-8 ��� ��������
    SetConsoleOutputCP(65001); // ���������� ��������� UTF-8 ��� ������

    char input[256]; // ����� ��� �����
    printf("������ �������: ");

    if (!fgets(input, sizeof(input), stdin)) { // �������� �� NULL (EOF)
        printf("������� ���������� ��������!\n");
        return 1;
    }

    // ��������� ������� ������ ����� (���� �)
    input[strcspn(input, "\n")] = 0;

    // �������� ���������� �����
    if (!has_valid_ending(input)) {
        printf("����������� ������ �����!\n");
        return 1;
    }

    // ��������� ���������� �������
    remove_ending(input);

    // ������� �������
    int yi_count = count_yi(input);
    if (yi_count > 0) {
        printf("ʳ������ '�': %d\n", yi_count);
    } else {
        remove_vowels(input);
        printf("������������ �������: %s\n", input);
    }

    return 0;
}
