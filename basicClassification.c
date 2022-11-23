#include <stdio.h>
#include "NumClass.h"

int factorial (int n){
    int fact = 1;
    for(int i = 1 ; i <=n ; i++){
        fact*=i;
    }
    return fact;
}

int isPrime(int num ){
    for(int i = 2 ; i<num ; i++){
        if (num % i == 0){
            return 0;
        }
    }
    return 1;
}
int isStrong(int num){
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
