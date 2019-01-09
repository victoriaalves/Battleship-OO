#include "player.h"
#include <sstream>
#include <regex>
#include <iostream>
#include <string>


List<piece*> & player::getPieces(){
    return playerPieces;
}

void player::addPiece(piece* newPiece){
    playerPieces.insert(newPiece);
}

bool player::getPlaying(){
    return playing;
}

void player::setPlaying(bool isPlaying){
    playing = isPlaying;
}

void player::removePiece(piece *nowDead){
    playerPieces.remove(nowDead);
}

List<piece*> & player::getDeadPieces(){
    return deadPieces;
}

gameSpace::playSpace & player::getPSpace(){
    return pSpace;
}

std::vector<std::vector<gameSpace::cell> >& player::getBoard(){
    return pSpace.getUserBoard();
}

void player::addDeadPiece(piece * dead){
    deadPieces.insert(dead);
}

std::vector<position> player::getOrientationPosition(rotation orientation, position instancePos, int sizePiece){
    std::vector<position> newPositions;
    position newPos;
    bool validePos;
    newPositions.push_back(instancePos);
    int i = 0;
    int x, y;
    while (i < sizePiece -1){
        switch(orientation){
            case 0:          x = instancePos.getPositionX() +1;
                             y = instancePos.getPositionY();
                             validePos = newPos.setPosition(x, y);
                             break;
            case 1:          x = instancePos.getPositionX();
                             y = instancePos.getPositionY() +1;
                             validePos = newPos.setPosition(x, y);;
                             break;
            case 2:          x = instancePos.getPositionX() -1;
                             y = instancePos.getPositionY();
                             validePos = newPos.setPosition(x, y);
                             break;
            case 3:          x = instancePos.getPositionX();
                             y = instancePos.getPositionY() -1;
                             validePos = newPos.setPosition(x, y);
                             break;
        }
        if (validePos){
            newPositions.push_back(newPos);
            instancePos = newPos;
            i++;
        }
        else{
            generateRotation(orientation);
        }
    }
    return newPositions;
}

bool player::checkAllPositions(std::vector<position> newPositions, std::vector<std::vector<gameSpace::cell>> & board){
    for (position pos : newPositions){
        std::vector<gameSpace::cell> & row = board.at(pos.getPositionY());
        gameSpace::cell & cellInstance = row.at(pos.getPositionX());
        displayType cellType = cellInstance.getCurrentDisplay();
        if (cellType != water)
            return false;
    }
    return true;
}


void player::generateRotation(rotation & orientation){
    int r = rand() % 3;
    orientation = (rotation)r;
}

void player::generatePosition(position & instancePos){
        // the limist is 15 houses, but the vector start 0, so we take 1 out.
        int x = rand() % (ciVerticalEnd - 1);
        int y = rand() % (ciHorizontalEnd - 1);
        instancePos.setPosition(x, y);
}


void player::generateSmallPieces(std::vector<std::vector<gameSpace::cell> >& board, piece * ricinus){
        position pos;
        bool generated = false;
        while (!generated){
            generatePosition(pos);
            std::vector<gameSpace::cell> & row = board.at(pos.getPositionY());
            gameSpace::cell & cellInstance = row.at(pos.getPositionX());
            displayType cellType = cellInstance.getCurrentDisplay();
            if (cellType == water){
                ricinus->setCoordinates(pos);
                ricinus->setRotation(standard_0);
                cellInstance.setPiece(ricinus);
                cellInstance.setPieceIndex(0);
                cellInstance.setCurrentDisplay(nothingAttacked);
                generated = true;
            }
        }

}

void player::generatePieces(std::vector<std::vector<gameSpace::cell> >& board, piece *motorcycle, int size){
        position jetSkiPos;
        bool generated = false;
        while (!generated){
            rotation orientation;
            std::vector<position> positions;
            generatePosition(jetSkiPos);
            generateRotation(orientation);
            positions = getOrientationPosition(orientation, jetSkiPos, size);
            bool check = checkAllPositions(positions, board);
            if (check){
                int j = 0;
                motorcycle->setCoordinates(jetSkiPos);
                motorcycle->setRotation(standard_0);
                generated = true;
                for (position pos : positions){
                    std::vector<gameSpace::cell> & row = board.at(pos.getPositionY());
                    gameSpace::cell & cellInstance = row.at(pos.getPositionX());
                    cellInstance.setPiece(motorcycle);
                    cellInstance.setPieceIndex(j);
                    cellInstance.setCurrentDisplay(nothingAttacked);
                    j++;
                }
            }
    }
}


void gamePlayer::ai::attack(std::vector<std::vector<gameSpace::cell>> & board, player & enemy, int posX, int posY){
    position attackPosition;
    bool attacked = false;
    while (!attacked){
        generatePosition(attackPosition);
        std::vector<gameSpace::cell> & row = board.at(attackPosition.getPositionY());
        gameSpace::cell & cellInstance = row.at(attackPosition.getPositionX());
        if (cellInstance.getAttacked())
            continue;
        cellInstance.setAttacked(true);
        if (cellInstance.getCurrentDisplay() == water){
            cellInstance.setCurrentDisplay(attackedWater);
        }
        else{
            cellInstance.setCurrentDisplay(atackedShip);
            piece * attackedPiece = cellInstance.getPiece();
            int idPiece = cellInstance.getPieceIndex();
            attackedPiece->lostMyLife();
            if (attackedPiece->getALife() == 0){
                enemy.addDeadPiece(attackedPiece);
                enemy.removePiece(attackedPiece);
            }
        }
        attacked = true;
    }
}

void gamePlayer::user::attack(std::vector<std::vector<gameSpace::cell>> & board, player & enemy, int posX, int posY){
        std::vector<gameSpace::cell> & row = board.at(posY);
        gameSpace::cell & cellInstance = row.at(posX);
        cellInstance.setAttacked(true);
        if (cellInstance.getCurrentDisplay() == water){
            cellInstance.setCurrentDisplay(attackedWater);
        }
        else{
            cellInstance.setCurrentDisplay(atackedShip);
            piece * attackedPiece = cellInstance.getPiece();
            int idPiece = cellInstance.getPieceIndex();
            attackedPiece->lostMyLife();
            if (attackedPiece->getALife() == 0){
                enemy.addDeadPiece(attackedPiece);
                enemy.removePiece(attackedPiece);
            }
        }
}
