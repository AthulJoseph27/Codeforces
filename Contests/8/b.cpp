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
    int n;
    cin >> n;

    vector<int> a(n);

    for (int &i : a)
        cin >> i;

    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }

    int zeros = 0, neg = 0, non_neg = 0;
    int pmn = INT_MAX, nmx = INT_MIN;

    for (int i : a)
        if (i == 0)
            zeros++;
        else if (i < 0)
        {
            nmx = max(nmx, i);
            neg++;
        }
        else
        {
            pmn = min(pmn, i);
            non_neg++;
        }

    sort(all(a));

    int diff = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        if (a[i] < 0)
        {
            diff = min(diff, abs(a[i] - a[i - 1]));
        }
    }

    if (non_neg == 0)
    {
        cout << n << '\n';
        return;
    }

    if (zeros <= 1)
    {
        if (diff == INT_MAX)
        {
            if (neg == 0)
            {
                cout << 1 << '\n';
                return;
            }
            // only 1 neg
            if (zeros == 0)
            {
                cout << 2 << '\n';
                return;
            }
            else
            {
                if (pmn <= abs(a[0]))
                {
                    neg = neg + zeros + 1;
                }
                else
                {
                    neg = neg + zeros;
                }
                cout << neg << '\n';
                return;
            }
        }
        neg = neg + zeros;
        if (zeros == 0)
        {
            if (diff >= pmn)
                neg++;
        }
        else
        {
            if (diff >= pmn && abs(nmx) >= pmn)
                neg++;
        }
        cout << neg << '\n';
    }
    else
    {
        cout << (zeros + neg) << '\n';
    }
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