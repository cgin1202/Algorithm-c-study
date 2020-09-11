#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(pair<int, int> x, pair<int, int> y) {
	if (x.first < y.first)
		return true;
	else if (x.first == y.first)
		return x.second < y.second;
	return false;
}

int solution(vector<int> food_times, long long k) {
	int answer = 0;

	vector<pair<int, int>> v;
	for (int i = 0; i < food_times.size(); i++)
		v.push_back({ food_times[i], i });

	sort(v.begin(), v.end(), compare);

	int n = food_times.size();
	vector<bool> isVisited(n + 1, false);

	long long before = 0;
	int people = n;

	for (int i = 0; i < v.size(); i++) {
		long long time = v[i].first;
		if (k - (time-before)*people >= 0) {
			k = k - (time-before)*people;
			isVisited[v[i].second] = true;
			before = v[i].first;
			people--;
		}
		else
			break;
	}

	vector<int> result;

	for (int i = 0; i < n; i++)
		if (isVisited[i] == false)
			result.push_back(i);

	if (k >= 0 && result.size() == 0)
		answer = -1;
	else {
		int m = result.size();
		k = k % m;
		answer = result[k] + 1;
	}
	return answer;
}