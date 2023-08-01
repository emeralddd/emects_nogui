/**
darkemeralddd
**/
#define emerald ""
#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define l2 long long
#define ld long double
#define _ld (ld)
#define _l2 (l2)
#define st first
#define nd second
#define ll2 pair<l2, l2>
#define ii pair<int, int>
#define iii pair<int, ii>
#define il2 pair<int, l2>
#define l2i pair<l2, int>
#define memset(a, b) memset(a, b, sizeof(a))
#define ladd(a) a = " " + a
#define bit(x, y) (((y) >> (x)) & 1)
#define infinity() for (;;)
#define cntbit(x) __builtin_popcountll((x))
#define all(v) (v).begin(), (v).end()
#define __unique(v) (v).resize(distance((v).begin(), unique(all((v)))))
#define eb emplace_back
#define pb push_back
const l2 mod = 1000000007;
using namespace std;
l2 random(l2 _L, l2 _R)
{
    l2 tmp = 0;
    for (int i = 0; i < 4; i++)
        tmp = (tmp << 15) ^ (rand() & ((1 << 15) - 1));
    assert(_L <= _R);
    return _L + tmp % (_R - _L + 1);
}
void write(int id)
{
    if (id <= 15)
    {
        int a[25];
        int n = random(16, 17);
        for (int i = 1; i <= n; i++)
        {
            a[i] = random(97, 122);
            cout << char(a[i]);
        }
        cout << endl
             << (random(0, 5) ? char(a[random(1, n)]) : char(random(97, 122)));
    }
    else if (id <= 20)
    {
        int a[50];
        for (int i = 97; i <= 122; i++)
        {
            a[i - 96] = i;
        }

        random_shuffle(a + 1, a + 27);
        int n = random(24, 26);
        for (int i = 1; i <= n; i++)
        {
            cout << char(a[i]);
        }

        cout << endl
             << char(a[random(1, n)]);
    }
    else if (id <= 25)
    {
        int n = random(8e4, 1e5);
        int pos = random(1, n);
        int ch = random(97, 122);
        for (int i = 1; i <= n; i++)
        {
            int m = random(97, 122);
            if (i == pos)
                cout << char(ch);
            else
            {
                if (m == ch)
                    cout << 'z';
                else
                    cout << char(m);
            }
        }

        cout << endl
             << char(ch);
    }
    else if (id <= 35)
    {
        int n = random(2e4, 5e4);
        int m = random(2e4, 5e4);

        for (int i = 1; i <= n; i++)
        {
            cout << 'a';
        }
        for (int j = 1; j <= m; j++)
        {
            cout << 'b';
        }
        cout << endl
             << 'b';
    }
    else if (id <= 40)
    {
        int n = random(800, 1e3);
        for (int i = 1; i <= n; i++)
        {
            cout << char(random(97, 122));
        }
        cout << endl
             << char(random(97, 122));
    }
    else
    {
        int n = random(8e4, 1e5);
        for (int i = 1; i <= n; i++)
        {
            cout << char(random(97, 122));
        }
        cout << endl
             << char(random(97, 122));
    }
}
int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(int(time(0)) ^ stoi(argv[1]));

    freopen("UNISSTR.INP", "w", stdout);

    int test = stoi(argv[1]);
    write(test);
}
