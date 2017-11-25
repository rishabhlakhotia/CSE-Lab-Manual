#include<stdio.h>
int isprime(int);//functon prototype
void main(){
  int n1,n2,r,i;
  printf("Enter the range n1 and n2 to find prime numbers\n");
  scanf("%d%d",&n1,&n2);//read the inputs
  printf("The prime numbers between %d and %d are\n",n1,n2);
  for(i=n1;i<=n2;i++){

    r=isprime(i);//functon call
    if(r==1){
      printf("%d\t",i);
    }
  }
}
int isprime(int x){
  int i,c=0;
  for(i=1;i<=x;i++){
    if(x%i==0){//check if number is completely divisible
      c++;
    }
  }
  if(c==2)//check if number is divisible by 1 and itself
    return (1);
  else
    return (0);
}
