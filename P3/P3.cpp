#define _USE_MATH_DEFINES

#include <iostream>
#include "complexNum.h"
#include <cmath>


class RLC {
public: 
	complexNum Z, I, V;
	RLC() {	
		Z = calculateImpedance();	
		V = calculateVoltage();
		I = V / Z;
	};
	complexNum getImpedance() {
		return Z;
	}
	complexNum getCurrent() {
		return I;
	}
	complexNum getVoltage() {
		return V;
	}
private:
	double resistance, frequency, capacitance, inductance;
	complexNum calculateImpedance() {
		double  real, imaginary, angularFrequency;


		std::cout << "Resistance (Ω): ";
		std::cin >> resistance;
		std::cout << std::endl;

		std::cout << "Capacitance (C): ";
		std::cin >> capacitance;
		std::cout << std::endl;

		std::cout << "Inductance (L): ";
		std::cin >> inductance;
		std::cout << std::endl;

		std::cout << "Frequency (Rad/s): ";
		std::cin >> frequency;
		std::cout << std::endl;



		angularFrequency = 2 * M_PI * frequency;
		//angularFrequency = frequency;

		real = resistance;
		imaginary = ((angularFrequency * inductance) - (1 / (angularFrequency * capacitance)));
		return complexNum(real, imaginary);

	}
	complexNum calculateVoltage() {
		double voltage, realVoltage, imaginary, angularFrequency, impedance, realResistance;
				
		std::cout << "Voltage (Amplitude) (V): ";
		std::cin >> voltage;
		std::cout << std::endl;
		//realVoltage = voltage / Z.getModulus();
		return complexNum(voltage, 0);
	}
};



int main()
{
	
	RLC circuit1;
	
	complexNum Z = circuit1.getImpedance();
	complexNum I = circuit1.getCurrent();
	complexNum V = circuit1.getVoltage();

	std::cout << "Impedance: " << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl;

	std::cout << "Polar Form: " << Z.getModulus() << "<" << Z.getPhase()<<std::endl;
	if (Z.getPhase() > 0) {
		std::cout << "Rectangular Form: " << Z.getReal() << " + j" << abs(Z.getImaginary()) << std::endl;
	}
	else if (Z.getPhase() < 0) {
		std::cout << "Rectangular Form: " << Z.getReal() << " - j" << abs(Z.getImaginary()) << std::endl;
	}
	std::cout << "----------------------------------------------------------" << std::endl;

	
	//printComplexNum(Z);

	std::cout << "Current: " << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl;
	std::cout << "Polar Form: " << I.getModulus() << "<" << I.getPhase() <<std::endl;
	if (I.getPhase() > 0) {
		std::cout << "Rectangular Form: " << I.getReal() << " + j" << abs(I.getImaginary()) << std::endl;
	}
	else if (I.getPhase() < 0) {
		std::cout << "Rectangular Form: " << I.getReal() << " - j" << abs(I.getImaginary()) << std::endl;
	}
	std::cout << "----------------------------------------------------------" << std::endl;
	//printComplexNum(I);


	std::cout << "Voltage: " << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl;
	std::cout << "Polar Form: " << V.getModulus() << "<" << V.getPhase()<< std::endl;
	if (V.getPhase() > 0) {
		std::cout << "Rectangular Form: " << V.getReal() << " + j" << abs(V.getImaginary()) << std::endl;
	}
	else if (Z.getPhase() < 0) {
		std::cout << "Rectangular Form: " << V.getReal() << " - j" << abs(V.getImaginary()) << std::endl;
	}
	std::cout << "----------------------------------------------------------" << std::endl;
	//printComplexNum(V);

	
}
