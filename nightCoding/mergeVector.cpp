bool v_sort(const vector<int> &v1, const vector<int> &v2){
	if(v1[0] == v2[0]){
		return v1[1] <= v2[1];
	}
	return v1[0] < v2[0];
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
	vector<vector<int>> res;
	sort(intervals.begin(), intervals.end(),v_sort);
	for(int i = 0; i < intervals.size();){
		int beg = intervals[i][0];
		int end = intervals[i][1];
		int j = i + 1;
		for(; j < intervals.size(); j++){
			if(end  >= intervals[j][0]){
				end = max(end, intervals[j][1]);
			}
			else{
				break;
			}
		}
		res.push_back({beg,end});
		i = j;

	}
	return res;
}
