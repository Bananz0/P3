#include <iostream>

class complexNum {
public:
	complexNum();
	complexNum(double realIn, double imaginaryIn) {
		real = realIn;
		imaginary = imaginaryIn;
	};

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
const complexNum operator +( complexNum& uno,  complexNum& dos) {
	double realSum = uno.getReal() + dos.getReal();
	double imagSum = uno.getImaginary() + dos.getImaginary();
	return complexNum(realSum, imagSum);
}
void printComplexNum(complexNum& printee) {
	std::cout << "Real: " << printee.getReal()
		<< "\nImaginary: " << printee.getImaginary()
		<< "\nModulus: " << printee.getModulus()
		<< "\nPhase: " << printee.getPhase() << std::endl;
}

int main()
{
	complexNum c3(3, 4);
	complexNum c2(1, 2) , c1 = c2 + c3;

	printComplexNum(c1);

}
