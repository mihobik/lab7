// В последовательности символов могут встречаться только цифры и знаки "+", при этом последовательность представляет собой формулу сложения однозначных чисел. 
// Напишите рекурсивную функцию, определяющую значение формулы.
#include <iostream>
#include <string>
#include <locale>
#include <cctype>
using namespace std;

// рекурсия
int evaluate_formula(const string& formula, int index = 0) {
    // остановка рекурсии
    if (index >= formula.size()) {
        return 0;
    }

    // если не цифра
    if (!isdigit(formula[index])) {
        cout << "Ошибка: ожидалась цифра в позиции " << index << endl;
        exit(1);
    }

    int current = formula[index] - '0';

    // если конец строки
    if (index + 1 >= formula.size()) {
        return current;
    }

    // если не + после цифры
    if (formula[index + 1] != '+') {
        cout << "Ошибка: ожидался знак '+' в позиции " << index + 1 << endl;
        exit(1);
    }

    // если не цифра после +
    if (index + 2 >= formula.size() || !isdigit(formula[index + 2])) {
        cout << "Ошибка: ожидалась цифра после '+' в позиции " << index + 2 << endl;
        exit(1);
    }

    return current + evaluate_formula(formula, index + 2);
}

int main() {
    setlocale(LC_ALL, "RU");
    string input;
    cout << "Введите формулу: ";
    getline(cin, input);

    if (input.empty()) {
        cout << "Ошибка: введена пустая строка" << endl;
        return 1;
    }

    int result = evaluate_formula(input);
    cout << "Результат: " << result << endl;

    return 0;
}
