
#include"MoveBlock.h"
#include"taoKhoiGach.h"
#include"struct.h"
#include"console.h"

int Inside(int i, int j)
{
    return ((i > 0 && i < MaxI) && (j > 0 && j < MaxJ));
}



int Left(int i, int j)
{
    if(j > 0 && Inside(i, j) && Board[i][j - 1] == 0)
        return 1;
    return 0;
}
int Right(int i, int j)
{
    if((j < MaxJ - 1) && Inside(i, j) && Board[i][j + 1] == 0)
        return 1;
    return 0;
}
int Down(int i, int j)
{
    if((j < MaxI - 1) && Inside(i, j) && Board[i + 1][j] == 0)
        return 1;
    return 0;
}


void SangTrai(KhoiGach* pkhoigach)
{
    int i, j;
    for(i = 0; i < pkhoigach->Row; i++)
    {
        for(j = 0; j < pkhoigach->Col; j++)
        {
            if(pkhoigach->arr[i][j] == 1)
            {
                if(Left(pkhoigach->iBoard + i, pkhoigach->jBoard + j) == 0 || pkhoigach->iBoard <= 3)
                    return;
            }
        }
    }
    pkhoigach->jBoard-=1;
}

void SangPhai(KhoiGach* pkhoigach)
{
    int i, j;
    for(i = 0; i < pkhoigach->Row; i++)
    {
        for(j = 0; j < pkhoigach->Col; j++)
        {
            if(pkhoigach->arr[i][j] == 1)
            {
                if(Right(pkhoigach->iBoard + i, pkhoigach->jBoard + j) == 0 || pkhoigach->iBoard <= 3)
                    return;
            }
        }
    }
    pkhoigach->jBoard+=1;
}

int RoiXuong(KhoiGach* pkhoigach)
{
    int i, j;
    for(i = 0; i < pkhoigach->Row; i++)
    {
        for(j = 0; j < pkhoigach->Col; j++)
        {
            if(pkhoigach->arr[i][j] == 1)
            {
                if(Down(pkhoigach->iBoard + i, pkhoigach->jBoard + j) == 0 || pkhoigach->iBoard <= 3)
                    return 0; // khong roi xuong
            }
        }
    }
    pkhoigach->iBoard+=1;
    return 1; // roi xuong
}



void XoayKhoiGach(KhoiGach* pkhoigach) // hoi quan
{
	int i,j;
	int ** tmpArr;
	int tmpRow = pkhoigach->Col;
	int tmpCol = pkhoigach->Row;
	//Cấp phát bộ nhớ cho ma trận phụ tmpArr.
	tmpArr= new int*;
	for( i = 0; i < tmpRow; i++)
	{
		tmpArr[i] = new int;
	}
	///////////////////////////////////////////////
	for(i = pkhoigach->Row - 1; i >= 0; i--)
		for(j = pkhoigach->Col - 1; j >= 0; j--)
		{
			tmpArr[j][pkhoigach->Row - i - 1] = pkhoigach->arr[i][j];
		}
	//Kiểm tra hợp lệ.
		for (i=0;i<tmpRow;i++)
		{
			for(j=0;j<tmpCol;j++)
				if(!Inside(pkhoigach->iBoard+i,pkhoigach->jBoard+j)||Board[pkhoigach->iBoard+i][pkhoigach->jBoard+j]==1)
					return;
		}
	for(i=0;i<pkhoigach->Row;i++) delete(pkhoigach->arr[i]);
	delete(pkhoigach->arr);
	//Cập nhật thay đổi sau khi xoay.
	pkhoigach->Col=tmpCol;
	pkhoigach->Row=tmpRow;
	pkhoigach->arr=tmpArr;

}
