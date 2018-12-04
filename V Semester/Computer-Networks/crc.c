#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#define lenKey strlen(key)

char Tdata[128], checkSum[128], key[] = "10001000000100001";
int lenTdata;

void xor()
{
    int i;
    for(i = 0; i < lenKey; i++)
        checkSum[i] = checkSum[i] == key[i] ? '0' : '1';
}
void crc() //Modulo 2 Division
{
    int i, j;

    for(i = 0; i < lenKey; i++)
        checkSum[i] = Tdata[i];

    while(i < lenTdata + lenKey)
    {
        if(checkSum[0] == '1')
            xor();

        for(j = 0; j < (lenKey - 1); j++)
            checkSum[j] = checkSum[j + 1];

        checkSum[j] = Tdata[i++];
    }
}

int main()
{
    int i, input;

    printf("\n\nEnter Tramsmission Data: ");
    scanf("%s",Tdata);
    lenTdata = strlen(Tdata);
    printf("Generator Polynomial is: %s",key);

    for(i = lenTdata; i < (lenTdata + lenKey - 1); i++)
        Tdata[i] = '0';

    crc();
    for(i = lenTdata; i < (lenTdata + lenKey - 1); i++)
        Tdata[i] = checkSum[i - lenTdata];
    printf("\nCode Word is: %s",Tdata);

    printf("\nTest Error Detection? yes(1) or no(0): ");
    scanf("%d",&input);
    if(input == 1)    //Yes
    {
        printf("\nEnter Postion to enter the error: ");
        scanf("%d",&i);
        Tdata[i] = Tdata[i] == '1'? '0' : '1';      //Tdata manipulated
        printf("\nData Recieved at reciever (With Error): %s",Tdata);
    }

    crc();

    for(i = 0; i < lenKey - 1; i++)     //check if the checksum is all 0's
        if(checkSum[i] == '1')      //if '1' in any digit .. error detected
        {
            printf("\n\nError Detected ;( \n\n");
            exit(0);
        }

    printf("\n\nNo Error Detected!!\n\n");
    return(0);
}
