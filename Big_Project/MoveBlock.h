// nho khai bao prototype

#ifndef _console_header
#define _console_header
#include<windows.h>

/* ham kiem tra xem vien gach co nam trong bang khong*/
/*!
 * Function: Inside(int i, int j)
 *
 * @Brief: kiem tra xem 1 vien gach co thuoc bang Board[22][10]
 *
 * @Param: i: vi trí hang của viên gạch đang xét
 *         j: vi tri côt của viên gạch đang xét
 * @Return: trả về kết quả: vien gạch thuộc mảng Board[22][10] hay không
 */
int Inside(int, int);

/*------------------------------------------------------*/


/* ham di chuyen tung vien gach*/

/* ham di chuyen vien gach sang trai*/

int Left(int, int);

/*ham di chuyen vien gach sang ben phai*/

int Right(int);

/* ham di chuyen vien gach roi xuong*/

int Down(int);

/*------------------------------------------------*/

/* ham di chuyen ca khoi gach*/

/*ham di chuyen ca khoi gach sang trai*/

void SangTrai(KhoiGach*);

/* ham di chuyen ca khoi gach sang phai*/

void SangPhai(KhoiGach*);

/* ham di chuyen ca khoi gach roi xuong*/

void RoiXuong(KhoiGach*);


/*-------------------------------------------------*/

/*ham xoay khoi gach*/

void XoayKhoiGach(KhoiGach* pkhoigach);

#endif
