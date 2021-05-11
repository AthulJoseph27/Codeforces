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
    long long n, l, r;
    cin >> n >> l >> r;

    vector<long long> all_color(n);
    for (int i = 0; i < n; i++)
    {
        cin >> all_color[i];
    }

    long long cost = 0;

    // n/2 pairs of socks is required

    cost = n / 2 - min(l, r);

    unordered_map<long long, long long> left;
    unordered_map<long long, long long> right;

    set<long long> colors;

    for (long long i : all_color)
        colors.insert(i);

    for (int i = 0; i < l; i++)
    {
        left[all_color[i]]++;
    }

    for (int i = l; i < n; i++)
    {
        right[all_color[i]]++;
    }

    long long count = cost;

    for (long long c : colors)
    {
        if (count == 0)
            break;

        if (right[c] <= left[c])
            continue;

        long long total = left[c] + right[c];
        if (total % 2 != 0)
            continue;

        total /= 2;
        total = min(total, count);
        count -= total;

        if (l < r)
        {
            left[c] += total;
            right[c] -= total;
        }
        else if (l > r)
        {
            left[c] -= total;
            right[c] += total;
        }
    }

    // debug(left);
    // debug(right);

    for (long long c : colors)
    {
        if (count == 0)
            break;

        if (right[c] == left[c])
            continue;

        if (l < r)
        {
            if (right[c] < left[c])
                continue;
            long long total = min(right[c], count);
            count -= total;
            left[c] += total;
            right[c] -= total;
        }
        else if (l > r)
        {
            if (right[c] > left[c])
                continue;
            long long total = min(left[c], count);
            count -= total;
            left[c] -= total;
            right[c] += total;
        }
    }

    for (long long c : colors)
    {
        if (left[c] > right[c])
        {
            cost += (left[c] - right[c]);
        }
    }

    cout << cost << '\n';
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