#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    //Print messages to the terminal
    std::cout << "\nYou are a secret agent breaking into a secure server room: " << Difficulty;
    std::cout << std::endl; //this is used to make new line
    std::cout << "Enter the correct code to continue...";
    std::cout << std::endl;
}

bool PlayGame(int Difficulty)
{

    PrintIntroduction(Difficulty);
    //Declare 3 number code
    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;

    // sum and paoduct the 3 number code
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    //print the sum and product in terminal
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code" << std::endl;
    std::cout << "+ The codes add-up to: ";
    std::cout << CodeSum << std::endl;
    std::cout << "+ The codes multiply to give: ";
    std::cout << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;

    //Taking user input
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (CodeSum == GuessSum && CodeProduct == GuessProduct)
    {
        std::cout << "\n*** Well done agent! You have extracted a file! Keep going ***\n";
        return true;
    }
    else
    {
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again\n";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 10;

    while (LevelDifficulty <= MaxDifficulty)
    {
        bool LevelCompleated = PlayGame(LevelDifficulty);
        // PlayGame(LevelDifficulty);
        std::cin.clear();  //clears any error
        std::cin.ignore(); //Discards the buffer

        if (LevelCompleated)
        {
            ++LevelDifficulty;
        }
    }
    std::cout << "\n*** Great work agent! You got all the files! Now get out of there ***";
    return 0;
}