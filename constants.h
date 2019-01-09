#include <string>

/*
    Since the constants are being used around the program, 
    we need an assurance of what they are and where they come from.

    So when adding a new constant please follow the Hungarian Notation,
    addind a prefix of what they are:
    c - constant (all constants should have it then)
    i - integer
    f - float
    s - string

    and so on.
*/

// char Parameters
const int ciASCIIPaddingLower   = 65;  // A
const int ciASCIILimitLower     = 79;  // O
const int ciASCIIPaddingUpper   = 97;  // a
const int ciASCIILimitUpper     = 111; // o

// printing game
// @TODO fix the between bord with internationalization
const std::string csWater             = "~";
const std::string csSpaceAttacked     = "X";
const std::string csSpaceHitten       = "o";
const std::string csPiece             = "M";
const std::string csSpacePadding      = "  ";
const std::string csHidden            = "?";
const std::string csEndLineBoard      = "|\n";
const std::string csGameHeader        = "@-------------------YOUR  BOARD-------------------@           @------------------ENEMY BOARD--------------------@\n";
const std::string csGameFooter        = "@-------------------------------------------------@           @-------------------------------------------------@\n";
const std::string csFirstLineBoard    = "|    ";
const std::string csBetweenLineBoard  = "|           |    ";
const std::string csLineBoard         = "| ";
const std::string csSpacing           = "  ";
const std::string csBetweenPlayer     = "|  ";
const std::string csBetweenPieces     = "|  ";
const std::string csEndLineForMessage = "|  ";
const std::string csBetweenEnemy      = "|  ";
const std::string csBetweenSpaceBig   = "     ";
const std::string csBetweenSpaceSmall = "    ";
const std::string csEndLineDefault    = "|        ";
const std::string csnewLine                 = "\n";

// printing messages
const std::string csInitialMessageFlags = "pour le francais: fr\npara portugues: pt\nanything else can be typed for english.\n";

// flags
const int ciFlagError    = -1;
const int ciFlagQuit     =  1;
const int ciFlagNone     =  0;
const int ciStandardPosX = -1;
const int ciStandardPosY = -1;

// Game Board
const int ciVerticalBeginning   = 0;
const int ciVerticalEnd         = 15;
const int ciHorizontalBeginning = 0;
const int ciHorizontalEnd       = 15;
const int ciMinimumLife         = 1;

// Game Pieces
    // piece sizes
const int ciSizeOfBig           = 3;
const int ciSizeOfMedium        = 2;

    // pieces quantities
const int ciBigPieces           = 3;
const int ciMediumPieces        = 4;
const int ciSmallPieces         = 5;
const int ciModifierMin         = 0;
const int ciModifierMax         = 3;

enum rotation   {standard_0, rotated_90, rotated_180, rotated_270};

enum displayType{water, atackedShip, attackedWater, nothingAttacked};

enum flags      {flag_nothing = 0, flag_quit=-1, flag_debug=-2, flag_language_pt=100, flag_language_fr=101};


