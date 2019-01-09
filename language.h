#include <string>
#include <functional>


/*
    The strings should follow hungarian notation as well AND add the language:
    csEN - for english
    csFR - for french
    csPT - for portuguese

    and so on.
*/

const std::string csEN_insertCoordinate     = "Please insert a valid coordinate: ";
const std::string csEN_wrongPosition        = "H O N E Y, you ALREADY attacked that! Choose some other place, p-lease";
const std::string csEN_gameEndSpacing       = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
const std::string csEN_gameEnded            = "THE\nGAME\nIS\nOVER\nHONEY\n.";
const std::string csEN_gameEndedMoralLesson = "\n do your homework and learn girl, no one won. No one. Ever. Wins.";
const std::string csEN_gameRulesHeader      = "Hello B, this is our game, and these are our rules:\n";
const std::string csEN_gameRule1            = "1 - you can only wear pink. Kidding, but on wednesday you HAVE to wear pink.\n";
const std::string csEN_gameRule2            = "2 - our super smart AI will play against you.\n";
const std::string csEN_gameRule3            = "3 - this is how you'll do: \n o is attacked water \n X piece that suffered a hit\n ~ is water\n M is a ship. \n Good Luck, you'll need it.\n";
const std::string csEN_BetweenPlayer        = "YOUR  ";
const std::string csEN_BetweenPieces        = "PIECES";
const std::string csEN_BetweenEnemy         = "ENEMY ";
const std::string csEN_LevelModifier        = "more enemies 0 ... 3 less enemies\n";


const std::string csFR_insertCoordinate     = "S'il vous plaît, introduis une coordonnées valide: ";
const std::string csFR_wrongPosition        = "M O N  C H É R I, vous avez déjà attaqué ça! Choisissez un autre endroit s'il vous plaît";
const std::string csFR_gameEndSpacing       = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
const std::string csFR_gameEnded            = "LE\nJEU\nEST\nTERMINÉ\nMON\nAMOUR\n";
const std::string csFR_gameEndedMoralLesson = "Fais tes devoirs et apprendre mon chéri, personne n'a gagné, personne ne gagne";
const std::string csFR_gameRulesHeader      = "Salut! c'est notre jeu, et ces sont notre règles:\n";
const std::string csFR_gameRule1            = "1 - Vous ne pouvez porter que du rose. J'ai blagué, mais le mercredi, vous devez porter du rose.\n";
const std::string csFR_gameRule2            = "2 - notre IA trés brillant jouera contre vous.\n";
const std::string csFR_gameRule3            = "3 - C'est comme ça que tu vas faire: \n ~ - c'est de l'eau \n o - c'est aussi de l'eau, mais attaqué \n X - est une pièce qui a été attaqué \n M - est un navire.\n bonne chance, vous en aura besoin.\n";
const std::string csFR_BetweenPlayer        = "TES   ";
const std::string csFR_BetweenPieces        = "PIÈCES";
const std::string csFR_BetweenEnemy         = "ENNEMI";
const std::string csFR_LevelModifier        = "plus d'ennemis 0 ... 3 moins d'ennemis\n";


const std::string csPT_insertCoordinate     = "Por favor, insira uma coordenada válida: ";
const std::string csPT_wrongPosition        = "Q U E R I D I N H A, você ja atacou isso! Escolha outra, ok?";
const std::string csPT_gameEndSpacing       = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
const std::string csPT_gameEnded            = "O\nJOGO\nESTÁ\nTERMINADO\nQUERIDA\n";
const std::string csPT_gameEndedMoralLesson = "Faça o seu dever e aprenda, amiga, ninguém ganhou. Ninguém. Nunca. Ganha.";
const std::string csPT_gameRulesHeader      = "Olá! Esse é o nosso jogo, e essas são nossas regras:\n";
const std::string csPT_gameRule1            = "1 - Você só pode vestir rosa. Brinks, mas nas quartas você TEM que usar rosa.\n";
const std::string csPT_gameRule2            = "2 - Nossa IA super inteligente vai jogar contra você.\n";
const std::string csPT_gameRule3            = "3 - É assim que você vai jogar: \n ~ - isso é agua \n o - isso também é agua, mas atacada \n X - uma peça que foi atacada \n M - é um navio.\n boa sorte, não tenho o que dizer.\n";
const std::string csPT_BetweenPlayer        = "SUAS  ";
const std::string csPT_BetweenPieces        = "PEÇAS ";
const std::string csPT_BetweenEnemy         = "OUTRAS";
const std::string csPT_LevelModifier        = "mais inimigos 0 ... 3 menos inimigos\n";


/*
    The idea here is simple:the language class should initialize all its variables
    and after that you can use a getTextYouWant() that will return the correct string.
    Everytime a new text is added you should:
        a - create the corresponding variable (private)
        b - create the corresponding setter   (private)
        c - create the corresponding getter   (public)
        d - initialize the corresponding variable in initializeLanguage and/or delegations.
*/

class language{
    public:
        language();
        void  initializeLanguage ();
        void  updateLanguage(int flag);
        void  updateToFrench();
        void  updateToPortuguese();

        std::string getInsertCoordinate     ();
        std::string getWrongPosition        ();
        std::string getGameEndedSpacing     ();
        std::string getGameEndedMoralLesson ();
        std::string getGameEnded            ();
        std::string getGameRulesHeader      ();
        std::string getGameRule1            ();
        std::string getGameRule2            ();
        std::string getGameRule3            ();
        std::string getBetweenPlayer        ();
        std::string getBetweenPieces        ();
        std::string getBetweenEnemy         ();
        std::string getLevelModifier        ();

    private:
        void updateWindowsConsoleOutput();

        std::string   _insertCoordinate;
        void        setInsertCoordinate (std::string newText);

        std::string   _wrongPosition;
        void        setWrongPosition (std::string newText);

        std::string   _gameEndedSpacing;
        void        setGameEndedSpacing (std::string newText);

        std::string   _gameEndedMoralLesson;
        void        setGameEndedMoralLesson (std::string newText);

        std::string   _gameEnded;
        void        setGameEnded (std::string newText);

        std::string   _gameRulesHeader;
        void        setGameRulesHeader (std::string newText);

        std::string   _gameRule1;
        void        setGameRule1 (std::string newText);

        std::string   _gameRule2;
        void        setGameRule2 (std::string newText);

        std::string   _gameRule3;
        void        setGameRule3 (std::string newText);

        std::string   _betweenPlayer;
        void        setBetweenPlayer (std::string newText);

        std::string   _betweenPieces;
        void        setBetweenPieces (std::string newText);

        std::string   _betweenEnemy;
        void        setBetweenEnemy (std::string newText);

        std::string   _LevelModifier;
        void        setLevelModifier (std::string newText);
};
