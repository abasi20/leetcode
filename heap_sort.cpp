

void heap_sort(vector<int> & vec){
    int size = vec.size();
    for(int i=size-2;i>=0;i++){
        heapify(vec, i);
    }
}

//堆排序，获取topk
void heapify(vector<int> & vec, int idx){
    
    int max_id = vec[2*idx+1]>vec[2*idx+2]?2*idx+1: 2*idx+2;
    if(vec[idx] <vec[max_id]) {
        swap(vec[idx] ,vec[max_id]);
        heapify(vec, max_id);
    }

}

int main(int argc, char** argv){

    return 0;
}