#include <bits/stdc++.h>
#include "receipt.cpp"
using namespace std;

class show
{
protected:
    vector<bool> A;
    vector<bool> B;
    vector<bool> C;
    int priceA = 320;
    int priceB = 280;
    int priceC = 240;
    float serviceTax = 0.14;
    float swachhBharatCess = 0.005;
    float krishiKalyanCess = 0.005;

public:
    show()
    {
    }
    show(int sizeA, int sizeB, int sizeC)
    {
        A.resize(sizeA, false);
        B.resize(sizeB, false);
        C.resize(sizeC, false);
    }

    bool check(vector<bool> &row, int col)
    {
        if (row[col - 1] == false)
            return true;
        else
            return false;
    }

    bool isAvailable(char row, char column)
    {
        if (row == 'A' or row == 'a')
        {
            return check(A, column);
        }
        else if (row == 'B' or row == 'b')
        {
            return check(B, column);
        }
        else if (row == 'C' or row == 'c')
        {
            return check(C, column);
        }
        return false;
    }

    void book(vector<bool> &row, int col)
    {
        row[col - 1] = true;
    }

    void bookSeats(char row, char column)
    {
        if (row == 'A' or row == 'a')
        {
            book(A, column);
        }
        else if (row == 'B' or row == 'b')
        {
            book(B, column);
        }
        else if (row == 'C' or row == 'c')
        {
            book(C, column);
        }
    }

    void printAvailabeSeat(vector<bool> &row, char category)
    {
        for (int i = 0; i < row.size(); i++)
        {
            if (row[i] == false)
                cout << category << i + 1 << " ";
        }
        cout << "\n";
    }

    void availableSeats()
    {
        printAvailabeSeat(A, 'A');
        printAvailabeSeat(B, 'B');
        printAvailabeSeat(C, 'C');
    }

    int calculateCost(char row)
    {
        if (row == 'A')
            return priceA;
        else if (row == 'B')
            return priceB;
        else if (row == 'C')
            return priceC;
        return 0;
    }
};

class derivedShow : public show
{
public:
    derivedShow()
    {
        cout << "Printed Vertically.";
    }
};

receipt bookingMenu(show &chosenShow, string seats)
{
    bool flag = true;
    for (int i = 0; i < seats.size(); i++)
    {
        map<string, float> ans;
        if (!chosenShow.isAvailable(seats[i], seats[i + 1]))
        {
            cout << seats[i] << seats[i + 1] << " not available, Please select different seats \n";
            receipt bookingReceipt(0);
            return bookingReceipt;
        }
        i += 2;
    }
    int subTotal = 0;
    for (int i = 0; i < seats.size(); i++)
    {
        chosenShow.bookSeats(seats[i], seats[i + 1]);
        subTotal += chosenShow.calculateCost(seats[i]);
        i += 2;
    }
    receipt bookingReceipt(subTotal);
    cout << "Successfully booked the show\n";
    cout << "Subtotal : " << subTotal << "\n";
    bookingReceipt.print();
    return bookingReceipt;
}

int main()
{

    show show_1(9, 6, 7);
    show show_2(7, 6, 7);
    show show_3(7, 8, 9);
    int revenue = 0;
    float serviceTax = 0;
    float swachhBharatCess = 0;
    float krishiKalyanCess = 0;
    while (true)
    {
        int subtotal = 0;
        int choice;
        string seats;
        cout << "Enter show number : ";
        cin >> choice;
        show selectedShow;
        if (choice == 1)
        {
            selectedShow = show_1;
        }
        else if (choice == 2)
        {
            selectedShow = show_2;
        }
        else if (choice == 3)
        {
            selectedShow = show_3;
        }
        else
        {
            cout << "Please enter valid show number\n";
            continue;
        }
        selectedShow.availableSeats();
        cout << "Enter seats : ";
        cin >> seats;

        receipt bookingReceipt = bookingMenu(selectedShow, seats);
        revenue += bookingReceipt.getSubTotal();
        serviceTax += bookingReceipt.getServiceTax();
        swachhBharatCess += bookingReceipt.getSwachhBharatCess();
        krishiKalyanCess += bookingReceipt.getKrishiKalyanCess();

        string enter;
        cout << "Would you like to continue? ";
        cin >> enter;
        if (enter == "No" or enter == "no")
            break;
    }
    cout << "Total Sales :\n";
    cout << "Revenue: Rs. " << revenue << "\n";
    cout << "Service Tax : Rs. " << serviceTax << "\n";
    cout << "Swachh Bharat Cess: Rs. " << swachhBharatCess << "\n";
    cout << "Krishi Kalyan Cess: Rs. " << krishiKalyanCess << "\n";
}
