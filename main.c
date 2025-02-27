﻿#include <stdio.h>   // Подключаем стандартную библиотеку для работы с вводом/выводом
#include <stdlib.h>  // Подключаем стандартную библиотеку для работы с памятью и функциями генерации случайных чисел
#include <time.h>    // Подключаем библиотеку для работы с датой и временем (для генерации случайных чисел на основе времени)

// Функция сравнения для сортировки
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);  // Преобразуем указатели к типу int и возвращаем разницу между ними для сортировки
}

int main() {
    int numbers[100];  // Массив для хранения 100 случайных чисел

    // Инициализация генератора случайных чисел с использованием текущего времени
    srand(time(NULL));  // Функция time(NULL) возвращает текущее время, используем его как зерно для генератора случайных чисел

    // Вывод заголовка
    printf("100 random numbers:\n");

    // Генерация и вывод 100 случайных чисел
    for (int i = 0; i < 100; i++) {
        numbers[i] = rand() % 1000;  // Генерация случайного числа от 0 до 999
        printf("%3d ", numbers[i]);  // Выводим число с выравниванием по правому краю (ширина 3 символа)

        // После каждых 10 чисел выводим новую строку
        if ((i + 1) % 10 == 0) {
            printf("\n");  // Переводим на новую строку после 10 чисел
        }
    }

    // Сортировка массива чисел с помощью стандартной функции qsort
    qsort(numbers, 100, sizeof(int), compare);  // Сортировка 100 чисел типа int с помощью функции compare

    // Вывод заголовка для отсортированных чисел
    printf("\nSorted numbers:\n");

    // Вывод отсортированных чисел
    for (int i = 0; i < 100; i++) {
        printf("%3d ", numbers[i]);  // Выводим отсортированное число с выравниванием по правому краю (ширина 3 символа)

        // После каждых 10 чисел выводим новую строку
        if ((i + 1) % 10 == 0) {
            printf("\n");  // Переводим на новую строку после 10 чисел
        }
    }

    return 0;  // Завершаем программу с кодом 0 (успешное завершение)
}