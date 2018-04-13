#include"taoKhoiGach.h"
#include"MoveBlock.h"


KhoiGach *TaoKhoiGach(int ID)
{
	KhoiGach *pkhoigach = new KhoiGach;
	switch(ID)
	{
		case 15: // hình chữ I
			pkhoigach->Row=4;
			pkhoigach->Col=1;
			pkhoigach->iBoard=5;
			pkhoigach->jBoard=5;
			break;
		case 31: // hinh vuông
			pkhoigach->Row=pkhoigach->Col=2;
			pkhoigach->iBoard=5;
			pkhoigach->jBoard=5;
            break;
		default: // hình T,L,Z
			pkhoigach->Row=2;
			pkhoigach->Col=3;
			pkhoigach->iBoard=5;
			pkhoigach->jBoard=5;
			break;
	}
	pkhoigach->arr = new int*;
	for(int i = 0; i < pkhoigach->Row; i++)
	{
		pkhoigach->arr[i] = new int;
	}
	for(int k = 0; k < pkhoigach->Col * pkhoigach->Row; k++)
	{
		pkhoigach->arr[k / pkhoigach->Col][k % pkhoigach->Col] = (ID >> (pkhoigach->Col * pkhoigach->Row - 1 - k)) & 1;
	}
	return pkhoigach;
}
int Loai()
{
    srand(time(NULL));
    int x=rand()%7;
	if(x==0)
        return 15;
    if(x==1)
        return 31;
    if(x==2)
        return 58;
    if(x==3)
        return 57;
    if(x==4)
        return 60;
    if(x==5)
        return 51;
    if(x==6)
        return 30;

}

void VeKhoiGach(KhoiGach* pkhoigach)
{
	int i;
	int j;
	for(i = 0;i < pkhoigach->Row; i++)
		for(j = 0;j < pkhoigach->Col; j++)
			if(pkhoigach->arr[i][j] == 1 ) // arr k hieu
			{
				TextColor(13);
				gotoXY(LEFT + pkhoigach->jBoard + j + 1, TOP + pkhoigach->iBoard + i - 3);
				cout << char(2); // nho cout ra
			}
}
