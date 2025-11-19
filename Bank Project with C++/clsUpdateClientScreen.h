#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputVaildation.h"
#include "clsMainScreen.h"
#include "clsAddNewClientScreen.h"
using namespace std;

class clsUpdateClientScreen :protected clsScreen 
{
private:

    static  void ReadClientInfo(clsBankClient& Client)
    {
        char answer;

        cout << "Do you want to update First Name? (y/n)\n";
        cin >> answer;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (tolower(answer) == 'y')
        {
            cout << "Enter First Name: ";
            Client.FirstName = clsInputValidate::ReadString();
        }

        cout << "Do you want to update Last Name? (y/n)\n";
        cin >> answer;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (tolower(answer) == 'y')
        {
            cout << "Enter Last Name: ";
            Client.LastName = clsInputValidate::ReadString();
        }

        cout << "Do you want to update Email? (y/n)\n";
        cin >> answer;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (tolower(answer) == 'y')
        {
            cout << "Enter Email: ";
            Client.Email = clsInputValidate::ReadString();
        }

        cout << "Do you want to update Phone? (y/n)\n";
        cin >> answer;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (tolower(answer) == 'y')
        {
            cout << "Enter Phone: ";
            Client.Phone = clsInputValidate::ReadString();
        }

        cout << "Do you want to update PinCode? (y/n)\n";
        cin >> answer;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (tolower(answer) == 'y')
        {
            cout << "Enter PinCode: ";
            Client.PinCode = clsInputValidate::ReadString();
        }

        cout << "Do you want to update Account Balance? (y/n)\n";
        cin >> answer;
        if (tolower(answer) == 'y')
        {
            cout << "Enter Account Balance: ";
            Client.AccountBalance = clsInputValidate::ReadFloatNumber();
        }
    }
    static  void PrintInfo(clsBankClient ClientInfo)
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

    static void UPDateClient()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;
        }

        clsScreen::_DrawScreenHeader("\t Update Client Screen");

        string AccountNumber = "";
        cout << "Please enter account Number?\n";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account Number Not Found ,Please enter Another One?\n";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        PrintInfo(Client);
        cout << "\n\nUpdate Client Info:";
        cout << "\n--------------------\n";
        ReadClientInfo(Client);
        clsBankClient::enSaveResult SaveResult;
        SaveResult = Client.Save();
        switch (SaveResult)
        {
        case clsBankClient::enSaveResult::svSucceeded:
        {
            cout << "\Account UpDated Successfully.\n";
            PrintInfo(Client);
            break;
        }
        case clsBankClient::enSaveResult::svFaildEmptyObject:
        {
            cout << "\nError! Account Was Not Saved.\n";
            break;
        }
        }


    }

};

