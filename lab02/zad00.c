// Jakie będą wyniki następujących działań?
// a.5&3
// b.5|3
// c.7<<2&7
// d.7<<(2&7)
// e.((-1)<<8)>>16
// f.13^9

#include <stdio.h>

int main()
{
  printf("A. 5&3 = %i\n", 5&3);
  printf("B. 5|3 = %i\n", 5|3);
  printf("C. 7<<2&7 = %i\n", 7<<2&7);
  printf("D. 7<<(2&7) = %i\n", 7<<(2&7));
  printf("E. ((-1)<<8)>>16 = %i\n", ((-1)<<8)>>16);
  printf("F. 13^9 = %i\n", 13^9);
}
