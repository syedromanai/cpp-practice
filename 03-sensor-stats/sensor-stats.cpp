#include <iostream>
#include <vector>
#include <iomanip>

double average(const std::vector<double>& reading){
    double value = 0.0;
    for (double read: reading){
        value += read;
    }
    return value / reading.size();
}

double lowest(const std::vector<double>& reading){
    double low = reading[0];
    for (double read: reading){
        if (read < low){
            low = read;
        }
        }
    return low;
    }

double highest(const std::vector<double>& reading){
    double high = reading[0];
    for (double read: reading){
        if (high < read){
            high = read;
        }
        }
    return high;
    }

int main() {
    std::vector<double> reading;
    std::cout << std::fixed << std::setprecision(1);
    double value;
    std::cout << "Enter reading in Celsius, -999 to finish.\n";

    do {
        std::cin >> value;
        if(value != -999){
            reading.push_back(value);
        }
    }
    while (value != -999);

    if(reading.empty()){
        std::cout << "No reading entered.\n";
        return 0;
    }
    else {
        std::cout << reading.size() << " reading\n";
    }

    double averageValue = average(reading);
    double lowestValue = lowest(reading);
    double highestValue = highest(reading);

    
    std::cout << "Average: " << averageValue << " C\n";
    std::cout << "Lowest: " << lowestValue << " C\n";
    std::cout << "Highest: " << highestValue << " C\n";
    return 0;
}