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

    int q;
    cin >> q;

    int MAXN = 5 * 1e5 + 1;

    vector<vector<int>> locations(MAXN, vector<int>());

    int index = 0;

    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int x;
            cin >> x;
            locations[x].push_back(index);
            index++;
        }
        else
        {
            int x, y;
            cin >> x >> y;

            if (x == y)
                continue;

            if (locations[x].size() > locations[y].size())
            {
                swap(locations[x], locations[y]);
            }

            for (int j : locations[x])
                locations[y].push_back(j);

            locations[x].clear();
        }
    }

    vector<int> a(index);

    for (int i = 0; i < locations.size(); i++)
    {
        for (int j : locations[i])
        {
            a[j] = i;
        }
    }

    debug(locations[2]);

    for (int i : a)
        cout << i << " ";

    cout << "\n";
}

/*
    4->3
    2->4
*/

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