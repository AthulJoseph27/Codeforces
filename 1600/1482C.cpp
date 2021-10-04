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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(m);
    unordered_map<int, int> mp;
    vector<bool> can(m, false);

    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++)
        {
            int d;
            cin >> d;
            a[i].push_back(d);
            mp[d]++;
        }
    }

    int frq = 0, f = -1;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second > frq)
        {
            frq = it->second;
            f = it->first;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j : a[i])
        {
            if (j == f)
            {
                can[i] = true;
                break;
            }
        }
    }

    vector<int> ans(m);

    mp.clear();

    for (int i = 0; i < m; i++)
    {
        if (a[i].size() == 1)
        {
            ans[i] = a[i][0];
            mp[ans[i]]++;
            continue;
        }

        for (int j : a[i])
        {
            if (j != f)
            {
                ans[i] = j;
                mp[ans[i]]++;
                break;
            }
        }
    }

    int mxt_cnt = 0, nf = -1;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second > mxt_cnt)
        {
            mxt_cnt = it->second;
            nf = it->first;
        }
    }

    int limit = (m % 2 == 0) ? m / 2 : (m + 1) / 2;

    if (mxt_cnt > limit)
    {
        for (int i = 0; i < m && (mxt_cnt > limit); i++)
        {
            if (can[i] && ans[i] == nf)
            {
                mxt_cnt--;
                ans[i] = f;
            }
        }
    }

    mp.clear();

    for (int i : ans)
        mp[i]++;

    mxt_cnt = 0;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second > mxt_cnt)
        {
            mxt_cnt = it->second;
            nf = it->first;
        }
    }

    if (mxt_cnt > limit)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i : ans)
    {
        cout << i << " ";
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