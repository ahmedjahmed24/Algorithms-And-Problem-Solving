#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ==========================================
// Enums & Structs
// ==========================================

/**
 * @enum enOperationType
 * @brief Represents the types of arithmetic operations available.
 */
enum enOperationType
{
    Add = 1,
    Sub = 2,
    Mul = 3,
    Div = 4,
    MixOp = 5
};

/**
 * @enum enQuestionsLevel
 * @brief Represents difficulty levels for quiz questions.
 */
enum enQuestionsLevel
{
    EasyLevel = 1,
    MidLevel = 2,
    HardLevel = 3,
    Mix = 4
};

/**
 * @struct stQuestion
 * @brief Holds detailed attributes for an individual math question.
 */
struct stQuestion
{
    int Number1 = 0;
    int Number2 = 0;
    enOperationType OperationType;
    enQuestionsLevel QuestionLevel;
    int PlayerAnswer = 0;
    int CorrectAnswer = 0;
    bool AnswerResult = false;
};

/**
 * @struct stQuizz
 * @brief Aggregates full quiz session parameters and statistics.
 */
struct stQuizz
{
    stQuestion QuestionsList[100];
    enOperationType OpType;
    enQuestionsLevel QuestionsLevel;
    short NumberOfQuestions = 0;
    short NumberOfWrongAnswers = 0;
    short NumberOfRightAnswers = 0;
    bool IsPass = false;
};

// ==========================================
// Utility & Input Handlers
// ==========================================

/**
 * @brief Generates a pseudo-random number within a given range [From, To].
 */
int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

/**
 * @brief Prompts and validates the requested number of quiz questions.
 */
short ReadHowManyQuestions()
{
    short NumberOfQuestions;
    do
    {
        cout << "How Many Questions Do You Want To Answer ? ";
        cin >> NumberOfQuestions;
    } while (NumberOfQuestions < 1 || NumberOfQuestions > 10);

    return NumberOfQuestions;
}

/**
 * @brief Reads and validates the user's preferred question difficulty level.
 */
enQuestionsLevel ReadQuestionsLevel()
{
    short QuestionsLevel = 0;
    do
    {
        cout << "Enter Questions Level [1] Easy, [2] Mid, [3] Hard, [4] Mix ? ";
        cin >> QuestionsLevel;
    } while (QuestionsLevel < 1 || QuestionsLevel > 4);

    return enQuestionsLevel(QuestionsLevel);
}

/**
 * @brief Reads and validates the user's chosen arithmetic operation type.
 */
enOperationType ReadOpType()
{
    short OpType = 0;
    do
    {
        cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
        cin >> OpType;
    } while (OpType < 1 || OpType > 5);

    return enOperationType(OpType);
}

/**
 * @brief Returns a random arithmetic operation (Add, Sub, Mul, Div).
 */
enOperationType GetRandomOperationType()
{
    int Op = RandomNumber(1, 4);
    return (enOperationType)Op;
}

// ==========================================
// Math Logic & Generation
// ==========================================

/**
 * @brief Computes arithmetic calculation based on operation type.
 */
int SimpleCalculater(int Number1, int Number2, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return Number1 + Number2;
    case enOperationType::Sub:
        return Number1 - Number2;
    case enOperationType::Mul:
        return Number1 * Number2;
    case enOperationType::Div:
        return (Number2 != 0) ? (Number1 / Number2) : 1; // Safe division check
    default:
        return Number1 + Number2;
    }
}

/**
 * @brief Generates a randomized question structure based on level and operation.
 */
stQuestion GenarateQuestion(enQuestionsLevel QuestionLevel, enOperationType OpType)
{
    stQuestion Question;

    if (QuestionLevel == enQuestionsLevel::Mix)
    {
        QuestionLevel = (enQuestionsLevel)RandomNumber(1, 3);
    }

    if (OpType == enOperationType::MixOp)
    {
        OpType = GetRandomOperationType();
    }

    Question.OperationType = OpType;

    switch (QuestionLevel)
    {
    case enQuestionsLevel::EasyLevel:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        Question.CorrectAnswer = SimpleCalculater(Question.Number1, Question.Number2, Question.OperationType);
        Question.QuestionLevel = QuestionLevel;
        return Question;

    case enQuestionsLevel::MidLevel:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        Question.CorrectAnswer = SimpleCalculater(Question.Number1, Question.Number2, Question.OperationType);
        Question.QuestionLevel = QuestionLevel;
        return Question;

    case enQuestionsLevel::HardLevel:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
        Question.CorrectAnswer = SimpleCalculater(Question.Number1, Question.Number2, Question.OperationType);
        Question.QuestionLevel = QuestionLevel;
        return Question;
    }
    return Question;
}

/**
 * @brief Populates the quiz array with generated questions.
 */
void GenarateQuizzQuestions(stQuizz &Quizz)
{
    for (short Question = 0; Question < Quizz.NumberOfQuestions; Question++)
    {
        Quizz.QuestionsList[Question] = GenarateQuestion(Quizz.QuestionsLevel, Quizz.OpType);
    }
}

// ==========================================
// Formatting & UI Evaluation
// ==========================================

/**
 * @brief Converts operation enum to mathematical symbol string.
 */
string GetTypeSymbol(enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return "+";
    case enOperationType::Sub:
        return "-";
    case enOperationType::Mul:
        return "*";
    case enOperationType::Div:
        return "/";
    default:
        return "Mix";
    }
}

/**
 * @brief Renders single question layout to the console.
 */
void PrintTheQuestion(stQuizz Quizz, short QuestionNumber)
{
    cout << "\n";
    cout << "Question [" << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "]\n\n";
    cout << Quizz.QuestionsList[QuestionNumber].Number1 << endl;
    cout << Quizz.QuestionsList[QuestionNumber].Number2 << " ";
    cout << GetTypeSymbol(Quizz.QuestionsList[QuestionNumber].OperationType);
    cout << "\n------------" << endl;
}

/**
 * @brief Reads player answer input.
 */
int ReadQuestionAnswer()
{
    int Answer = 0;
    cin >> Answer;
    return Answer;
}

/**
 * @brief Dynamically modifies console color based on response accuracy.
 */
void SetScreenColor(bool Right)
{
    if (Right)
    {
        system("color 2F"); // Green background
    }
    else
    {
        system("color 4F"); // Red background
        cout << "\a";       // Warning sound
    }
}

/**
 * @brief Evaluates accuracy of current question response and updates stats.
 */
void CorrectTheQuestionAnswer(stQuizz &Quizz, short QuestionNumber)
{
    if (Quizz.QuestionsList[QuestionNumber].PlayerAnswer != Quizz.QuestionsList[QuestionNumber].CorrectAnswer)
    {
        Quizz.QuestionsList[QuestionNumber].AnswerResult = false;
        Quizz.NumberOfWrongAnswers++;

        cout << "Wrong Answer :-( \n";
        cout << "The Right Answer is: " << Quizz.QuestionsList[QuestionNumber].CorrectAnswer << "\n";
    }
    else
    {
        Quizz.QuestionsList[QuestionNumber].AnswerResult = true;
        Quizz.NumberOfRightAnswers++;

        cout << "Right Answer :-) \n";
    }
    cout << endl;

    SetScreenColor(Quizz.QuestionsList[QuestionNumber].AnswerResult);
}

/**
 * @brief Processes complete questioning flow and calculates pass status.
 */
void AskAndCorrectQuestionsListAnswers(stQuizz &Quizz)
{
    for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++)
    {
        PrintTheQuestion(Quizz, QuestionNumber);
        Quizz.QuestionsList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
        CorrectTheQuestionAnswer(Quizz, QuestionNumber);
    }

    Quizz.IsPass = (Quizz.NumberOfRightAnswers >= Quizz.NumberOfWrongAnswers);
}

/**
 * @brief Returns descriptive status text based on pass result.
 */
string GetFinalResultText(bool Pass)
{
    return Pass ? "PASS :-)" : "Fail :-(";
}

/**
 * @brief Converts difficulty enum to readable string format.
 */
string GetQuestionLevelText(enQuestionsLevel QuestionLevel)
{
    string arrQuestionLevelText[4] = {"Easy", "Mid", "Hard", "Mix"};
    return arrQuestionLevelText[QuestionLevel - 1];
}

/**
 * @brief Renders the end-of-game summary scorecard.
 */
void PrintQuizzResult(stQuizz Quizz)
{
    cout << "\n------------------------------\n\n";
    cout << "Final Result is " << GetFinalResultText(Quizz.IsPass);
    cout << "\n------------------------------\n\n";

    cout << "Number Of Questions     : " << Quizz.NumberOfQuestions << endl;
    cout << "Questions Level         : " << GetQuestionLevelText(Quizz.QuestionsLevel) << endl;
    cout << "OpType                  : " << GetTypeSymbol(Quizz.OpType) << endl;
    cout << "Number Of Right Answers : " << Quizz.NumberOfRightAnswers << endl;
    cout << "Number Of Wrong Answers : " << Quizz.NumberOfWrongAnswers << endl;
    cout << "---------------------------------------------------------------\n";
}

// ==========================================
// Controller Logic
// ==========================================

/**
 * @brief Initiates and handles a single quiz round session.
 */
void PlayMathGame()
{
    stQuizz Quizz;

    Quizz.NumberOfQuestions = ReadHowManyQuestions();
    Quizz.QuestionsLevel = ReadQuestionsLevel();
    Quizz.OpType = ReadOpType();

    GenarateQuizzQuestions(Quizz);
    AskAndCorrectQuestionsListAnswers(Quizz);
    PrintQuizzResult(Quizz);
}

/**
 * @brief Clears current output and restores default terminal background color.
 */
void ResetScreen()
{
    system("cls");
    system("color 0F");
}

/**
 * @brief Main outer loop controlling session retries.
 */
void StartGame()
{
    char PlayAgain = 'Y';

    do
    {
        ResetScreen();
        PlayMathGame();

        cout << endl << "Do you want to play again ? Y/N ? ";
        cin >> PlayAgain;

    } while (PlayAgain == 'y' || PlayAgain == 'Y');
}

/**
 * @brief Entry point of program execution.
 */
int main()
{
    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}