#include<iostream>
using namespace std;
void move(int n, string src , string dst){
    cout<< n << "号盘从位置"<< src<<"移动到"<<dst<<endl;//移动过程
}
/**
 * n: n号盘子
 * src：从src
 * dst：放到B
 * min:借助
 */
void hanoi(int n, string src, string dst, string mid){
    if(n==1){
        move(n, src, dst);//base case
        return;
    }else{
        hanoi(n-1, src, mid, dst);//将前n-1个盘子借助dst，放到mid
        move(n, src, dst);
        hanoi(n-1, mid, dst, src);//将前n-1个盘子借助src，放到dst
        return;
    }
}

void main(int argc, char** argv){
    int n=3;
    hanoi(n,"左","中","右");
    return;
}