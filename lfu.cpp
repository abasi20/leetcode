#include<unordered_map>
using namespace std;



typedef struct  Node{
    int key;
    int value;
    int freq;

    node* prev;
    node* next;

    Node(int key, int value) {
        key = key;
        value = value;
        prev= nullptr;
        next = nullptr;
    }

    Node(){
        prev = this;
        next = this;
    }

    bool is_empy(){
        return prev==this && next==this;
    }
} Queue;

class LFU_cache{

    public:
        LFU_cache(int capicity){
            capicaity_ = capicity;
            min_stage = 0;
        }

        int get(int key){
            if(keys_map_.size() == 0) return -1;
            auto it = keys_map.find(key);
            if(it == keys_map.end()) return -1;

            auto freq = it->second->freq;
            auto next_freq = freq+1;
            //
            auto node = it->second;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            if(freq_2_queue_[freq].is_empty()){
                freq_2_queue_.erase(freq);
                if(freq_2_queue_[freq] == min_stage) min_stage = next_freq;
            }
            if(freq_2_queue_.count(next_freq)==0){
                freq_2_queue_[next_freq] = new Queue();
            }
            node->next = freq_2_queue_[next_freq]->next;
            freq_2_queue_[next_freq]->next = node;
            node->prev = freq_2_queue_[next_freq];
            return node->value;
        }

        void put(int key, int value){

            auto it = keys_map_.find(key);
            if(capicaity_ < key_map_.size()){
                if(it == keys_map_.end()){
                    auto * node = new Node(key, value);
                    if(freq_2_queue_.count(key)==0){
                        min_stage = 1;
                        freq_2_queue_[1] = new Queue();}
                    node->next = freq_2_queue_[1]->next;
                    freq_2_queue_[1]->next = node;
                    node->prev = freq_2_queue_[1];
                    retrun;
                }
                //存在
                auto node = it->second;
                node->value = value;
                node->prev->next = node->next;
                node->next->prev = node->prev;
                if(freq_2_queue_[freq].is_empty()){
                    freq_2_queue_.erase(freq);
                    if(freq_2_queue_[freq] == min_stage) min_stage = next_freq;
                }
                if(freq_2_queue_.count(next_freq)==0){
                    freq_2_queue_[next_freq] = new Queue();
                }
                node->next = freq_2_queue_[next_freq]->next;
                freq_2_queue_[next_freq]->next = node;
                node->prev = freq_2_queue_[next_freq];

                return ;
            }else{
                if(it == keys_map_.end()){
                    //清楚尾巴
                    freq_2_queue_[min_stage]
                    auto * node = new Node(key, value);
                    if(freq_2_queue_.count(key)==0){
                        min_stage = 1;
                        freq_2_queue_[1] = new Queue();}
                    node->next = freq_2_queue_[1]->next;
                    freq_2_queue_[1]->next = node;
                    node->prev = freq_2_queue_[1];
                    
                    
                    retrun;
                }


            }
            
        }


    private:
        int capicaity_;
        int min_stage;
        unordermap<int, Queue*> freq_2_queue_;//记录每一freq中存储的数据
        unordered_map<int, Node*> keys_map_;//记录出现的key值

};

int main(int argc, char* argv){


}