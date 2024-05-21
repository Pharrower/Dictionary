#include <iostream> // Подключение библиотеки для ввода/вывода данных
#include <fstream> // Подключение библиотеки для работы с файлами
#include <map> // Подключение библиотеки для работы с контейнером
#include <string> // Подключение библиотеки для работы со строками
#include <windows.h>
#include <algorithm> // Подключение библиотеки для работы с контейнерами

using namespace std; // Использование пространства имен std

#include "loader.h" // Заголовочный файл с функцией загрузки словаря

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "russian"); // Установка локали на русский язык

    map<string, string> dictEngToRus, dictRusToEng; // Создаём два словаря для хранения переводов
    loadDictionary(dictEngToRus, dictRusToEng); // Функция загрузки словарей

    ofstream result; // Поток для записи
    result.open("results.txt"); // Открытие файла для записи
    if (result.is_open()) {

        bool running = true; // Переменная для управления работой программы
        while (running) {
            char option; // Переменная для выбора опции перевода
            cout << "\nВыберите опцию перевода:\nR - для перевода с Русского на английский,\nE - для перевода с Английского на русский,\n0 - для выхода из программы.\nОпция: ";
            cin >> option;

            // Этот блок кода выполняется, если пользователь выбрал перевод с русского на английский
            if (option == 'R' || option == 'r') {
                string rusWord;
                cout << "Введите русское слово: ";
                cin >> rusWord;
                transform(rusWord.begin(), rusWord.end(), rusWord.begin(), tolower);

                if (dictRusToEng.find(rusWord) != dictRusToEng.end()) {
                    cout << "Английский перевод: " << dictRusToEng[rusWord] << endl;
                    result << rusWord << " - " << dictRusToEng[rusWord] << endl;
                }
                else {
                    cout << "Перевод не найден." << endl;
                    result << rusWord << " - Перевод не найден" << endl;
                }
            }

            // Этот блок кода выполняется, если пользователь выбрал перевод с английского на русский
            else if (option == 'E' || option == 'e') {
                string engWord;
                cout << "Введите английское слово: ";
                cin >> engWord;
                transform(engWord.begin(), engWord.end(), engWord.begin(), tolower);

                if (dictEngToRus.find(engWord) != dictEngToRus.end()) {
                    cout << "Русский перевод: " << dictEngToRus[engWord] << endl;
                    result << engWord << " - " << dictEngToRus[engWord] << endl;
                }
                else {
                    cout << "Перевод не найден." << endl;
                    result << engWord << " - Перевод не найден" << endl;
                }
            }

            // Этот блок кода выполняется, если пользователь выбрал опцию "завершить программу"
            else if (option == '0') {
                running = false;
            }

            // Этот блок кода выполняется, если пользователь ввёл неизвестную опцию
            else {
                cout << "Неверная опция." << endl;
            }
        }
    }
    result.close(); // Закрытие файла с результатами поиска
    cout << "\nРезультаты поиска записаны в файл results.txt" << endl;

    return 0;
}
