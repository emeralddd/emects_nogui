/**
darkemeralddd
**/
#define emerald "test"
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define l2 long long
#define ld long double
#define _ld (ld)
#define _l2 (l2)
#define st first
#define nd second
#define ll2 pair<l2,l2>
#define ii pair<int,int>
#define iii pair<int,ii>
#define il2 pair<int,l2>
#define l2i pair<l2,int>
#define memset(a,b) memset(a,b,sizeof(a))
#define ladd(a) a=" "+a
#define bit(x,y) (((y)>>(x))&1)
#define infinity() for(;;)
#define cntbit(x) __builtin_popcountll((x))
#define all(v) (v).begin(),(v).end()
#define __unique(v) (v).resize(distance((v).begin(),unique(all((v)))))
#define eb emplace_back
#define pb push_back
const l2 mod = 1000000007;
using namespace std;
int n;
char ch;
string s,a[1<<20];
void s1() {
    int z=0;
    for(int i=1; i<(1<<n); i++) {
        string tmp="";
        for(int j=0; j<n; j++) {
            if(bit(j,i)) {
                tmp+=s[j];
            }
        }

        if(tmp[tmp.length()-1]==ch) a[++z]=tmp;
    }

    sort(a+1,a+1+z);
    z=unique(a+1,a+1+z)-a-1;

    cout<<z;
}
void s2() {
    for(int i=0; i<n; i++) {
        if(s[i]==ch) {
            cout<<(1<<i);
            return;
        }
    }

    cout<<0;
}
int last[130];
l2 f[100005];
void s3() {
    s=" "+s;
    f[0]=1;
    memset(last,-1);
    l2 ans=0;
    for(int i=1; i<=n; i++) {
        if(s[i]==ch) {
            cout<<f[i-1];
            return;
        }
        f[i]=((2*f[i-1]-(last[s[i]]==-1?0:f[last[s[i]]-1]))%mod+mod)%mod;
        last[s[i]]=i;
    }

    cout<<0;
}
void s4() {
    int a=0,b=0;
    for(int i=0; i<n; i++) {
        if(s[i]=='a') a++;
        else b++;
    }

    cout<<1ll*(a+1)*b%mod;
}
l2 f1[1005][30];
void s5() {
    s=" "+s;
    for(int i=1; i<=n; i++) {
        if(last[s[i]]==0) {
            f1[i][s[i]-97]=1;
        }
        for(int j=0; j<=25; j++) {
            (f1[i][j]+=f1[i-1][j])%=mod;
            if(j+97==s[i]) {
                for(int k=0; k<=25; k++) {
                    f1[i][j]=(f1[i][j]+f1[i-1][k])%mod;
                }
                if(last[j+97]!=0) {
                    for(int k=0; k<=25; k++) {
                        f1[i][j]=(f1[i][j]-f1[last[j+97]-1][k]+mod)%mod;
                    }
                }
            }
        }
        last[s[i]]=i;
    }
    cout<<f1[n][ch-97];
}
void s6() {
    s=" "+s;
    f[0]=1;
    memset(last,-1);
    l2 ans=0;
    for(int i=1; i<=n; i++) {
        f[i]=((2*f[i-1]-(last[s[i]]==-1?0:f[last[s[i]]-1]))%mod+mod)%mod;
        if(s[i]==ch) {
            ans=((ans+f[i]-f[i-1])%mod+mod)%mod;
        }
        last[s[i]]=i;
    }

    cout<<ans<<'\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>s>>ch;
    n=s.length();

    int cnt[130];
    memset(cnt,0);
    for(int i=0; i<n; i++) {
        cnt[s[i]]++;
    }

    bool cs2=1,cs3=1,cs4=1;

    for(int i=97; i<=122; i++) {
        if(cnt[i]>1) cs2=0;
    }

    if(cnt[ch]>1) cs3=0;

    for(int i=0; i<n; i++) {
        if(s[i]!='a') {
            for(int j=i; j<n; j++) {
                if(s[j]!='b') {
                    cs4=0;
                    break;
                }
            }
            break;
        }
    }

    if(n<18) s1();
    else if(cs2) s2();
    else if(cs3) s3();
    else if(cs4) s4();
    else if(n<=1000) s5();
    else s6();
}

