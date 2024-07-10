#include<iostream>
using namespace std;
void move(int n, string src , string dst){
    cout<< n << "号盘从位置"<< src<<"移动到"<<dst<<endl;
}
/**
 * n: n号盘子
 * src：从src
 * dst：放到B
 * min:借助
 */
void hanoi(int n, string src, string dst, string mid){
    if(n==1){
        move(n, src, dst);
        return;
    }else{
        hanoi(n-1, src, min, dst);
        move(n, src, dst);
        hanoi(n-1, min, dst, src);
        return;
    }
}

void main(int argc, char** argv){
    int n=1;
    hanoi(n,"左","中","右");
    return;
}