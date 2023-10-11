#include <iostream>
#include <string>
#include <Windows.h>

int main()
{
    //CHANGE PATHS
    HINSTANCE handle = LoadLibrary(TEXT("C:\\Users\\markh\\OneDrive\\Documents\\Gamer repositories\\CaesarsCipher\\x64\\Debug\\CaesarsCipher.dll"));

    typedef void(*encryptText)(char*, int);
    encryptText encrypt_ptr = (encryptText)GetProcAddress(handle, "encryptText");

    typedef void(*decryptText)(char*, int);
    decryptText decrypt_ptr = (decryptText)GetProcAddress(handle, "decryptText");

    typedef void(*printText)(char*);
    printText print_ptr = (printText)GetProcAddress(handle, "printText");

    int cmd;
    char text[100];
    text[99] = '\0';
    int key = 0;

    std::cout << "\nenter text - 1, encrypt - 2, decrypt - 3, print - 4: ";
    std::cin >> cmd;

    while (1) {
        switch (cmd)
        {
        case 1:

            std::cin.ignore();
            std::cout << "\nEnter text: ";

            fgets(text, sizeof(text), stdin);
            break;

        case 2:

            std::cin.ignore();
            std::cout << "\nEnter key: ";
            std::cin >> key;

            encrypt_ptr(text, key);
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
