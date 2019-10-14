/* 用最少数量的纸币组成money */
   /* 贪心算法 依次从大面值开始寻找，直到凑出money或者没有纸币可以组成money */
const int N = 5;
int Money[N] = {5, 2, 2, 3, 5};
int Value[N] = {1, 5, 10, 50, 100};
int FindLessMoney(int money) {
    int re = 0;
    for(int n = 4; n >= 0; n--){
        re += min(money/Value[n],Money[n]);
        money -= Value[n]*min(money/Value[n]n Money[n]);
    }
    if(money == 0){
        return re;
    }
    else{
        return -1;
    }
}
