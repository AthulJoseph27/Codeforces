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

vector<int> primeSieve(int n)
{
    vector<int> numbers(n + 1, true);
    vector<int> prime;

    numbers[0] = false;
    numbers[1] = false;

    int sqt = sqrt(n) + 1;

    for (int i = 2; i <= n; i++)
    {
        if (i > sqt)
        {
            if (numbers[i])
                prime.push_back(i);

            continue;
        }

        if (numbers[i])
        {
            prime.push_back(i);
            for (int j = i * i; j <= n; j += i)
            {
                numbers[j] = false;
            }
        }
    }

    return prime;
}

vector<int> primes;

void solve(int cc)
{
    int d;

    cin >> d;

    long long ans = 1;

    int last = 1;

    int cnt = 0;

    for (int i = 0; i < primes.size(); i++)
    {
        if (cnt == 2)
            break;

        if ((last + d) <= primes[i])
        {
            last = primes[i];
            // debug(last);
            ans = ans * ((long long)primes[i]);
            cnt++;
        }
    }

    assert(cnt == 2);

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    primes = primeSieve(1e5);
    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
    }

    return 0;
}