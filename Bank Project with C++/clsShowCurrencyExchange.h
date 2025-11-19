#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsInputVaildation.h"
#include "clsShowListCurrency.h"
#include "clsShowFindCurrencyScreen.h"
#include "clsUpdateCurrencyRate.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std;
class clsShowCurrencyExchange:protected clsScreen
{
private:
	enum enCurrencyExchange { eListCurrency = 1, eFindCurrency = 2,eUpdateRate = 3,eCurrencyCaluclator = 4,eBackToMainMenu = 5 };

	static short _ReadCurrencymenu() 
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadshortNumberBetween(1, 5, "Invaild Number!enter Again?");
		return Choice;
	}

    static  void _GoBackToExchangeMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowExchangeMainMenue();
    }

	static void _ShowListCurrency() 
	{
        clsShowListCurrency::ShowCurrencyList();
	}

	static void _ShowFindCurrency()
	{
        clsShowFindCurrencyScreen::FindCurrencyScreen();
	}

	static void _ShowUpdateRate()
	{
        clsUpdateCurrencyRate::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCaluclator()
	{
        clsCurrencyCalculatorScreen::ShowCurrencyCaluclatorScreen();
	}

    static void _PerfromMainMenueOption(enCurrencyExchange CurrencyMainMenueOption)
    {
        switch (CurrencyMainMenueOption)
        {
        case enCurrencyExchange::eListCurrency:
        {
            system("cls");
            _ShowListCurrency();
            _GoBackToExchangeMainMenue();
            break;
        }
        case enCurrencyExchange::eFindCurrency:
            system("cls");
            _ShowFindCurrency();
            _GoBackToExchangeMainMenue();
            break;

        case enCurrencyExchange::eUpdateRate:
            system("cls");
            _ShowUpdateRate();
            _GoBackToExchangeMainMenue();
            break;

        case enCurrencyExchange::eCurrencyCaluclator:
            system("cls");
            _ShowCurrencyCaluclator();
            _GoBackToExchangeMainMenue();
            break;

        case enCurrencyExchange::eBackToMainMenu: 
        {
        
        }

        
        }
    }


public:

    static void ShowExchangeMainMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange)) 
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\tCurrency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1]Show Currency List.\n";
        cout << setw(37) << left << "" << "\t[2]Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3]Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4]Currency Caluclator.\n";
        cout << setw(37) << left << "" << "\t[5]Back To MainMenu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enCurrencyExchange)_ReadCurrencymenu());
    }




};

