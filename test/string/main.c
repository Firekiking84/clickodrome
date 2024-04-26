#include		"efstring.h"

#include		<string.h>
#include		<assert.h>

int			main(void)
{
  t_string		*str1;
  t_string		*str2;
  t_string		*str3;
  int			i;

  str1 = string_new();
  assert(!str1->str);
  assert(str1->size_alloc == 0);
  assert(str1->str_len == 0);
  string_push_back(str1, 'c');
  assert(string_get_char(str1, 0) == 'c');
  string_append_str(str1, "UnCauchemar");
  assert(strcmp(string_get_content(str1), "cUnCauchemar") == 0);
  str2 = string_new_str("JteJure");
  string_append_string(str1, str2);
  str3 = string_new_string(str1);
  assert(string_compare(str1, str3) == 0);
  string_erase(str2, 3);
  assert(string_compare_str(str2, "Jteure") == 0);
  assert(str2->str_len == strlen("Jteure"));
  assert(str2->size_alloc == (strlen("JteJure") + 1));
  string_pop_back(str2);
  assert(string_compare_str(str2, "Jteur") == 0);
  string_shrink_to_fit(str2);
  assert(str2->size_alloc == (str2->str_len + 1));
  string_clear(str2);
  assert(string_get_len(str2) == 0);
  i = 0;
  while (i < 100)
    {
      string_push_back(str2, 'a');
      i += 1;
    }
  assert(string_get_len(str2) == 100);
  string_clear(str1);
  assert(string_append_str(str1, "0123456789abcdefghijklmnopqrstuvwxyz") != -1);
  assert(string_append_string(str1, str2) != -1);
  assert(string_get_len(str1) == 100 + strlen("0123456789abcdefghijklmnopqrstuvwxyz"));
  string_delete(str1);
  string_delete(str2);
  string_delete(str3);
}
