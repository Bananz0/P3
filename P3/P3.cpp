#include <iostream>

#include "complexNum.h"

#define PI = 3.14


complexNum calculateImpedance() {
	double resistance, frequency, capacitance, inductance, real, imaginary, angularFrequency;
	

	std::cout << "Resistance: ";
	std::cin >> resistance;
	std::cout<<std::endl;

	std::cout << "Capacitance: ";
	std::cin >> capacitance;
	std::cout << std::endl;

	std::cout << "Inductance: ";
	std::cin >> inductance;
	std::cout << std::endl;

	std::cout << "Frequency: ";
	std::cin >> frequency;
	std::cout << std::endl;



	angularFrequency = 2 * 3.14 * frequency;

	real = resistance;
	imaginary = ((angularFrequency*inductance) - (1/(angularFrequency*capacitance)));
	return complexNum(real, imaginary);

}
int main()
{
	
	complexNum c1 = calculateImpedance();
	printComplexNum(c1);



}
