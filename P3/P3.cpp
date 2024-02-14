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

		std::cout << "Frequency (Hz): ";
		std::cin >> frequency;
		std::cout << std::endl;



		angularFrequency = 2 * M_PI * frequency;

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

	std::cout << "Impedance" << std::endl;
	printComplexNum(Z);
	std::cout << "Current" << std::endl;
	printComplexNum(I);
	std::cout << "Voltage" << std::endl;
	printComplexNum(V);
}
