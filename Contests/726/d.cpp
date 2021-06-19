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

int binpower(int base, int e, int mod)
{
    int result = 1;
    base %= mod;
    while (e)
    {
        if (e & 1)
            result = (long long)result * base % mod;
        base = (long long)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(int n, int a, int d, int s)
{
    long long x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++)
    {
        x = x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool MillerRabin(int n)
{ // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    int d = n - 1;
    while ((d & 1) == 0)
    {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

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

vector<int>all_primes;

int firstFactor(int n){

    for(int i=0;i<all_primes.size();i++)
        if(n%i == 0)
            return i;
}

void solve(int cc)
{
    int n;
    cin >> n;

    if (n == 1 || MillerRabin(n))
    {
        cout << "Bob" << '\n';
    }
    else
    {
        
        
        if (alice)
        {
            cout << "Bob" << '\n';
        }
        else
        {
            cout << "Alice" << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    all_primes = primeSieve((int)sqrt(1'000'000'005));

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
    }

    return 0;
}