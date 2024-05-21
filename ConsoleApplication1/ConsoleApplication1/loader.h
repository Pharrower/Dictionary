#pragma once
void loadDictionary(map<string, string>& dictEngToRus, map<string, string>& dictRusToEng) {
    ifstream file("dictionary.txt"); // �������� ����� � ������ ������

    if (!file.is_open()) {
        cout << "������ �������� �����!" << endl;
        exit(0);
    }

    else {
        string engWord, rusWord;
        // �������� ������������� �������� � �����
        while (file >> rusWord >> engWord) {
            dictRusToEng[rusWord] = engWord;
            dictEngToRus[engWord] = rusWord;
        }
    }

    file.close(); // �������� �����
}
