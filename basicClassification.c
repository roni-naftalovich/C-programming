#include <stdio.h>
#include "NumClass.h"

int isPrime(int num)
{
    if (num<=0){
    return 0;
    } else if(num==1 || num==2|| num==3){
        return 1;
    }else{
    for(int i=2; i * i <=num; i++){
        if (num%i ==0)
        return 0;

    }}
    return 1;
}

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int isStrong (int num){
    if (num<=0)
    return 0;
  int originalNum = num;
  int sum = 0;

    while (num > 0) {
        int digit = num % 10;
        sum += factorial(digit);
        num /= 10;
    }

    return (sum == originalNum) ? 1 : 0;
}

