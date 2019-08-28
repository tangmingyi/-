//
// Created by zb198 on 2019/8/28.
//
#include <iostream>
#include <vector>
bool result(int n){
    int num;
    int num4 =0;
    int num2 =0;
    int num3 = 0;
    for(n;n!=0;n--){
        scanf("%d",&num);
        if(num%4==0){
            num4++;
        } else if(num%2==0){
            num2++;
        } else {
            num3++;
        }
    }
    if(num2){
        num3++;
    }
    return (num3-num4)<=1;
}
int main(){
    int rows,n;
    scanf("%d",&rows);
    for(rows;rows!=0;rows--){
        scanf("%d",&n);
        if(result(n)){
            std::cout<<"Yes"<<std::endl;
        } else{
            std::cout<<"No"<<std::endl;
        }
    }
    return 0;
}

