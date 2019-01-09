#include <vector>
#include <iostream>
#include "constants.h"
#include "delegates.h"


class position{
    public:
        position(int x, int y);
        position();
        int getPositionX();
        int getPositionY();
        bool setPosition(int x, int y);
        bool setPosition(position anotherPosition);
        ~position() = default;

    private:
        int positionX;
        int positionY;
};

class piece {
    private:
        position coordinates;
        int size;
        int life;
        bool canItMove;
        rotation direction;
        void setLife(int pieceLife);

    protected:
        void setCanItMove (bool isMoveable);
        void setSize(int pieceSize);

    public:
        piece(position newPiecePosition, rotation newOrientation, int size, bool isMoveable);
        piece();
        piece(int size, bool isMoveable);
        ~piece() = default;
        position          getCoordinates();
        bool              getCanItMove();
        int               getSize();
        int               getALife();
        void              setCoordinates(position newPiecePosition);
        void              setRotation(rotation direction42);
        rotation          getRotation();
        void              lostMyLife();
        
        bool operator==(piece& p){
            if (coordinates.getPositionX()==p.getCoordinates().getPositionX() && coordinates.getPositionY() == p.getCoordinates().getPositionY())
            return true;
            return false;
        }
};

class dynamicPiece : public piece{
   
    public:
        dynamicPiece();
        dynamicPiece(int size) : piece(size, true){};
        ~dynamicPiece() = default;
        
   
        dynamicPiece(position coordinates, rotation newOrientation, int size):
            piece(coordinates, newOrientation ,size, true){};

    protected:
        bool movePiece(position coordinates);
};

class staticPiece : public piece{

    public:
        staticPiece();
        ~staticPiece() = default;
        staticPiece(int size) : piece(size, true){};
        staticPiece(position coordinates, rotation newOrientation, int size):
            piece(coordinates, newOrientation ,size, false){
                // Não precisa ter nada aqui, PORÉM é interessante saber:
                // primeiro chama o construtor de piece com os parametros
                // e depois vem pra ca caso você queira.
            };
};