#include<stdio.h>

int main(void){
  int N, a, b, c, cn = 0;
  scanf("%d", &N);
  while(N--){
    scanf("%d %d %d", &a, &b, &c);
    printf("Case %d: %s\n", ++cn, a <= 20 && b <= 20 && c <=20 ? "good" : "bad");
  }
  return 0;
}
