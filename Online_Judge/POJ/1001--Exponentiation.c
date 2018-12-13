#include <stdio.h>

int main(void){
	double R, result;
	int n, i;
	
	while(scanf("%lf %d", &R, &n)==2){
		result = R;
		for(i = 1; i < n; i++){
			result *= R;
		}
		printf("%f",result);	
	}
	
	return 0;
	
}
