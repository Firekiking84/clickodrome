t_div		*efadd_timer_div(t_div				*div,
				 const char				*name,
				 const char				*text,
				 t_vector				*functions)
{
  efvector_push(div->timer, efnew_timer(name ,texte ,functions));
}
