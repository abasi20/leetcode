

#include<iostream>



void sort(int[] array,  int idx, int length){
    int min_idx = idx;
    if(2*idx+2>=length){
        if(2*idx+1<length) {
            min_idx = 2*idx+1
        }
    }else{
        min_idx = array[2*idx+1]>array[2*idx+1]? 2*idx+1: 2*idx+1;
    }
    if(array[idx]>array[min_idx]){
        swap(array[idx], array[min_idx]);
        sort(array, min_idx, length);
    }
    
}

out(array,0, le)


void priority_sort(array, idx, length){
    for(int i = length-1;i>=0;i--){
        sort(array, i, length);
    }

    //输出，把最大的数据放在末尾，
    for(int i = length - 1;i>=0;i--){
        swap(array[0], array[i]);
        sort(array, 0, i);
    }
    //结果从小到大的排序
}

int main(int argc, char** argv){

    return 0;
}