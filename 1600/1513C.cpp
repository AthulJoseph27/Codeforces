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

long long lookup[10][200001][10];
const int modulo = (int)(1e9 + 7);

void solve(int cc)
{
    /*
        12 100
        23 34 45 56 67 78 89 910 1021 2132 3242 4352 5462 
    */
    int n, m;
    cin >> n >> m;

    long long ans = 0;

    string s = to_string(n);

    for (char c : s)
    {
        for (int i = 0; i < 10; i++)
        {
            // long long d = lookup[c - '0'][m][i];
            // assert(d >= 0);
            ans += lookup[c - '0'][m][i];
            ans %= modulo;
        }
    }
    // assert(ans >= 0);
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(lookup, 0, sizeof(lookup[0][0][0]) * 20000100);

    for (int i = 0; i < 10; i++)
        lookup[i][0][i] = 1;

    for (int d = 0; d < 10; d++)
    {
        for (int i = 1; i < 200001; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (lookup[d][i - 1][j] == 0)
                    continue;

                if (j == 9)
                {
                    lookup[d][i][0] = lookup[d][i - 1][j];
                    lookup[d][i][1] += lookup[d][i - 1][j];
                    lookup[d][i][1] %= modulo;
                    lookup[d][i][0] %= modulo;
                }
                else
                {
                    lookup[d][i][j + 1] = lookup[d][i - 1][j];
                    lookup[d][i][j + 1] %= modulo;
                }
            }
        }
    }

    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
    }

    return 0;
}