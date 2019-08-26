//
// Created by zb198 on 2019/8/26.
//
#include <iostream>
int verserNum(int num){
    int sum = 0;
    while(num!=0){
        int lastNum = num%10;
        sum = sum*10 + lastNum;
        num = num/10;
    }
    return sum;
}
int main(){
    int num;
    scanf("%d",&num);
    printf("%d",num+verserNum(num));
    return 0;
}

