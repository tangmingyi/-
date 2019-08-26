//
// Created by zb198 on 2019/8/26.
//
#include <iostream>
float core(char* strings,int index, float& kind){
    char current = strings[index];
    float count = 0.0;
    while (current==strings[index]){
        count += 1;
        index++;
    }
    kind += 1.0;
    if(strings[index]=='\0'){
        return count;
    }
    float sum = count+core(strings,index,kind);
    return sum/kind;

}

float core1(char* strings,int index){
    float count = 0.0;
    float sum = 0.0;
    char current = strings[index];
    float kind = 1.0;
    while (strings[index]!='\0'){
        if(strings[index]==current){
            count++;
        } else{
            current = strings[index];
            sum = sum+count;
            kind += 1.0;
            count = 1.0;
        }
        index++;
    }
    return (sum+count)/kind;
}
int main(){
//    char temp[] = "aabbbccaaa";
    char strings[55];
//    float kind = 0.0;
    scanf("%s",strings);
//    strings = temp;
    printf("%.2f",core1(strings,0));
    return 0;
}
