#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputVaildation.h"
#include "clsMainScreen.h"

using namespace std;
class clsFindClientScreen :protected clsScreen
{
private:
    static void PrintInfo(clsBankClient ClientInfo)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << ClientInfo.FirstName;
        cout << "\nLastName    : " << ClientInfo.LastName;
        cout << "\nFull Name   : " << ClientInfo.FullName();
        cout << "\nEmail       : " << ClientInfo.Email;
        cout << "\nPhone       : " << ClientInfo.Phone;
        cout << "\nAcc. Number : " << ClientInfo.AccountNumber();
        cout << "\nPassword    : " << ClientInfo.PinCode;
        cout << "\nBalance     : " << ClientInfo.AccountBalance;
        cout << "\n___________________\n";
    }


public:

    static void FindClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }

        _DrawScreenHeader("\t Find Client Screen");
        string AccountNumber = "";
        cout << "Please enter account Number?\n";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account Number Not Found ,Please enter Another One?\n";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);

        if (!Client.IsEmpty())
        {
            cout << "Client Was Found.\n";
        }
        else 
        {
            cout << "Client Was Not Found.\n";
        }
        PrintInfo(Client);
    }
};

