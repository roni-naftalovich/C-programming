#include <stdio.h>
#include "NumClass.h"

int power(int base, int exponent) {
    int result = 1;
    for (int i = 1; i <= exponent; i++) {
        result *= base;
    }
    return result;
}

int countDigits(int num) {
    if (num == 0) {
        return 1; // Special case for 0
    }

    int count = 0;
    int temp= num;

    while (temp > 0) {
        temp = temp / 10;
        count++;
    }

    return count;
}

// check if a number is Armstrong with recursion
int isArmstrongRecursive(int num, int n) {
    if (num == 0) {
        return 0;
    }
    return power(num % 10, n) + isArmstrongRecursive(num / 10, n);
}

// Function to check if a number is Armstrong
int isArmstrong(int num) {
     if (num <=0) {
        return 0; // Negative numbers are not considered Armstrong numbers
    }
    int n =countDigits(num); 


    int sum = isArmstrongRecursive(num, n);

    return (sum == num) ? 1 : 0;
}
//check if a number is palindrome number with recursion
int isPalindromeRec(int arr[],int start,int end){
    if(start<end){
        if(arr[start]!=arr[end]){
            return 0;
        }
        else return isPalindromeRec(arr,start+1,end-1);
    }
    return 1;
}



int isPalindrome(int num){
    if (num <0) {
        return 0; // Negative numbers are not considered Palindrome numbers
    }
    int size =countDigits(num);
    int arr [size+1];
    int count=0;
    int numSaver=num;
    while(numSaver>0){
        arr[count]=numSaver%10;
        numSaver=numSaver/10;
        count++;
    }
    return isPalindromeRec(arr,0,count-1);
}
