#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputVaildation.h"
#include "clsScreen.h"

using namespace std;
class clsDeleteClientScreen :protected clsScreen
{

private:

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

	static void DeleteClient()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}

		clsScreen::_DrawScreenHeader("\t Delete Client Screen");


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
		cout << "are you sure you want to delete this Client?\n";

		char answer = 'y';
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			if (Client.Delete())
			{
				cout << "Client Deleted Succsessflly\n";
				PrintInfo(Client);
			}
		}
		else
		{
			cout << "Client Was Not Deleted!\n";
		}



	}



};

