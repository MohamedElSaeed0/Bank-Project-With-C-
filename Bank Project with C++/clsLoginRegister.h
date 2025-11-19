#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "clsUser.h"
#include "clsScreen.h"
using namespace std;
class clsLoginRegister :protected clsScreen
{
private:
    static void PrintClientRecordLine(clsUser::stLoginRegisterRecord LogUser)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << LogUser._DateTime;
        cout << "| " << setw(27) << left << LogUser._UserName;
        cout << "| " << setw(10) << left << LogUser._Password;
        cout << "| " << setw(12) << left << to_string(LogUser._Permissions);
    }
public:
    static void ShowLoginRegister()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return;
        }

        vector <clsUser::stLoginRegisterRecord> vLogUser = clsUser::GetLogUsersList();
        string Title = "\t Login Register List Screen";
        string SubTitle = "\t (" + to_string(vLogUser.size()) + ") Login Users History(s).";
        clsScreen::_DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t______________________________________________________________________";
        cout << "_________________________________________\n" << endl;;
        cout << setw(8) << left << "" << "| " << left << setw(30) << "Date/Time";
        cout << "| " << left << setw(27) << "UserName";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t______________________________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLogUser.size() == 0)
            cout << "\t\t\t\tNo Users History Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord LogUser : vLogUser)
            {

                PrintClientRecordLine(LogUser);
                cout << endl;
            }

        cout << setw(8) << left << "\n\t______________________________________________________________________";
        cout << "_________________________________________\n" << endl;
    }
};

