#include "piece.h"

position::position (int x, int y){
        positionX = x;
        positionY = y;
}

position::position(){ 
    positionX = -1;
    positionY = -1;
}

bool position::setPosition(int x, int y){
    bool validRangeX = x < ciVerticalEnd   && x >= ciVerticalBeginning,
         validRangeY = y < ciHorizontalEnd && y >= ciHorizontalBeginning;
    
    if ( validRangeX && validRangeY){
        positionX = x;
        positionY = y;
        return true;
    }
    else 
        return false;
}

bool position::setPosition(position oldPosition){
    bool value = setPosition(oldPosition.positionX, oldPosition.positionY);
    return value;
}

int position::getPositionX(){
    return positionX;
}

int position::getPositionY(){
    return positionY;
}

void piece::setLife(int currentLife){
    life = currentLife;
}

void piece::lostMyLife(){
    if (life >= ciMinimumLife)
        life--;
}


void piece::setCoordinates(position newPiecePosition){
    coordinates.setPosition(newPiecePosition);
}


void piece::setCanItMove (bool isMoveable){
    canItMove = isMoveable;
}

void piece::setSize(int pieceSize){
    size = pieceSize;
}

position piece::getCoordinates(){
    return coordinates;
}

bool piece::getCanItMove(){
    return canItMove;
}
int piece::getSize(){
    return size;
}
int piece::getALife(){
    return life;
}


void piece::setRotation(rotation direction42){
    direction = direction42;
}

rotation piece::getRotation(){
    return direction;
}

piece::piece(){

}

piece::piece(int size, bool isMoveable){
    setCanItMove(isMoveable);
    setSize(size);
    setLife(size);
}

piece::piece(position newPiecePosition, rotation newOrientation, int size, bool isMoveable){
    setCoordinates(newPiecePosition);
    setCanItMove(isMoveable);
    setSize(size);
    setLife(size);
    setRotation(newOrientation);
}

staticPiece::staticPiece(){
}


dynamicPiece::dynamicPiece(){
}