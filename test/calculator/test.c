#include <stdio.h>

static void swap(char *a,
          char *b)
{
    char c;

    c = *a;
    *a = *b;
    *b = c;
}

static char* reverse(char *word, int i, int j)
{
    while (i < j)
      {
        swap(&word[i++], &word[j--]);
      }
    return word;
}

static char *efitoa (char * word ,int num)
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

static char *efdtoa (char * word ,double num)
{
  double dtempnum;
  int tempnum;
  int i;
  i = 0;
  tempnum = num;
  dtempnum = num;
  dtempnum -= tempnum;
  while(tempnum)
    {
      word[i++] = (tempnum % 10) + 48;
      tempnum = tempnum / 10;
    }
  word = reverse(word,0,i - 1);
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
  return (word);
}

int main()
{
  double buh;
  char buffer[128];
  buh = 839.421;
  puts(efdtoa(buffer,buh));
}
