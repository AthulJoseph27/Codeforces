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
    int n, k;
    cin >> n >> k;

    vi a(n);

    for (int &i : a)
        cin >> i;

    vvi c(k);

    // int MAXN = 2 * 100'000 + 1;

    map<int, vector<int>> indicies;

    for (int i = 0; i < n; i++)
    {
        indicies[a[i]].push_back(i);
    }

    int cur = 0;

    for (auto it = indicies.begin(); it != indicies.end(); it++)
    {
        int cnt = 0;
        for (int j : it->second)
        {
            if (cnt == k)
                break;
            c[cur].push_back(j);
            cnt++;
            cur = (cur + 1) % k;
        }
    }

    int mn = c.back().size();

    for (int i = 0; i < k; i++)
    {
        mn = min((int)c[i].size(), mn);
    }

    vi color(n, 0);

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < mn; j++)
        {
            color[c[i][j]] = i + 1;
        }
    }

    for (int i : color)
    {
        cout << i << ' ';
    }

    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
    }

    return 0;
}