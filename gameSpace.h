#include "pieceSpecializations.h"

namespace gameSpace{

    class cell{
    private:
        displayType currentDisplay;
        piece*      pieceInstance;
        int         pieceIndex;
        bool        wasAttacked;
    public:
        displayType getCurrentDisplay();
        void        setCurrentDisplay(displayType newDisplay);
        piece*      getPiece();
        void        setPiece(piece* newPiece);
        int         getPieceIndex();
        void        setPieceIndex(int id);
        bool        getAttacked();
        void        setAttacked(bool attacked);
        cell();
        ~cell();
    };

    class playSpace{
    private: 
        std::vector<std::vector<cell>> userBoard;
        void setUserBoard();
    public:
        std::vector<std::vector<cell>> & getUserBoard();
        cell &  getBoardPosition (int posX, int posY);
        void    setBoardPosition (int posX, int posY, displayType display);
        bool    checkFreePosition(int x, int y);
        playSpace();
        ~playSpace() = default;
    };
    

}
