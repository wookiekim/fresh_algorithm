#include <iostream>
#include <algorithm>

using namespace std;

int n, k, ans, a[10001];

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) cin >> a[i];
	
	std::sort(a, a + n); 
        ans = a[n - 1] - a[0];
	for (int i = n - 1; i > 0; i--) a[i] = a[i] - a[i - 1];
	
	std::sort(a + 1, a + n);

        k--;
	for (int i = n - 1; i > 0 && k--; i--) ans -= a[i];

	cout << ans;

	return 0;
}
