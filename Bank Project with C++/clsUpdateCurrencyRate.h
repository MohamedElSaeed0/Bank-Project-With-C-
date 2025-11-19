#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsInputVaildation.h"
#include "clsScreen.h"
using namespace std;
class clsUpdateCurrencyRate :protected clsScreen
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

public:

    static void ShowUpdateCurrencyScreen()
    {
        _DrawScreenHeader("\t Update Currency Screen");
    
        cout << "Please enter Currency Code? :";
        string CurrencyCode = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "Wrong Currency Please enter again?";
            CurrencyCode = clsInputValidate::ReadString();
        }
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        PrintInfo(Currency);


        cout << "are you sure you wnat update this Currency?";
        char Answer = 'y';
        cin >> Answer;
        if (Answer == 'y'||Answer == 'Y')
        {
            cout << "\n-----------------------\n";
            cout << "Please enter New Rate?\n";
            float NewRate = clsInputValidate::ReadFloatNumber();
            Currency.UpdateRate(NewRate);
            cout << "Currency Updated Successfully. \n";
            PrintInfo(Currency);
        }
        else 
        {
            cout << "Operation canceld.";
        }
    }
   
};

