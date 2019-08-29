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
void initDp(std::vector<std::vector<int >>& dp, const std::vector<int >& value,int n){
    auto Iter = dp.begin() +2;
    auto IterValue = value.begin() +2;
    for(Iter;Iter!=dp.end();Iter++){
        (*Iter)[0] = (*(Iter-1))[0] + std::abs(*IterValue - *(IterValue-1));
        IterValue++;
    }
    dp[2][1] = std::abs(value[1]-value[0]);
    for(int i=3;i<n;i++){
        dp[i][i-1] = dp[i-1][i-2] + std::abs(value[i-1]-value[i-2]);
    }
}
void fillDp(std::vector<std::vector<int >>& dp, const std::vector<int>& value,int n){
    for(int i=2;i<n;i++){
//        dp[i][i-1] = dp[i-1][i-2] + std::abs(value[i]-value[i-2]);
        for(int j=0;j<i-1;j++){
           dp[i][j] = dp[i-1][j] + std::abs(value[i]-value[i-1]);
           dp[i][i-1] = std::min(dp[i][i-1],dp[i-1][j] + std::abs(value[j]-value[i]));
        }
    }
}
int main(){
    int n;
    std::cin>>n;
//    n = 8;
    std::vector<int > value(n,0);
    std::vector<std::vector<int> > dp(n,std::vector<int >(n,0));
    initVector(value);
    initDp(dp,value,n);
    fillDp(dp,value,n);
    auto listIter = dp[n-1].begin();
    int Min = *listIter;
    for(listIter;listIter!=dp[n-1].end()-1;listIter++){
        if(*listIter<Min){
            Min = *listIter;
        }
    }
    std::cout<<Min;
    return 0;
}

