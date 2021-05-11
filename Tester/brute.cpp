#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, c;
    cin >> n >> c;
    vector<long long> odd;
    vector<long long> even;

    for (long long i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            even.push_back(i);
        }
        else
        {
            odd.push_back(i);
        }
    }
    vector<long long> v;
    for (long long i : odd)
        v.push_back(i);

    for (long long i : even)
        v.push_back(i);

    cout << v[c - 1] << endl;
}