#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pi;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

void __print(int x)
{
    cerr << x;
}
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

void solve(int cc)
{
    int n;
    cin >> n;

    vi a(n);

    for (int &i : a)
        cin >> i;

    int q;
    cin >> q;

    map<int, int> mp;

    int g2 = 0, g4 = 0;

    for (int i : a)
        mp[i]++;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        g2 += (it->second / 2);
        g4 += (it->second / 4);
    }

    while (q)
    {
        q--;

        char ch;
        int d;
        cin >> ch;

        if (ch == '+')
        {
            cin >> d;
            mp[d]++;
            if ((mp[d] % 4) == 0)
            {
                g4++;
            }
            if ((mp[d] % 2) == 0)
            {
                g2++;
            }
        }
        else
        {
            cin >> d;
            int cnt = mp[d];
            mp[d]--;
            if ((cnt % 4) == 0)
            {
                g4--;
            }
            if ((cnt % 2) == 0)
            {
                g2--;
            }
        }

        // debug(g4, g2);
        if ((g4 > 1) || (g4 == 1 && (g2 - 1) >= 3))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    T = 1;

    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
    }

    return 0;
}

/*
    In a fully connected K-ary Tree
    parent of nth node is
    p = (n+k-2)/k
*/