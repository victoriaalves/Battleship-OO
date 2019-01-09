#include <limits>
#include <sstream>
#include <chrono>
#include <pthread.h>
#include <time.h>
#include "game.h"

void game::begin(int quantityModifier){
    generatePieces(pcPlayer, quantityModifier);
    generatePieces(userPlayer, quantityModifier);
    pcPlayer.setPlaying(false);
    userPlayer.setPlaying(true);

}

bool game::isModifierValid(int quantityModifier){
    if (quantityModifier >= ciModifierMin && quantityModifier <= ciModifierMax){
        return true;
    } else {
        return false;
    }
}

void game::generatePieces(player & playerToGeneratePieces, int quantityModifier){
    int bigPieces,
        mediumPieces,
        smallPieces;

    if (isModifierValid(quantityModifier)){
        bigPieces    = ciBigPieces    - quantityModifier;
        mediumPieces = ciMediumPieces - quantityModifier;
        smallPieces  = ciSmallPieces  - quantityModifier;
    } else{
        bigPieces    = ciBigPieces;
        mediumPieces = ciMediumPieces;
        smallPieces  = ciSmallPieces;
    }

    generateBigPieces   (bigPieces   , playerToGeneratePieces);
    generateMediumPieces(mediumPieces, playerToGeneratePieces);
    generateSmallPieces (smallPieces , playerToGeneratePieces);
}

void game::generateSmallPieces(int numberPieces, player & currentPlayer){
    std::vector<std::vector<gameSpace::cell>> & board = currentPlayer.getBoard();
    for (int i = 0; i < numberPieces; i++){
        specialPiece::swimmer * pedestrian = new specialPiece::swimmer();

        currentPlayer.generateSmallPieces(board, pedestrian);
        currentPlayer.addPiece(pedestrian);

        specialPiece::mine * ricinus = new specialPiece::mine();
        currentPlayer.generateSmallPieces(board, ricinus);
        currentPlayer.addPiece(ricinus);

    }

 }

void game::generateMediumPieces(int numberPieces, player & currentPlayer){
    std::vector<std::vector<gameSpace::cell>> & board = currentPlayer.getBoard();
    for (int i = 0; i < numberPieces; i++){
        specialPiece::jetSki * motorcycle = new specialPiece::jetSki();
        currentPlayer.generatePieces(board, motorcycle, ciSizeOfMedium);
        currentPlayer.addPiece(motorcycle);

        specialPiece::submarine * yellow = new specialPiece::submarine();
        currentPlayer.generatePieces(board, yellow, ciSizeOfMedium);
        currentPlayer.addPiece(yellow);
    }
}

void game::generateBigPieces(int numberPieces, player & currentPlayer){
    std::vector<std::vector<gameSpace::cell>> & board = currentPlayer.getBoard();
    for (int i = 0; i < numberPieces; i++){
        specialPiece::launchBoat * car = new specialPiece::launchBoat();
        currentPlayer.generatePieces(board, car, ciSizeOfBig);
        currentPlayer.addPiece(car);

        specialPiece::ship * titanic = new specialPiece::ship();
        currentPlayer.generatePieces(board, titanic, ciSizeOfBig);
        currentPlayer.addPiece(titanic);
    }
}


void game::pcPlayerTurn (){
    pcPlayer.attack(userPlayer.getBoard(), userPlayer);
    isGameOver();
    setNextToPlay();
}

void game::setIsGameOver(bool value){
    gameOver = value;
}

void game::userPlayerTurn (){
    int x;
    int y;
    int flag;
    bool validMove = false;

    gameSpace::playSpace & pcPSpace = pcPlayer.getPSpace();

    input currentInput;
    currentInput.setGamePrinter(&printer);

    while (!validMove){
        currentInput.getUserInput();
        x    = currentInput.getPosX();
        y    = currentInput.getPosY();
        flag = currentInput.getFlag();
        if (flag == 0){
            gameSpace::cell & instCell = pcPSpace.getBoardPosition(y, x);

            if (instCell.getAttacked()){
                std::cout << printer.currentLanguage.getWrongPosition() << csnewLine;
            } else {
                userPlayer.attack(pcPlayer.getBoard(), pcPlayer, y, x);
                validMove = true;
            }
        } else {
            setIsGameOver(true);
            validMove=true;
        }
    }
    setNextToPlay();
    isGameOver();
}

player & game::getPlaying(){
    if (pcPlayer.getPlaying()){
        return pcPlayer;
    }
    else {
        return userPlayer;
    }
}

player & game::getNotPlaying(){
    if (pcPlayer.getPlaying()){
        return userPlayer;
    }
    else {
        return pcPlayer;
    }
}

void game::setNextToPlay(){
    if (pcPlayer.getPlaying()){
        pcPlayer.setPlaying(false);
        userPlayer.setPlaying(true);
    }
    else {
        pcPlayer.setPlaying(true);
        userPlayer.setPlaying(false);
    }
}

bool game::isGameOver(){
    if (gameOver == true){
        return true;
    }
    if (pcPlayer.getPieces().getSize() == 0 || userPlayer.getPieces().getSize() == 0){
        gameOver = true;
        return true;
    }
}

bool game::isGameOver(bool placeHolder){
    return isGameOver();
}

void game::playerTurn(){
    if (pcPlayer.getPlaying()){
        pcPlayerTurn();
    }
    else {
        userPlayerTurn();
    }
}

void gamePrinter::showLevelModifier(){
    std::cout << currentLanguage.getLevelModifier();
}

void gamePrinter::showGameOver(){
    std::cout << currentLanguage.getGameEndedSpacing();
    std::cout << currentLanguage.getGameEnded();
    std::cout << currentLanguage.getGameEndedMoralLesson();
}

void gamePrinter::showGameRules(){
    std::cout << currentLanguage.getGameRulesHeader();
    std::cout << currentLanguage.getGameRule1();
    std::cout << currentLanguage.getGameRule2();
    std::cout << currentLanguage.getGameRule3();
}

void gamePrinter::showChooseYourLanguage(){
    std::cout << csInitialMessageFlags;
}

void gamePrinter::showCoordinatePositions(){

    for (int m = ciHorizontalBeginning; m < ciHorizontalEnd; m++){
        if (m < 10){
            std::cout << m << "  ";
        } else {
            std::cout << m << " ";
        }
    }
}
void gamePrinter::showHeader(){
    std::cout << csGameHeader;
    std::cout << csFirstLineBoard;
    gamePrinter::showCoordinatePositions();
    std::cout << csBetweenLineBoard;
    gamePrinter::showCoordinatePositions();
    std::cout << csEndLineBoard;
}

void gamePrinter::showFooter(){
    std::cout << csGameFooter;
}

void gamePrinter::showEndBoard(){
    std::cout << csEndLineBoard;
}

void gamePrinter::showLetterCoordinates(int currentPosition){
    std::cout << csLineBoard;
    std::cout << char(currentPosition+ciASCIIPaddingLower);
    std::cout << csSpacing;
};

void gamePrinter::showBoardLine(gameSpace::playSpace & spaceToPrint, bool showPieces, int currentLine){

    for (int i = ciHorizontalBeginning; i < ciHorizontalEnd; i ++){
        if (i==0){
            gamePrinter::showLetterCoordinates(currentLine);
        }
        gameSpace::cell & cellInstance = spaceToPrint.getBoardPosition(i, currentLine);

        switch(cellInstance.getCurrentDisplay()){
            case 0: std::cout << csWater         << csSpacePadding;
                    break;
            case 1: std::cout << csSpaceAttacked << csSpacePadding;
                    break;
            case 2: std::cout << csSpaceHitten   << csSpacePadding;
                    break;
            case 3:
                if (showPieces){
                    std::cout << csPiece  << csSpacePadding;
                } else {
                    std::cout << csWater  << csSpacePadding;
                };
        }
    }
}

void gamePrinter::showPiecesInformation(int pieces){
    std::cout << csEndLineForMessage;
    std::cout << pieces;
    if (pieces < 10){
        std::cout << csBetweenSpaceBig;
    } else {
        std::cout << csBetweenSpaceSmall;
    }
}

void gamePrinter::showBetweenBoards(int currentLine, int userPieces, int pcPieces){
    switch(currentLine){
        case 3: std::cout << csBetweenPlayer << currentLanguage.getBetweenPlayer();
                break;
        case 4: std::cout << csBetweenPieces << currentLanguage.getBetweenPieces();
                break;
        case 5: gamePrinter::showPiecesInformation(userPieces);
                break;
        case 7: std::cout << csBetweenEnemy << currentLanguage.getBetweenEnemy();
                break;
        case 8: std::cout << csBetweenPieces << currentLanguage.getBetweenPieces();
                break;
        case 9: gamePrinter::showPiecesInformation(pcPieces);
                break;
        default: std::cout << csEndLineDefault;

    }
    std::cout << "   ";
}

void gamePrinter::showGame(gamePlayer::user &player1, gamePlayer::ai &player2){

    gameSpace::playSpace & gameSpace1 = player1.getPSpace();
    gameSpace::playSpace & gameSpace2 = player2.getPSpace();
    int player1PiecesQuantity = player1.getPieces().getSize(),
        player2PiecesQuantity = player2.getPieces().getSize();

    gamePrinter::showHeader();
    for (int  j = ciVerticalBeginning; j < ciVerticalEnd; j++){
        gamePrinter::showBoardLine(gameSpace1, true, j);
        gamePrinter::showBetweenBoards(j, player1PiecesQuantity, player2PiecesQuantity);
        gamePrinter::showBoardLine(gameSpace2, false, j);
        gamePrinter::showEndBoard();
    }
    gamePrinter::showFooter();
}

void input::setGamePrinter(gamePrinter * currentPrinter){
    printer = currentPrinter;
}

int  input::getPosX(){
    return userCoordinates.posX;
}

int  input::getPosY(){
    return userCoordinates.posY;
}

int input::getFlag(){
    return userCoordinates.flag;
}

void input::setFlag(int newFlag){
    userCoordinates.flag = newFlag;
}

void input::setPosX(int newPosX){
    userCoordinates.posX = newPosX;
}

void input::setPosY(int newPosY){
    userCoordinates.posY = newPosY;
}

int input::convertCharToCoordinate(char charToConvert){
    int convertedNumber = static_cast<int>(charToConvert);

    if (convertedNumber >= ciASCIIPaddingLower &&
        convertedNumber <= ciASCIILimitLower){

        convertedNumber = convertedNumber - ciASCIIPaddingLower;
        return convertedNumber;

    } else if (convertedNumber >= ciASCIIPaddingUpper &&
        convertedNumber <= ciASCIILimitUpper){

        convertedNumber = convertedNumber - ciASCIIPaddingUpper;
        return convertedNumber;

    } else {
        return -1;
    }
}

bool input::validateInputPosX(int newPosX){
    if (newPosX >= ciHorizontalBeginning && newPosX < ciHorizontalEnd){
        return true;
    } else {
        return false;
    }
}

bool input::validateInputPosY(int newPosY){
    if (newPosY >= ciVerticalBeginning && newPosY < ciVerticalEnd){
        return true;
    } else {
        return false;
    }
}

bool input::validateInputFlag(int newFlag){
    if (newFlag == ciFlagQuit){
        return true;
    } else {
        return false;
    }
}

void input::resetInput(){
    setPosX(ciStandardPosX);
    setPosY(ciStandardPosY);
    setFlag(ciFlagNone);
}

void input::getUserInput(){
    bool validInput = false;
    coordinates currentInput;
    resetInput();

    while (!validInput) {
        std::cout << printer->currentLanguage.getInsertCoordinate();
        currentInput = inputRegexSearch();
        validInput   = setUserInput(currentInput);
    }
}

int input::getBeginInput(){
    int inputResult = 0;
    std::string input = "";

    std::smatch result;

    getline(std::cin, input);

    if (isNumberRange(input, &result)){
        inputResult = getNumberRange(result[0].str());
    } else if (isDebug(input, &result)){
        inputResult = flag_debug;
    } else if(isLanguageModifier(input, &result)){
        inputResult = getLanguageModifier(result[0].str());
    } else if(isExitFlag(input, &result)){
        inputResult = flag_quit;
    }
    return inputResult;
}


int input::getNumberRange(std::string toParse){
    return stoi(toParse);
}

int input::getLanguageModifier(std::string toParse){
    if(toParse == "pt"){
        return flag_language_pt;
    } else if (toParse == "fr"){
        return flag_language_fr;
    } else return flag_nothing;
}

bool input::isNumberRange(std::string input, std::smatch *result){
    std::regex numberModifier("[0-3]");
    return regex_match(input, *result, numberModifier);

}

bool input::isDebug(std::string input, std::smatch *result){
    std::regex debug("debug42");
    return regex_match(input, *result, debug);
}

bool input::isLanguageModifier(std::string input, std::smatch *result){
    std::regex language("pt|fr");
    return regex_match(input, *result, language);
}

bool input::isExitFlag(std::string input, std::smatch *result){
    std::regex quit("!|q|Q");
    return regex_match(input, *result, quit);
}

coordinates input::inputRegexSearch(){
    int number;
    coordinates checkedInput;
    std::string input = "";

    std::regex numberLetter("([0-9]|[1][0-4])([A-O]|[a-o])");
    std::regex letterNumber("([A-O]|[a-o])([1][0-4]|[0-9])");
    std::regex flagInput("!|q|Q");
    std::smatch result;

    getline(std::cin, input);


    if (regex_match(input, result, letterNumber)) {
        //In the first pattern result[1] holds the letter and result[2] holds the number
        checkedInput.posX = convertCharToCoordinate(result[1].str()[0]);
        checkedInput.posY = stoi(result[2].str());
        checkedInput.flag = ciFlagNone;
    } else if (regex_match(input, result, numberLetter)) {
        //In the second pattern result[1] holds the number and result[2] holds the letter
        checkedInput.posX = convertCharToCoordinate(result[2].str()[0]);
        checkedInput.posY = stoi(result[1].str());
        checkedInput.flag = ciFlagNone;
    } else if (regex_match(input, result, flagInput)){
        checkedInput.posY = ciStandardPosY;
        checkedInput.posX = ciStandardPosX;
        checkedInput.flag = ciFlagQuit;
    } else {
        checkedInput.posY = ciStandardPosY;
        checkedInput.posX = ciStandardPosX;
        checkedInput.flag = ciFlagError;
    }

    return checkedInput;
}

bool input::setUserInput(coordinates currentInput) {
    if (validateInputPosX(currentInput.posX) && validateInputPosY(currentInput.posY)){
        setPosX(currentInput.posX);
        setPosY(currentInput.posY);
        setFlag(ciFlagNone);
        return true;
    } else if (validateInputFlag(currentInput.flag)){
        setFlag(currentInput.flag);
        return true;
    } else {
        return false;
    }
}
