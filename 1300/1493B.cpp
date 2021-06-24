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

pair<int, int> getTime(string s)
{
    int t = 0;

    int h = 0, m = 0;

    h = (s[0] - '0') * 10 + (s[1] - '0');
    m = (s[3] - '0') * 10 + (s[4] - '0');

    return make_pair(h, m);
}

string getTime(int h, int m)
{
    assert(h != -1 && m != -1);

    string H = "", M = "";

    if (h < 10)
        H = "0";

    if (m < 10)
        M = "0";

    H += to_string(h);
    M += to_string(m);

    return H + ":" + M;
}

int getFlipTime(int n)
{
    string s = to_string(n);
    reverse(all(s));
    string res = "";

    for (char c : s)
        if (c == '2')
            res += '5';
        else if (c == '5')
            res += '2';
        else
            res += c;

    return stoi(res);
}

void solve(int cc)
{
    // numbers 0,1,2,5,8 are symmetrical
    // HH - first digit can be 0,1,2 and the second digit can be any number
    // on reflection , HH:MM becomes M'M':H'H'
    // possible valid times are 00:00 , 05:11 , 11:20
    // 0 _:_ _ => 2 * 3 * 4 * 5 = 120
    // 2 _:_ _ => 1 * 2 * 4 * 5 = 40
    // valid hours = 00 01 02 05 08 10 11 12 15 18 20 21 22

    int H, M;
    cin >> H >> M;

    string s;
    cin >> s;

    vector<int> valid_time = {0, 1, 2, 5, 8, 10, 11, 12, 15, 18, 20, 21, 22, 25, 28, 50, 51, 52, 55, 58, 80, 81, 82, 85, 88, 100};
    vector<int> flips = {0, 10, 50, 20, 80};

    for (int i = 5; i < valid_time.size(); i++)
    {
        flips.push_back(getFlipTime(valid_time[i]));
    }

    // debug(valid_time);
    // debug(flips);

    // exit(0);

    pair<int, int> inp = getTime(s);

    int h = -1;
    int m = -1;

    // debug(valid_time);

    bool hourOk = false;

    for (int i = 0; i < valid_time.size(); i++)
    {
        if (valid_time[i] >= H)
        {
            break;
        }
        if (inp.first == valid_time[i] && flips[i] < M)
        {
            //     debug(inp.first, valid_time[i]);
            hourOk = true;
            h = inp.first;
            break;
        }
        if (inp.first < valid_time[i] && flips[i] < M)
        {
            h = valid_time[i];
            break;
        }
    }

    if (h == -1)
    {
        cout << "00:00" << '\n';
        return;
    }

    if (hourOk)
    {
        for (int i = 0; i < valid_time.size(); i++)
        {
            if (valid_time[i] >= M)
            {
                break;
            }
            if (inp.second == valid_time[i] && flips[i] < H)
            {
                cout << s << '\n';
                return;
            }
            if (inp.second < valid_time[i] && flips[i] < H)
            {
                m = valid_time[i];
                break;
            }
        }
    }

    if (m == -1 && hourOk)
    {
        int index = -1;

        for (int i = 0; i < valid_time.size(); i++)
        {
            if (valid_time[i] >= H)
            {
                break;
            }
            if (valid_time[i] > h && flips[i] < M)
            {
                index = i;
                h = valid_time[i];
                break;
            }
        }

        if (index == -1)
        {
            cout << "00:00" << '\n';
            return;
        }
    }

    if (m == -1)
    {
        m = 0;
    }

    string res = getTime(h, m);
    cout << res << '\n';
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