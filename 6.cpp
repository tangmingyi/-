//
// Created by zb198 on 2019/8/28.
//
#include <iostream>
#include <string>
#include <map>
bool isLegal(std::string str){
    int n=0;
    int length = str.size();
    for(int i=0;i<length;i++){
        if(str[i]=='('){
            n++;
        } else if(str[i]==')'){
            n--;
            if(n<0){
                return false;
            }
        }
    }
    return n==0;
}
std::string getSubString(std::string* str,int index){
    return str->substr(0,index) + str->substr(index+1,str->size()-index-1);
}
std::string insertString(std::string* str,int index,char insert){
    return str->substr(0,index) + insert + str->substr(index,str->size()-index);
}
int main(){
    std::map<std::string,int> hash;
    std::string str;
    std::cin>>str;
//    str = "(())";
    int n = str.size();
    for(int i=0;i<n;i++){
        std::string temp = getSubString(&str,i);
        for(int j=0;j<n-1;j++) {
            char stri = str[i];
            std::string insert = insertString(&temp,j,stri);
            if (insert != str && isLegal(insert)) {
                hash[insert] = 0;
            }
        }
    }
    std::cout<<hash.size();
    return 0;
}
