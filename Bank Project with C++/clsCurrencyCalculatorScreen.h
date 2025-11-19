#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputVaildation.h"
using namespace std;
class clsCurrencyCalculatorScreen : protected clsScreen
{
private:

    static void _PrintInfo(clsCurrency CurrencyInfo, string Title = "CurrencyCard")
    {
        cout << "\n" << Title << "\n";
        cout << "\n___________________";
        cout << "\nCountry: " << CurrencyInfo.Country();
        cout << "\nCode   : " << CurrencyInfo.CurrencyCode();
        cout << "\nName   : " << CurrencyInfo.CurrencyName();
        cout << "\nRate   : " << CurrencyInfo.Rate();
        cout << "\n___________________\n";
    }

    static clsCurrency _GetCurrency(string Massage) 
    {
        string CurrencyCode;
        cout << Massage << endl;

       
        CurrencyCode = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "Wrong Currency Please enter again?";
            CurrencyCode = clsInputValidate::ReadString();
        }
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

        return Currency;
    }


    static void PrintCalcuationResult(float Amount ,clsCurrency Currency1, clsCurrency Currency2)
    {
    
        _PrintInfo(Currency1,"Convert Form:");

        float AmountInUSD = Currency1.ConvertToUSD(Amount);
        
        cout << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << " USD\n";

        if (Currency2.CurrencyCode() == "USD")
        {
            return;
        }
        _PrintInfo(Currency2, "Converting From USD To:");

        float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount,Currency2);

        cout << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode();

    }


public:
    static void ShowCurrencyCaluclatorScreen()
    {
        char Contiune = 'y';
        while (Contiune == 'y'|| Contiune == 'Y')
        {
            system("cls");
            _DrawScreenHeader("\t Currency Caluclator Screen");

            clsCurrency CurrencyFrom = _GetCurrency("\nPlease enter Currency1 Code: ");
            clsCurrency CurrencyTo = _GetCurrency("\nPlease enter Currency2 Code: ");
            float Amount;
            cout << "\nenter Amount to Exchange?\n";
            Amount = clsInputValidate::ReadFloatNumber();

            PrintCalcuationResult(Amount, CurrencyFrom, CurrencyTo);
            cout << "\nDo you want do Another Calculations?\n";
            cin >> Contiune;
        }
 



    }



};

