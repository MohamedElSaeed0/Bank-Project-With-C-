#pragma once
#include <iostream>
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"

using namespace std;
class clsShowListCurrency:protected clsScreen
{
private:
    static void PrintCurrencyRecord(clsCurrency Currency)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(10) << left << Currency.CurrencyCode();
        cout << "| " << setw(40) << left << Currency.CurrencyName();
        cout << "| " << setw(8) << left << Currency.Rate();
       
    }
public:

    static void ShowCurrencyList()
    {
        vector <clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();
        string Title = "\tCurrency List Screen";
        string SubTitle = "\t (" + to_string(vCurrency.size()) + ") Currency(s).";

        clsScreen::_DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t______________________________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(10) << "Code";
        cout << "| " << left << setw(40) << "Name";
        cout << "| " << left << setw(8) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t______________________________________________________________________";
        cout << "_________________________________________\n" << endl;



        if (vCurrency.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsCurrency Currency : vCurrency)
            {

                PrintCurrencyRecord(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "\n\t______________________________________________________________________";
        cout << "_________________________________________\n" << endl;
    }

};

