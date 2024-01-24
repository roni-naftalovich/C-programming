#include <stdio.h>
#include "NumClass.h"



int main() {
   
   int x1,x2;
   scanf("%d",&x1);
   scanf("%d",&x2);
   if(x1>x2){
       int temp=x1;
       x1=x2;
       x2=temp;
   }
   printf("The Armstrong numbers are:");
   for(int i=x1;i<=x2;i++)
   {
       if(isArmstrong(i)==1){
           printf(" %d",i);
       }
   }
   printf("\n");
    printf("The Palindromes are:");
    for(int i=x1;i<=x2;i++)
   {
       if(isPalindrome(i)==1){
           printf(" %d",i);
       }
   }
   printf("\n");
   printf("The Prime numbers are:");

   for(int i=x1;i<=x2;i++)
   {
       if(isPrime(i)==1){
           printf(" %d",i);
       }
   }
   printf("\n");
    
      printf("The Strong numbers are:");

    for(int i=x1;i<=x2;i++)
   {
       if(isStrong(i)==1){
           printf(" %d",i);
       }
   }
   printf("\n");
    
}