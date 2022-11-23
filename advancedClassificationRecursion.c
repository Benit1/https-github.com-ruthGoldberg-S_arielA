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
	int same_num = num;
    int len= length(num);
    int sum = 0;
   if (num ==0){
       return 0;
   }
   sum=(my_pow(num%10,len) +isArmstrong(num/10));
   if(sum == same_num){
       return 1;
   }
    return 0;
}

int isPalindrome(int num){
	int same_num = num;
        int digit;
        int reversed=0;
        if(num=0) {
            return 0;
        }
        digit=num%10;
        reversed=(reversed * 10 + digit )+isPalindrome(num/10);
        if(reversed ==same_num) {
            return 1;
        }
    return 0;
}
