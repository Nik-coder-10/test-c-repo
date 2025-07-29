#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char board[3][3];
int player1Score = 0, player2Score = 0, drawCount = 0;

void resetBoard();
void printBoard();
int checkWin();
int isDraw();
void playerMove(char symbol);
void friendMove(char symbol);
void computerMoveEasy(char symbol);
void computerMoveHard(char comp, char player);
void playWithFriend();
void playWithComputer();
int menu();

int main() {
    int choice;
    while (1) {
        choice = menu();
        if (choice == 1)
            playWithFriend();
        else if (choice == 2)
            playWithComputer();
        else
            break;
    }

    printf("\n===== FINAL SCORE =====\n");
    printf("Player 1: %d\n", player1Score);
    printf("Player 2 / Computer: %d\n", player2Score);
    printf("Draws: %d\n", drawCount);
    printf("Thanks for playing!\n");
    return 0;
}

int menu() {
    int ch;
    printf("\n===== TIC TAC TOE =====\n");
    printf("1. Play with Friend\n");
    printf("2. Play with Computer\n");
    printf("3. Exit\n");
    printf("Choose option: ");
    scanf("%d", &ch);
    return ch;
}

void resetBoard() {
    char c = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = c++;
}

void printBoard() {
    printf("\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n\n");
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];
    return 0;
}

int isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
    return 1;
}

void playerMove(char symbol) {
    int pos;
    while (1) {
        printf("Enter your move (1-9): ");
        scanf("%d", &pos);
        pos--;
        int r = pos / 3, c = pos % 3;
        if (pos >= 0 && pos < 9 && board[r][c] != 'X' && board[r][c] != 'O') {
            board[r][c] = symbol;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    printBoard();
}

void friendMove(char symbol) {
    int pos;
    while (1) {
        printf("Friend's move (1-9): ");
        scanf("%d", &pos);
        pos--;
        int r = pos / 3, c = pos % 3;
        if (pos >= 0 && pos < 9 && board[r][c] != 'X' && board[r][c] != 'O') {
            board[r][c] = symbol;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    printBoard();
}

void computerMoveEasy(char symbol) {
    int pos, r, c;
    while (1) {
        pos = rand() % 9;
        r = pos / 3;
        c = pos % 3;
        if (board[r][c] != 'X' && board[r][c] != 'O') {
            board[r][c] = symbol;
            break;
        }
    }
    printBoard();
}

void computerMoveHard(char comp, char player) {
    for (int i = 0; i < 9; i++) {
        int r = i / 3, c = i % 3;
        if (board[r][c] != 'X' && board[r][c] != 'O') {
            char temp = board[r][c];
            board[r][c] = player;
            if (checkWin() == player) {
                board[r][c] = comp;
                printBoard();
                return;
            }
            board[r][c] = temp;
        }
    }
    computerMoveEasy(comp);  // fallback
}

void playWithFriend() {
    char p1, p2, again;
    do {
        resetBoard();
        printf("\nPlayer 1, choose your symbol (X/O): ");
        scanf(" %c", &p1);
        p1 = (toupper(p1) == 'O') ? 'O' : 'X';
        p2 = (p1 == 'X') ? 'O' : 'X';

        printBoard();
        int turn = 0;
        while (1) {
            if (turn % 2 == 0)
                playerMove(p1);
            else
                friendMove(p2);

            int winner = checkWin();
            if (winner) {
                if (winner == p1) {
                    printf("Player 1 (%c) wins!\n", p1);
                    player1Score++;
                } else {
                    printf("Player 2 (%c) wins!\n", p2);
                    player2Score++;
                }
                break;
            }
            if (isDraw()) {
                printf("It's a draw!\n");
                drawCount++;
                break;
            }
            turn++;
        }
        printf("Play again? (Y/N): ");
        scanf(" %c", &again);
    } while (toupper(again) == 'Y');
}

void playWithComputer() {
    char player, comp, again;
    int level;
    do {
        resetBoard();
        srand(time(0));

        printf("\nChoose your symbol (X/O): ");
        scanf(" %c", &player);
        player = (toupper(player) == 'O') ? 'O' : 'X';
        comp = (player == 'X') ? 'O' : 'X';

        printf("Choose Difficulty:\n1. Easy\n2. Hard\nEnter: ");
        scanf("%d", &level);

        printBoard();
        int turn = 0;
        while (1) {
            if (turn % 2 == 0)
                playerMove(player);
            else {
                printf("Computer's move:\n");
                if (level == 1)
                    computerMoveEasy(comp);
                else
                    computerMoveHard(comp, player);
            }

            int winner = checkWin();
            if (winner) {
                if (winner == player) {
                    printf("You (%c) win!\n", player);
                    player1Score++;
                } else {
                    printf("Computer (%c) wins!\n", comp);
                    player2Score++;
                }
                break;
            }
            if (isDraw()) {
                printf("It's a draw!\n");
                drawCount++;
                break;
            }
            turn++;
        }
        printf("Play again? (Y/N): ");
        scanf(" %c", &again);
    } while (toupper(again) == 'Y');
}
