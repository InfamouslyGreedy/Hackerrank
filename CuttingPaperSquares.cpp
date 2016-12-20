#include <iostream>

using namespace std;

int main()
{
    long long int n = 0, m = 0;
    cin >> n >> m;
    long long int res = (n - 1) + (n * (m - 1));
    cout << res << endl;
    return 0;
}
