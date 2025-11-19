#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputVaildation.h"
using namespace std;

class clsShowFindCurrencyScreen :protected clsScreen
{
private:

	
    static void PrintInfo(clsCurrency CurrencyInfo)
    {
        cout << "\Currency Card:";
        cout << "\n___________________";
        cout << "\nCountry: " << CurrencyInfo.Country();
        cout << "\nCode   : " << CurrencyInfo.CurrencyCode();
        cout << "\nName   : " << CurrencyInfo.CurrencyName();
        cout << "\nRate   : " << CurrencyInfo.Rate();
        cout << "\n___________________\n";
    }

    static void ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "Currency Was Found.\n";
            PrintInfo(Currency);
        }
        else
        {
            cout << "Currency Was Not Found.\n";
        }
       
    }

public:

    static void FindCurrencyScreen()
    {
        _DrawScreenHeader("\t Find Currency Screen");
        cout << "Find By: [1] Code Or [2] Country ?";
        short Choice = clsInputValidate::ReadshortNumberBetween(1, 2);
        
        if (Choice == 1) 
        {
            string CurrencyCode = "";
            cout << "Please enter Code?\n";
            CurrencyCode = clsInputValidate::ReadString();
            while (!clsCurrency::IsCurrencyExist(CurrencyCode))
            {
                cout << "Code Not Found ,Please enter Another One?\n";
                CurrencyCode = clsInputValidate::ReadString();
            }
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            ShowResults(Currency);
        }
        else 
        {
            string CountryName = "";
            cout << "Please enter Country Name?\n";
            CountryName = clsInputValidate::ReadString();
            while (!clsCurrency::IsCurrencyExistByCountry(CountryName))
            {
                cout << "Country Name Not Found ,Please enter Another One?\n";
                CountryName = clsInputValidate::ReadString();
            }
            clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
            ShowResults(Currency);
        }

    }
};

