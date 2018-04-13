
#include"DrawMap.h"
#include"MoveBlock.h"

void DrawBoard()
{
	int i,j;
	for(i=LEFT;i<=LEFT+10+1;i++)
		for(j=TOP;j<=TOP+18+1;j++)
		{
			if((j==TOP||j==TOP+18+1)&&i>LEFT&&i<LEFT+10+1)
			{
				gotoXY(i,j);TextColor(7);
				cout << char(205);
			}
			if((i==LEFT||i==LEFT+10+1)&&j>TOP&&j<TOP+18+1)
			{
				gotoXY(i,j);TextColor(7);
				cout << char(186);
			}
		}
		gotoXY(LEFT,TOP);TextColor(10);cout << char(219);
		gotoXY(LEFT+10+1,TOP);TextColor(10);cout << char(219);
		gotoXY(LEFT,TOP+18+1);TextColor(10);cout << char(219);
		gotoXY(LEFT+10+1,TOP+18+1);TextColor(10);cout << char(219);

}



//void XoaKhoiGach(KhoiGach* pkhoigach)
//{
//    int i, j;
//    for(i = 0; i < pkhoigach->Row; i++)
//    {
//        for(j = 0; j < pkhoigach->Col; j++)
//        {
//            if(pkhoigach->arr[i][j] == 1)
//            {
//                TextColor(0);
//                gotoXY(LEFT + pkhoigach->jBoard + j + 1, TOP + pkhoigach->iBoard + i - 3); //  k hieu
//                cout <<"";
//            }
//        }
//    }
//}

//void DisplayBoard()
//{
//	int i,j;
//	for(i=0;i<MaxI;i++)
//		for(j=0;j<MaxJ;j++)
//		{
//			if(Board[i][j]==1&&i>=4)
//			{
//				gotoXY(j+LEFT+1,i+TOP+1-4);TextColor(15);cout << char(2);
//			}
//			if(Board[i][j]==0&&i>=4)
//			{
//				TextColor(0);gotoXY(j+LEFT+1,i+TOP+1-4);cout << "";
//			}
//		}
//}
