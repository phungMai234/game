#include"Imenu.h"

/* CODE */

void mainMenu()
{
    TextColor(11);
    cout << "\t\t--------------GAME TETRIS-------------\n"
         "\t\t**************MAIN MENU***************\n"
         "\t\t(1) - New Game\n"
         "\t\t(2) - Help\n"
         "\t\t(3) - Credit\n"
         "\t\t(4) - Quit Game\n"
         "\t\t--------------------------------------\n";
}

bool help()
{
    char choice;
    TextColor(15);
    cout << "------------------Guide to Play Tetris Game----------------\n"
         " Playing a new game:\n"
         " right-handed(left-handed):\n"
         " -> using key above (key W): to rotate the bricks block\n"
         " -> using key left  (key A): move the brick block left\n"
         " -> using key right (key D): move the brick block right\n"
         " -> using key down  (key S): move the brick block down\n\n\n"
         " When playing a tetris game, one turns them or moves left\n"
         " and right, trying to arrange the shapes in a line.      \n"
         " When a line of squares makes a line from edge to edge,  \n"
         " it disappears and all the pieces move down by a square. \n"
         " When the well is filled up, the player lose.            \n\n";
    TextColor(14);
    cout << " Do you want to back Main menu? (Y/N) \n";
    cout << " Choice: ";

    choice = _getch();
    if(choice == 'N' || choice == 'n')
        return false;
    return true;
}
bool credit()
{
    char choice;
    TextColor(15);
    cout << "\t\t--------Credit Game Tetris-------\n"
         "\t\t-- Author: Phung Thi Tuyet Mai --\n"
         "\t\t-- Number: 17020875            --\n"
         "\t\t-- Class : K62IE3              --\n"
         "\t\t---------------------------------\n";
    TextColor(14);
    cout << "Do you want to back Main menu? (Y/N) \n";
    cout << "Choice: ";
    choice = _getch();
    if(choice == 'N' || choice == 'n')
        return false;
    return true;
}
