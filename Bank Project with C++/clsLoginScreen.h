#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
class clsLoginScreen :protected clsScreen 
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;

        string Username, Password;
        short Attempts = 0;
        do
        {
            if (LoginFaild)
            {
                Attempts++;
                cout << "you have " << 3 - Attempts << " Trial(s) Left.\n";
            }
            if (Attempts == 3)
            {
                cout << "You are Locked After 3 Faild Trial.\n";
                return false;
            }
                
              
            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;
            Password = clsUser::_EncryptText(Password, 2);
            CurrentUser = clsUser::Find(Username, Password);
            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);
        CurrentUser.RegisterLogin();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:

    static bool ShowLoginScreen()
    {
        
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();
        
    }
   
};

    