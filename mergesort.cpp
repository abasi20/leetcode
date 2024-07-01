
#include <iostream>
#include <vector>
using namespace std;



class MergeSort{






    public:
        void mergesort(int start , int end){

            if(start==end) return;
            auto mid = start + (end-start+1)/2;
            
            mergesort(start, mid);
            mergesort(mid+1, end);
            merge(start, mid, end);


        }


        void merge(int start, int mid, end){
            auto l = start;
            auto r = mid+1;
            auto s = start;
            while(l< =mid&& r<=end){
                if(datas[l]<=datas[r]){
                    temp[s] = datas[l++];
                }else{
                    temp[s] = datas[r++];
                }
                s++;
            }
            if(l<mid){
                memcpy(datas+l, temp+s, mid-l);
            }else{
                memcpy(datas+r, temp+s, end-r);
            }
            memcpy(datas+start, temp+start, end-start+1);
        }


    private:
        vector<int> datas;
        int* temp;

}



void merge()





int main(int argc, char** argv){

    return 0;
}