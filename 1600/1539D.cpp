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
    long long n;
    cin >> n;

    vector<pair<long long, long long>> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(all(a), [&](const pair<long long, long long> aa, const pair<long long, long long> bb)
         { return aa.second > bb.second; });

    long long cost = 0;
    long long items = 0;

    int s = 0, e = n - 1;

    /*
        3
        3 4
        1 3
        items = 1 + 2 +1+1
        2+2*2+1+1 = 2+2+4 = 8
    */

    // debug(a);

    while (s < e)
    {
        while (s < e && items >= a[e].second)
        {
            cost += a[e].first;
            items += a[e].first;
            e--;
        }

        if (s >= e)
            break;

        if (a[s].first == 0)
        {
            s++;
        }

        if ((items + a[s].first) >= a[e].second)
        {
            long long delta = a[e].second - items;
            items += delta;
            a[s].first -= delta;

            cost += (delta * 2LL);

            items += (a[e].first);
            cost += (a[e].first);

            a[e].first = 0;

            e--;
        }
        else
        {
            items += a[s].first;
            cost += (a[s].first * 2LL);

            a[s].first = 0;
            s++;
        }

        // debug(a, cost);
    }

    if (items >= a[s].second)
    {
        items += a[s].first;
        cost += (a[s].first);
    }
    else
    {
        long long delta = a[s].second - items;

        if (delta <= a[s].first)
        {
            items += delta;
            cost += (delta * 2LL);
            a[s].first -= delta;
            items += a[s].first;
            cost += a[s].first;
        }
        else
        {
            items += a[s].first;
            cost += (a[s].first * 2LL);
        }
    }

    // debug(a, cost);

    cout << cost << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(1);

    return 0;
}