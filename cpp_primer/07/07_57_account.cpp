#include <iostream>

using namespace std;

class Account 
{
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; }
private:
    string owner;
    double amount;
    static constexpr int period = 30;
    static double interestRate;
    static constexpr double todayRate = 43.21;
    static double initRate { return todayRate; }
}

double Account::interestRate = initRate();
