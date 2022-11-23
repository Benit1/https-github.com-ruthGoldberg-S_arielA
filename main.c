#include <stdio.h>
#include "NumClass.h"


int main() {
    int num1,num2;
    printf("please enter two numbers :");
    scanf("%d %d \n" , &num1,&num2);

    printf("The Armstrong numbers are:");
    for(int i = num1 ; i<=num2 ; i++){
    	int armstrong=isArmstrong(i);
    	if(armstrong ==1 ){
        	printf( "%d" ,i);
        }
    }
	
    printf("\n The Palindromes are:");
    for(int i = num1 ; i<=num2 ; i++){
    	int palindrom = isPalindrome(i);
    	if(palindrom == 1){
        	printf(" %d" ,i);
        }
    }
    printf("\n The Prime numbers are:");
    for(int i = num1 ; i<=num2 ; i++){
        int prime = isPrime(i);
    	if(prime == 1){
        	printf(" %d" ,i);
        }
    }
    
    printf("\n The Strong numbers are:");
    for(int i = num1 ; i<=num2 ; i++){
        int strong = isStrong(i);
    	if(strong == 1){
        	printf(" %d" ,i);
        }
    }
}
