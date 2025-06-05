import matplotlib.pyplot as plt

# рекурсия для построения множества 
def drawCantorSet(x, y, length, depth):
    if depth == 0:
        return

    plt.plot([x, x + length], [y, y], color='black', linewidth=2)

    # рекурсия для левой и правой части
    newY = y - 20  # расстояние между уровнями 
    newLength = length / 3.0
    drawCantorSet(x, newY, newLength, depth - 1)  # левая часть
    drawCantorSet(x + 2 * newLength, newY, newLength, depth - 1)  # правая часть

def main():
    width = 2000
    height = 600
    depth = 7  # количество уровней множества

    plt.figure(figsize=(width / 100, height / 100))  # размер окна
    plt.axis('off')
    drawCantorSet(50, height - 50, 1800, depth)  # начальная точка и длина
    plt.show()

if __name__ == "__main__":
    main()
