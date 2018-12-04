#include<stdio.h>
#include<string.h>

int mod_exp(int base, int exp, int n)   //returns (base^exp) modulo n
{
    int i, power = 1; 
    for(i = 0; i < exp; i++)
        power = (power * base) % n; 
    return power;
}

int gcd(int m,int n)    //Highest common factor of m and n
{
    int temp;
    while(1)
    {
        temp = m % n;
        if(temp == 0)
            return(n);
        m = n;
        n = temp;
    }
}

int main() 
{
    int p = 3, q = 11, n, e, phi, d, i, j;
    char data[20]=" ";
    int cipherData[20]={0}, decrData[20];

    n = p * q;
    phi = (p - 1) * (q - 1); 
    e = 2;  //encryptor is a coprime to phi and (1 < e < phi)
    d = 2;  

    //finding encrypot value (e)
    while(e < phi)
    {
        if( gcd(e, phi) == 1)   //co-primes
            break;
        e++; 
    }
    printf("\nValue of e is: %d", e);
 
    //finding decryptor value (d)
    while(d < phi)
    {
        if( ((e * d) % phi) == 1 )  
            break;
        d++;
    } 
    printf("\nValue of d is: %d", d);

    printf("\nEnter a String: "); 
    gets(data);
    printf("\nThe entered string is: %s \n",data); 

    //Encryption at server with Public key (n, e)
    for(i = 0; i < strlen(data); i++) 
    {
        cipherData[i] = mod_exp(data[i], e, n);
        printf("%c = %d\n", data[i], cipherData[i]); 
    }

    //Decryption at Client with Private Key (n, d)
    printf("\nDecrypted string is: ");
    for(i=0;i<strlen(data);i++) 
    {
        decrData[i] = mod_exp(cipherData[i], d, n);
        printf("%c", (char)decrData[i]); 
    }
    printf("\n\n");
    return 0;
}
