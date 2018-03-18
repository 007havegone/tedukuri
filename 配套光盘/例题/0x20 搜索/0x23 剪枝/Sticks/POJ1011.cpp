#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100], v[100], n, len, cnt;

// ����ƴ��stick��ԭʼľ�����Ѿ�ƴ����stick-1����
// ��stick��ľ���ĵ�ǰ����Ϊcab
// ƴ�ӵ���stick��ľ���е���һ��Сľ��Ϊlast
bool dfs(int stick, int cab, int last) {
	// ����ԭʼľ���Ѿ�ȫ��ƴ�ã������ɹ�
	if (stick > cnt) return true;
	// ��stick��ľ���Ѿ�ƴ�ã�ȥƴ��һ��
	if (cab == len) return dfs(stick + 1, 0, 1);
	int fail = 0; // ��֦(b)
	// ��֦(a)��Сľ�����ȵݼ�����last��ʼö�٣�
	for (int i = last; i <= n; i++)
		if (!v[i] && cab + a[i] <= len && fail != a[i]) {
			v[i] = 1;
			if (dfs(stick, cab + a[i], i + 1)) return true;
			fail = a[i];
			v[i] = 0; // ��ԭ�ֳ�
			if (cab == 0) return false; // ��֦(c)
		}
	return false; // ���з�֧�����Թ�������ʧ��
}

int main() {
	while (cin >> n && n) {
		int sum = 0, val = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
			val = max(val, a[i]);
		}
		sort(a + 1, a + n + 1);
		reverse(a + 1, a + n + 1); 
		for (len = val; len <= sum; len++) {
			if (sum % len) continue;
			cnt = sum / len; // ԭʼľ������Ϊlen����cnt��
			memset(v, 0, sizeof(v));
			if (dfs(1, 0, 1)) break;
		}
		cout << len << endl;
	}
}