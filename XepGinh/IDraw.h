#ifndef IDRAW_H_INCLUDED
#define IDRAW_H_INCLUDED

#include<iostream>

#include"Idesign.h"
#include"Iconsole.h"

#define MaxI 22
#define MaxJ 10

#define TOP 4
#define LEFT 4

/*matrix*/
extern int Board[MaxI][MaxJ];

using namespace std;

/* PROTOTYPE */

/*
 * Function: {void} VeKhoiGach(KhoiGach* pKhoiGach)
 * Brief: Draw block object in ingameScence
 */
void VeKhoiGach(KhoiGach* pKhoiGach);

/*
 * Function: {void} VeKhoiGach(KhoiGach* pKhoiGach)
 * Brief: delete block object in ingameSence
 */
void xoaKhoiGach(KhoiGach* pKhoiGach);

/*
 * Function: {void} Ve_Next(int ID)
 * Brief: draw block object
 */
void Ve_Next(int ID);

/*
 * Function: {void} Xoa_Next()
 * Brief: delete block object
 */
void Xoa_Next();

/*--------------------------------------------------------------*/


/*
 * Function: {void} render()
 * Brief: drawing frames to display up screen
 */
void render();

/*
 * Function: {void} veBangDiem(INFO)
 * Brief: drawing table current game information
 */
void veBangDiem(INFO info);

/*
 * Function: {void} disPlayBoard()
 * Brief:  status value assignment for a battle
 */
void disPlayBoard();



#endif // IVEXOAKHOIGACH_H_INCLUDED
