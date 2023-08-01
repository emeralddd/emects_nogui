#define emerald "UNISSTR"
#include <bits/stdc++.h>
#define l2 long long
#define bit(i, m) (((m) >> (i)) & 1)
const l2 mod = 1000000007;
const l2 mod1 = 1000000003;
using namespace std;
int last[130];
l2 f[200005];
string s, a[1 << 20];
char ch;
void s1()
{
    int n = s.length(), z = 0;
    for (int i = 1; i < (1 << n); i++)
    {
        string tmp = "";
        for (int j = 0; j < n; j++)
        {
            if (bit(j, i))
            {
                tmp += s[j];
            }
        }

        if (tmp[tmp.length() - 1] == ch)
            a[++z] = tmp;
    }

    sort(a + 1, a + 1 + z);
    z = unique(a + 1, a + 1 + z) - a - 1;

    cout << z;
}
void s3()
{
    int n = s.length();
    s = " " + s;
    f[0] = 1;
    memset(last, -1, sizeof(last));
    l2 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = ((2 * f[i - 1] - (last[s[i]] == -1 ? 0 : f[last[s[i]] - 1])) % mod + mod) % mod;
        if (s[i] == ch)
            ans = ((ans + f[i] - f[i - 1]) % mod + mod) % mod;
        last[s[i]] = i;
    }

    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen(emerald ".INP", "r", stdin);
    freopen(emerald ".OUT", "w", stdout);

    cin >> s >> ch;
    s3();
}
