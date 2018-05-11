#include<iostream>
#include<ctime>
#include<cstdlib>
#include<windows.h>
#include<conio.h>

#include"Idesign.h"
#include"IPlayer.h"
#include"IUpdate.h"
#include"INFO.h"
#include"Icheck.h"
#include"IDraw.h"
#include"Imenu.h"


int Board[MaxI][MaxJ];

using namespace std;

int main()
{
    char choice;
    do
    {
        /*Draw a main menu */

        mainMenu();

        /*Get a character from keyBoard*/

        choice = _getch();

        /*choose a function to be exercuted*/

        /* Play new game*/

        if(choice == '1')
        {
            clrscr();
            if(!playGame())
                break;
        }

        /* How to play game*/

        if(choice == '2')
        {
            clrscr();
            if(!help())
                break;
        }

        /* Information of author*/

        if(choice == '3')
        {
            clrscr();
            if(!credit())
                break;
        }

        /* Exit game*/

        if(choice == '4')
        {
            break;
        }
        clrscr();

    }
    while(1);


    return 0;
}
