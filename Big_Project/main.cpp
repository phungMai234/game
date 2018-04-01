#include <iostream>
#include"console.h"

using namespace std;
void DrawBoard();

int main()
{
    DrawBoard();
    return 0;
}
void DrawBoard()
{
	int i,j;
	for(i=LEFT;i<=LEFT+10+1;i++)
		for(j=TOP;j<=TOP+18+1;j++)
		{
			if((j==TOP||j==TOP+18+1)&&i>LEFT&&i<LEFT+10+1)
			{
				gotoXY(i,j);TextColor(7);cout << char(205);
			}
			if((i==LEFT||i==LEFT+10+1)&&j>TOP&&j<TOP+18+1)
			{
				gotoXY(i,j);TextColor(7);cout << char(186);
			}
		}
		gotoXY(LEFT,TOP);TextColor(10);cout << char(219);
		gotoXY(LEFT+10+1,TOP);TextColor(10);cout << char(219);
		gotoXY(LEFT,TOP+18+1);TextColor(10);cout << char(2);
		gotoXY(LEFT+10+1,TOP+18+1);TextColor(10);cout << char(219);

}
