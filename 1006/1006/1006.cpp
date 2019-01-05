#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct person {
	string id;
	string sign_in_time;
	string sign_out_time;
};

bool unlock(person p1,person p2) {
	return p1.sign_in_time < p2.sign_in_time;
}
bool lock(person p1, person p2) {
	return p1.sign_out_time > p2.sign_out_time;
}
int main(void) {
	person *p;
	vector<person> v;
	int M;
	cin >> M;
	p = new person[M];
	for (int i = 0; i < M; i++) {
		cin >> p[i].id >> p[i].sign_in_time >> p[i].sign_out_time;
		v.push_back(p[i]);
	}
	sort(v.begin(), v.end(), unlock);
	string unlock_person = (*v.begin()).id;
	sort(v.begin(), v.end(), lock);
	string lock_person = (*v.begin()).id;
	cout << unlock_person << " " << lock_person;
	system("pause");
	return 0;
}