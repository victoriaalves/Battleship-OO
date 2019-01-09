#include "gameSpace.h"
#include "list.h"
#include <sstream>
#include <regex>
#include <iostream>
#include <string>


class player{
    private:
        List<piece*> playerPieces;
        List<piece*> deadPieces;
        gameSpace::playSpace pSpace;
        bool playing;

        void generateRotation(rotation & orientation);
        std::vector<position> getOrientationPosition(rotation orientation, position instancePos, int sizePiece);
        bool checkAllPositions(std::vector<position> newPositions, std::vector<std::vector<gameSpace::cell>> & board);

    public:
        void generatePosition(position & instancePos);
         virtual void attack(std::vector<std::vector<gameSpace::cell>> & board, player & enemy, int posX = -1, int posY = -1) = 0;
         player(){};
        ~player() = default;
         List<piece*> & getPieces();
         List<piece*> & getDeadPieces();
         void addDeadPiece(piece *dead);
         void addPiece(piece* newPiece);
         void removePiece(piece*nowDead);
         gameSpace::playSpace & getPSpace();
         std::vector<std::vector<gameSpace::cell> >& getBoard();
         void setPlaying(bool isPlaying);
         bool getPlaying();

         void generateSmallPieces(std::vector<std::vector<gameSpace::cell>> & board, piece * ricinus);
         void generatePieces(std::vector<std::vector<gameSpace::cell>> & board, piece *motorcycle, int size);
    };


namespace gamePlayer{

    class user: public player{
    public:
        void setPiecePosition(piece newPiece, position pos);
        void attack(std::vector<std::vector<gameSpace::cell>> & board, player & enemy, int posX = -1, int posY = -1) override;
    };

    class ai: public player{
    public:
        void attack(std::vector<std::vector<gameSpace::cell>> & board, player & enemy,  int posX = -1, int posY = -1) override;

    };

}
