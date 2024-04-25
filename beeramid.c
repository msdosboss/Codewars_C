#include <stdio.h>
int beeramid(double bonus, double price) {
	if(bonus < 0){
		return 0;
	}
	int total = 0;
	int i = 0;
	while(total <= bonus/price){
		i++;
		total = total + (i * i);
	}
	return i - 1;
}
int main(){
	printf("beeramid() returned: %d", beeramid(10.00, 2.00));
}
