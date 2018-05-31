
#ifndef ICHECK_H_INCLUDED
#define ICHECK_H_INCLUDED


#include<conio.h>

#include"IDraw.h"
#include"IUpdate.h"


/* PROTOTYPE */

/*
 * Function: {int} checkToGetPoint(Object *pObject, INFO* info)
 * Brief: check matrix after each blocks brick down, eat it
 */
int checkToGetPoint(Object* pObject, INFO* info);

/*
 * Function: {bool} inside(int i, int j)
 * Brief: check small object in matrix
 */
bool inside(int i, int j);

/*
 * Function: {bool} left(int i, int j)
 * Brief: check small object move left (yes/no)
 */
bool left(int i, int j);

/*
 * Function: {bool} right(int i, int j)
 * Brief: check small object move right (yes/no)
 */
bool right(int i, int j);

/*
 * Function: {bool} down(int i, int j)
 * Brief: check small object go down (yes/no)
 */
bool down(int i, int j);

/*
 * Function: {void} moveLeftObject(Object* pObject)
 * Brief: move the block object go to the left
 */




#endif // ICHECK_H_INCLUDED
