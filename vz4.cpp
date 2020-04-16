#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

bool resuelveCaso() {
	int C, F, n;
	std::cin >> C >> F >> n;
	if (C == 0 && F == 0 && n == 0)
		return false;
	int v1, v2;
	vector <pair<int, int>> v;
	for (int i = 0; i < n; ++i) {
		cin >> v1 >> v2;
		v.push_back({ v1, v2 });
	}
	int min = 0;
	int fin = C;
	sort(v.begin(), v.end());
	bool imposible = false, salir = false;
	stack <pair<int, int>> cu_stack;
	int i = 0;
	while (i < n & !imposible && !salir) {
		if (v[i].first > fin && !cu_stack.empty()) {
			if (cu_stack.top().first <= fin) {
				min++;
				fin = cu_stack.top().second;
				cu_stack.pop();
			}
			else imposible = true;
		}
		if (fin >= F) salir = true;
		if (v[i].first <= fin && !salir) {
			if (cu_stack.empty() || v[i].second >= cu_stack.top().second) cu_stack.push(v[i]);
		}
		++i;
	}
	if (!cu_stack.empty() && !salir) {
		if (cu_stack.top().first <= fin) {
			min++;
			fin = cu_stack.top().second;
			cu_stack.pop();
		}
		else imposible = true;
	}
	if (fin < F) imposible = true;
	if (imposible) cout << "Imposible\n";
	else cout << min << '\n';
	return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}