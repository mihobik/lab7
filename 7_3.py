# рекурсия
def evaluate_formula(formula, index=0):
    # остановка рекурсии
    if index >= len(formula):
        return 0

    # если не цифра
    if not formula[index].isdigit():
        print(f"Ошибка: ожидалась цифра в позиции {index}")
        exit(1)

    current = int(formula[index])

    # если конец строки
    if index + 1 >= len(formula):
        return current

    # если не + после цифры
    if formula[index + 1] != '+':
        print(f"Ошибка: ожидался знак '+' в позиции {index + 1}")
        exit(1)

    # если не цифра после +
    if index + 2 >= len(formula) or not formula[index + 2].isdigit():
        print(f"Ошибка: ожидалась цифра после '+' в позиции {index + 2}")
        exit(1)

    return current + evaluate_formula(formula, index + 2)


def main():
    input_str = input("Введите формулу: ")

    if input_str == "":
        print("Ошибка: введена пустая строка")
        return

    result = evaluate_formula(input_str)
    print("Результат:", result)


if __name__ == "__main__":
    main()
