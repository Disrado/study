#include "Settings.hpp"

Settings::Settings()
{
    boardSize = 8;
    opponentType = OpponentType::player;
    level = DifficultyLevel::Easy;
}

int Settings::getBoardSize()
{
    return boardSize;
}

Settings& Settings::getInstance()
{
    static Settings instance;
    return instance;
}

void Settings::setBoardSize(int _boardSize)
{
    boardSize = _boardSize;
}

void Settings::setOpponentType(OpponentType _type)
{
    opponentType = _type;
}

OpponentType Settings::getOpponentType()
{
    return opponentType;
}

void Settings::setDifficultyLevel(DifficultyLevel _level)
{
    level = _level;
}

DifficultyLevel Settings::getDifficultyLevel()
{
    return level;
}
