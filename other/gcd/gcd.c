#include <stdio.h>

int gcd(int m, int n){
  if( n )
    return gcd(n, m%n);
  else
    return m;
}

int main(int argc, char *argv[]){
  int i;

  printf("GCD(%d, %d) = %d yays\n", 15,5,gcd(15,5));
  return 0;
}