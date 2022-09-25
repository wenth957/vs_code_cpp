#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
// [1,2] [2,3]���Ժϲ�
const int N = 100010;
int n;
vector<PII> segs;
void merge(vector<PII>& segs)
{
	vector <PII> res;
	sort(segs.begin(), segs.end());
	int st = -2e9, ed = -2e9;
	for (auto seg : segs)
	{
		if (ed < seg.first)
		{
			if (st != -2e9) res.push_back({ st, ed });
			//����st ed
			st = seg.first, ed = seg.second;
		}
		else ed = max(ed, seg.second);
	}
	if (st != -2e9) res.push_back({ st, ed });//ÿ�μӵĶ���ǰһ�����䣬��Ҫ������һ������

	segs = res;

}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i ++)
	{
		int l, r;
		cin >> l >> r;
		segs.push_back({ l ,r });
	}

	merge(segs);
	cout << segs.size() << endl;
	return 0;
}