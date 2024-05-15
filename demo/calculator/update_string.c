/*
** *****     ***     ***     ***       **       ***      ********************
** ****  ******  ******  **  *****  *******  *****  *************************
** ***     ***     ***     ******  *******  *****      **********************
** **  ******  ******  *** *****  *******  *********  ***********************
** *     ***  ******  *** ***       ****  *****      ************************
** 07/05/2024 16:35:08 ******************************************************
** romain.cescutti <romain.cescutti@aldrin.efrits.fr>
** - clickodrome -
** * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
*/

#include "calculator.h"

void swap(char *a,
          char *b)
{
    char c;

    c = *a;
    *a = *b;
    *b = c;
}

char* reverse(char *word, int i, int j)
{
    while (i < j)
      {
        swap(&word[i++], &word[j--]);
      }
    return word;
}

char *efitoa (char * word ,int num)
{
  int tempnum;
  int i;
  i = 0;
  tempnum = num;
  while(tempnum)
    {
      word[i++] = (tempnum % 10) + 48;
      tempnum = tempnum / 10;
    }
  return (reverse(word,0,i - 1));
}

void update_string	(t_gui *gui, void *data)
{
  t_calculator *calc;
  char* buffer;
  buffer = bunny_malloc(128);
  calc = data;
  string_clear(calc->string);
  calc->string = string_new_str((const char*)efitoa(buffer,calc->res));
}
