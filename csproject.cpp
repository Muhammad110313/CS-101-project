#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void convertCurrency(float *amount, float conversionRate) 
{
    *amount = (*amount) * conversionRate;
}

void displayCurrencies() {
    cout << "1. USD to PKR\n";
    cout << "2. EUR to PKR\n";
    cout << "3. GBP to PKR\n";
    cout << "4. JPY to PKR\n";
}

int main() {
    int choice;
    float amount;
    float conversionRate;
    bool validInput = true;

    float rates[] = {284.53, 302.21, 351.14, 2.07}; 

    displayCurrencies();

    cout << "Enter your choice (1-4): ";
    cin >> choice;

    if (choice < 1 || choice > 4) {
        cout << "Invalid choice! Exiting...\n";
        return 0;
    }

    cout << "Enter amount to convert: ";
    cin >> amount;

    switch (choice) {
        case 1: 
            conversionRate = rates[0]; 
            break;
        case 2:
            conversionRate = rates[1]; 
            break;
        case 3:
            conversionRate = rates[2]; 
            break;
        case 4:
            conversionRate = rates[3]; 
            break;
        default:
            validInput = false;
            break;
    }

    if (validInput) {
        convertCurrency(&amount, conversionRate);

        cout << "Converted amount: " << amount << " PKR" << endl;
    } else {
        cout << "Invalid input. Exiting...\n";
    }

    char continueChoice;
    cout << "Do you want to convert another currency? (Y/N): ";
    cin >> continueChoice;

    while (continueChoice == 'Y' || continueChoice == 'y') {
        main(); 
    }

    return 0;
}
