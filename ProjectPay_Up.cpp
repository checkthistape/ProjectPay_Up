#include <iostream>
#include <Windows.h>

using namespace std;

class Class {
public:
    int screenresX = 1920;
    int screenresY = 1080;

    void gotoxy(int x, int y)
    {
        COORD c;
        c.X = x - 1;
        c.Y = y - 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }

    BOOL ShowConsoleCursor(BOOL bShow)
    {
        CONSOLE_CURSOR_INFO cci;
        HANDLE hStdOut;
        hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hStdOut == INVALID_HANDLE_VALUE)
            return FALSE;
        if (!GetConsoleCursorInfo(hStdOut, &cci))
            return FALSE;
        cci.bVisible = bShow;
        if (!SetConsoleCursorInfo(hStdOut, &cci))
            return FALSE;
        return TRUE;
    }


    void actions(int age)
    {
        clear();
        gotoxy(50, 13);
        cout << "Enter your age please: "; cin >> age;
        cout << "\t\n" << endl;

        _age = age;

        if (age < 120 && age>0) {
            cout << "Age: " << age << endl << endl;
            keyfunctions(age);
        }
        else if (age > 120) { throw 0; exception(age); }
        else if (age < 0) { throw 1; exception(age); }
        else if (age == 0) { throw 2; exception(age); }
        else { throw 3; exception(age); }


    }
    void exception(int age)
    {
        try
        {
            actions(age);
        }
        catch (int x)
        {
            cout << "\nError " << x << ": You did something wrong, please check the error's number and solve the problem" << endl;
            keyfunctions(age);
        }
        catch (...)
        {
            cout << "\nError: You did something wrong, please check the error's number and solve the problem" << endl;
            keyfunctions(age);
        }
    }
    int keyfunctions(int age)
    {
        gotoxy(50, 13);
        age = age;
        auto SPACE = VK_SPACE;
        auto BACKSPACE = VK_BACK;
        auto LSHIFT = VK_LSHIFT;
        auto RSHIFT = VK_RSHIFT;
        auto LCONTROL = VK_LCONTROL;
        auto RCONTROL = VK_RCONTROL;
        cout << "\nPress 'Space' to exit\nPress 'Backspace' to reload\nPress 'Shift' to watch error codes\nPress 'Ctrl' to clear a console window" << endl;
        while (true)
        {
            Sleep(500);
            if (GetAsyncKeyState(SPACE))
            {
                return 0;
            }
            if (GetAsyncKeyState(BACKSPACE))
            {
                cout << "\n" << endl;
                actions(age);
            }
            if (GetAsyncKeyState(LSHIFT) or GetAsyncKeyState(RSHIFT)) {
                errors();
                instructions();
            }
            if (GetAsyncKeyState(LCONTROL) or GetAsyncKeyState(RCONTROL)) {
                clear();
                instructions();
            }
        }
    }
    void errors() {
        gotoxy(50, 0);
        cout << "\n\n~~~~~~~~~~~~~~~Error numbers~~~~~~~~~~~~~~~\n" << endl;
        cout << "Error 0: -- Your number (age) is more than 120" << endl;
        cout << "Error 1: -- Your number (age) is less than 0" << endl;
        cout << "Error 2: -- Your number (age) is equal 0" << endl;
        cout << "Error 3: -- Another problem" << endl;
    }
    void clear() {
        system("CLS");
    }
    void instructions() {
        gotoxy(50, 0);
        cout << "\n\nPress 'Space' to exit\nPress 'Backspace' to reload\nPress 'Shift' to watch error codes\nPress 'Ctrl' to clear a console window" << endl;
    }
    void menu() {
        while (true) {
            SetConsoleTitle(L"                                                 THE GAME ");
            ShowConsoleCursor(FALSE);
            SetCursorPos(6000, 6000);
            gotoxy(2, 29);
            cout << "\t\tMain menu\t\t|\t\t ";
            cout << "Second menu\t\t|\t\t";
            cout << "Third menu\t\t\t\t";
        }
    }
private:
    int _age;
};

/*
BOOL WINAPI ConsoleHandler(DWORD CEvent)
{
    char mesg[128];
    
    switch (CEvent)
    {
    case CTRL_C_EVENT:
        MessageBox(NULL,"CTRL+C received!", "CEvent", MB_OK);
        break;
    case CTRL_BREAK_EVENT:
        MessageBox(NULL,
            "CTRL+BREAK received!", "CEvent", MB_OK);
        break;
    case CTRL_CLOSE_EVENT:
        MessageBox(NULL,
            "Program being closed!", "CEvent", MB_OK);
        break;
    case CTRL_LOGOFF_EVENT:
        MessageBox(NULL,
            "User is logging off!", "CEvent", MB_OK);
        break;
    case CTRL_SHUTDOWN_EVENT:
        MessageBox(NULL,
            "User is logging off!", "CEvent", MB_OK);
        break;

    }
    return TRUE;
    
}
*/
void screensizetosymb() {
    int ScreenResX = GetSystemMetrics(SM_CXSCREEN);
    int ScreenResY = GetSystemMetrics(SM_CYSCREEN);
    /*
    int pixelsminY[1][5] = 
    {
        {
            600,             
        },
    };
    */

    int SymbolicScreenResX=0;
    int SymbolicScreenResY=0;

    cout << "Your resolution x: " << ScreenResX << " Your resolution y: " << ScreenResY << endl;

    switch (ScreenResY) 
    {
    case 600:
        SymbolicScreenResX = (ScreenResX) / 8;
        SymbolicScreenResY = (ScreenResY) / 16;
    break;

    case 720:
        SymbolicScreenResX = (ScreenResX) / 8;
        SymbolicScreenResY = (ScreenResY) / 16;
    break;

    case 1050:
        SymbolicScreenResX = (ScreenResX) / 8;
        SymbolicScreenResY = (ScreenResY) / 16;
    break;

    case 1080:
        SymbolicScreenResX = (ScreenResX) / 8;
        SymbolicScreenResY = (ScreenResY - 56) / 16;
    break;

    case 1440:
        SymbolicScreenResX = (ScreenResX) / 8;
        SymbolicScreenResY = (ScreenResY) / 16;
    break;


    }
    
    cout << "Your resolution in symbolic system, x: " << SymbolicScreenResX << " Your resolution y: " << SymbolicScreenResY << endl;
}
int main()
{
    screensizetosymb();
    

    /*
    Class screen;
    bool ready = false;
    cout << "Your Resolution x: " << x << "\tResolution y: " << y << "\n\n"<<x/16<< endl;
    cout << "Please open your console for the whole window!\n\n" << endl;
    Sleep(5000);
    cout << "After that write 1 if you are ready: "; cin >> ready;
    
    while (true) {
        if (ready == true){
            screen.gotoxy(x/16, y/32);
            
            cout << "It's a center of the screen. Congratulations!" << endl;
            break;
        }
    }
    */
    return 1;

    /*
    Class a;
    a.gotoxy(50, 13);
    //a.menu();
    a.exception(0);
    return 1;*/
}   
