#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>vt;
ll ar[40],po[25],b[50000];
int n;
ll w,test;

bool check(int N,int pos) {
    return (bool)(N & (1<<pos));
}
int main() {
    int cnt;
    po[0]=1;
    for(int i=1; i<=17; i++) {
        po[i]=po[i-1]*2;
    }
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++) {
        scanf("%d %lld",&n,&w);
        for(int i=0; i<n; i++) {
            scanf("%lld",&ar[i]);
        }
        int half=ceil((double)n/2.0);
        int p=po[half];
        int in1=0;
        for(int i=0; i<p; i++) {
            ll sum=0;
            for(int j=0; j<half; j++) {
                if(check(i,j)) {
                    sum+=ar[j];
                }
            }

            in1++;
            b[in1]=sum;
        }
        if(n&1)p/=2;

        for(int i=0; i<p; i++) {
            ll sum=0;
            for(int j=half,k=0; j<n; j++,k++) {
                if(check(i,k)) {
                    sum+=ar[j];
                }
            }
            vt.push_back(sum);
        }
        sort(vt.begin(),vt.end());
        cnt=0;
        //cout<<in1<<" "<<vt.size()<<endl;
        for(int i=1; i<=in1; i++) {
            if(b[i]<=w) {
                ll index=upper_bound(vt.begin(),vt.end(),w-b[i])-vt.begin();
                cnt+=index;
            }
        }
        vt.clear();
        printf("Case %d: %d\n",cs,cnt);
        //if(cs!=test)printf("\n");
    }
    return 0;
}
