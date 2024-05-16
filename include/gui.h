#ifndef			__GUI_H__

#define			__GUI_H__

#include		"lib.h"
#include                "vector_ptr.h"
#include		"div.h"

#include                <dlfcn.h>

typedef	enum		e_type
  {
    BUTTON = 0,
    TEXTBOX,
    PICTURE,
    TIMER,
    LABEL
  }			t_type;

typedef struct		s_font
{
  char			*name;
  t_bunny_pixelarray	*px;
}			t_font;

typedef struct		s_component
{
  t_type		type;
  union
  {
    t_button		*button;
    t_text_box		*textbox;
  };
}			t_component;

typedef struct		s_gui
{
  t_bunny_size		screen_size;
  t_vector_ptr		*components; // ce vecteur devra contenir uniquement des t_component
  t_component		*focus_element; // contient l'élément qui a le focus
  int			index_focus; // représente l'index actuel de l'élément focus dans le vecteur
  t_vector_ptr          *libs;  // ce vecteur contenir les liens avec dlsym;
  t_vector_ptr		*divs;  // ce vecteur devra contenir uniquement des t_div
  t_vector_ptr		*fonts; // ce vecteur devra contenir uniquement des noms de font
  int			nb_input_components;
  bool			is_end;
}			t_gui;

t_gui			*efnew_gui(const char				*file);
void			efdelete_gui(t_gui				*gui);
void			efload_conf_gui(t_gui				*gui);

//void			efinteract_gui(t_gui				*ck,
//				       const char			*type,
//				       const char			*div_name,
//				       const char			*obj_name,
//				       ...);

void			efevent_gui(t_bunny_event const			*event,
				    void				*data);
void			efrefresh_gui(t_gui				*gui);
void			efdisplay_gui(t_gui				*ck,
				      t_bunny_pixelarray		*px);
int			efadd_button_cnf(t_bunny_configuration		*cnf,
					 t_gui				*gui);
int			efadd_label_cnf(t_bunny_configuration		*cnf,
					t_gui				*gui);
int			efadd_picture_cnf(t_bunny_configuration		*cnf,
					  t_gui				*gui);
int			efadd_text_box_cnf(t_bunny_configuration	*cnf,
					   t_gui			*gui);
int			efadd_timer_cnf(t_bunny_configuration		*cnf,
					t_gui				*gui);
int			efadd_div_cnf(t_bunny_configuration	        *cnf,
				      t_gui				*gui);
t_bunny_color		*efget_color_cnf(t_bunny_configuration		*cnf,
					char				*name);
t_bunny_position	efget_pos_cnf(t_bunny_configuration		*cnf);
t_bunny_size		efget_size_cnf(t_bunny_configuration		*cnf,
				       char const			*elem);
t_div			*efget_div_cnf(t_bunny_configuration		*cnf,
				       t_gui				*gui);
t_type			efcomp_type(const char*				str);
t_vector_ptr		*efget_functions(t_bunny_configuration		*cnf,
					 t_gui				*gui);
void                    eftype_func(t_bunny_configuration               *comp,
				    t_gui                               *gui);
void			efedit_button_gui(t_gui				*gui,
					  const char			*div_name,
					  t_button_settings		*edit);
void			efedit_label_gui(t_gui				*gui,
					 const char			*div_name,
					 t_label_settings		*edit);
void			efedit_textbox_gui(t_gui			*gui,
					   const char			*div_name,
					   t_textbox_settings		*edit);
void			efedit_picture_gui(t_gui			*gui,
					   const char			*div_name,
					   t_picture_settings		*edit);
void			efedit_timer_gui(t_gui				*gui,
					 const char			*div_name,
					 t_timer_settings		*edit);
void			efadd_button_gui(t_gui				*gui,
					 const char			*div_name,
					 t_button_settings		*add);
void			efadd_label_gui(t_gui				*gui,
					const char			*div_name,
					t_label_settings 		*add);
void			efadd_textbox_gui(t_gui				*gui,
					  const char			*div_name,
					  t_textbox_settings		*add);
void			efadd_picture_gui(t_gui				*gui,
					  const char			*div_name,
					  t_picture_settings		*add);
void			efadd_timer_gui(t_gui				*gui,
					const char			*div_name,
					t_timer_settings		*add);
void			efdelete_elem_gui(t_gui				*gui,
					  const char			*div_name,
					  const char			*elem_name);
t_div			*get_div_by_name(t_gui				*gui,
					 const char			*div_name);
void			stop_program(t_gui				*gui);
t_bunny_response	manage_continue(t_gui				*gui);
t_bunny_pixelarray	*is_font_already_load(const char		*tmp,
					      t_gui			*gui);

#endif //		__GUI_H__
