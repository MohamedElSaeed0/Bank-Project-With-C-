#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputVaildation.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
using namespace std;

class clsAddNewClientScreen:protected clsScreen
{
private:

    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
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
public :



   static void AddNewClient()
   {
       if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
       {
           return;
       }

       _DrawScreenHeader("\t  Add New Client Screen");

           string AccountNumber = "";
           cout << "Please enter account Number?\n";
           AccountNumber = clsInputValidate::ReadString();
           while (clsBankClient::IsClientExist(AccountNumber))
           {
               cout << "Account Number already Used, Choose anothe one.\n";
               AccountNumber = clsInputValidate::ReadString();
           }
           clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

           _ReadClientInfo(NewClient);

           clsBankClient::enSaveResult SaveResult;

           SaveResult = NewClient.Save();

           switch (SaveResult)
           {
           case clsBankClient::enSaveResult::svSucceeded:
           {
               cout << "Client Added Successfully\n";
               PrintInfo(NewClient);
               break;
           }
           case clsBankClient::enSaveResult::svFaildEmptyObject:
           {
               cout << "Error! Account Number Was Not Saved because its empty\n";
               break;
           }
           case clsBankClient::enSaveResult::svFaildAccountNumberExists:
           {
               cout << "Error! Account Number is Already Used\n";
               break;
           }
           }
   }
};

