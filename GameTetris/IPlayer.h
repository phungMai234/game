#ifndef IMOVE_H_INCLUDED
#define IMOVE_H_INCLUDED

#include"Icheck.h"


/* PROTOTYPE */

void moveLeftObject(Object* pObject);

/*
 * Function: {void} moveRightObject(Object* pObject)
 * Brief: move the block object go to the right
 */
void moveRightObject(Object* pObject);

/*
 * Function: {bool} moveDownObject(Object* pObject)
 * Brief: Move the falling blocks
 */
bool moveDownObject(Object* pObject);

/*
 * Function: {void} rotateObject(Object* pObject)
 * Brief: Turn the brick block at an angle of 90 degrees
 */
void rotateObject(Object* pObject);



/*---------------------------------------------*/

/*
 * Function: {bool} playGame()
 * Brief: Player play game
 */
bool playGame();


#endif // IMOVEBRICK_H_INCLUDED
