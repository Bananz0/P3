#include <iostream>

#include "complexNum.h"

int main()
{
	complexNum c3, c4, c5, c6;
	complexNum c1(4, 6);
	complexNum c2(2, 2);
	

	c3 = c1 + c2;
	c4 = c1 - c2;

	c5 = c1 / c2;
	c6 = c1 * c2;

	printComplexNum(c3);
	printComplexNum(c4);
	printComplexNum(c5);
	printComplexNum(c6);

}
