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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int &i : a)
    {
        cin >> i;
        i %= k;
    }

    map<int, int> mp;

    for (int i : a)
        mp[i]++;

    int count = 0;

    if (mp[0] > 0)
        count = 1;

    // debug(mp);

    mp[0] = 0;

    int msize = mp.size() / 2 + 1;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        // debug(mp, count);
        if (it->first == 0 || it->second == 0)
            continue;

        int t = k - it->first;
        if (t == it->first)
        {
            it->second = 0;
            count++;
            continue;
        }
        // debug(it->first, t);
        int mn = min(it->second, mp[t]);
        it->second -= mn;
        mp[t] -= mn;
        if (mn != 0 && it->second > mp[t])
        {
            it->second--;
        }
        else if (mn != 0 && mp[t] > it->second)
        {
            debug(t);
            mp[t]--;
        }
        if (mn > 0)
            count++;

        // debug(mn, count);
    }

    // debug(mp, count);

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        count += it->second;
    }

    cout << count << '\n';

    /*
        a b c d e f g
        a+b = k
        b+c = k

        a = c
        b = d
    */
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