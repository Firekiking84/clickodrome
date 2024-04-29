int		mult_arrondi(int		x,
			     int		mult,
			     int		mode) // -1 = à l'inférieur 0 = au plus proche 1 = au supérieur
{
  int		delta;

  delta = x % mult;
  if ((mode != 1) && (mode == -1 || delta < (mult / 2)))
    x -= delta;
  else
    x += (mult - delta);
  return(x);
}
