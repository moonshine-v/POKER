#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck {
public:
    Deck();
    void shuffle();
    std::vector<Card> deal(int numPlayers, int cardsPerPlayer);

private:
    std::vector<sf::Texture> frontTextures;
    sf::Texture backTexture;
    std::vector<Card> cards;
};

#endif // DECK_H