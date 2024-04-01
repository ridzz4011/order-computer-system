#include <iostream>
#include <string>

/* Function Misc */

#include "include/clearscreen.hpp"
#include "include/loading.hpp"
#include "include/pauseconsole.hpp"
#include "include/intro.hpp"

/* Function Tugas */

#include "include/classItem.h"

void deco() {
    for (int i = 0; i < 85; i++) {
        std::cout << "=" ;
    }
}

void deco2() {
    for (int i = 0; i < 85; i++) {
        std::cout << "_" ;
    }
}

int main(int, char**){
    using namespace std;

    Intro();

    Loading();

    int program;

    bool ulang = true;

    katalogItem TokoOnline; // Deklarasi Class menjadi Object

    do 
    {
        deco();
        cout << "\n" ;

        cout << "\t\t\t" << "|" << "\tToko Komputer Ceritanya\t    " << "|" << "\n";
        cout << "1. Tambahkan item ke katalog" << "\n";
        cout << "2. Ambil order" << "\n";
        cout << "3. Hapus order" << "\n";
        cout << "4. Edit order" << "\n";
        cout << "5. Print struk pembayaran\n" ;
        cout << "6. Exit" << "\n";

        deco();
        cout << "\n";

        cout << "Masukkan pilihan: ";
        cin >> program;

        deco2();
        cout << endl;

        switch (program)
        {
        case 1:
            TokoOnline.addItem();
            PauseConsole();
            ClearScreen();
            break;

        case 2:
            TokoOnline.orderItem();
            PauseConsole();
            ClearScreen();
            break;

        case 3:
            TokoOnline.removeOrder();
            PauseConsole();
            ClearScreen();
            break;

        case 4:
            TokoOnline.editOrder();
            PauseConsole();
            ClearScreen();
            break;

        case 5:
            TokoOnline.displayReceipt();
            PauseConsole();
            ClearScreen();
            break;

        case 6:
            cout << "Keluar dari program..." << endl;
            ulang = false;
            PauseConsole();
            ClearScreen();
            break;
        
        default:
            cout << "Angka yang anda pilih tidak ada di pilihan!" << endl ;
            PauseConsole();
            ClearScreen();
            break;
        }

    } while (ulang);

    return 0;
}
