#include <stdio.h>
#include <stdlib.h>

int compare_li(const void* a, const void* b){
	long int arg1 = *(const long int*) a;
	long int arg2 = *(const long int*) b;

	if(arg1<arg2) return -1;
	if(arg1>arg2) return 1;
	return 0;
}

int count(long arr[], int n, long int num){
	int c=0;
	for(int i=0; i<n; i++)
		if(arr[i]==num) c++;
	return c;
}

int main(){

	/* PART ONE */

	long int left[1000], right[1000], l, r;

	int n=0;
	while(scanf("%ld %ld", &left[n], &right[n])==2)
        n++;

	qsort(left, n, sizeof(long int), compare_li);
	qsort(right, n, sizeof(long int), compare_li);

	long long result=0;
	for(int i=0; i<n; i++){
		result+=labs(left[i]-right[i]);
	}

	printf("%lld\n", result);


	/* PART TWO */

	long long similarity_score=0;

	for(int i=0; i<n; i++){
		int c=count(right, n, left[i]);
		if(c) similarity_score+=left[i]*c;
	}

	printf("%lld\n", similarity_score);

	return 0;
}
