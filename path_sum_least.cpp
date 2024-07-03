
#include<iostream>

/**
 * n维数组，只能从左上角开始向右或者向下走，直到走到右下角
 * 寻找路径权重最短的结果
 */
//1.解体思路暴力递归 min 最小
//2.使用矩阵
const MAX_INT = numeric_limites<int>::max();
int path_sum_least(int[][] arr, int a,int b, int lx, int ly){
    int array[lx][ly]={MAX_INT};
    array[0][0] = arr[0][0];
    for(int i = 1;i<lx;i++){
        array[i][0] = array[i-1][0]+arr[i][0];
    }
    for(int i = 1;i<ly;i++){
        array[0][i] = array[0][i-1]+arr[0][i-1];
    }

    for(int i =1;i<lx;i++){
        for(int j =1;j<ly;j++){
            array[i][j] = min(array[i-1][j] , array[i][y-1])+ arr[i][y];
        }
    }

    return array[lx-1][ly-1]

}

int main(int argc, char** argv){


    return 0;
}