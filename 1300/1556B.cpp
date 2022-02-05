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
    int n;
    cin >> n;

    vi a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = a[i] % 2;
    }

    int odd = 0, even = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i])
            odd++;
        else
            even++;
    }

    if (abs(odd - even) > 1)
    {
        cout << -1 << '\n';
        return;
    }

    deque<ll> ones;
    deque<ll> zeros;

    ll moves = 0;

    if (odd >= even)
    {
        for (int i = 0; i < n; i++)
        {
            int has_to = !(i % 2);
            if (has_to != a[i])
            {
                if (a[i])
                    ones.push_back(i);
                else
                    zeros.push_back(i);
            }
            else if (i == (n - 1))
            {
                if (a[i])
                    ones.push_back(i);
                else
                    zeros.push_back(i);
            }
        }
        while (ones.size() > 0 && zeros.size() > 0)
        {
            moves += llabs(ones.front() - zeros.front());
            ones.pop_front();
            zeros.pop_front();
        }
    }

    ll ans = moves;

    moves = 0;

    ones.clear();
    zeros.clear();

    if (even >= odd)
    {
        if (even != odd)
            ans = LLONG_MAX;
        for (int i = 0; i < n; i++)
        {
            int has_to = (i % 2);
            if (has_to != a[i])
            {
                // wrong position
                if (a[i])
                    ones.push_back(i);
                else
                    zeros.push_back(i);
            }
            else if (i == (n - 1))
            {
                if (a[i])
                    ones.push_back(i);
                else
                    zeros.push_back(i);
            }
        }

        while (ones.size() > 0 && zeros.size() > 0)
        {
            moves += llabs(ones.front() - zeros.front());
            ones.pop_front();
            zeros.pop_front();
        }

        ans = min(ans, moves);
    }

    cout << ans << '\n';
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