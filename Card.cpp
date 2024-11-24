#include "Card.h"
#include <cmath>

Card::Card(const sf::Texture& frontTexture, const sf::Texture& backTexture, int value)
    : front(frontTexture), back(backTexture), value(value), isFlipped(false), flipping(false), flipProgress(0.0f) {
    sprite.setTexture(back);
}

// Constructor sao chép
Card::Card(const Card& other)
    : front(other.front), back(other.back), value(other.value), isFlipped(other.isFlipped), flipping(other.flipping), flipProgress(other.flipProgress) {
    sprite.setTexture(isFlipped ? front : back);
    sprite.setPosition(other.sprite.getPosition());
}

// Toán tử gán
Card& Card::operator=(const Card& other) {
    if (this != &other) {
        front = other.front;
        back = other.back;
        value = other.value;
        isFlipped = other.isFlipped;
        flipping = other.flipping;
        flipProgress = other.flipProgress;
        sprite.setTexture(isFlipped ? front : back);
        sprite.setPosition(other.sprite.getPosition());
    }
    return *this;
}

void Card::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Card::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

int Card::getValue() const {
    return value;
}

void Card::flip() {
    if (!flipping) {
        flipping = true;
        flipProgress = 0.0f;
    }
}

void Card::update(float deltaTime) {
    if (flipping) {
        flipProgress += deltaTime * flipSpeed;
        if (flipProgress >= 1.0f) {
            flipProgress = 1.0f;
            flipping = false;
            isFlipped = !isFlipped;
            sprite.setTexture(isFlipped ? front : back);
        }
        float scale = std::abs(std::cos(flipProgress * 3.14159f));
        sprite.setScale(scale, 1.0f);
    }
}

bool Card::contains(sf::Vector2f point) {
    return sprite.getGlobalBounds().contains(point);
}