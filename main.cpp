#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

// Function to generate nPoints based on the seed
std::vector<sf::Vector2f> generatePoints(int seed, int width, int height, int nPoints) {
    std::vector<sf::Vector2f> points;
    std::mt19937 rng(seed); // Initialize random number generator with seed
    std::uniform_int_distribution<int> distX(0, width);
    std::uniform_int_distribution<int> distY(0, height);

    for (int i = 0; i < nPoints; ++i) {
        points.emplace_back(distX(rng), distY(rng));
    }

    return points;
}

int main() {
    int seed = 156;

    // SFML window settings
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Main menu", sf::Style::Default, settings);
    window.setFramerateLimit(144); // set frame rate limit
    window.setVerticalSyncEnabled(true); // enable vertical sync

    // Generate 5 points based on the seed 
    std::vector<sf::Vector2f> points = generatePoints(seed, window.getSize().x, window.getSize().y, 5);

    int colorR = 0, colorG = 0, colorB = 0;

    while (window.isOpen()) {
        // Update
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) { // mouse events (left)
                points = generatePoints(rand(), window.getSize().x, window.getSize().y, 5); // Regenerate points with new seed

            }
        }

        // Draw the map
        window.clear(sf::Color::White);

        // Draw the points
        for (const auto& point : points) {
            sf::RectangleShape rectangle(sf::Vector2f(10, 10)); // Create a rectangle of size 10x10
            rectangle.setPosition(point);
            rectangle.setFillColor(sf::Color(colorR % 256, colorG % 256, colorB % 256));
            colorR += 60;
            colorG += 80;
            colorB += 70;
            window.draw(rectangle);
        }

        colorR = 0;
        colorG = 0;
        colorB = 0;

        window.display();
    }

    return 0;
}