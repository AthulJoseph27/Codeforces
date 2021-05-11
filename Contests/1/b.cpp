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

    vector<vector<int>> paths(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> paths[i][j];
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     sort(all(paths[i]));
    // }

    vector<pair<int, pair<int, int>>> d;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            d.push_back(make_pair(paths[i][j], make_pair(i, j)));
        }
    }

    sort(all(d), [&](const pair<int, pair<int, int>> a, const pair<int, pair<int, int>> b) {
        return a.first < b.first;
    });

    vector<vector<int>> ans(n, vector<int>(m, 0));
    unordered_map<int, vector<int>> index_map;
    int col = 0;
    for (int i = 0; i < d.size(); i++)
    {
        if (col < m)
        {
            ans[d[i].second.first][col] = d[i].first;
            index_map[d[i].second.first].push_back(d[i].second.second);
            col++;
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> used = index_map[i];
        vector<int> ele;

        for (int j = 0; j < m; j++)
        {
            bool flag = false;
            for (int k = 0; k < used.size(); k++)
            {
                if (j == used[k])
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                continue;
            ele.push_back(paths[i][j]);
        }
        // debug(used);
        // debug(ele);
        // debug(ans[i]);
        // debug(paths[i]);

        // fill all index from 1 to m-1 with any element other than element at index used
        for (int j = 0; j < m; j++)
        {
            if (ans[i][j] == 0)
            {
                assert(!ele.empty());
                ans[i][j] = ele.back();
                ele.pop_back();
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}

// 1 2 3
// 5 6 7
// 3 4 5
// 1  2 3

// 1 2 3 4
// 1 2 3 4

// 1 2 3 4
// 4 1 2 3
// 4 3 1 2

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