#include<stdio.h>
struct employee{
  int eid,eage;
  char ename[20];
  float esal;
};
struct employee e[50];
void main(){
  int n,i;

  //Read number of employees
  printf("Enter the number of Employees: ");
  scanf("%d",&n);
  //Read details of n- Employees
  for(i=0;i<n;i++){
    printf("\nEnter the details of Employee: %d\n",i+1);
    printf("Enter eid ");
    scanf("%d",&e[i].eid);
    printf("Enter ename ");
    scanf("%s",&e[i].ename);
    printf("Enter eage ");
    scanf("%d",&e[i].eage);
    printf("Enter esal ");
    scanf("%f",&e[i].esal);
  }
  //Display the details
  printf("\n************************************************\n");
  printf("\nDetails of %d Employees are as follows\n",n);
  printf("\n************************************************\n");
  printf("\nEmpid\tEmpname\tEmpage\tEmpsal\n");
  printf("\n------------------------------------------------\n");
  for(i=0;i<n;i++){
    printf("\n%d\t%s\t%d\t%f",e[i].eid,e[i].ename,e[i].eage,e[i].esal);
  }
  printf("\n------------------------------------------------\n");
}
