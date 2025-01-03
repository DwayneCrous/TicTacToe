#include <iostream>
#include <ctime>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main()
{

  char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  char player = 'X';
  char computer = 'O';
  bool running = true;

  srand(time(0));

  drawBoard(spaces);

  while (running)
  {
    playerMove(spaces, player);
    drawBoard(spaces);

    if (checkWinner(spaces, player, computer))
    {
      running = false;
      break;
    }
    else if (checkTie(spaces))
    {
      running = false;
      break;
    }

    computerMove(spaces, computer);
    drawBoard(spaces);

    if (checkWinner(spaces, player, computer))
    {
      running = false;
      break;
    }
    else if (checkTie(spaces))
    {
      running = false;
      break;
    }
  }
  std::cout << "Thanks for playing!\n";

  return 0;
}

void drawBoard(char *spaces)
{
  std::cout << "     |     |     " << "\n";
  std::cout << " " << spaces[0] << "   |   " << spaces[1] << " |   " << spaces[2] << "\n";
  std::cout << "_____|_____|_____" << "\n";
  std::cout << "     |     |     " << "\n";
  std::cout << " " << spaces[3] << "   |   " << spaces[4] << " |   " << spaces[5] << "\n";
  std::cout << "_____|_____|_____" << "\n";
  std::cout << "     |     |     " << "\n";
  std::cout << " " << spaces[6] << "   |   " << spaces[7] << " |   " << spaces[8] << "\n";
  std::cout << "     |     |     " << "\n\n";
}

void playerMove(char *spaces, char player)
{

  int number;

  do
  {
    std::cout << "Enter a spot to place a marker (1 - 9): ";
    std::cin >> number;
    number--;

    if (number >= 0 && number < 9 && spaces[number] == ' ')
    {
      spaces[number] = player;
      break;
    }
    else
    {
      std::cout << "Invalid move. Try again.\n";
    }

  } while (true);
}

void computerMove(char *spaces, char computer)
{

  int number;

  while (true)
  {
    number = rand() % 9;

    if (spaces[number] == ' ')
    {
      spaces[number] = computer;
      break;
    }
  }
}

bool checkWinner(char *spaces, char player, char computer)
{

  // rows
  if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2]))
  {
    spaces[0] == player ? std::cout << "You won!\n" : std::cout << "You lost!\n";
    return true;
  }
  else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5]))
  {
    spaces[3] == player ? std::cout << "You won!\n" : std::cout << "You lost!\n";
    return true;
  }
  else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8]))
  {
    spaces[6] == player ? std::cout << "You won!\n" : std::cout << "You lost!\n";
    return true;
  }

  // columns
  else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6]))
  {
    spaces[0] == player ? std::cout << "You won!\n" : std::cout << "You lost!\n";
    return true;
  }
  else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7]))
  {
    spaces[1] == player ? std::cout << "You won!\n" : std::cout << "You lost!\n";
    return true;
  }
  else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8]))
  {
    spaces[2] == player ? std::cout << "You won!\n" : std::cout << "You lost!\n";
    return true;
  }

  // Diagonals
  else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8]))
  {
    spaces[0] == player ? std::cout << "You won!\n" : std::cout << "You lost!\n";
    return true;
  }
  else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6]))
  {
    spaces[2] == player ? std::cout << "You won!\n" : std::cout << "You lost!\n";
    return true;
  }

  return false;
}

bool checkTie(char *spaces)
{

  for (int i = 0; i < 9; i++)
  {
    if (spaces[i] == ' ')
    {
      return false;
    }
  }
  std::cout << "It is a tie!\n";

  return true;
}
