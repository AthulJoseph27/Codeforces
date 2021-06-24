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

    int n, m, x;

    cin >> n >> m >> x;

    vector<int> blocks(n);

    map<int, vector<int>> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> blocks[i];
        mp[blocks[i]].push_back(i);
    }

    sort(all(blocks));

    vector<int> ans(n);

    vector<long long> tower(m, 0);

    for (int i = 0; i < m; i++)
    {
        tower[i] = blocks[i];
        ans[mp[blocks[i]].back()] = i;
        mp[blocks[i]].pop_back();
    }

    deque<int> blks;

    for (int i = m; i < n; i++)
        blks.push_back(blocks[i]);

    bool ft = false;

    while (blks.size() > 0)
    {
        int sz = min((int)blks.size(), m);
        for (int i = 0; i < sz; i++)
        {
            if (ft)
            {
                tower[i] += blks.front();
                ans[mp[blks.front()].back()] = i;
                mp[blks.front()].pop_back();
                blks.pop_front();
            }
            else
            {
                tower[i] += blks.back();
                ans[mp[blks.back()].back()] = i;
                mp[blks.back()].pop_back();
                blks.pop_back();
            }
        }
        ft = !ft;
    }

    int mn = *min_element(all(tower));
    int mx = *max_element(all(tower));

    // debug(tower);

    if (mx - mn > x)
    {
        cout << "NO" << '\n';
    }
    else
    {
        cout << "YES" << '\n';
        for (int i : ans)
            cout << (i + 1) << ' ';
        cout << '\n';
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