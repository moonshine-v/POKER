#ifndef CARD_H
#define CARD_H

#include <SFML/Graphics.hpp>

class Card {
public:
    Card(const sf::Texture& frontTexture, const sf::Texture& backTexture, int value);
    Card(const Card& other); // Constructor sao chép
    Card& operator=(const Card& other); // Toán tử gán
    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y);
    int getValue() const;
    void flip();
    void update(float deltaTime);
    bool contains(sf::Vector2f point);

private:
    sf::Sprite sprite;
    sf::Texture front;
    sf::Texture back;
    int value;
    bool isFlipped;
    bool flipping;
    float flipProgress;
    const float flipSpeed = 2.0f; // Tốc độ lật
};

#endif // CARD_H