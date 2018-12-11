#include <bits/stdc++.h>
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#define ll long long
#define ull unsigned long long 
using namespace std;
const int MXN=250250;
const int INF=1000000007;
char a[MXN],b[MXN];
int alen,blen,st,n;
ull pp[MXN],h1[MXN],h2[MXN];
ull gethash1(int l,int r){
	ull ret;
	if(l)
		ret=((h1[r]-h1[l-1])*1ULL*pp[n-r]);
	else
		ret=(h1[r]*1ULL*pp[n-r]);
	return ret;
}
ull gethash2(int l,int r){
	ull ret;
	if(l)
		ret=((h2[r]-h2[l-1])*1ULL*pp[n-r]);
	else
		ret=(h2[r]*1ULL*pp[n-r]);
	return ret;
}
bool check(int len){
	set<ull> mp;
	for(int i=0;i<alen-len+1;i++)
		mp.insert(gethash1(i,i+len-1));
	for(int i=0;i<blen-len+1;i++){
		if(mp.find(gethash2(i,i+len-1))!=mp.end()){
			st=i;
			return true;
		}
	}
	return false;
}
int main(){
	input;
	scanf("%s",&a);
	scanf("%s",&b);
	alen=strlen(a);
	blen=strlen(b);
	n=alen;
	pp[0]=1;
	for(int i=1;i<=n;i++)
		pp[i]=(pp[i-1]*37ULL);
	for(int i=0;i<alen;i++){
		if(i)
			h1[i]=h1[i-1];
		h1[i]+=(1ULL*(a[i]-'a'+1)*pp[i]);
	}
	for(int i=0;i<blen;i++){
		if(i)
			h2[i]=h2[i-1];
		h2[i]+=(1ULL*(b[i]-'a'+1)*pp[i]);
	}
	int l=0,r=blen+1;
	while(r-l>1){
		int m = (l + r) >> 1;
		if ( check(m) )
			l = m;
		else
			r = m;
	}
	for(int i=st;i<st+l;i++){
		cout<<a[i];
	}
}