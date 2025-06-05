#include <SFML/Graphics.hpp>

// рекурсия для построения множества кантора
void drawCantorSet(sf::RenderWindow& window, float x, float y, float length, int depth) {
    if (depth == 0) return;

    // отрезок
    sf::RectangleShape line(sf::Vector2f(length, 2)); // высота 2 пикселя
    line.setPosition(x, y);
    line.setFillColor(sf::Color::Black);
    window.draw(line);

    // рекурсия для левой и правой части отрезка
    float newY = y + 20; // расстояние между уровнями
    float newLength = length / 3.0f;
    drawCantorSet(window, x, newY, newLength, depth - 1);                 // левая часть
    drawCantorSet(window, x + 2 * newLength, newY, newLength, depth - 1); // правая часть
}

int main() {
    const int width = 2000;
    const int height = 600;
    const int depth = 6; // количество уровней множества

    sf::RenderWindow window(sf::VideoMode(width, height), "Cantor Set");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White); // фон
        drawCantorSet(window, 50, 20, 1800, depth); // начальная точка и длина
        window.display();
    }

    return 0;
}
