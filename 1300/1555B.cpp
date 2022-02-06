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
    int W, H;
    cin >> W >> H;

    pi bl, tr;
    cin >> bl.first >> bl.second >> tr.first >> tr.second;

    int w, h;
    cin >> w >> h;

    float dist = 3.402823466e+38F;

    bool can = false;

    // move the box to the right

    // w-bl.first
    int delta = max(0, w - bl.first);
    if ((delta + tr.first) <= W)
    {
        can = true;
        dist = min(dist, (float)delta);
    }

    // move the box to the left

    delta = max(0, tr.first - (W - w));
    if ((bl.first - delta) >= 0)
    {
        can = true;
        dist = min(dist, (float)delta);
    }

    // move the box to the top
    delta = max(0, h - bl.second);
    if ((tr.second + delta) <= H)
    {
        can = true;
        dist = min(dist, (float)delta);
    }

    // move the box to the bottom
    delta = max(0, tr.second - (H - h));
    if ((bl.second - delta) >= 0)
    {
        can = true;
        dist = min(dist, (float)delta);
    }

    if (can)
        printf("%.7f\n", dist);
    else
        printf("-1\n");
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