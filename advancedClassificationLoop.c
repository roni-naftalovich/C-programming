#include <stdio.h>
#include "NumClass.h"

int isArmstrong(int num){
    if(num<=0){
        return 0;
    }
    int currentNum= num;
    int sum=0;
    while (currentNum!=0)
    {
        int digit= currentNum%10;
        sum+= digit*digit*digit;
        currentNum= currentNum/10;
    }
    if(sum==num){
    return 1;
    }
return 0;
}

int isPalindrome(int num){
    if(num<0){
        return 0;
    }
    if(num==0){
        return 1;
    }
     int originalNum = num;
     int oppositeNum = 0;

    while (num > 0) {
        int digit = num % 10;
        oppositeNum = oppositeNum * 10 + digit;
        num /= 10;
    }

   
    return (oppositeNum == originalNum) ? 1 : 0; 
}