/* 关注了N个主播，将一天划分为M个时间段，主播每天都有固定的直播时间，问一天最多能完整地看多少场直播 */
/*  设置一个struct用来存储主播的直播时间， 写一个bool函数作为sort的判断条件， 首先按直播结束的时间从小到大排序，用贪心算法，每一次都选择直播最先结束的进行选择，期间比较当前直播的结束时间是否小于下场直播的开始时间， 若为否，就跳过下一场，比较之后的一场，依次类推 */
/* 注意当直播的结束时间为0时，代表着最后才结束，可以将0替换为M， 若结束时间小于开始时间，表示跨越了一天，可以直接将结束时间设置为M+1，以便后续遍历时直接筛除 */
#include <iostream>
#include <algorithm>

struct Node{
	int s;
	int t;
};

bool compare(Node n1, Node n2){
	if(n1.t == n2.t){
		return n1.s <= n2.s;
	}
	return n1.t < n2.t;
}

using namespace std;

Node a[100000];

int main(){
	int N,M;
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> a[i].s >> a[i].t;
		if(a[i].t == 0){
			a[i].t = M;
		}
		if(a[i].t < a[i].s){
			a[i].t = M + 1;
		}
	}
	sort(a,a + N,compare);
	int res = 0;
	int last = 0;
	for(int i = 0; i < N; i++){
		if(a[i].s >= last &&a[i].t <= M){
			res++;
			last = a[i].t;
		}
	}
	cout << res << endl;
}
