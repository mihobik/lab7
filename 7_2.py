def length_s(n):
    # функция для вычисления длины Sn = 2^n - 1
    return (1 << n) - 1

def find_kth_bit(n, k):
    # функция для поиска k-го бита в Sn
    if n == 1:
        return '0'
    
    length = length_s(n)
    mid = (length // 2) + 1

    if k == mid:
        return '1'
    elif k < mid:
        return find_kth_bit(n - 1, k)
    else:
        pos = length - k + 1
        bit = find_kth_bit(n - 1, pos)
        return '1' if bit == '0' else '0'

if __name__ == "__main__":
    print("Введите n и k:")
    n, k = map(int, input().split())
    print("Результат:")
    print(find_kth_bit(n, k))
