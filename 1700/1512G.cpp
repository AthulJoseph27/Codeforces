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

const int MAXN = 1e7 + 1;

int spf[MAXN]; // stores the smallest prime factor
long long sm[MAXN];

void prime_sieve()
{
    spf[1] = 1;

    for (int i = 3; i < MAXN; i += 2)
    {
        spf[i] = i; // initializing spf of every odd number to itself
    }

    for (int i = 2; i < MAXN; i += 2)
        spf[i] = 2; // spf of all even number is 2

    for (int i = 3; i * i < MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j = i * i; j < MAXN; j += i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

int ans[MAXN];

void solve(int cc)
{
    int c;
    cin >> c;

    cout << ans[c] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(sm, 0, sizeof(sm));

    prime_sieve();

    sm[1] = 1;

    for (int i = 2; i < MAXN; i++)
    {
        if (spf[i] == i)
        {
            sm[i] = spf[i] + 1;
            continue;
        }

        long long last = 1;
        long long _sm = 1;

        int j = i;

        while (j % spf[i] == 0)
        {
            j /= spf[i];
            last *= (long long)spf[i];
            _sm += last;
        }

        sm[i] = _sm * sm[j];
    }

    for (int i = 0; i < MAXN; i++)
        ans[i] = -1;

    for (int i = 1; i < MAXN; i++)
        if (sm[i] < MAXN)
            if (ans[sm[i]] == -1)
                ans[sm[i]] = i;
            else
                ans[sm[i]] = min(i, ans[sm[i]]);

    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
    }

    return 0;
}