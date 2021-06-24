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

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void solve(int cc)
{
    int n;
    cin >> n;

    vector<long long> a(n);

    for (long long &i : a)
        cin >> i;

    vector<vector<long long>> answers;

    long long prime = 1000000007;
    long long prime2 = 1000000009;

    bool flag = true;

    for (int i = 1; i < n; i++)
    {
        if (gcd(a[i], a[i - 1]) != 1)
        {
            // debug(a[i], a[i - 1], gcd(a[i], a[i - 1]));
            long long mn = min(a[i], a[i - 1]);
            if (a[i] < a[i - 1])
            {
                long long p = prime;
                if (flag)
                {
                    p = prime2;
                    flag = !flag;
                }
                else
                {
                    p = prime;
                    flag = !flag;
                }
                a[i - 1] = p;
                answers.push_back({i - 1, i, p, mn});
            }
            else
            {
                long long p = prime;
                if (flag)
                {
                    p = prime2;
                    flag = !flag;
                }
                else
                {
                    p = prime;
                    flag = !flag;
                }
                a[i] = p;
                answers.push_back({i - 1, i, mn, p});
            }
        }
    }

    // debug(a);

    assert(answers.size() <= n);
    cout << answers.size() << '\n';

    for (auto v : answers)
    {
        cout << (v[0] + 1) << " " << (v[1] + 1) << " " << v[2] << " " << v[3] << '\n';
    }

    // unordered_map<int, int> prefs;
    // unordered_map<int, int> unq;

    // for (int i = 1; i < n; i++)
    // {
    //     if (gcd(a[i], a[i - 1]) != 1)
    //     {
    //         prefs[i]++;
    //         prefs[i - 1]++;
    //         unq[i]++;
    //     }
    // }

    // vector<vector<long long>> answers;

    // for (int i = 1; i < n; i++)
    // {
    //     if (unq[i] == 0)
    //         continue;

    //     if (prefs[i] == 2)
    //     {
    //         if (!((a[i] < a[i - 1]) && (a[i] < a[i + 1])))
    //         {
    //             if (a[i] > a[i - 1])
    //             {
    //                 answers.push_back({i - 1, i, a[i - 1], (a[i - 1] * a[i + 1] - 1)});
    //             }
    //             else
    //             {
    //                 answers.push_back({i, i + 1, a[i + 1], (a[i - 1] * a[i + 1] - 1)});
    //             }
    //             a[i] = (a[i - 1] * a[i + 1] - 1);
    //             i++;
    //         }
    //         else
    //         {
    //             if (i == 1)
    //             {
    //                 if (a[i - 1] > a[i])
    //                 {
    //                     answers.push_back({i - 1, i, a[i], a[i] + 1});
    //                     a[i - 1] = a[i] + 1;
    //                 }
    //                 else
    //                 {
    //                     answers.push_back({i - 1, i, a[i - 1], a[i - 1] + 1});
    //                     a[i] = a[i - 1] + 1;
    //                 }
    //             }
    //             else
    //             {
    //                 if (a[i - 1] > a[i])
    //                 {
    //                     answers.push_back({i - 1, i, a[i], (a[i] * a[i - 2] - 1)});
    //                     a[i - 1] = (a[i] * a[i - 2] - 1);
    //                 }
    //                 else
    //                 {
    //                     if (i == (n - 1))
    //                     {
    //                         answers.push_back({i - 1, i, a[i - 1], a[i] + 1});
    //                         a[i] = a[i] + 1;
    //                     }
    //                     else
    //                     {
    //                         answers.push_back({i - 1, i, a[i - 1], a[i - 1] * a[i + 1] - 1});
    //                         a[i] = a[i - 1] * a[i + 1] - 1;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     else
    //     {
    //         if (i == 1)
    //         {
    //             if (a[i - 1] > a[i])
    //             {
    //                 answers.push_back({i - 1, i, a[i], a[i] + 1});
    //                 a[i - 1] = a[i] + 1;
    //             }
    //             else
    //             {
    //                 answers.push_back({i - 1, i, a[i - 1], a[i - 1] + 1});
    //                 a[i] = a[i - 1] + 1;
    //             }
    //         }
    //         else
    //         {
    //             if (a[i - 1] > a[i])
    //             {
    //                 answers.push_back({i - 1, i, a[i], (a[i] * a[i - 2] - 1)});
    //                 a[i - 1] = (a[i] * a[i - 2] - 1);
    //             }
    //             else
    //             {
    //                 if (i == (n - 1))
    //                 {
    //                     answers.push_back({i - 1, i, a[i - 1], a[i] + 1});
    //                     a[i] = a[i] + 1;
    //                 }
    //                 else
    //                 {
    //                     answers.push_back({i - 1, i, a[i - 1], a[i - 1] * a[i + 1] - 1});
    //                     a[i] = a[i - 1] * a[i + 1] - 1;
    //                 }
    //             }
    //         }
    //     }
    // }

    // // debug(a);

    // cout << answers.size() << '\n';

    // for (auto v : answers)
    // {
    //     cout << (v[0] + 1) << " " << (v[1] + 1) << " " << v[2] << " " << v[3] << '\n';
    // }
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