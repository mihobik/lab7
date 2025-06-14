﻿#include <iostream>
#include <locale>
using namespace std;

// функция для вычисления длины Sn = 2^n - 1
long long length_s(int n) {
    return (1LL << n) - 1; // 1LL — это целое число 1 типа (int) long long. "Вернуть число 2^n - 1, при этом вычисления проводить в типе long long"
}

// функция для поиска k-го бита в Sn
char find_kth_bit(int n, long long k) {
    if (n == 1) {
        return '0';
    }
    long long length = length_s(n);
    long long mid = (length / 2) + 1;

    if (k == mid) {
        return '1';
    }
    else if (k < mid) {
        return find_kth_bit(n - 1, k);
    }
    else {
        long long pos = length - k + 1;
        char bit = find_kth_bit(n - 1, pos);
        return (bit == '0') ? '1' : '0';
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    int n;
    long long k;
    cout << "Введите n и k:" << endl;
    cin >> n >> k;
    cout << "Результат:" << endl;
    cout << find_kth_bit(n, k) << '\n';
    return 0;
}
