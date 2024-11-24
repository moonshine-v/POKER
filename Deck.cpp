#include "Deck.h"
#include <algorithm>
#include <random>

Deck::Deck() {
    std::string suits[] = { "hearts", "diamonds", "clubs", "spades" };
    std::string values[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "jack", "queen", "king", "ace" };

    backTexture.loadFromFile("D:/POKER/Project1/PNG-cards-1.3/backCard.png");

    for (const auto& suit : suits) {
        for (const auto& value : values) {
            sf::Texture frontTexture;
            std::string filePath = "D:/POKER/Project1/PNG-cards-1.3/" + value + "_of_" + suit + ".png";
            frontTexture.loadFromFile(filePath);
            frontTextures.push_back(frontTexture);
            cards.emplace_back(frontTexture, backTexture, cards.size() + 1);
        }
    }
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

std::vector<Card> Deck::deal(int numPlayers, int cardsPerPlayer) {
    std::vector<Card> dealtCards;
    int totalCards = numPlayers * cardsPerPlayer;
    for (int i = 0; i < totalCards; ++i) {
        dealtCards.push_back(cards.back());
        cards.pop_back();
    }
    return dealtCards;
}