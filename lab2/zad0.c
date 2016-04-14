#include <stdio.h>

int main()
{
  printf("5&3 = %i\n", 5&3);
  printf("5|3 = %i\n", 5|3);
  printf("7<<2&7 = %i\n", 7<<2&7);
  printf("7<<(2&7) = %i\n", 7<<(2&7));
  printf("((-1)<<8)>>16 = %i\n", ((-1)<<8)>>16);
  printf("13^9 = %i\n", 13^9);
  return 0;
}
