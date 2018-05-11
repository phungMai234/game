#ifndef IMOVE_H_INCLUDED
#define IMOVE_H_INCLUDED

#include"Icheck.h"


/* PROTOTYPE */

void moveLeftObject(KhoiGach* pKhoiGach);

/*
 * Function: {void} moveRightObject(KhoiGach* pKhoiGach)
 * Brief: move the block object go to the right
 */
void moveRightObject(KhoiGach* pKhoiGach);

/*
 * Function: {bool} moveDownObject(KhoiGach* pKhoiGach)
 * Brief: Move the falling blocks
 */
bool moveDownObject(KhoiGach* pKhoiGach);

/*
 * Function: {void} rotateObject(KhoiGach* pKhoiGach)
 * Brief: Turn the brick block at an angle of 90 degrees
 */
void rotateObject(KhoiGach* pKhoiGach);



/*---------------------------------------------*/

/*
 * Function: {bool} playGame()
 * Brief: Player play game
 */
bool playGame();


#endif // IMOVEBRICK_H_INCLUDED
