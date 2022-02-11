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

void bfs(set<pi> &visited, pi pos, int n, char last_dir)
{
    if (n == 0)
    {
        visited.insert(pos);
        return;
    }

    if (last_dir == 'N' || last_dir == 'S')
    {
        bfs(visited, {pos.first + 1, pos.second}, n - 1, 'E');
        bfs(visited, {pos.first - 1, pos.second}, n - 1, 'W');
    }
    else
    {
        bfs(visited, {pos.first, pos.second + 1}, n - 1, 'N');
        bfs(visited, {pos.first, pos.second - 1}, n - 1, 'S');
    }
}

void solve_brute(int cc)
{
    int n;
    cin >> n;

    pi pos = {0, 0};

    set<pi> visited;

    bfs(visited, pos, n, 'N');
    bfs(visited, pos, n, 'S');
    bfs(visited, pos, n, 'W');
    bfs(visited, pos, n, 'E');

    cout << visited.size() << '\n';
}

void solve(int cc)
{
    int n;
    cin >> n;

    if (n <= 2)
    {
        cout << 4 << '\n';
        return;
    }

    if (n == 3)
    {
        cout << 12 << '\n';
        return;
    }

    n--;
    vl diff;

    ll a = 0, b = 8, c = 3, d = 12;

    for (int i = 0; i < n; i++)
    {
        ll e = a + b;
        diff.push_back(a);
        diff.push_back(e);
        ll f = c + d;
        diff.push_back(c);
        diff.push_back(f);
        a = e;
        b = d + 4ll;
        c = f;
        d += 8ll;
    }
    // debug(diff);

    ll cur = 4;

    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 1)
        {
            cur += diff[i];
        }
        else
        {
            cur -= diff[i];
        }
    }

    cout << cur << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    solve(0);
    // // T = 1;
    // cin >> T;

    // for (int i = 0; i < T; i++)
    // {
    //     solve(i + 1);
    // }

    return 0;
}