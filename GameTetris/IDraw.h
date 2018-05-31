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
 * Function: {void} drawObject(Object* pObject)
 * Brief: Draw block object in ingameScence
 */
void drawObject(Object* pObject);

/*
 * Function: {void} drawObject(Object* pObject)
 * Brief: delete block object in ingameSence
 */
void deleteObject(Object* pObject);

/*
 * Function: {void} drawNextObject(int ID)
 * Brief: draw block object
 */
void drawNextObject(int ID);

/*
 * Function: {void} deleteNextObject()
 * Brief: delete block object
 */
void deleteNextObject();

/*--------------------------------------------------------------*/


/*
 * Function: {void} render()
 * Brief: drawing frames to display up screen
 */
void render();

/*
 * Function: {void} drawTableScore(INFO)
 * Brief: drawing table current game information
 */
void drawTableScore(INFO info);

/*
 * Function: {void} disPlayBoard()
 * Brief:  status value assignment for a battle
 */
void displayBoard();



#endif // IVEXOAKHOIGACH_H_INCLUDED
