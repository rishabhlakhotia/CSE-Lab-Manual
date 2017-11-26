#include<stdio.h>
void main(){
  char STR1[100],STR2[100],STR3[100];
  int i=0,j=0,count=0;

  //READING STR1 AND STR2
  printf("Enter the String 1\n");
  gets(STR1);
  printf("Enter the String 2\n");
  gets(STR2);

  //COPY STR1 TO STR3
  while(STR1[i]!='\0'){
    STR3[count]=STR1[i];
    i++;
    count++;
  }
  //INSERT BLANK SPACE BETWEEN STR1 AND STR2
  STR3[count++]=' ';

  //COPY STRING STR2 TO STR3 FROM THE LOCATION count
  while(STR2[j]!='\0'){
    STR3[count]=STR2[j];
    count++;
    j++;
  }
  //END OF String
  STR3[count]='\0';
  //PRINTING OF STRINGS STR1,STR2,STR3
  printf("\nString STR1=\t");
  puts(STR1);
  printf("\nString STR2=\t");
  puts(STR2);
  printf("\nString STR3=\t");
  puts(STR3);

}
