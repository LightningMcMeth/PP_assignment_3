#include <iostream>
#include <string>
#include <Windows.h>

int main()
{
    //CHANGE PATHS //C:\\Users\\markh\\OneDrive\\Documents\\Gamer repositories\\PP assignments\\PP_assignment_3\\CaesarsCipher\\Debug\\CaesarsCipher.dll
    HINSTANCE handle = LoadLibrary(TEXT("C:\\Users\\markh\\OneDrive\\Documents\\Gamer repositories\\PP assignments\\PP_assignment_3\\CaesarsCipher\\Debug\\CaesarsCipher.dll"));
    DWORD err = GetLastError();

    typedef void(*encryptText)(char*, int);
    encryptText encrypt_ptr = (encryptText)GetProcAddress(handle, "encryptText");
    err = GetLastError();

    typedef void(*decryptText)(char*, int);
    decryptText decrypt_ptr = (decryptText)GetProcAddress(handle, "decryptText");
    err = GetLastError();

    typedef void(*printText)(char*);
    printText print_ptr = (printText)GetProcAddress(handle, "printText");
    err = GetLastError();

    int cmd = 0;
    char text[100];
    text[99] = '\0';
    int key = 0;

    while (1) {

        std::cout << "\nenter text - 1 \nencrypt - 2 \ndecrypt - 3 \nprint - 4: ";
        std::cin >> cmd;

        switch (cmd)
        {
        case 1:

            std::cin.ignore();
            std::cout << "\nEnter text: ";

            fgets(text, sizeof(text), stdin);
            std::cout << "\n text entered";

            break;

        case 2:

            std::cin.ignore();
            std::cout << "\nEnter key: ";
            std::cin >> key;

            encrypt_ptr(text, key);
            std::cout << "\n text decrypted";
            break;

        case 3:

            std::cin.ignore();
            std::cout << "\nEnter key: ";
            std::cin >> key;

            decrypt_ptr(text, key);
            break;

        case 4:

            print_ptr(text);
            break;

        }
    }

    FreeLibrary(handle);
    return 0;
}
