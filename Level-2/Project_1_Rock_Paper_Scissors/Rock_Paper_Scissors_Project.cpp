#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ==========================================
// Enums & Data Structures
// ==========================================

/**
 * @enum enGameChoice
 * @brief Represents the available choices in the game.
 */
enum enGameChoice
{
    Stone = 1,
    Paper = 2,
    Scissors = 3
};

/**
 * @enum enWinner
 * @brief Represents the possible round or overall game winners.
 */
enum enWinner
{
    Player1 = 1,
    Computer = 2,
    Draw = 3
};

/**
 * @struct stRoundInfo
 * @brief Holds detailed information for a single round execution.
 */
struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

/**
 * @struct stGameResult
 * @brief Aggregates the final game results and overall stats across all rounds.
 */
struct stGameResult
{
    short GameRounds = 0;
    short Player1WonTimes = 0;
    short ComputerWonTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};

// ==========================================
// Utility & Helper Functions
// ==========================================

/**
 * @brief Generates a pseudo-random integer within a specified range [From, To].
 * @param From Lower bound of the range.
 * @param To Upper bound of the range.
 * @return Random integer value.
 */
int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

/**
 * @brief Generates a string consisting of tab characters for console alignment.
 * @param NumberOfTabs Number of tab indents to display.
 * @return Formatted tab string.
 */
string Tabs(short NumberOfTabs)
{
    string t = "";
    for (int i = 1; i < NumberOfTabs; i++)
    {
        t = t + "\t";
        cout << t;
    }
    return t;
}

/**
 * @brief Resets the console screen and sets default background/foreground colors.
 */
void ResetScreen()
{
    system("cls");
    system("color 0F"); // Black background, Bright White text
}

// ==========================================
// Input & Choice Handlers
// ==========================================

/**
 * @brief Prompts and validates the total number of rounds to play.
 * @return Number of valid rounds (1 to 10).
 */
short ReadHowManyRounds()
{
    short GameRounds = 0;
    do
    {
        cout << "How Many Rounds ?\n";
        cin >> GameRounds;
    } while (GameRounds < 1 || GameRounds > 10);

    return GameRounds;
}

/**
 * @brief Reads and validates Player 1's move choice.
 * @return Selected enum value of enGameChoice.
 */
enGameChoice ReadPlayer1Choice()
{
    short Player1Choice = 1;
    do
    {
        cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
        cin >> Player1Choice;
    } while (Player1Choice < 1 || Player1Choice > 3);

    return enGameChoice(Player1Choice);
}

/**
 * @brief Randomly selects the computer's choice.
 * @return Randomly selected enum value of enGameChoice.
 */
enGameChoice GetComputerChoice()
{
    return enGameChoice(RandomNumber(1, 3));
}

// ==========================================
// Game Logic & Evaluation
// ==========================================

/**
 * @brief Converts enGameChoice enum to its corresponding string representation.
 * @param Choice Enum choice to convert.
 * @return Name of the choice.
 */
string GetChoiceName(enGameChoice Choice)
{
    string arrChoiceName[3] = {"Stone", "Paper", "Scissors"};
    return arrChoiceName[Choice - 1];
}

/**
 * @brief Converts enWinner enum to its corresponding string representation.
 * @param Winner Enum winner to convert.
 * @return Name of the winner.
 */
string GetWinnerName(enWinner Winner)
{
    string arrWinnerName[3] = {"Player1", "Computer", "No Winner"};
    return arrWinnerName[Winner - 1];
}

/**
 * @brief Evaluates rules to determine the winner of a single round.
 * @param RoundInfo Structure containing player and computer choices.
 * @return The round winner as enWinner.
 */
enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
    {
        return enWinner::Draw;
    }

    switch (RoundInfo.Player1Choice)
    {
    case enGameChoice::Stone:
        if (RoundInfo.ComputerChoice == enGameChoice::Paper)
        {
            return enWinner::Computer;
        }
        break;

    case enGameChoice::Paper:
        if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
        {
            return enWinner::Computer;
        }
        break;

    case enGameChoice::Scissors:
        if (RoundInfo.ComputerChoice == enGameChoice::Stone)
        {
            return enWinner::Computer;
        }
        break;
    }

    return enWinner::Player1;
}

/**
 * @brief Compares total win counts to determine the overall game winner.
 * @param Player1WonTimes Player 1 win count.
 * @param ComputerWonTimes Computer win count.
 * @return Overall winner as enWinner.
 */
enWinner WhoWonTheGame(short Player1WonTimes, short ComputerWonTimes)
{
    if (Player1WonTimes == ComputerWonTimes)
    {
        return enWinner::Draw;
    }
    else if (Player1WonTimes > ComputerWonTimes)
    {
        return enWinner::Player1;
    }
    else
        return enWinner::Computer;
}

/**
 * @brief Constructs and fills the stGameResult structure with final game metrics.
 */
stGameResult FillGameResults(int GameRounds, short Player1WonTimes, short ComputerWonTimes, short DrawTimes)
{
    stGameResult GameResults;

    GameResults.GameRounds = GameRounds;
    GameResults.Player1WonTimes = Player1WonTimes;
    GameResults.ComputerWonTimes = ComputerWonTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.GameWinner = WhoWonTheGame(Player1WonTimes, ComputerWonTimes);
    GameResults.WinnerName = GetWinnerName(GameResults.GameWinner);

    return GameResults;
}

// ==========================================
// Display & UI Controllers
// ==========================================

/**
 * @brief Dynamic visual feedback: changes console colors based on round/game outcome.
 * @param Winner Current winner evaluating color rules.
 */
void SetWinnerScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player1:
        system("color 2F"); // Green background for Player1 win
        break;

    case enWinner::Computer:
        system("color 4F"); // Red background for Computer win
        cout << "\a";       // Audio alert
        break;

    default:
        system("color 6F"); // Yellow/Amber background for Draw
        break;
    }
}

/**
 * @brief Prints single round details to console.
 * @param RoundInfo Detailed information of the evaluated round.
 */
void PrintRoundResult(stRoundInfo RoundInfo)
{
    cout << "\n________________Round [" << RoundInfo.RoundNumber << "] ______________\n\n";
    cout << "Player 1 Choice: " << GetChoiceName(RoundInfo.Player1Choice) << endl;
    cout << "Computer Choice: " << GetChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner   : " << RoundInfo.WinnerName << endl;
    cout << "_________________________________________\n\n";

    SetWinnerScreenColor(RoundInfo.Winner);
}

/**
 * @brief Displays the styled "Game Over" header banner.
 */
void ShowGameOverScreen()
{
    cout << Tabs(2) << "------------------------------------------------------\n";
    cout << Tabs(2) << "                +++ G a m e  O v e r +++              \n";
    cout << Tabs(2) << "------------------------------------------------------\n";
}

/**
 * @brief Formats and prints the final score summary screen.
 * @param GameResult Structure containing overall game statistics.
 */
void ShowFinalGameResults(stGameResult GameResult)
{
    cout << Tabs(2) << "\n                ____________________[Game Results]_____________\n\n";
    cout << Tabs(2) << "Game Rounds        : " << GameResult.GameRounds << endl;
    cout << Tabs(2) << "Player 1 Won Times : " << GameResult.Player1WonTimes << endl;
    cout << Tabs(2) << "Computer Won Times : " << GameResult.ComputerWonTimes << endl;
    cout << Tabs(2) << "Draw Times         : " << GameResult.DrawTimes << endl;
    cout << Tabs(2) << "Final Winner       : " << GameResult.WinnerName << endl;
    cout << Tabs(2) << "________________________________________________\n";

    SetWinnerScreenColor(GameResult.GameWinner);
}

// ==========================================
// Main Flow Control
// ==========================================

/**
 * @brief Orchestrates the round loop for a single game session.
 * @param HowManyRounds Total rounds to play in this session.
 * @return Aggregated game result structure.
 */
stGameResult PlayGame(short HowManyRounds)
{
    stRoundInfo RoundInfo;
    short Player1WonTimes = 0, ComputerWonTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
    {
        cout << "\nRound [" << GameRound << "] begins:\n\n";

        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = GetWinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Player1)
        {
            Player1WonTimes++;
        }
        else if (RoundInfo.Winner == enWinner::Computer)
        {
            ComputerWonTimes++;
        }
        else
            DrawTimes++;

        PrintRoundResult(RoundInfo);
    }

    return FillGameResults(HowManyRounds, Player1WonTimes, ComputerWonTimes, DrawTimes);
}

/**
 * @brief Main execution loop controlling replay prompts and screen resets.
 */
void StartGame()
{
    char PlayAgain = 'Y';

    do
    {
        ResetScreen();
        stGameResult GameResult = PlayGame(ReadHowManyRounds());
        ShowGameOverScreen();
        ShowFinalGameResults(GameResult);

        cout << endl
             << Tabs(3) << "Do You Want To Play Again ? Y/N ?\n";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

/**
 * @brief Program Entry Point.
 */
int main()
{
    // Seed the random number generator using system time to ensure unique sequences per run
    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}