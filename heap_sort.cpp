
/**
 * 获取最小的k个值算法
 * 思路使用堆进行存储k个数据
 * 算法复杂度O（N）主要是需要拿所有的数与topk的0位置数据比较
 */
void topK(vector<int> & vec, int k){
    int size = vec.size();
    if(size<=k) return vec;
    else{
        vector<int> result(vec.begin(), vec.begin()+k);//由前k个进行初始化

        heap_sort(result);//取得是最大k个
        for(int i=k;i<size;i++){
            if(vec[i]<result[0]){
                result[0] = vec[i];
                heapify(result, 0);
            }
        } 
        return result; 
    }
}

void heap_sort(vector<int> & vec){
    int size = vec.size();
    for(int i=size-2;i>=0;i++){
        heapify(vec, i);
    }
}



//堆排序，获取topk 大根堆,大根堆求topk (最小值)
void heapify(vector<int> & vec, int idx){
    int max_id;
    int size = vec.size();
    if(2*idx+1>=size) return;
    if(2*idx+2<size){
        max_id = vec[2*idx+1]>vec[2*idx+2]?2*idx+1: 2*idx+2;
    }
    else{
        max_id = 2*idx+1;
        }
    if(vec[idx] <vec[max_id]) {
        swap(vec[idx] ,vec[max_id]);
        heapify(vec, max_id);
    }

}

int main(int argc, char** argv){
    
    return 0;
}