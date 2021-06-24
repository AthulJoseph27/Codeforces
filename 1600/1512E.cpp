#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define all(v) v.begin(), v.end()

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
    int n, l, r, s;

    cin >> n >> l >> r >> s;

    int k = r - l + 1;

    // get s with no coins

    /*
        k = r - l + 1

        low = k(k+1)/2
        high = n + n-1 + ..n-k+1 => kn - (k(k-1))/2 = k(2n-k+1)/2

        any sum between low and high can be achieved
        
    */

    int low = (k * (k + 1)) / 2;
    int high = (k * (2 * n - k + 1)) / 2;

    if (s < low || s > high)
    {
        cout << -1 << '\n';
        return;
    }

    vector<int> a;
    map<int, int> mp;

    for (int i = n; i > 0; i--)
    {
        int nk = k - 1;
        int nlw = (nk * (nk + 1)) / 2;
        int nhg = (nk * (2 * (i - 1) - nk + 1)) / 2;
        int ns = s - i;
        if (ns < nlw || ns > nhg)
        {
            continue;
        }
        k--;
        s -= i;
        a.push_back(i);
        mp[i]++;
    }

    assert(s == 0);

    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (count == (l - 1))
            break;
        if (mp[i] == 0)
        {
            cout << i << ' ';
            mp[i]++;
            count++;
        }
    }

    for (int i : a)
        cout << i << ' ';

    for (int i = 1; i <= n; i++)
    {
        if (mp[i] == 0)
        {
            cout << i << ' ';
        }
    }

    // debug(a);

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