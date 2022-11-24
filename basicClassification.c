#include <stdio.h>
#include "NumClass.h"

int factorial (int n){ //function for factorial calculation
    int fact = 1;
    for(int i = 1 ; i <=n ; i++){
        fact*=i;
    }
    return fact;
}

float my_sqrt(int num){
    float sqt=num/2;   
    float temp=0;
    while(sqt!=temp){ 
	temp=sqt; 
	sqt=(num/temp+temp)/2;
    }
    return sqt;
}

int isPrime(int num ){
    if (num == 0)
        return 0;
    int sqrt= my_sqrt(num);
    for(int i = 2 ; i<=sqrt ; i++){
        if (num % i == 0)
            return 0;
    }
    return 1;
}
int isStrong(int num){
    if(num == 0)
       return 0;
    int original_num = num;
    int sum=0;
    while (num != 0){
        int digit = num%10;
        sum +=factorial(digit);
        num/=10;
    }
    if (sum == original_num){
        return 1;
    }
    return 0;
}
