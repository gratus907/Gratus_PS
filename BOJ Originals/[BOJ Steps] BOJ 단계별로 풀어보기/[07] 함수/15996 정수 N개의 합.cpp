#include <vector>
long long sum(std::vector<int> &a) {
	long long ans = 0;
    int size = a.size();
	for (int i = 0; i<size; i++)
		ans += a[i];
	return ans;
}
