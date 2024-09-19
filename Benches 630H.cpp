#include <iostream>
#include <string>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    long long int numberOfPaths, result = 1ll;
    cin >> numberOfPaths;
    result = (numberOfPaths * (numberOfPaths-1) * (numberOfPaths-2) * (numberOfPaths-3) * (numberOfPaths-4))/120ll;
    result = result * (numberOfPaths * (numberOfPaths-1) * (numberOfPaths-2) * (numberOfPaths-3) * (numberOfPaths-4));
    cout << result << endl;
    return 0;
}