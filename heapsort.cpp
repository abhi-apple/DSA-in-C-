#include<iostream>
#include<math.h>
using namespace std;
class minheap{
    public:
    int * harr;
    int capacity;
    int heapsize;
    minheap(int cap){
        heapsize=cap;
        capacity=cap;
        harr=new int[cap];
    }
    void printarr(){
        for(int i=0;i<heapsize;i++){
            cout<<harr[i]<<" ";

        }
        cout<<endl;

    }
    int parent(int i){
        return(i-1)/2;
    }
    int left(int i){
        return(2*i +1);
    }
    int right(int i){
        return(2*i +2);
    }
    int getmin(){
        return harr[0];
    }
    void minheapi(int i){
        int l=left(i);
        int r=right(i);
        int smallest=i;
        if(l<heapsize && harr[l]<harr[i]){
            smallest=l;
        }
        if(r<heapsize && harr[r]<harr[smallest]){
            smallest=r;
        }
        if(smallest!=i){
            swap(harr[i],harr[smallest]);
            minheapi(smallest);
        }
    }
    int extractmin(){
        if(heapsize<=0){
            return INT_MIN;
        }
        if(heapsize==1){
            heapsize--;
            return harr[0];
        }
        int root=harr[0];
        harr[0]=harr[heapsize-1];
        heapsize--;
        minheapi(0);
        return root;
    }
    void getun(){
        cout<<"Enter the elements to be sorted by the HEap sort "<<endl;
        for(int i=0; i<capacity;i++){
            cin>>harr[i];
        }
    }
    void heapsort(){
        int temp[capacity];
        for(int j=0;j<capacity;j++){
            temp[j]=extractmin();
            cout<<temp[j]<<" ";
        }
    }
};
int main(){
    int s;
    cout<<"Enter the size of the min heap "<<endl;
    cin>>s;
    minheap obj(s);
    obj.getun();
    cout<<"unsorted array is "<<endl;
    obj.printarr();
    for(int i=s/2 -1;i>=0;i--){
        obj.minheapi(i);
    }
    cout<<"heap sorted array "<<endl;
    obj.heapsort();
}