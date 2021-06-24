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

bool isPalindrome(string &s)
{
    for (int i = 0; i < s.size(); i++)
        if (s[i] != s[s.size() - 1 - i])
            return false;

    return true;
}

void solve(int cc)
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    /*
        if len(s) is odd and s is palindrome,
        if center digit is 0, then alice can keep the string palindrome
        hence forcing bob to pay 1 dollar and the string would become non palindrome, hence forth
        alice can reverse the string and pay 0 dollar
    */

    if (isPalindrome(s))
    {
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                count++;
        }

        if (s.size() % 2 != 0 && s[s.size() / 2] == '0' && count > 1)
        {
            cout << "ALICE" << '\n';
            return;
        }
        cout << "BOB" << '\n';
    }
    else
    {
        /*
            alice can rotate the string, untill bob make the string palindrome
            for bob to win , he have to make the string palindrome with changing less than n/2 zeros
            but when the string is about to be palindrome, alice cud always pay 1 dollar and make the
            life harder for bob

            chances for draw ?

            if s can be made palindrome with one move, then its optimal for alice to pay 1 dollar
            and there is one more zero, then bob will pay one dollar and the game wud be drawn
        */

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                count++;
            }
        }

        if (s.size() % 2 != 0 && count == 2 && (s[s.size() / 2] == '0'))
            cout << "DRAW" << '\n';
        else
            cout << "ALICE" << '\n';
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