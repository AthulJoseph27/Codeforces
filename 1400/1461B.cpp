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
    int n, m;
    cin >> n >> m;

    vector<string> a(n);

    for (auto &p : a)
        cin >> p;

    ll ans = 0;

    vvl w(n, vl(m, 0));

    for (int i = 0; i < n; i++)
    {
        ll cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '*')
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            w[i][j] = cnt;
        }
        cnt = 0;
        for (int j = m - 1; j >= 0; j--)
        {
            if (a[i][j] == '*')
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            w[i][j] = max(0ll, min(w[i][j], cnt) * 2ll - 1ll);
        }
    }

    // debug(w);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ll mn_width = 1;
            for (int h = 0; (i + h) < n; h++)
            {
                if (w[i + h][j] >= mn_width)
                {
                    ans++;
                }
                else
                {
                    break;
                }
                mn_width += 2;
            }
        }
    }

    cout << ans << '\n';
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

/*
    In a fully connected K-ary Tree
    parent of nth node is
    p = (n+k-2)/k
*/