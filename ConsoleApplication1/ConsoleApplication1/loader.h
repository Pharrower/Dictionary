#pragma once
void loadDictionary(map<string, string>& dictEngToRus, map<string, string>& dictRusToEng) {
    ifstream file("dictionary.txt"); // открытие файла в режиме чтения

    if (!file.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        exit(0);
    }

    else {
        string engWord, rusWord;
        // создание двустороннего перевода в цикле
        while (file >> rusWord >> engWord) {
            dictRusToEng[rusWord] = engWord;
            dictEngToRus[engWord] = rusWord;
        }
    }

    file.close(); // закрытие файла
}
