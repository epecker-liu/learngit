/* 题目： 将字符串S分成最多的段数， 每一段的字母在其他段中都不存在 */
/* 总共有26个字母，可以用一个字符串来存储已经出现过得字母，再用一个int类型的值存储段的长度，用for循环遍历字符串，若contains是空的，就将当前的字母存入到其中，并将该字母作为一段的起始字母，将stringLen++，再次循环，若当前字母在contains中出现过时，直接将stringLen++，并进入下一次循环，否则判断当前字母之后是否存在已出现过得字母，若没有，则当前字母之前的字母可构成一段，并将当前字母作为新一段的开始，若有，则将当前字母存入到contains中，执行下一次循环 */
/* 注意最后一段的长度也要压入到向量中去 */
vector<int> partitionLabels(string S){
	int stringLen = 0;
	string contains = "";
	vector<int> res;
	for(int i = 0; i < S.length(); i++){
		if(contains.length() == 0){
			contains += S[i];
			stringLen++;
			continue;
		}
		if(contains.find(S[i])){
			stringLen++;
		}
		else{
			bool flag = false;
			for(int j = 0; j < contains.length(); j++){
				if(S.find(contains[j],i+1)){
					flag = true;
					break;
				}
			}
			if(flag){
				contains += S[i];
				stringLen++;
			}
			else{
				res.push_back(stringLen);
				contains = "";
				contains += S[i];
				stringLen = 1;
			}
		}
	}
	res.push_back(stringLen);
	return res;
}
