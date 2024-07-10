


/**
 * 多个有序数组合并的算法
 * 1.假设数组n个
 * 2.每个数组都是按照由小到大的顺序排序
 * 输入：{
 * {1，3，4}，
 * {2}，
 * {3，5，6，7，8}，
 * {2，3，4}
 * }
 * 输出：
 * {1，2，2，3，3，3，4，4，5，6，7，8}
 * 方法1：
 * 暴力方法，两两合并然，最终合并成一个大的数组，算法复杂度O(n)涉及到数据的copy问题
 * 方法2：
 * 同时比较那个数组，并取其中最小的放入到结果数组中，算法复杂度。
 */
//方法一：
vector<int> merge_2_vec(vector<int>& A, vector<int>&B){
    
    int size_a= A.size();
    int size_b = B.size();
    if(size_a == 0 ) return B;
    if(size_b == 0) return A;
    int loc_a=0;
    int loc_b=0;
    int loc_r=0;
    vector<int> result;
    result.reserve(size_a+size_b);
    while(loc_a<size_a&& loc_b<size_b){
        if(A[loc_a]<B[loc_b]){
            result[loc_r] = A[loc_a];
            loc_a++;
        }else{
            result[loc_r] = B[loc_b];
            loc_b++;
        }
        loc_r++;
    }
    
    for(;loc_a<size_a;loc_a++){
        result[loc_r] = A[loc_a];
        loc_r++
    }
    for(;loc_b<size_b;loc_b++){
        result[loc_r] = b[loc_b];
        loc_r++
    }
    return result;
}

//方法2

typedef struct Node{
    int index;//数组
    int id;//第几个数组 0~n-1
    int value;//存储的值
    Node(int i, int id, int value){
        index = i;
        id = id;
        value = value;
    }
} Node;

struct Comparetor{

    bool operator (Node* a, Node*b){
        return a->value > b->value;
    }
};

void merge_mul_arrays(vector<vector<int>> vecs){

    //合并多个向量
    priority_queue<Node*, Comparetor> queue;
    int nums_a = vecs.size();//记录数组的长度
    for(int i =0;i<nums_a;i++){
        queue.push(New Node(i, 0, vecs[i][0]));
    }
    int loc =0;
    vector<int> result;
    while(!queue.empty()){
        
        auto* node = queue.top();
        result.push_back(node->value);
        if(node->index <vecs[node->id].size()){
            node->index = node->index+1;
            node->value = vecs[node->id][node->index];
            queue.push(node);
        }else{
            delete node;
        }
        queue.pop();
    }

    return result;

}

int main(int argc, char** argv){

    return 0;
}