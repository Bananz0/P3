#pragma once
#include <iostream>


class complexNum {
public:
	complexNum() : real(0), imaginary(0) {}
	complexNum(double realIn, double imaginaryIn) : real(realIn), imaginary(imaginaryIn) {}

	double getReal() {
		return real;
	}
	double getImaginary() {
		return imaginary;
	}
	double getModulus() {
		return sqrt(pow(imaginary, 2) + pow(real, 2));
	}
	double getPhase() {
		return atan2(imaginary, real);
	}

private:
	double real = 0, imaginary = 0, absoluteVal = 0, congugate = 0;
};
const complexNum operator +(complexNum& uno, complexNum& dos) {
	double realSum = uno.getReal() + dos.getReal();
	double imagSum = uno.getImaginary() + dos.getImaginary();
	return complexNum(realSum, imagSum);
}
const complexNum operator -(complexNum& uno, complexNum& dos) {
	double realSum = uno.getReal() - dos.getReal();
	double imagSum = uno.getImaginary() - dos.getImaginary();
	return complexNum(realSum, imagSum);
}
const complexNum operator /(complexNum& uno, complexNum& dos) {
	if (dos.getModulus() == 0) {
		std::cerr << "Divide By zero is not mathematical nigga";
		return complexNum();
	}
	double polarDiv = uno.getModulus() / dos.getModulus();
	double phaseDiv = uno.getPhase() - dos.getPhase();

	double realDiv = polarDiv * cos(phaseDiv);
	double imagDiv = polarDiv * sin(phaseDiv);



	return complexNum(realDiv, imagDiv);
}
const complexNum operator *(complexNum& uno, complexNum& dos) {
	double polarDiv = uno.getModulus() * dos.getModulus();
	double phaseDiv = uno.getPhase() + dos.getPhase();

	double realDiv = polarDiv * cos(phaseDiv);
	double imagDiv = polarDiv * sin(phaseDiv);



	return complexNum(realDiv, imagDiv);
}
void printComplexNum(complexNum& printee) {
	std::cout << "-------------";
	std::cout << "\nReal: " << printee.getReal()
		<< "\nImaginary: " << printee.getImaginary()
		<< "\nImaginary: " << printee.getModulus()
		<< "\nPhase difference: " << printee.getPhase() * 180 / M_PI << std::endl;
	std::cout << "-------------";
	std::cout << std::endl;
}