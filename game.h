#include "player.h"
#include "language.h"
#ifndef GAME_H
#define GAME_H

class gamePrinter{
    public:
        language currentLanguage;
        language getLanguage() {return currentLanguage;}
        void     setLanguage(language newLanguage) {currentLanguage = newLanguage;}
        void     showGame(gamePlayer::user &player1, gamePlayer::ai &player2);
        void     showGameOver();
        void     showGameRules();
        void     showChooseYourLanguage();
        void     showLevelModifier();

        // set language
        // new langage
        // get language
        // language as pointer, not an object inside the class

    private:
        void    showBoardLine(gameSpace::playSpace & spaceToPrint, bool showPieces, int currentLine);
        void    showCoordinatePositions();
        void    showHeader();
        void    showLetterCoordinates(int currentPosition);
        void    showBetweenBoards(int currentLine, int userPieces, int pcPieces);
        void    showFooter();
        void    showEndBoard();
        void    showPiecesInformation(int pieces);
};


class game{
    public:
        game(){};
       ~game() = default;
        bool    getIsGameOver() {return gameOver;};
        bool    isGameOver(bool placeHolder);
        void    begin(int quantityModifier);
        void    playerTurn();
        void    setGamePrinter(gamePrinter newPrinter);
        gamePlayer::ai   & getPcPlayer(){return pcPlayer;}
        gamePlayer::user & getUserPlayer(){return userPlayer;}
        gamePlayer::ai     pcPlayer;
        gamePlayer::user   userPlayer;
        gamePrinter printer;

    private:
        bool     gameOver = false;
        bool     isModifierValid(int quantityModifier);
        void     generatePieces(player & playerToGeneratePieces, int quantityModifier);
        void     pcPlayerTurn ();
        void     userPlayerTurn();
        void     generateBigPieces    (int numberPieces, player & currentPlayer);
        void     generateMediumPieces (int numberPieces, player & currentPlayer);
        void     generateSmallPieces  (int numberPieces, player & currentPlayer);
        bool     isGameOver();
        void     setNextToPlay();
        void     setIsGameOver(bool value);
        player & getNotPlaying();
        player & getPlaying();

};

/*
    This struct will pass along in the input class,
    not only it will hold the values that are of interest,
    it will be used as object to be passed and validated along the way.
*/
struct coordinates{
  int posX;
  int posY;
  int flag;
};

class input{
    public:
        // the only way to set the input is by getting the user input!
        int   getPosX();
        int   getPosY();
        int   getFlag();
        void  getUserInput();  // regex: to get the coordinates ingame
        int   getBeginInput(); // regex: to get the parameters to begin game
        void  setGamePrinter(gamePrinter * currentPrinter);

    private:
        coordinates userCoordinates;
        gamePrinter * printer;

        void setPosX(int newPosX);
        void setPosY(int newPosY);
        void setFlag(int newFlag);
        void resetInput();

        int  getNumberRange(std::string toParse);
        int  getLanguageModifier(std::string toParse);
        bool isNumberRange(std::string input, std::smatch *result);
        bool isDebug(std::string input, std::smatch *result);
        bool isLanguageModifier(std::string input, std::smatch *result);
        bool isExitFlag(std::string input, std::smatch *result);

        bool validateInputPosX(int newPosX);
        bool validateInputPosY(int newPosY);
        bool validateInputFlag(int newFlag);
        bool setUserInput(coordinates currentInput);
        int  convertCharToCoordinate(char charToConvert);
        coordinates inputRegexSearch();
};

#endif /* GAME_H */
