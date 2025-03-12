#include <stdio.h>
#include <locale.h>
#include <windows.h> // ��� ���������� ����������� ������ � Windows-������

#define SIZE 14 // ʳ������ �������� � �����

/**
 * ������� �������� ������� �������� ����� � �����.
 * @param arr ������� ����� �����.
 * @param size ����� ������.
 * @return ʳ������ �������� �����.
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
 * ������� �������� ���� �������� ����� � �����.
 * @param arr ������� ����� �����.
 * @param size ����� ������.
 * @return ���� �������� �����.
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
 * ������� �������� ����� ��������� ������������ �������.
 * @param arr ����� ��� ���������� �������� �����.
 * @param size ����� ������.
 */
void input_array(int arr[], int size) {
    printf("������ %d �����:\n", size);
    for (int i = 0; i < size; i++) {
        printf("����� �%d: ", i + 1);
        while (scanf("%d", &arr[i]) != 1) { // �������� ��������
            printf("�������! ������ ���� �����: ");
            while (getchar() != '\n'); // �������� ������ �����
        }
    }
}

/**
 * ������� ������� ��������.
 * ������ ����� ����� �� �����������, �������� ���� �� �������� ����������.
 * @return 0 ��� �������� ��������.
 */
int main() {
    // ������������ ����������� ��������� ��� Windows-������
    setlocale(LC_ALL, "uk_UA.UTF-8");
    SetConsoleCP(65001);       // ���������� ��������� UTF-8 ��� ��������
    SetConsoleOutputCP(65001); // ���������� ��������� UTF-8 ��� ������

    int numbers[SIZE]; // ���������� ������
    input_array(numbers, SIZE); // ���������� ������

    // ���������� ������� �� ���� �������� �����
    int positive_count = count_positive_numbers(numbers, SIZE);
    int positive_sum = sum_positive_numbers(numbers, SIZE);

    // ���� ����������
    printf("\nʳ������ �������� �����: %d\n", positive_count);
    printf("���� �������� �����: %d\n", positive_sum);

    // ���������� Enter ����� ���������
    printf("\n�������� Enter ��� ������...\n");
    getchar();
    getchar();

    return 0;
}

