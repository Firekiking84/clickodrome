#include		    "efstring.h"

static void                 calc_len(int                                        *fin,
                                     int                                        *p10,
                                     int                                        nbr2)
{
    int                     fint;
    int                     p10t;

    fint = *fin;
    p10t = *p10;
    while (nbr2 / p10t >= 10)
    {
        fint ++;
        p10t = p10t * 10;
    }
    *p10 = p10t;
    *fin = fint;
}

static char			*negative_and_append_base10(t_setting		*setting,
							    int			*nbr,
							    char		*decimal)
{
  setting->chiffre = 10;
  setting->i = 0;
  setting->fin = 0;
  setting->p10 = 1;
  if (*nbr < 0)
    {
      decimal[0] = '-';
      *nbr *= -1;
      setting->i = 1;
      setting->fin = 1;
    }
  return(decimal);
}

int				convert_integer(int				nbr,
						char				*decimal)
{
  t_settings			setting;

  decimal = negative_and_append_base10(&setting , &nbr, decimal);
  setting->nbr2 = nbr;
  calc_len(&setting.fin, &setting.p10, setting.nbr2);
  setting.i --;
  while (setting.i < setting.fin)
    {
      if (setting.chiffre <= 9)
	decimal[i] = (setting.chiffre + 48);
      setting.chiffre = setting.nbr2 / setting.p10;
      setting.nbr2 = setting.nbr2 % setting.p10;
      setting.p10 = setting.p10 / 10;
      setting.i ++;
    }
  decimal[setting.i] = ((nbr % 10) + 48);
  decimal[++setting.i] = '\0';
  return (setting.i);
}
