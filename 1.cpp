#include <iostream>
#include <stack>

int main() {
    int n;
    std::stack<char> printStrack;
    scanf("%d",&n);
    while(n!=0){
        if(!(n&1)){
            printStrack.push('2');
            n = (n-2)>>1;
        } else{
            printStrack.push('1');
            n = (n-1)>>1;
        }
    }
    while (!printStrack.empty()){
        printf("%c",printStrack.top());
        printStrack.pop();
    }
}
