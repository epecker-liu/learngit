/* 有n项工作，分别在S[i]开始在T[i]结束，求如何安排才能做更多项工作 */
/* 用贪心算法，先用pair进行对T[i]进行排序，判断下一项的工作开始时间是否大于当前工作的结束时间，若是，则选择下一项工作，否则跳过下一项工作，继续判断之后的工作，依次循环 */
const int n = 5;
int S[n] = {1, 2, 4, 6, 8};
int T[n] = {3, 5, 7, 9, 10};

void PairSort(pair<int, int> a);
int IntervalScheduling() {
    pair<int, int> a[n];            //pair的定义！！！！！！！<-----
    for(int i = 0; i < n; i++){
        a[i].first = T[i];
        a[i].second = S[i];
    }
    sort( a, a+n );
    int re = 1;
    int fTime = a[0].first;
    for(int i = 1; i < n; i++){
        if(a[i].second >= fTime){
            fTime = a[i].first;
            re++;
        }
    }
    return re;

}
