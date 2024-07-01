

#include <unordered_map>
#include <iostream>

using namespace std;

template<typename KT,typename VT>
typedef struct Node{
    KT key;
    VT value;
    Node*  prev;
    Node* next;
    Node(KT key, VT value){
        key = key;
        value = value;
        prev = nullptr;
        next = nullptr;
    }

    Node(){//初始化头
        prev = this;
        next = this;//指向自己为空
    }

    bool is_empty(){//是否为空
        return prev==this && next == this;
    }
} Queue;

template<typename KT,typename VT>
class LRU_Cache{

    public:

        LRU_Cache(int capicity){
            capicity_ = capicity;
            queue = new Node();
            
        }
        ~LRU_Cache(){
            capicity_ = 0;
            auto node = queue_->next;
            while(node!=queue_){
                auto next = node->next;
                delete node;
                node = next;
            }
            delete queue_;
            
        }
        VT get(KT key){
            auto it = keys_2_nodep.find(key);
            if(it == keys_2_nodep.end()) return static_cast<VT>(-1);
            
            auto* node = it->second;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next = queue->next;
            queue->next = node;
            node->prev = queue_;

            return node->value;
        }

        void put(KT key, VT value){
            auto it = keys_2_nodep.find(key);
            if(it == keys_2_nodep.end()){
                if(key_2_nodep.size()==capicity_){
                    //remove
                    auto* tail = queue_->prev;

                    //删除map
                    auto key = tail->key;
                    keys_2_nodep.erase(key);
                    //清楚queue_;
                    tail->prev->next = queue_;
                    queue_->prev = tail->prev;
                    delete tail;//释放空间
                }
                auto* node = new(key, value);
                node->next = queue_->next;
                node->prev = queue;
                queue_next =node;
                keys_2_nodep[key] = node;
            }

        }

    private:
        int capicity_;
        unordered_map<KT, Node*> keys_2_nodep;
        Node* queue;//头插入
        
};



int main(int argc, char** argv){

    LRU_Cache<int, int> lru_cache(2);
    lru_cache.get(1);

    lru_cache.put(2,2);
    lru_cache.put(3,3);
    lru_cache.put(4,4);

    return 0;
}