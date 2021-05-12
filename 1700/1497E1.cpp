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

vector<int> smallest_factor((int)1e7 + 6, 1);

vector<int> primeSieve(int n)
{
    vector<int> numbers(n + 1, true);
    vector<int> pr;

    numbers[0] = false;
    numbers[1] = false;

    int sqt = sqrt(n) + 1;

    for (int i = 2; i <= n; i++)
    {
        if (i > sqt)
        {
            if (numbers[i])
                pr.push_back(i);

            continue;
        }

        if (numbers[i])
        {
            pr.push_back(i);
            for (int j = i * i; j <= n; j += i)
            {
                if (numbers[j])
                {
                    numbers[j] = false;
                    smallest_factor[j] = i;
                }
            }
        }
    }

    return pr;
}

vector<int> prime;
vector<int> normalized_map((int)1e7 + 6, -1);

int normalize(int n)
{
    if (normalized_map[n] != -1)
    {
        return normalized_map[n];
    }

    int N = n;

    vector<pair<int, int>> factors;

    while (n != 1)
    {
        int cnt = 0;

        int i = smallest_factor[n];

        if (i == 1)
        {
            factors.emplace_back(n, i);
            break;
        }

        while (n % i == 0)
        {
            n /= i;
            cnt++;
        }

        if (cnt > 0)
            factors.emplace_back(i, cnt);
    }

    for (auto &p : factors)
    {
        p.second %= 2; // for a perfect square, all the powers of prime factors will be even
    }

    int res = 1;

    for (auto p : factors)
    {
        if (p.second != 0)
            res *= p.first;
    }

    normalized_map[N] = res;

    return res;
}

void solve(int cc)
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        a[i] = normalize(d);
    }

    unordered_set<int> st;

    int count = 1;

    for (int i : a)
    {
        if (st.find(i) != st.end())
        {
            st.clear();
            count++;
        }
        st.insert(i);
    }

    cout << count << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    prime = primeSieve(1e7 + 5);

    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
    }

    return 0;
}