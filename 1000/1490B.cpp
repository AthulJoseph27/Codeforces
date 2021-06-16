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
    int n;
    cin >> n;

    vector<int> a(n);

    map<int, int> mp;

    for (int &i : a)
    {
        cin >> i;
        i %= 3;
        mp[i]++;
    }

    // make mp[0] == mp[1] == mp[2] = n/3

    n /= 3;

    if (mp[0] == mp[1] && mp[1] == mp[2] && mp[1] == n)
    {
        cout << 0 << '\n';
        return;
    }

    int ans = 0;

    // debug(mp[0], mp[1], mp[2], n);

    for (int i = 0; i < 2; i++)
    {
        if (mp[0] > n)
        {
            mp[1] += (mp[0] - n);
            ans += (mp[0] - n);
            mp[0] = n;
        }

        if (mp[1] > n)
        {
            mp[2] += (mp[1] - n);
            ans += (mp[1] - n);
            mp[1] = n;
        }

        if (mp[2] > n)
        {
            mp[0] += (mp[2] - n);
            ans += (mp[2] - n);
            mp[2] = n;
        }
    }

    // debug(mp[0], mp[1], mp[2]);
    assert(mp[1] == mp[2] && mp[2] == mp[0] && mp[1] == n);

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