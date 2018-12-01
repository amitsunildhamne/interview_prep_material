#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int my_printf(char *str)
{
  int len = strlen(str);
  write(1, str, len);
  return 0;
}

int main(int argc, char *argv[])
{
  if (argc<2)
  {
    char error[] = "Usage: ./printf blah blah\n";
    my_printf(error);
    exit(1);
  }
  my_printf(argv[1]);
  return 0;
}
