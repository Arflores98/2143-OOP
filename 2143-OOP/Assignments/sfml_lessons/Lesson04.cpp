
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dice Roll Animation");

    // Load textures for animation frames
    std::vector<sf::Texture> textures;
    for (int i = 1; i <= 6; ++i) {
        sf::Texture texture;
        if (!texture.loadFromFile("dice_face" + std::to_string(i) + ".png")) {
            std::cerr << "Error loading dice_face" << i << ".png" << std::endl;
            return -1;
        }
        textures.push_back(texture);
    }

    sf::Sprite sprite;
    sprite.setTexture(textures[0]);
    sprite.setPosition(300.f, 200.f);

    sf::Clock clock;
    const sf::Time frameDuration = sf::milliseconds(100);
    size_t currentFrame = 0;
    bool isRolling = true;

    std::srand(std::time(nullptr)); // Seed for random number generation

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Start dice roll on mouse click
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                isRolling = true;
                currentFrame = 0;
                clock.restart();
            }
        }

        // Update animation
        if (isRolling && clock.getElapsedTime() >= frameDuration) {
            clock.restart();
            currentFrame++;

            if (currentFrame >= textures.size()) {
                isRolling = false; // Stop rolling
                sprite.setTexture(textures[std::rand() % 6]); // Display random final frame
            } else {
                sprite.setTexture(textures[currentFrame % textures.size()]);
            }
        }

        // Render
        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();
    }

    return 0;
}