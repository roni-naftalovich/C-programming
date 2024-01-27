#include <stdio.h>
#include "NumClass.h"

int main(){
    int num1, num2;

    scanf("%d", &num1);
    scanf("%d", &num2);

    if(num1>num2){
        int temp= num1;
        num1=num2;
        num2=temp;
    }

    int i;
    
    printf("The Armstrong numbers are:");
    for (i = num1; i <= num2; i++)
    {
        if (isArmstrong(i) == 1){
            printf(" %d", i);
        }
    }

    printf("\nThe Palindromes are:");
    for (i = num1; i <= num2; i++)
    {
        if (isPalindrome(i) == 1){
            printf(" %d", i);
        }
    }

    printf("\nThe Prime numbers are:");
    for (i = num1; i <= num2; i++)
    {
        if (isPrime(i) == 1){
            printf(" %d", i);
        }
    }

    printf("\nThe Strong numbers are:");
    for (i = num1; i <= num2; i++)
    {
        if (isStrong(i) == 1){
            printf(" %d", i);
        }
    }
    printf("\n");
}
