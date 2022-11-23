#include <stdio.h>
#include "NumClass.h"

int my_pow(int x, int y){
	int xpowy=1;
	if (x == 0 )
		return 0;
	for(int i=1 ; i<=y ;i++){
		xpowy*=x;
	}
	return xpowy;		
}

int length (int n){
    int count = 0;
    while(n != 0){
        count++;
        n/=10;
    }
    return count;
}

int is_ArmstrongRec(int n , int originalLen, int currentLen){
    if(currentLen == 0)
    	return 0;
    return is_ArmstrongRec(n/10 , originalLen , currentLen-1) + my_pow(n%10 , originalLen);		
}
int isArmstrong(int num){
    int len= length(num);
    int sum = is_ArmstrongRec(num , len , len);
    if(sum == num)
    	return 1;
    return 0;	
}

int reversNum(int num , int len){
    if(num == 0)
        return 0;
    return ((num%10 * my_pow(10,len-1)) + reversNum(num/10,len-1));
}

int isPalindrome(int num){	
    int len= length(num);
    int sum = reversNum(num , len);
    if(sum == num)
    	return 1;
    return 0;
}
