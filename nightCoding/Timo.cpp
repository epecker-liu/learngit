/* 题目： 第一个向量里传入攻击的时间间隔， 第二个int值传入，中毒的时间，求总共会中毒多长时间 */
/* 先判断特殊情况，即没有攻击的时候，返回中毒时间为0，之后依次判断两次的攻击时间间隔是否小于中毒时间，若小于，将攻击的时间间隔加到中毒时间上，否则，加duration。*/
/* 注意最后一次攻击的中毒时间 */
int findPoisonedDuration(vector<int>& timeSeries, int duration){
	if(timeSeries.size() == 0){
		return 0;
	}
	int res = 0;
	for(int i = 1; i < timeSeries; i++){
		if(timeSeries[i] - timeSeries[i-1] <= duration){
			res += timeSeries[i] - timeSeries[i-1];
		}
		else{
			res += duration; 
		}
	}
	res += duration;
	return res;
}
