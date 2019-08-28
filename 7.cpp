//
// Created by zb198 on 2019/8/28.
//
#include <iostream>
#include <vector>
#include <math.h>
void initVector(std::vector<int >& value){
    for(auto Iter = value.begin();Iter!=value.end();Iter++){
        std::cin>>*Iter;
    }
}
void initDp(std::vector<std::vector<int >>& dp, const std::vector<int >& value){
    auto Iter = dp.begin() +2;
    auto IterValue = value.begin() +2;
    for(Iter;Iter!=dp.end();Iter++){
        (*Iter)[0] = (*(Iter-1))[0] + std::abs(*IterValue - *(IterValue-1));
        IterValue++;
    }
}
void fillDp(std::vector<std::vector<int >>& dp, const std::vector<int>& value,int n){
    for(int i=1;i<n;i++){
//        dp[i][i-1] = ;
        for(int j=1;j<i;j++){
           dp[i][j] = dp[i][j-1] + std::abs(value[j]-value[j-1]);

        }
    }
}
int main(){
    int n;
    std::cin>>n;
    std::vector<int > value(n,0);
    std::vector<std::vector<int> > dp(n,std::vector<int >(n,0));
    initVector(value);
    initDp(dp,value);
    fillDp(dp,value,n);
    auto Iter = (*dp.end()).begin();
    int Min = *Iter;
    for(Iter;Iter!=(*dp.end()).end();Iter++){
        if(*Iter<Min){
            Min = *Iter;
        }
    }
    std::cout<<Min;
    return 0;
}

