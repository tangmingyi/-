#include <iostream>
#include <vector>
#include <algorithm>
void initParent(int* parent,int length){
    for(int i=0;i<length;i++){
        scanf("%d",parent);
        parent++;
    }
}
int main(){
    int n,l;
    scanf("%d%d",&n,&l);
    int parent[n];
    initParent(parent,n);
    std::vector<int> nodeLength(n,0);
//    nodeLength[0] = 1;
    for(int i=1;i<n;i++){
        nodeLength[i] = nodeLength[parent[i-1]] + 1;
    }
    auto maxElement = std::max_element(nodeLength.begin(),nodeLength.end());
    if(l<=*maxElement){
        printf("%d",l+1);
    } else{
        printf("%d",std::min(n,(l-*maxElement)/2 + *maxElement + 1));
    }
    return 0;
}
