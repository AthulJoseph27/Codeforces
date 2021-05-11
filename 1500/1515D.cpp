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
    int n, l, r;

    int mx_color = 0;

    cin >> n >> l >> r;

    vector<int> colors(n);

    for (int &i : colors)
    {
        cin >> i;
        i--;
        mx_color = max(mx_color, i);
    }

    map<int, long long> lcolors;
    map<int, long long> rcolors;

    for (int i = 0; i < l; i++)
    {
        lcolors[colors[i]]++;
    }

    for (int i = l; i < n; i++)
    {
        rcolors[colors[i]]++;
    }

    if (l < r)
    {
        swap(l, r);
        swap(lcolors, rcolors);
    }

    long long totalCost = 0;
    long long diff = n / 2 - r;

    for (int i = 0; i <= mx_color; i++)
    {
        if (lcolors[i] > rcolors[i])
        {
            long long v = lcolors[i] - rcolors[i];
            v /= 2;
            long long d = min(diff, v);
            lcolors[i] -= d;
            rcolors[i] += d;
            diff -= d;
            l -= d;
            r += d;
            totalCost += d;
        }
    }

    if (diff > 0)
    {
        for (int i = 0; i <= mx_color; i++)
        {
            if (diff == 0)
            {
                break;
            }
            if (lcolors[i] > rcolors[i])
            {
                long long d = lcolors[i] - rcolors[i];

                if (d == 1)
                {
                    lcolors[i]--;
                    rcolors[i]++;
                    totalCost++;
                    diff--;
                }
            }
        }
    }

    assert(diff == 0);

    diff = 0;

    for (int i = 0; i <= mx_color; i++)
    {
        diff += llabs(rcolors[i] - lcolors[i]);
    }

    diff /= 2;

    totalCost += diff;

    cout << totalCost << '\n';
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

long long min(long long a, long long b)
{
    if (a < b)
        return a;
    return b;
}