#include "gameSpace.h"


void gameSpace::cell::setCurrentDisplay(displayType newDisplay){
    currentDisplay = newDisplay;
}

displayType gameSpace::cell::getCurrentDisplay(){
    return currentDisplay;
}

gameSpace::cell::cell(){
    currentDisplay  = water;
    pieceInstance   = nullptr;
    pieceIndex      = 0;
    wasAttacked     = false;
}

gameSpace::cell::~cell(){
}

void gameSpace::cell::setAttacked(bool attacked){
    wasAttacked = attacked;
}

bool gameSpace::cell::getAttacked(){
    return wasAttacked;
}

piece* gameSpace::cell::getPiece(){
    return pieceInstance;
}

void gameSpace::cell::setPiece(piece* newPiece){
    pieceInstance = newPiece;
}

int gameSpace::cell::getPieceIndex(){
    return pieceIndex;
}

void gameSpace::cell::setPieceIndex(int id){
    pieceIndex = id;
}

void gameSpace::playSpace::setUserBoard(){
    userBoard.reserve(15);
    for (int i = 0; i < 15; i ++){
         std::vector<cell> row;
         row.reserve(15);
         for (int j = 0; j < 15; j++){
             cell ci;
             row.push_back(ci);
         }
         userBoard.push_back(row);
    }

}


std::vector<std::vector<gameSpace::cell>> & gameSpace::playSpace::getUserBoard(){
    return userBoard;
}

gameSpace::cell& gameSpace::playSpace::getBoardPosition(int posX, int posY){
    std::vector<gameSpace::cell> & row = userBoard.at(posY);
    gameSpace::cell & cellInstance = row.at(posX);
    return cellInstance;
    
}

void gameSpace::playSpace::setBoardPosition(int posX, int posY, displayType display){

}

gameSpace::playSpace::playSpace(){
    setUserBoard();   
}

bool gameSpace::playSpace::checkFreePosition(int x, int y){
    std::vector<cell> & row = userBoard.at(y);
    cell & cellInstance = row.at(x);
    displayType cellType = cellInstance.getCurrentDisplay();
    if (cellType == water)
        return true;
    else
        return false;
}


