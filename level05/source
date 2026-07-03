#include <stdio.h>

int main()
{
  char buffer[100];
  unsigned int i;

  i = 0;
  fgets(buffer, 100, stdin);
  for ( i = 0; i < strlen(buffer); ++i )
  {
    if ( buffer[i] > 64 && buffer[i] <= 90 )
      buffer[i] ^= 32;
  }
  printf(buffer);
  exit(0);
}