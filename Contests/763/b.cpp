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

void find(map<pi, int> &mp, set<pi> &st, vi &cnt, int d)
{
    if (d > cnt.size())
        return;

    vi ans;

    for (int i = 0; i < cnt.size(); i++)
    {
        if (cnt[i] == d)
        {
            ans.push_back(i);
        }
    }

    for (int i : ans)
    {
        for (auto [l, r] : st)
        {
            if (i >= l && i <= r)
            {
                mp[{l, r}] = i;
                st.erase({l, r});
                break;
            }
        }
    }

    find(mp, st, cnt, d + 1);
}

void solve(int cc)
{
    int n;
    cin >> n;

    set<pi> st;

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        st.insert({l, r});
    }

    vi cnt(n + 1, 0);

    for (auto [l, r] : st)
    {
        for (int i = l; i <= r; i++)
        {
            cnt[i]++;
        }
    }

    map<pi, int> mp;

    find(mp, st, cnt, 1);

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first.first << " " << it->first.second << " " << it->second << '\n';
    }
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