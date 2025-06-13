# Chess Program in C++

This is a simple chess program written in C++ that includes:

- Chess board setup and display
- Basic chess pieces (Pawn, Rook, etc.)
- Move input handling
- Object-oriented design with smart pointers

## Features

- Console-based chess board visualization
- Piece classes and game logic foundation
- Designed to be extended with AI or additional chess rules

## Getting Started

### Prerequisites

- C++17 compatible compiler (tested with MinGW-w64 / MSYS2)
- Git (optional, for version control)

### Build Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/your-repo-name.git
   cd your-repo-name
2. Compile the code (example using g++):
    ```bash
    g++ -std=c++17 -o chess main.cpp board.cpp pieces/*.cpp
3. Run the executable:
    ```bash
    ./chess

### How to Use
- Run the program in your terminal
- The board will be displayed
- Enter moves in the format e2 e4 (from square to square)

## Future Work
- Implement full chess rules and check/checkmate detection
- Add AI opponent with basic chess bot logic
- GUI frontend integration

## Contributing
- Contributions are welcome! Feel free to submit pull requests or open issues.

## License
- MIT License

Created by Preston Wong