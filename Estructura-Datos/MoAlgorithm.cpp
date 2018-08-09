#include <bits/stdc++.h>
using namespace std;

const int N=200002;
long long a[N],ans[N],n,t,nb,k;
long long cnt=0;
long long f[1000002];
struct query{
    int l,r,ind;
}Q[N];

bool cmp(const query& p,const query& q){
    if(p.l/nb != q.l/nb)
        return p.l/nb<q.l/nb;
    return ((p.r<q.r)^((p.l/nb)&1));
}

void add(int pos){
   if(!f[pos])
        cnt++;    
    f[pos]++;
  
}
void remove(int pos){
    if(f[pos]==1)
        cnt--;
     f[pos]--;
}

void solve(){
    nb =448;
    sort(Q,Q+t,cmp);
    int l = 0, r = 0;
    for (int i = 0; i < t; ++i)
    {
   
        while(l<Q[i].l) remove(a[l++]);
   
        while(l>Q[i].l) add(a[--l]);
   
        while(r<Q[i].r) add(a[r++]);
   
        while(r>Q[i].r) remove(a[--r]);
   
        ans[Q[i].ind] = cnt;
    }

}


int main() {
//  input;
    scanf("%d", &n);
         for (int i = 0; i < n; ++i)
    {
         scanf("%d",&a[i]);
    }
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        int l,r;
        scanf("%d%d", &l, &r);
        Q[i]={--l,r,i};
    }
    solve();
    for (int i = 0; i < t; ++i)
    {
         printf("%I64d\n",ans[i]);  
    }
    return 0;
}  
