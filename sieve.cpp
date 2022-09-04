#include<bits/stdc++.h>
using namespace std;
set<int>__sieve(){
    vector<bool>p(100001,false);
    p[0]=true;
    p[1]=true;
    p[2]=false;
    for(long long int i=2;i<=100000;++i){
        if(p[i]==false){
           for(long long int j=i*i;j<=100000;j+=i){
                p[j]=true; 
           }
        }
    }
    set<int>sv;
    for(int i=2;i<=100000;++i)
        if(p[i]==false)
           sv.insert(i);
    return sv;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}
