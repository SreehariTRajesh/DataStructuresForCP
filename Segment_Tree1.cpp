#include<bits/stdc++.h>
using namespace std;
class SegmentTree{
    vector<int>tree;
    map<int,int>imap;
    int size;
    public:
    SegmentTree(int n){
        int x=pow(2,ceil(log2(n))); 
        size=2*x-1;   
        tree.resize(size,-1);
    }
    int build_tree(int arr[],int l,int r,int idx){
         if(l==r){
            tree[idx]=arr[l];
            imap[l]=idx;
            return tree[idx];  
         }
         else{
            int m=(l+r)/2;
            tree[idx]=build_tree(arr,l,m,2*idx+1)+build_tree(arr,m+1,r,2*idx+2);
            return tree[idx];
         }
    }
    void set(int i,int v){
         int j=imap[i];
         int d=v-tree[j];
         while(j!=0){
            tree[j]=tree[j]+d;
            j/=2;
         }    
         tree[0]=tree[0]+d;
    }
    int sum(int l,int r,int ql,int qr,int idx){
        if(l>qr or r<ql){
            return 0;        
        }
        
        else{
            if(l==r){
               return tree[idx];            
            }
            int m=(l+r)/2;
            return sum(l,m,ql,qr,2*idx+1)+sum(m+1,r,ql,qr,2*idx+2); 
        }
    }
};
int main(){
    int n;
    cin>>n;    
    int arr[n];
    SegmentTree T(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    T.build_tree(arr,0,n-1,0);
    while(1){
      char op;
      cin>>op;
      if(op=='u'){
         int i,v;
         cin>>i>>v;
         T.set(i,v);   
      }
      else if(op=='s'){
         int ql,qr;
         cin>>ql>>qr;
         cout<<T.sum(0,n-1,ql,qr,0)<<endl;
      }
      else if(op=='e'){
        break;
      }    
    }
    return 0;
}
