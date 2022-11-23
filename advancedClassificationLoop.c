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

int isArmstrong(int num){
	int original_num = num;
    int sum=0;
    int len = length(num);
    while (num != 0){
        int digit = num%10;
        sum +=my_pow(digit,len);
        num/=10;
    }
    if (sum == original_num){
        return 1;
    }
    return 0;
}

int isPalindrome(int num){
    int remain, reversed=0;
    int same_num = num;
    while(num!=0){
        remain = num%10;
        reversed += remain;
		if(num < 10)
			break;
		reversed*=10;
        num/=10;
    }
    if (reversed == same_num){
        return 1;
    }
    return 0;

}
