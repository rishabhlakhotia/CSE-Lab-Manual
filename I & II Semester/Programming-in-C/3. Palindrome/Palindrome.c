#include <stdio.h>
void main(){
  int n,rev=0,temp,digit;
  printf("Enter an integer number\n");
  scanf("%d",&n);
  temp=n;
  while(n!=0){
    digit=n%10;
    rev=rev*10+digit;
    n=n/10;
  }
  printf("Given number is: %d\n",temp);
  printf("It's reverse is:%d\n",rev);
  if(rev==temp)
    printf("The number is a palindrome\n");
  else
    printf("The number is not a palindrome\n");
}
