


#include <iostream>
#include<limites>

using namespace std;

long MAX_VALUE = numeric_limites<int64_t>::max();

/**
 * 有n种币值纸币，且每种币值张数不限
 * 给定目标：target，寻找最小张数解
 */

//length为数组长度
int64_t get_last_B(int* array, int idx, int length, int target){
    if(idx==length) return MAX_VALUE;
    int ans = MAX_VALUE;
    for(int zhang=0; array[idx]*zhang<=target;zhang++){//这个是个递增累加
        int next = get_last_B(array, idx+1, length, target-array[idx]);
        ans = min(ans, next+zhang);//张数最小值
    }
    return ans;
}




int main(int argc, char** argv){


    return 0;
}