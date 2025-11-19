#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputVaildation.h"
using namespace std;
class clsTransferScreen :protected clsScreen
{

private :


    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cin >> AccountNumber;
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            cout << "\nPlease enter again ?";
            AccountNumber = _ReadAccountNumber();
        }
        return AccountNumber;
    }


public:



    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t   TransferScreen");

        cout << "\nPlease enter AccountNumber to Transfer From? ";
        string AccountNumberFrom = _ReadAccountNumber();

        clsBankClient Client1 = clsBankClient::Find(AccountNumberFrom);
        _PrintClient(Client1);

        cout << "\nPlease enter AccountNumber to Transfer To? ";
        string AccountNumberTo = _ReadAccountNumber();

        clsBankClient Client2 = clsBankClient::Find(AccountNumberTo);
        _PrintClient(Client2);


        double Amount = 0;
        cout << "\nPlease enter a Transfer amount? ";
        Amount = clsInputValidate::ReadDblNumber();



        cout << "\nAre you sure you want to perform this Transfer? ";
        char Answer = 'y';
        cin >> Answer;
        
        while (Client1.AccountNumber() == Client2.AccountNumber()) 
        {
        cout << "The 'Source Client' and 'Destination Client' are the same. Transaction Failed !\n";
        return;
        }

        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client1.Transfer(Amount,Client2,CurrentUser.UserName))
            {
                cout << "\nAmount Transfer Successfully.\n";
                _PrintClient(Client1);

                _PrintClient(Client2);
            }
            else
            {
                while (Amount > Client1.AccountBalance)
                {
                    cout << "\nCannot Transfer, Insuffecient Balance!\n";
                    cout << "\nAmout to Transfer is: " << Amount;
                    cout << "\nYour Balance is: " << Client1.AccountBalance;
                    cout << "\nPlease enter a another Transfer amount? ";
                    Amount = clsInputValidate::ReadDblNumber();
                }

                if (Client1.Transfer(Amount, Client2, CurrentUser.UserName))
                {
                    cout << "\nAmount Transfer Successfully.\n";
                    _PrintClient(Client1);

                    _PrintClient(Client2);
                }
            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }


   



};

