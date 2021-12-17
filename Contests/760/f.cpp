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

int dddd = 0;

bool can_convert(string x, string y)
{
    int last_one = -1;

    for (int i = x.size() - 1; i >= 0; i--)
    {
        if (x[i] == '1')
        {
            last_one = i;
            break;
        }
    }

    int rem_zeros_count = 0;

    for (int i = last_one + 1; i < x.size(); i++)
        rem_zeros_count++;

    bool can = false;

    int y_rem_zeros = -1;

    if (dddd != 0)
        rem_zeros_count = 0;

    string base = x.substr(0, last_one + 1);

    for (int i = 0; i < y.size(); i++)
    {
        if (base.size() > (y.size() - i))
        {
            break;
        }
        if (base == y.substr(i, base.size()))
        {
            int cnt = 0;
            for (int j = i + base.size(); j < y.size(); j++)
            {
                if (y[j] == '1')
                    break;
                cnt++;
            }

            y_rem_zeros = cnt;

            if (cnt > 0 && cnt == rem_zeros_count)
            {
                can = true;
                break;
            }
            else if (cnt == 0)
            {
                can = true;
                break;
            }
        }
    }

    if (!can)
    {
        // debug(x);
        // debug(y);
        // debug("1");
        return false;
    }

    if (y_rem_zeros > 0)
    {
        for (int i = 0; i < y_rem_zeros; i++)
            base += '0';

        base += '1';
    }

    string temp = "";

    // int y_first_one = -1;

    // for (int i = 0; i < y.size(); i++)
    // {
    //     if (y[i] == '1')
    //     {
    //         y_first_one = i;
    //         break;
    //     }
    // }

    // y = y.substr(y_first_one, y.size() - y_first_one);

    for (int i = 0; i < y.size(); i++)
    {
        if (base.size() > (y.size() - i + 1))
        {
            break;
        }

        if (y.substr(i, base.size()) == base)
        {
            for (int j = 0; j < i; j++)
            {
                if (y[j] == '0')
                    return false;
            }

            for (int j = i + base.size(); j < y.size(); j++)
            {
                if (y[j] == '0')
                    return false;
            }

            return true;
        }
    }

    return false;
}

void solve(int cc)
{
    long long a, b;

    cin >> a >> b;

    if (a == b)
    {
        cout << "YES\n";
        return;
    }

    // if (a > b)
    //     swap(a, b);

    string x, y;

    x = std::bitset<64>(a).to_string();
    y = std::bitset<64>(b).to_string();

    if (y.back() == '0')
    {
        cout << "NO\n";
        return;
    }

    int index = -1;

    for (int i = 0; i < 64; i++)
    {
        if (x[i] != '0')
        {
            index = i;
            break;
        }
    }

    x = x.substr(index, x.size() - index);

    for (int i = 0; i < 64; i++)
    {
        if (y[i] != '0')
        {
            index = i;
            break;
        }
    }

    y = y.substr(index, y.size() - index);

    if (can_convert(x, y))
    {
        cout << "YES\n";
        return;
    }

    reverse(all(x));

    string tmp = x;

    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] != '0')
        {
            index = i;
            break;
        }
    }

    x = x.substr(index, x.size() - index);

    if (can_convert(x, y))
    {
        cout << "YES\n";
        return;
    }

    tmp = '1' + tmp;

    if (can_convert(tmp, y))
    {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    T = 1;

    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
    }

    return 0;
}