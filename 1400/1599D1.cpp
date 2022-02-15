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

class DisjointSet
{
    int *rank, *parent, n;

public:
    DisjointSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        make_set();
    }

    void make_set()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x)
    {

        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void Union(int x, int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] > rank[y_parent])
        {
            parent[y_parent] = x_parent;
        }
        else if (rank[x_parent] < rank[y_parent])
        {
            parent[x_parent] = y_parent;
        }
        else
        {
            parent[y_parent] = x_parent;
            rank[x_parent] = rank[x_parent] + 1;
        }
    }
};

void solve(int cc)
{
    int n;
    cin >> n;

    int m1, m2;
    cin >> m1 >> m2;

    vector<pi> f1(m1), f2(m2);

    for (auto &p : f1)
        cin >> p.first >> p.second;

    for (auto &p : f2)
        cin >> p.first >> p.second;

    DisjointSet *d1, *d2;

    d1 = new DisjointSet(n);
    d2 = new DisjointSet(n);

    for (auto p : f1)
    {
        d1->Union(p.first - 1, p.second - 1);
    }

    for (auto p : f2)
    {
        d2->Union(p.first - 1, p.second - 1);
    }

    vector<pi> ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d1->find(i) == d1->find(j))
                continue;

            if (d2->find(i) == d2->find(j))
                continue;

            ans.push_back({i + 1, j + 1});
            d1->Union(i, j);
            d2->Union(i, j);
        }
    }

    cout << ans.size() << '\n';
    for (auto p : ans)
        cout << p.first << " " << p.second << '\n';
}

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