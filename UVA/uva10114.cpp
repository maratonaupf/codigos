#include<stdio.h>

int main(void){
	bool owesMore;
	int dur, rec, month, currMonth, numOfMonths;
	double pay, amount, carValue, deprec, lastDeprec, part;
	while(scanf("%d %lf %lf %d", &dur, &pay, &amount, &rec), dur >= 0){
		carValue = amount + pay;
		part = amount / (double)dur;
		numOfMonths = currMonth = 0;
		owesMore = true;
		lastDeprec = 0.0;
		while(rec--){
			scanf("%d %lf", &month, &deprec);
			while(currMonth < month){
				carValue -= carValue * lastDeprec;
				if(currMonth > 0) amount -= part;
				if(owesMore && amount < carValue){
					owesMore = false;
					numOfMonths = currMonth;
				}
				currMonth++;
			}
			lastDeprec = deprec;
		}
		for(currMonth = month; currMonth <= dur; currMonth++){
			carValue -= carValue * deprec;
			amount -= part;
			if(owesMore && amount < carValue){
				owesMore = false;
				numOfMonths = currMonth;
			}
		}
		printf("%d month%s\n", numOfMonths, (numOfMonths == 1) ? "" : "s");
	}
	return 0;
}
