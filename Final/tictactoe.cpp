/* 
CISC 1600
Final Assignment - Tic Tac Toe game 
Date: Dec 16, 2024
Authors: Miguel Angel Vargas , Sithmi Sirisooriya
Collaboration through Replit platform
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Global variables 
const int SIZE = 3;

//Function declarations 

void initializeGame (char board[SIZE][SIZE], char& currentPlayer, bool& gameOver, int& turns);
// Pre: Takes in the board, current player, gameOver and turns as parameters. They must have been defined beforehand.
// Post: Initializes the board, current player, gameOver and turns. Important to note that this function draws the first board

void drawBoard(char board[SIZE][SIZE]);
// Pre: Takes in the board as a parameter.
// Post: Draws the board.

bool isValidMove(char board[SIZE][SIZE], int row, int col);
// Pre: Takes in the board and the row and column (entered by user) as parameters.
// Post: Returns true if the move is valid, false otherwise.

bool checkWin(char board[SIZE][SIZE], char player);
// Pre: Takes in the board and the current player as parameters.
// Post: Returns true if the current player has won, false otherwise.

void resetBoard(char board[SIZE][SIZE]);
// Pre: Takes in the board as a parameter. A game must have been played and the users indicated that they want to play again.
// Post: Resets the board.

char getFirstPlayer();
// Pre: None.
// Post: Returns the first player chosen randomly.

void showStats(int playerXWins, int playerOWins, int totalGames);
// Pre: Takes in the number of wins for each player and the total number of games played. The user must have indicated that they don't want to play again.
// Post: Displays the number of wins for each player and the total number of games played.

int main() {
  char board[SIZE][SIZE];
  int playerXWins = 0, playerOWins = 0, totalGames = 0;
  char repeatGame;
  
  do {
    // Initialization of the game
    char currentPlayer;
    bool gameOver;
    int turns;
    initializeGame(board, currentPlayer, gameOver, turns);

    // separate while loop, not to be confused with a do-while loop
    while (!gameOver && turns < 9){
      int row, col;
      cout << "Player " << currentPlayer << ", enter your move (row and column, 1-3): ";
      cin >> row >> col;

      // Check for valid move
      if (isValidMove(board, row-1, col-1)) { 
        // adjusting for 0-based indexing. We tried to do it inside the function itself but it was giving us logical errors.
        board[row-1][col-1] = currentPlayer; 
        // the board array is updated after each move
        drawBoard(board);
        gameOver = checkWin(board, currentPlayer);

        if (gameOver){
          cout << "Player " << currentPlayer << " wins!\n";
          if (currentPlayer == 'X')
            playerXWins++;
          else
            playerOWins++;
          
        } else {
          currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Checks if current player is X and switches to O if it is
          turns++;
        }
      } else {
        cout << "Invalid move. Try again.\n";
      }
    }

    if (!gameOver)
      cout << "It's a tie!\n";

    totalGames++;

    cout << "Do you want to play again? (y/n): ";
    cin >> repeatGame;
  
  } while (repeatGame == 'y' || repeatGame == 'Y');

  showStats(playerXWins, playerOWins, totalGames);

  return 0;
  
}

//Function definitions

void initializeGame(char board[SIZE][SIZE], char& currentPlayer, bool& gameOver, int& turns){
  resetBoard(board);
  currentPlayer = getFirstPlayer(); // Randomly determine who goes first
  gameOver = false;
  turns = 0;

  cout << "Welcome to Tic-Tac-Toe!\n"
    << "The first player has been selected at random. Enjoy!\n" << endl;
  drawBoard(board);
}

void drawBoard(char board[SIZE][SIZE]) {
  cout << "+--+--+--+\n"; // top line does not need to be inside the loop
  for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
          cout << "| " << (board[i][j] == ' ' ? ' ' : board[i][j]);
        // checks if the current element is empty and prints a space if it is, otherwise prints the element itself
      }
      cout << "|\n+--+--+--+\n";
  }
}

void resetBoard(char board[SIZE][SIZE]) { //Reset board to all empty spaces
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board [i][j] = ' ';
    }
  }
}

bool isValidMove(char board[SIZE][SIZE], int row, int col){ 
  return row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' '; // all conditions that must be true for the move to be valid
}

bool checkWin(char board[SIZE][SIZE], char player){
 // Check rows and cols 
  for (int i = 0; i < SIZE; i++) {
    if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // rows
      (board[0][i] == player && board[1][i] == player && board[2][i] == player)) { // cols
      return true;
      }
  }

  //Check diagonals
  if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
    (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
    return true;
  }
  return false;
}

char getFirstPlayer() {
  srand(time(0));
  return (rand() % 2 == 0) ? 'X' : 'O'; // ternary operator to replace if-else statement
}

void showStats(int playerXWins, int playerOWins, int totalGames) {
  cout << "Game Stats:\n";
  cout << "Player X Wins: " << playerXWins << endl;
  cout << "Player O Wins: " << playerOWins << endl;
  cout << "Total games played: " << totalGames << endl;
}