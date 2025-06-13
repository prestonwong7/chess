#include <iostream>
#include "board.hpp"

int main()
{

    std::cout << "Welcome to Chess!" << std::endl;
    Board board;
    board.setup();

    std::string from, to;
    while (true)
    {
        board.print();
        std::cout << "Enter move (e.g., e2 e4) or 'exit' to quit: ";
        std::cin >> from >> to;

        if (!board.move(from, to))
        {
            if (from == "exit" || to == "exit")
            {
                std::cout << "Exiting the game." << std::endl;
                break; // Exit the loop if 'exit' is entered
            }
            std::cout << "Invalid move. Try again." << std::endl;
        }
        else
        {
            std::cout << "Move successful." << std::endl;
        }

    }
    
    return 0;
}