#define _CRT_NO_WARNINGS
 
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

char A = '1';
char B = '2';
char C = '3';
char D = '4';
char E = '5'; 
char F = '6'; 
char G = '7'; 
char H = '8';
char I = '9';

int gameMode; // 1 -> multiplayer 2 -> singleplayer
int player = 0; // 1 or 2
int state = 0; // 0 game is running - 1 is draw - 2 is someone won
int chance = 0; // plyers chance

void drawBoard()
{
    printf("\n");

    printf("     |     |      \n");

    printf("  %c  |  %c  |  %c\n", A, B, C);

    printf("_____|_____|_____ \n");

    printf("     |     |      \n");

    printf("  %c  |  %c  |  %c\n", D, E, F);

    printf("_____|_____|_____ \n");

    printf("     |     |      \n");

    printf("  %c  |  %c  |  %c\n", G, H, I);

    printf("     |     |      \n");
}

int convertCharIntToInt(int a)
{
    return a - 48;
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void clearConsole(double mili)
{
    //printf("loading..");
    delay(mili);
    system("cls");
}

void ResetGame()
{
    
    A = '1';
    B = '2';
    C = '3';
    D = '4';
    E = '5';
    F = '6';
    G = '7';
    H = '8';
    I = '9';

    gameMode = 0; // 1 -> multiplayer 2 -> singleplayer
    player = 0; // 1 or 2
    state = 0; // 0 game is running - 1 is draw - 2 is someone won
    chance = 0; // players chance
}

int ValidateNumericInput()
{
    char answer = _getch();
    if (isdigit(answer))
    {
        return convertCharIntToInt(answer);
    }
    else
    {
        clearConsole(0.5);
        return 0;
    }
}

char ReturnPlayerSymbol() 
{
    if (player == 1)
        return 'X';
    else
        return 'O';
}

int CertifyPlayerChance(int n)  // chance
{
    if (n >= 1 && n <= 9)
    {
        switch (n)
        {

            case 1:

                if (A == '1')
                {
                    A = ReturnPlayerSymbol();
                    return 1;
                }
                else
                    return 0;

            case 2:

                if (B == '2')
                {
                    B = ReturnPlayerSymbol();
                    return 1;
                }
                else
                    return 0;

            case 3:

                if (C == '3')
                {
                    C = ReturnPlayerSymbol();
                    return 1;
                }
                else
                    return 0;

            case 4:

                if (D == '4')
                {
                    D = ReturnPlayerSymbol();
                    return 1;
                }
                else
                    return 0;

            case 5:

                if (E == '5')
                {
                    E = ReturnPlayerSymbol();
                    return 1;
                }
                else
                    return 0;

            case 6:

                if (F == '6')
                {
                    F = ReturnPlayerSymbol();
                    return 1;
                }
                else
                    return 0;

            case 7:

                if (G == '7')
                {
                    G = ReturnPlayerSymbol();
                    return 1;
                }
                else
                    return 0;

            case 8:

                if (H == '8')
                {
                    H = ReturnPlayerSymbol();
                    return 1;
                }
                else
                    return 0;

            case 9:

                if (I == '9')
                {
                    I = ReturnPlayerSymbol();
                    return 1;
                }
                else
                    return 0;

            default:
                return 1;
                break;
        }
    }
    else 
    {
        return 0;
    }
}

void verifyGameState() 
{
    //Winning Condition For First Row   

    if (A == B && B == C)

    {
        state = 2;
    }

    //Winning Condition For Second Row   

    else if (D == E && E == F)

    {
        state = 2;
    }

    //Winning Condition For Third Row   

    else if (G == H && H == I)

    {
        state = 2;
    }

    //Winning Condition For First Column       

    else if (A == D && D == G)
    {
        state = 2;
    }

    //Winning Condition For Second Column  

    else if (B == E && E == H)
    {
        state = 2;
    }

    //Winning Condition For Third Column  

    else if (C == F && F == I)
    {
        state = 2;
    }

    //Winning Condition For Diagonals  

    else if (A == E && E == I)
    {
        state = 2;
    }

    else if (C == E && E == G)
    {
        state = 2;
    }

    // If all the cells or values filled with X or O then any player has won the match  

    else if (A != '1' && B != '2' && C != '3' && D != '4' && E != '5' && F != '6' && G != '7' && H != '8' && I != '9')
    {
        state = 1;
    }

    else
    {
        state = 0;
    }
}

void TellWinner()
{
    clearConsole(0.5);
    drawBoard();
    if (state == 2)
        printf("\n player %d Venceu! \n", player);
    else
        puts("\n Empate !");

    ResetGame();

}

int ComputerChance()
{
    return rand() % 9;
}

void ComputerTry()
{
    do
    {
        
        clearConsole(0.1);
        drawBoard();
        printf("vez do player %d \n", player);

        chance = ComputerChance();

    } while (CertifyPlayerChance(chance) == 0);

}

void PlayerTry() 
{
    do
    {

        clearConsole(0.5);
        drawBoard();
        printf("vez do player %d \n", player);
        puts("digite o numero da posicao");
        
        chance = ValidateNumericInput();
        
    } while (CertifyPlayerChance(chance) == 0);
    
}

void singleplayer()
{
    /* */
    do
    {

        if (state == 0)
        {
            player = (player % 2) + 1;

            if (player == 1)
            {
                PlayerTry();
            }
            else
            {
                ComputerTry();
            }
        } 

        verifyGameState();

    } while (state == 0);

    TellWinner();
    clearConsole(3);
}

void multiplayer()
{
    do
    {
        player = (player % 2) + 1;
        if (state == 0)
            PlayerTry();

        verifyGameState();

    } while (state == 0);

    TellWinner();
    clearConsole(3);
}

void startGame()
{
    
    do {
        puts("\nBem vindo ao jogo do galo, escolha o modo de jogo \n ");
        puts("[1] Multiplayer [2] Singleplayer");
        
       gameMode = ValidateNumericInput();

    } while (gameMode == 0);
    
    switch (gameMode)
    {
    case 1:
        multiplayer();
        break;

    case 2:
        singleplayer();
        break;

    default:
        
        break;
    }
    
}

int main()
{
    while (1) 
    {
        startGame();
    }
        
}

