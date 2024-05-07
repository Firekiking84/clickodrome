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
#include	"gui.h"

typedef enum	e_calc
  {
    NONE  = 0,
    ADD,
    SUBSTRACT,
    MULTIPLY,
    DIVIDE,
    MODULO,
  }		t_calc;

typedef struct	s_calculator
{
  double	res;
  double	buffer;
  t_calc	operator;
  t_string	string;
}		t_calculator;

t_calculator init_calculator(void);
void update_string	(t_gui gui, void *data);
void push_0		(t_gui gui ,void *data);
void push_1		(t_gui gui ,void *data);
void push_2		(t_gui gui ,void *data);
void push_3		(t_gui gui ,void *data);
void push_4		(t_gui gui ,void *data);
void push_5		(t_gui gui ,void *data);
void push_6		(t_gui gui ,void *data);
void push_7		(t_gui gui ,void *data);
void push_8		(t_gui gui ,void *data);
void push_9		(t_gui gui ,void *data);
void add		(t_gui gui ,void *data);
void subtract		(t_gui gui ,void *data);
void divide		(t_gui gui ,void *data);
void multiply		(t_gui gui ,void *data);
void modulo		(t_gui gui ,void *data);
void result		(t_gui gui ,void *data);
void operation		(t_gui gui ,void *data);
void delete		(t_gui gui ,void *data);
void clear 		(t_gui gui ,void *data);
