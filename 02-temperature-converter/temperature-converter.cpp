#include <iostream>
#include <iomanip>

double f_to_c(double fahrenhite){
    double celcius = (fahrenhite - 32) * 5 / 9;
    return celcius;
}

double c_to_f(double celcius){
    double fahrenhite = (celcius * 9 / 5) + 32;
    return fahrenhite;
}

int main(){
    double temperature;
    char unit;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Enter temperature: ";
    std::cin >> temperature;

    std::cout << "\nEnter unit (C or F): ";
    std::cin >> unit;

    if(unit == 'c' || unit == 'C'){
        std::cout << temperature << unit << " = " << c_to_f(temperature) << "F\n";
    }
    else if(unit == 'f' || unit == 'F'){
        std::cout << temperature << unit << " = " << f_to_c(temperature) << "C\n";
    }
    else {
        std::cout << "Enter valid unit\n";
    }
    
}