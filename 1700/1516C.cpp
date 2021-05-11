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
    // sum will be n/2
    // if total sum is odd then, array cant be split into two sub sequence of  equal sum
    // if the total is even , check if the total sum/2 can be constructed

    int n;
    cin >> n;

    vector<int> a(n);

    int total = 0;

    for (int &i : a)
    {
        cin >> i;
        total += i;
    }

    // debug(a);

    int count = 0;

    if (total % 2 != 0)
    {
        cout << 0 << '\n';
        return;
    }

    // more like coin change problem, see which all numbers are attainble

    vector<bool> dp(200001, false);

    dp[0] = true;

    for (int i : a)
    {
        for (int j = (dp.size() - 1); j >= i; j--) // iterate backwards else we may double count thngs
        {
            if (dp[j - i])
            {
                // debug(j, j + 1);
                dp[j] = true;
            }
        }
    }

    // debug(dp[(total / 2)] == true ? "TRUE" : "False");
    // now dp contains which all sums are possible

    if (!dp[(total / 2)])
    {
        cout << 0 << '\n';
        return;
    }

    // we have two subsequence whose sum is equal
    // so removing an odd element will remove this
    // if all elements are even then ......
    // we can keep dividing the array with 2 , until we encounter a odd number
    // this is just like rescaling, the properties would remain the same

    int index = -1;
    int trailing_zeros = 33;

    for (int i = 0; i < n; i++)
    {
        if (__builtin_ctz(a[i]) < trailing_zeros)
        {
            trailing_zeros = __builtin_ctz(a[i]);
            index = i;
        }
    }

    // debug(total);

    assert(index != -1);

    cout << 1 << '\n';
    cout << (index + 1) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    solve(1);

    return 0;
}

// [2,6,5,7]
