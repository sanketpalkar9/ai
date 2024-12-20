#include <stdio.h>

#define SIZE 3

int isBoardFull(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

int checkWin(char board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        // Row check
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            if (board[i][0] == 'X')
            {
                return 1;
            }
            else if (board[i][0] == 'O')
            {
                return 2;
            }
        }

        // Column check
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        {
            if (board[0][i] == 'X')
            {
                return 1;
            }
            else if (board[0][i] == 'O')
            {
                return 2;
            }
        }
    }

    // Diagonal check
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        if (board[0][0] == 'X')
        {
            return 1;
        }
        else if (board[0][0] == 'O')
        {
            return 2;
        }
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    {
        if (board[0][2] == 'X')
        {
            return 1;
        }
        else if (board[0][2] == 'O')
        {
            return 2;
        }
    }

    return 0;
}

void printBoard(char board[SIZE][SIZE])
{
    printf("Current board:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1)
                printf("|");
        }
        printf("\n");
        if (i < SIZE - 1)
            printf("---|---|---\n");
    }
}

void computerMove(char board[SIZE][SIZE])
{
    // Simple AI: If the computer can win, it wins. If the player can win next, block them. Otherwise, take the first available spot.
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                // Try to win
                board[i][j] = 'O';
                if (checkWin(board) == 2)
                    return;
                board[i][j] = ' ';

                // Try to block player
                board[i][j] = 'X';
                if (checkWin(board) == 1)
                {
                    board[i][j] = 'O';
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    // Take the first available spot
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'O';
                return;
            }
        }
    }
}

void playGame()
{
    char board[SIZE][SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int player = 1;
    int row, col;
    int win = 0;

    while (win == 0 && !isBoardFull(board))
    {
        printBoard(board);
        if (player == 1)
        {
            printf("Player 1's turn. Enter row and column (0-2): ");
            scanf("%d %d", &row, &col);

            if (board[row][col] != ' ')
            {
                printf("Invalid move. Try again.\n");
                continue;
            }
            board[row][col] = 'X';
        }
        else
        {
            computerMove(board);
        }

        win = checkWin(board);

        if (win == 0)
        {
            player = (player == 1) ? 2 : 1;
        }
    }

    printBoard(board);
    if (win == 1)
    {
        printf("Player 1 (X) wins!\n");
    }
    else if (win == 2)
    {
        printf("Player 2 (O) wins!\n");
    }
    else
    {
        printf("It's a draw!\n");
    }
}

int main()
{
    playGame();
    return 0;
}
