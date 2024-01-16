#include <bits/stdc++.h>
using namespace std;

class receipt
{
private:
    float subTotal;
    float serviceTax;
    float swachhBharatCess;
    float krishiKalyanCess;
    float serviceTaxPercentage = 0.14;
    float swachhBharatCessPercentage = 0.005;
    float krishiKalyanCessPercentage = 0.005;
    float total;

public:
    receipt(float subTotal)
    {
        serviceTax = serviceTaxPercentage * subTotal;
        swachhBharatCess = swachhBharatCessPercentage * subTotal;
        krishiKalyanCess = krishiKalyanCessPercentage * subTotal;
        total = serviceTax + swachhBharatCess + krishiKalyanCess;
    }
    float getSubTotal()
    {
        return subTotal;
    }
    float getServiceTax()
    {
        return serviceTax;
    }
    float getSwachhBharatCess()
    {
        return swachhBharatCess;
    }
    float getKrishiKalyanCess()
    {
        return krishiKalyanCess;
    }
    float getTotal()
    {
        return total;
    }
    void print()
    {
        cout << std::setprecision(2) << std::fixed;
        cout << "Service Tax @ 14% : Rs. " << serviceTax << "\n";
        cout << "Swachh Cess Tax @ 0.5% : Rs. " << swachhBharatCess << "\n";
        cout << "Krishi Cess Tax @ 0.5% : Rs. " << krishiKalyanCess << "\n";
        cout << "Total : Rs. " << total << "\n";
    }
};
