#include <iostream>

using namespace std;

// Таблица римских цифр
const char* roman_numerals[] = { "I", "V", "X", "L", "C", "D", "M" };

// Функция для преобразования римской цифры в целое число
int roman_to_int(char c) {
    switch (c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return -1;
    }
}

// Функция для преобразования целого числа в римские цифры
string int_to_roman(int n) {
    string roman_number;

    // Цикл по тысячам
    for (int i = 0; n >= 1000; i++) {
        roman_number += roman_numerals[i];
        n -= 1000;
    }

    // Цикл по сотням
    for (int i = 1; n >= 100; i++) {
        if (n >= 500) {
            roman_number += roman_numerals[6];
            n -= 500;
        }
        else {
            roman_number += roman_numerals[i];
            n -= 100;
        }
    }

    // Цикл по десяткам
    for (int i = 2; n >= 10; i++) {
        if (n >= 50) {
            roman_number += roman_numerals[5];
            n -= 50;
        }
        else {
            roman_number += roman_numerals[i];
            n -= 10;
        }
    }

    // Цикл по единицам
    for (int i = 3; n >= 1; i++) {
        roman_number += roman_numerals[i];
        n -= 1;
    }

    return roman_number;
}

int main() {
    int n;
    cout << "Введите целое число (< 400): ";
    cin >> n;

    if (n < 1 || n > 400) {
        cout << "Число должно быть больше 0 и меньше 400." << endl;
        return 1;
    }

    string roman_number = int_to_roman(n);
    cout << "Запись числа " << n << " римскими цифрами: " << roman_number << endl;

    return 0;
}