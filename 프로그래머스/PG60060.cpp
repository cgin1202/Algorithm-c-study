#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <string.h>
#include <algorithm>

#define ALPHA 26
using namespace std;

struct Trie {
	Trie *next[ALPHA];
	bool isTerminal;
	map<int, int> m;

	Trie() {
		isTerminal = false;
		m.clear();
		memset(next, 0, sizeof(next));
	}

	~Trie() {
		for (int i = 0; i < ALPHA; i++)
			if (next[i])
				delete(next[i]);
	}

	void insert(int idx, string &input, int len) {
		if (input[idx] == '\0')
			isTerminal = true;
		else{
			int i = input[idx] - 'a';
			if (next[i] == NULL)
				next[i] = new Trie();

			if (m.find(len) == m.end())
				m[len] = 1;
			else
				m[len]++;
			return next[i]->insert(idx + 1, input, len);
		}
		
	}

	int getCnt(int idx, string &input, int len) {
		if (input[idx] == '\0')
			return 0;

		int i = input[idx] - 'a';
		if (input[idx] == '?')
			return m[len];

		if (next[i] == 0)
			return 0;
		else
			return next[i]->getCnt(idx + 1, input, len);
	}


};
vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;

	Trie* root = new Trie();
	Trie* reverseRoot = new Trie();

	for (int i = 0; i < words.size(); i++) {
		string input = words[i];
		int size = input.size();
		root->insert(0, input, size);

		reverse(input.begin(), input.end());
		reverseRoot->insert(0, input, size);
	}

	for (int i = 0; i < queries.size();  i++) {
		string query = queries[i];
		int size = query.size();
		int cnt = 0;
		if (query[0] == '?') {
			reverse(query.begin(), query.end());
			cnt=reverseRoot->getCnt(0, query, size);
		}
		else
			cnt = root->getCnt(0, query, size);
		answer.push_back(cnt);
	}
	return answer;
}