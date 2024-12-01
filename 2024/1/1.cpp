#include <iostream>
#include <vector>
#include <algorithm>

int main(){

	/* PART ONE */

	std::vector<long int> left, right;
	long r, l;
	while(std::cin >> l >> r){
		left.push_back(l);
		right.push_back(r);
	}

	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());

	int n=left.size();
	long long result=0;
	for(int i=0; i<n; i++)
		result+=std::abs(left[i]-right[i]);

	std::cout << result << std::endl;


	/* PART TWO */

	long long similarity_score=0;

	for(int i=0; i<n; i++){
		int c=std::count(right.begin(), right.end(), left[i]);
		if(c) similarity_score+=left[i]*c;
	}

	std::cout << similarity_score << std::endl;

}
