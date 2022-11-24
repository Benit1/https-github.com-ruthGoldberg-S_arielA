#include <stdio.h>
#include "NumClass.h"

int my_pow(int x, int y){ //function for power calculation
	int xpowy=1;
	if (x == 0 )
		return 0;
	for(int i=1 ; i<=y ;i++){
		xpowy*=x;
	}
	return xpowy;		
}

int length (int n){//function for length number calculation
    int count = 0;
    while(n != 0){
        count++;
        n/=10;
    }
    return count;
}

int is_ArmstrongRec(int n , int originalLen, int currentLen){ //the recursive function of the armstrong
    if(currentLen == 0)
    	return 0;
    return is_ArmstrongRec(n/10 , originalLen , currentLen-1) + my_pow(n%10 , originalLen);		
}
int isArmstrong(int num){ //the original function of the armstrong
    int len= length(num);
    if(len == 1)
       return 1;
    int sum = is_ArmstrongRec(num , len , len);
    if(sum == num)
    	return 1;
    return 0;	
}

int reversNum(int num , int len){ //the recursive function of the palindrome - reversing the number
    if(num == 0)
        return 0;
    return ((num%10 * my_pow(10,len-1)) + reversNum(num/10,len-1));
}

int isPalindrome(int num){ //the original function of the palindrome
    int len= length(num);
    if(len == 1)
       return 1;
    int sum = reversNum(num , len);
    if(sum == num)
    	return 1;
    return 0;
}
