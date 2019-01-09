#include "piece.h"

namespace specialPiece{

    class swimmer : public dynamicPiece{

    public:   
        ~swimmer() = default;
        swimmer() : dynamicPiece(1){};
        swimmer(position newCoordinates, rotation newOrientation) : dynamicPiece(newCoordinates, newOrientation,1){};
    };

    class jetSki : public dynamicPiece{

    public:  
        ~jetSki() = default;
        jetSki() : dynamicPiece(2){};
        jetSki(position newCoordinates, rotation newOrientation) : dynamicPiece(newCoordinates,newOrientation ,2){};
    };

    class launchBoat : public dynamicPiece{

    public:    
        ~launchBoat() = default;
        launchBoat() : dynamicPiece(3){};
        launchBoat(position newCoordinates, rotation newOrientation) : dynamicPiece(newCoordinates,newOrientation ,3){};
    };

    class submarine: public staticPiece{

    public:
        ~submarine() = default;
        submarine() : staticPiece(2){};
        submarine(position newCoordinates, rotation newOrientation) : staticPiece(newCoordinates, newOrientation,2){};
    };

    class ship: public staticPiece{
    public:    
        ~ship() = default;
        ship() : staticPiece(3){};
        ship(position newCoordinates, rotation newOrientation) : staticPiece(newCoordinates,newOrientation ,3){};
    };

    class mine: public staticPiece{
    public:   
        ~mine() = default;
        mine() : staticPiece(1){};
        mine(position newCoordinates, rotation newOrientation) : staticPiece(newCoordinates,newOrientation ,1){};
    };

}