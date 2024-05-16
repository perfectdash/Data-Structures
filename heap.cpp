
#include <bits/stdc++.h>
using namespace std;


class heap {
    public :
        int arr[100];
        int size = 0;

    heap(){
          arr[0]= -1;
          size = 0;
    }

    void insert(int val){
         size = size+1;
         int index =size;
         arr[index] =  val ;

         while(index>1){
             int parent  = (index/2);
             if(arr[index]>arr[parent]){
                swap(arr[index],arr[parent]);
                index = parent ;
             }else{
                return;
             }
         }
    }

    void print(){
        for(int i =1;i<=size;i++){
           cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    
    void pop(){
          // always delete the last node----------------------------------->
          if(size==0){
            return ;
          }
        // swapping the last and the first element ------------------------->
          arr[1]= arr[size];
          size--;
        // balancing the tree------------------------------------------------>
          int i= 1;
          while(i<size){
            int leftchild = 2*i;
            int rightchild = 2*i+1;
            if(arr[leftchild]>arr[i] && leftchild<=size){
                 swap(arr[leftchild],arr[i]);
                 i = leftchild;
            }else if(arr[rightchild]>arr[i] && rightchild<=size){
                 swap(arr[rightchild],arr[i]);
                 i = rightchild;
            }else{
                return;
            }

          }
    }

    
};


void heapify( int arr[],int n,int i){
         int largest = i;
         int left = 2*i;
         int right = 2*i+1;
         
         if(left<n && arr[largest]<arr[left]){
            largest= left;
         }
         if(right<n && arr[i]<arr[right]){
            largest = right;
         }

         if(largest!=i){
            swap(arr[i],arr[largest]);
            heapify(arr,n,largest);
         }
    }

int main(){
 
    int arr[] = {54,53,55,52,50};
    for(int i=5/2;i>=0;i--){
       heapify(arr,5,i);
    }


    return 0;
}