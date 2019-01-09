#include <limits>
#include <pthread.h>
#include <iostream>


#include "language.h"

language::language(){
    initializeLanguage();
}

void language::initializeLanguage(){
    updateWindowsConsoleOutput();

    setInsertCoordinate     (csEN_insertCoordinate);
    setWrongPosition        (csEN_wrongPosition);
    setGameEndedSpacing     (csEN_gameEndSpacing);
    setGameEnded            (csEN_gameEnded);
    setGameEndedMoralLesson (csEN_gameEndedMoralLesson);
    setGameRulesHeader      (csEN_gameRulesHeader);
    setGameRule1            (csEN_gameRule1);
    setGameRule2            (csEN_gameRule2);
    setGameRule3            (csEN_gameRule3);
    setBetweenPlayer        (csEN_BetweenPlayer);
    setBetweenPieces        (csEN_BetweenPieces);
    setBetweenEnemy         (csEN_BetweenEnemy);
    setLevelModifier        (csEN_LevelModifier);
}

void language::updateWindowsConsoleOutput(){
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif
}

std::string language::getInsertCoordinate     (){
    return _insertCoordinate;
}

std::string language::getWrongPosition        (){
    return _wrongPosition;
}

std::string language::getGameEndedSpacing     (){
    return _gameEndedSpacing;
}

std::string language::getGameEnded            (){
    return _gameEnded;
}

std::string language::getGameEndedMoralLesson (){
    return _gameEndedMoralLesson;
}

std::string language::getGameRulesHeader      (){
    return _gameRulesHeader;
}

std::string language::getGameRule1            (){
    return _gameRule1;
}

std::string language::getGameRule2            (){
    return _gameRule2;
}

std::string language::getGameRule3            (){
    return _gameRule3;
}

std::string language::getBetweenPlayer (){
    return _betweenPlayer;
}
std::string language::getBetweenPieces (){
    return _betweenPieces;
}
std::string language::getBetweenEnemy (){
    return _betweenEnemy;
}

std::string language::getLevelModifier(){
    return _LevelModifier;
}

void language::setInsertCoordinate (std::string newText){
    _insertCoordinate = newText;
}

void language::setWrongPosition (std::string newText){
    _wrongPosition = newText;
}

void language::setGameEndedSpacing (std::string newText){
    _gameEndedSpacing = newText;
}

void language::setGameEnded (std::string newText){
    _gameEnded = newText;
}

void language::setGameEndedMoralLesson (std::string newText){
    _gameEndedMoralLesson = newText;
}

void language::setGameRulesHeader (std::string newText){
    _gameRulesHeader = newText;
}

void language::setGameRule1 (std::string newText){
    _gameRule1 = newText;
}

void language::setGameRule2 (std::string newText){
    _gameRule2 = newText;
}

void language::setGameRule3 (std::string newText){
    _gameRule3 = newText;
}

void language::setBetweenPlayer (std::string newText){
    _betweenPlayer = newText;
}

void language::setBetweenPieces (std::string newText){
    _betweenPieces = newText;
}

void language::setBetweenEnemy (std::string newText){
    _betweenEnemy = newText;
}

void language::setLevelModifier(std::string newText){
    _LevelModifier = newText;
}

void language::updateLanguage (int flag){
    switch (flag){
        case 100:
            updateToPortuguese();
            break;
        case 101:
            updateToFrench();
            break;
        default:
            break;
    }
}

void language::updateToPortuguese(){
    setInsertCoordinate     (csPT_insertCoordinate);
    setWrongPosition        (csPT_wrongPosition);
    setGameEndedSpacing     (csPT_gameEndSpacing);
    setGameEnded            (csPT_gameEnded);
    setGameEndedMoralLesson (csPT_gameEndedMoralLesson);
    setGameRulesHeader      (csPT_gameRulesHeader);
    setGameRule1            (csPT_gameRule1);
    setGameRule2            (csPT_gameRule2);
    setGameRule3            (csPT_gameRule3);
    setBetweenPlayer        (csPT_BetweenPlayer);
    setBetweenPieces        (csPT_BetweenPieces);
    setBetweenEnemy         (csPT_BetweenEnemy);
    setLevelModifier        (csPT_LevelModifier);
}

void language::updateToFrench(){
    setInsertCoordinate     (csFR_insertCoordinate);
    setWrongPosition        (csFR_wrongPosition);
    setGameEndedSpacing     (csFR_gameEndSpacing);
    setGameEnded            (csFR_gameEnded);
    setGameEndedMoralLesson (csFR_gameEndedMoralLesson);
    setGameRulesHeader      (csFR_gameRulesHeader);
    setGameRule1            (csFR_gameRule1);
    setGameRule2            (csFR_gameRule2);
    setGameRule3            (csFR_gameRule3);
    setBetweenPlayer        (csFR_BetweenPlayer);
    setBetweenPieces        (csFR_BetweenPieces);
    setBetweenEnemy         (csFR_BetweenEnemy);
    setLevelModifier        (csFR_LevelModifier);
}
