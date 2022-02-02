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
    int n, m, Sx, Sy;
    cin >> n >> m >> Sx >> Sy;

    Sx--;
    Sy--;

    vector<pi> ans = {{Sx, Sy}};

    Sy++;
    while (Sy < m)
    {
        ans.push_back({Sx, Sy});
        Sy++;
    }

    Sy = ans[0].second;

    Sy--;
    while (Sy >= 0)
    {
        ans.push_back({Sx, Sy});
        Sy--;
    }

    assert(Sy == -1);

    Sy = 0;

    Sx++;

    while (Sx < n)
    {
        ans.push_back({Sx, Sy});
        Sx++;
    }

    Sx = ans[0].first - 1;

    int xi, yi;
    xi = ans[0].first;
    yi = ans[0].second;

    while (Sx >= 0)
    {
        ans.push_back({Sx, Sy});
        Sx--;
    }

    // debug(ans);
    // assert(false);

    // now at 0 0 , row Sx is filled and and column 0 0 is filled

    Sx = 0;
    Sy = 1;

    int size = n * m;

    int dir = 1;

    while (ans.size() < size)
    {
        ans.push_back({Sx, Sy});
        Sx += dir;
        if (Sx == xi)
        {
            Sx += dir;
        }
        if (Sx == n)
        {
            dir = -1;
            Sy++;
            Sx--;
        }
        else if (Sx == -1)
        {
            dir = 1;
            Sy++;
            Sx++;
        }
    }

    for (auto p : ans)
    {
        cout << (p.first + 1) << " " << (p.second + 1) << '\n';
    }
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