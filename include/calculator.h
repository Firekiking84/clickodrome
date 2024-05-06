/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 06/05/2024 16:19:46 ******************************************************
** romain.cescutti <romain.cescutti@gagarine.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#ifndef		__CALCULATOR_H__

#define		__CALCULATOR_H__

#include	"efstring.h"

typedef struct t_calculator
{
 double		res;
 double		buffer;
 void		*operator;
 t_string	string;
}

void push_0 (void);
void push_1 (void);
void push_2 (void);
void push_3 (void);
void push_4 (void);
void push_5 (void);
void push_6 (void);
void push_7 (void);
void push_8 (void);
void push_9 (void);



