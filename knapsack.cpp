#include<iostream>
#include<vector>
#include<pair>

class Knapsack{

    public:
        Knapsack(vector<pair<int, int >> packages， int bag){
            packages_= packages;
            bag_ = bag;
        }
        //背包问题
        int process(int idx, int value, int remind_bag){
            if(idx >= packages_.size()) return value;
            if（remind_bag<0) return -1;
            int l_value = process(idx+1, value, bag);//不拿当前的背包
            int r_value =  process(idx+1, packages_[idx] + value,remind_bag- packages_[idx].second);

            return max(l_weight, r_weight);
        }



    private:
        vector<pair<int, int >> packages_;//重量，价值
        int bag_;//包的容量

}


int main(int argc, char** argv){

    return 0;
}

