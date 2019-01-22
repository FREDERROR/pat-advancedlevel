#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

struct node {
	int score;
	string cn;
};

bool cmp(node a, node b) {
	return a.score != b.score ? a.score > b.score : a.cn < b.cn;
}

int main(void) {
	int N, M,num;
	string s;
	cin >> N >> M;
	vector<node> v(N);
	
	for(int i = 0; i < N; i++) {
		cin >> v[i].cn >> v[i].score;
	}
	for (int i = 0; i < M; i++) {
		int cnt = 0;
		cin >> num >> s;
		printf("Case %d: %d %s\n",i+1,num,s.c_str());
		vector<node> ans;
		if (num == 1) {
			for (int i = 0; i < N; i++) {
				if (s[0] == v[i].cn[0]) {
					ans.push_back(v[i]);
				}
			}
		}
		else if (num == 2) {
			int sum = 0;
			for (int i = 0; i < N; i++) {
				string site;
				site = v[i].cn.substr(1, 3);
				if (site == s) {
					cnt++;
					sum = sum + v[i].score;
				}
			}
			if (cnt != 0) {
				cout <<cnt << " " << sum << "\n";
			}	
		}
		else if (num == 3) {
			unordered_map<string, int> map;
			int cnt = 0;
			for (int i = 0; i < N; i++) {
				string date = v[i].cn.substr(4, 6);
				if (date == s) {
					map[v[i].cn.substr(1, 3)]++;
				}
			}
			for (auto it : map) {
				ans.push_back({it.second,it.first });
			}
		}
		sort(ans.begin(), ans.end(), cmp);
		if (((num == 1 || num == 3) && ans.size() == 0) || (num == 2 && cnt == 0)) {
			cout << "NA\n";
			
		}else
		{
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i].cn << " " << ans[i].score << "\n";
			}
		}
	}
	system("pause");
	return 0;
}