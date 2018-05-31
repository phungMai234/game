#ifndef IDESIGN_H_INCLUDED
#define IDESIGN_H_INCLUDED

#include "Iconsole.h"

/* library to call random*/
#include<ctime>
#include<cstdlib>


struct Object
{
    /* pointer to pointer array contain objects */
    int **arr;
    /* Row, col go with each of object */
    int Row, Col;
    /* located of object */
    int iBoard, jBoard;
};

struct INFO
{
    int score;
    int level;
    float speed;
};

/* PROTOTYPE */

/*
 * Function: {Object*} designObject(int ID)
 * Brief: Design a brick allow ID
 */
Object* designObject(int ID);

/*
 * Function: {void} destroyObject(Object* pObject)
 * Brief: Free up memory containing blocks of tiles
 */
void destroyObject(Object* pObject);

/*
 * Function: {int} randomObject()
 * Brief: Random ID of each brick
 */
int randomObject();


#endif // ICREATBRICK_H_INCLUDED
