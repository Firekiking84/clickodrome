#include "gui.h"

int main()
{
  t_bunny_configuration *cnf;
  t_gui *gui;
  char *divname;
  char *type;
  int i;
  int j;
  int nbr_divs;
  cnf = bunny_open_configuration(file,NULL);
  if (cnf == NULL)
    {
      puts("Failed to open file");
      return(0);
    }
  gui->conf_file = file;
  i = 0;
  nbr_divs = bunny_configuration_casesf(cnf,"divName");

  efnew_button(cnf,gui,,i)
}
