# Documentation for users

Gui is a structure that can be pass in parameter of member function to create, edit or delete gui component.

There is for the moment a few sub component like div which is the division that manage its components and can have a dynamic librairy.

Each component has a settings structure which contains all the parameters of the objects. All structure is describe bellow.

## How get it work

You need to create a t_gui structure with the functions below. If there is a configuration file or not you need to respect a structure.

Gui contains divs that contains buttons, textbox, picture box and else. But gui cannot contains button or any else component.

If you add a component not in a div in the dabsic file you will get an error or a nun-functionnal script.
You can find example of dabsic file in the demo or in the directory doc with the file example.dab.

## Warning

All pointers of the settings structure need to be allocate with bunny_malloc. And you must not free them.

They will be free by the destruction of the elements by calling the function ```efdelete_gui```.

## Gui

### Management :
- **efnew_gui**(```const char *file```) : Create a new t_gui * from a dabsic file
- **efdelete_gui**(```t_gui *gui```) : Delete a gui and all its components

### Usage functions :
- **efevent_gui**(```t_bunny_event const *event, t_gui *gui```) : manage event given in parameters
- **efrefresh_gui**(```t_gui *gui```) : refresh the timers composants
- **efdisplay_gui**(```t_gui *gui, t_bunny_pixelarray```) : display all composants in the pixelarray given in parameter

### Edition functions :
- **efedit_[```object_name```]_gui**(```t_gui *gui, const char *div_name, t_[*object_name*]_settings const *edit) : Edit the settings of an object. All value equal to -1 or Null are not edit
- **efdel_gui**(```t_gui *gui, const char *div_name, const char *object_name```) : delete the component with the given in parameter if this object is in the div with the name div_name
- **efadd_[```object_name```]_gui**(```t_gui *gui, const char *div_name, t_[*object_name*]_settings const *add```) : Create a new component and put it in the div with the name div_name

### Div

je ne sais pas quoi metre !!!!

### Settings:

 - ```pos(t_bunny_position)``` : x ,y and z positions of the button.
 - ```size(t_bunny_size)``` : x and y size of the button.
 - ```lib(t_lib)``` : library.
 - ```data(void *)``` : structure of user.
 - ```init_func(t_vector_ptr *)``` : different components below.

## Sub Components and settings structs

### Button

Button is a text area that can only be edit by gui.

#### Settings :
 - ```pos(t_bunny_position)``` : x ,y and z positions of the button.
 - ```size(t_bunny_size)``` : x and y size of the button.
 - ```name(char *)``` : name to id it for by example edit it or delete it.
 - ```text(char *)``` : text that will be display.
 - ```font(t_bunny_pixelarray *)``` : pixelarray of the font use to print the text.
 - ```font_size(t_bunny_size)``` : x and y size of the font use to print the text.
 - ```font_color(t_bunny_color *)``` : color of the font.
 - ```bg(t_bunny_color *)``` : background of the button. If null there is no background.
 - ```hover_color(t_bunny_color)``` : teint of color to button. can dose't exist.
 - ```function(t_vector_ptr *)``` : pointer storage function.

### Label

Label is a text area that can only be edit by gui.

#### Settings :
 - ```pos(t_bunny_position)``` : x and y positions of the label.
 - ```size(t_bunny_size)``` : x and y size of the label.
 - ```name(char *)``` : name to id it for by example edit it or delete it.
 - ```text(char *)``` : text that will be display.
 - ```font(t_bunny_pixelarray *)``` : pixelarray of the font use to print the text.
 - ```font_size(t_bunny_size)``` : x and y size of the font use to print the text.
 - ```font_color(t_bunny_color *)``` : color of the font.
 - ```bg(t_bunny_color *)``` : background of the label. If null there is no background.

### Text_Box

Text_Box is a text area that can only be edit by gui.

#### Settings :
 - ```pos(t_bunny_position)``` : x and y positions of the Text_box.
 - ```size(t_bunny_size)``` : x and y size of the text_box.
 - ```name(char *)``` : name to id it for by example edit it or delete it.
 - ```font(t_bunny_pixelarray *)``` : pixelarray of the font use to print the text.
 - ```font_size(t_bunny_size)``` : x and y size of the font use to print the text.
 - ```font_color(t_bunny_color *)``` : color of the font.
 - ```bg(t_bunny_color *)``` : background of the text_box. If null there is no background.
 - ```function(t_vector_ptr *)``` : pointer storage function.

### Picture

Picture is a text area that can only be edit by gui.

#### Settings :
 - ```pos(t_bunny_position)``` : x and y positions of the picture.
 - ```size(t_bunny_size)``` : x and y size of the picture.
 - ```name(char *)``` : name to id it for by example edit it or delete it.
 - ```filename(char *)``` : name of file of the picture.

### Timer

Timer is a text area that can only be edit by gui.

#### Settings :
 - ```name(char *)``` : name to id it for by example edit it or delete it.
 - ```delay(char *)``` : last use to timer,  into second.
 - ```function(t_vector_ptr *)``` : : pointer storage function.
