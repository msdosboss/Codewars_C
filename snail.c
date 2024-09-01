#include <stdbool.h>
#include <stdio.h>

bool canSnailReachEnd(double length, double speed, double lengthIncreases) {
	if(525600 * speed >= lengthIncreases * 525600 + length){
		return true;	
	}
	else{
		return false;
	}
}
