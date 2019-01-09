#include "game.h"
#include <time.h>
#include <functional>

struct MyClass
{
    int DoStuff(double d); // actually a DoStuff(MyClass* this, double d)
};

int main(){
    srand(time(NULL));   // change the random seed
    bool print = false;
    int  gameModifier;

    game newGame;
    input gameInput;
    // input initialization
    gameInput.setGamePrinter(&newGame.printer); // we must pass the printer to the gameInput

    // language getter
    newGame.printer.showChooseYourLanguage();
    gameModifier = gameInput.getBeginInput();
    newGame.printer.currentLanguage.updateLanguage(gameModifier);

    // level modifier
    newGame.printer.showLevelModifier();
    gameModifier = gameInput.getBeginInput();
    newGame.printer.showGameRules();


    // actual game
    newGame.begin(gameModifier);
    newGame.printer.showGame(newGame.getUserPlayer(), newGame.getPcPlayer());

    while (!newGame.getIsGameOver()){
        newGame.playerTurn();
        if (print){
            newGame.printer.showGame(newGame.getUserPlayer(), newGame.getPcPlayer());
            print = false;
        }
        else
            print = true;
    }
    newGame.printer.showGameOver();
    exit(0);
}