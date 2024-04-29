*void			efadd_label_gui(t_gui			*gui,
				    const char			*name,
				    t_bunny_position		pos,
				    t_bunny_size		size,
				    const char			*text,
				    t_bunny_color		*font_color,
				    t_bunny_color		*bg)
{
    size_t count;

  count = 0;
  while(count < gui->divs->data_count)
    {
      add_label_div(efvector_at(gui->divs, count, t_div),name,pos ,size ,text ,font_color ,bg);
      count++;
    }
}
