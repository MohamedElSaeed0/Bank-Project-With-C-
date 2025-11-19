#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputVaildation.h"
using namespace std;
class clsTransferLogScreen:protected clsScreen
{
private:
    static void PrintTransferLog(clsBankClient::stTransferLogRecord Client)
    {
        cout << setw(8) << left << "" << "| " << setw(25) << left << Client._DateTime;
        cout << "| " << setw(10) << left << Client.AccountNumber;
        cout << "| " << setw(12) << left << Client.DAccountNumber;
        cout << "| " << setw(15) << left << Client.Amount;
        cout << "| " << setw(12) << left << Client.AccountBalance;
        cout << "| " << setw(12) << left << Client.DAccountBalance;
        cout << "| " << setw(12) << left << Client._UserName;
    }
public:


    static void ShowTransferLogScreen()
    {
 
        vector <clsBankClient::stTransferLogRecord> vLog = clsBankClient::GetTransferLogList();
        string Title = "\t TransferLog Screen";
        string SubTitle = "\t (" + to_string(vLog.size()) + ") Transfer(s).";

        clsScreen::_DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t______________________________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(10) << "S.Acc";
        cout << "| " << left << setw(12) << "D.Acc";
        cout << "| " << left << setw(15) << "Amount";
        cout << "| " << left << setw(12) << "S.Balance";
        cout << "| " << left << setw(12) << "D.Balance";
        cout << "| " << left << setw(12) << "Username";
        cout << setw(8) << left << "" << "\n\t______________________________________________________________________";
        cout << "_________________________________________\n" << endl;



        if (vLog.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord Client : vLog)
            {

                PrintTransferLog(Client);
                cout << endl;
            }

        cout << setw(8) << left << "\n\t______________________________________________________________________";
        cout << "_________________________________________\n" << endl;
    }






};

