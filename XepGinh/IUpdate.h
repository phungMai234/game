#ifndef IUPDATE_H_INCLUDED
#define IUPDATE_H_INCLUDED

#include"IDraw.h"
#define MAX 5

/* PROTOTYPE */

/*
 * Function: {void} updateGame(int row)
 *@Brief:  update the following status of matrix after getting point
 */
void updateGame(int row);

/*
 * Function: {void} ganGiaTri(KhoiGach* pKhoiGach)
 *@Brief:  update the following status of matrix after block brick go down
 */
void ganGiaTri(KhoiGach* pKhoiGach);

/*
 * Function: {void} initGame(INFO* info)
 * Brief: Initialize the initial parameters for the game: score, level, speed
 */
void initGame(INFO* info);

/*
 * Function: {void} updateINFO(INFO* info)
 * Brief: Update the game parameters: score, level, speed
 */
void updateINFO(INFO* info);



#endif // IUPDATE_H_INCLUDED
