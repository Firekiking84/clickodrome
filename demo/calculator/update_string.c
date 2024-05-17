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

#include	"calculator.h"

static void	swap(char		*a,
		     char		*b)
{
    char	c;

    c = *a;
    *a = *b;
    *b = c;
}

static char*	reverse(char		*word,
			int		i,
			int		j)
{
  while (i < j)
    swap(&word[i++], &word[j--]);
  return word;
}

static char	*efdtoa(char		*word,
			double		num)
{
  double	dtempnum;
  int		tempnum;
  int		i;

  if (num == 0)
    {
      word[0] = '0';
      word[1] = '\0';
      return(word);
    }
  i = 0;
  tempnum = fabs(num);
  dtempnum = fabs(num);
  dtempnum -= tempnum;
  while(tempnum)
    {
      word[i++] = (tempnum % 10) + 48;
      tempnum = tempnum / 10;
    }
  if (num < 0)
    word[i++] = '-';
  word = reverse(word, 0, i - 1);
  if (dtempnum == 0)
    {
      word[i] = '\0';
      return(word);
    }
  word[i++] = ',';
  printf("%f\n",dtempnum);
  while(dtempnum > 0.000001)
    {
      printf("%f\n",dtempnum);
      dtempnum *= 10;
      tempnum = dtempnum;
      word[i++] = (tempnum % 10) + 48;
      dtempnum -= tempnum;
    }
  word[i] = '\0';
  return (word);
}

void		update_string(t_calculator *cal)
{
  char		buffer[128];

  string_delete(cal->string);
  cal->string = string_new_str((const char*)efdtoa(buffer, cal->buffer));
}
