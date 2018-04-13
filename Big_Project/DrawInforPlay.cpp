
//#include"taoKhoiGach.h"
//#include"DrawInforPlay.h"
//#include"DrawMap.h"
//#include"DIeuKhien.h"
//#include"MoveBlock.h"
//
//
//void InitGame(INFO *info)
//{
//	info->level=1;
//	info->score=0;
//	info->speed=0.4;
//}
//
//// cap nhat khi sang level moi
//
//int CapNhat(INFO *info, int score)
//{
//	info->score+=score;
//	if(info->score>=200&&info->level<2)
//	{
//		info->level++;
//		info->speed-=0.1;
//	}
//	return 0; //Chua win game.
//}
//
//void VeBangDiem(INFO info)
//{
//	TextColor(15);
//	gotoXY(LEFT+MaxJ+2,10);
//	cout << "  SCORE: " << info.score;
//	gotoXY(LEFT+MaxJ+2,11);
//	cout << "  LEVEL: " << info.level;
//	gotoXY(LEFT+MaxJ+2,12);
//	cout << "  SPEED: " << info.speed;
//}
