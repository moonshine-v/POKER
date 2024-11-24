#ifndef TABLE_H
#define TABLE_H

#include <SFML/Graphics.hpp>
#include "turnCard.h"

enum GameState { MENU, GAME_VS_PLAYER, GAME_VS_BOT, EXIT};

class TableWindow {
public:
    void showMenu(GameState& currentState);
    void showGameTable(bool playWithHuman);
    //----
    

private:
    turnCard TurnCards;
    int playerCount;
};

#endif // TABLE_H