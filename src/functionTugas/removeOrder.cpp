#include <iostream>
#include <string>

#include "../../include/classItem.h"

#include "../../include/pauseconsole.hpp"
#include "../../include/clearscreen.hpp"

void katalogItem::removeOrder() {

    PauseConsole();
    ClearScreen();

    node* temp = start_ptr;

    if (start_ptr == nullptr) {
        std::cout << "\t\t\t+================================================+\n" 
                  << "\t\t\t|    Tidak ada List yang dapat ditampilkan!!!    |\n" 
                  << "\t\t\t|                 List kosong!!!                 |\n"
                  << "\t\t\t+================================================+" << std::endl ;
    }

    else {
        int num, hitung;

        node *q;
        node *temp;

        std::cout << "\nMasukkan nomor struk pembayaran yang ingin diubah: ";
        std::cin >> num;
        
        bool found = false;

        if (start_ptr->orderID == num)
        {
            q = start_ptr;
            start_ptr = start_ptr->next;

            hitung--;

            if (start_ptr == nullptr) {
                last = nullptr;
            } delete q;

            std::cout << "\n+------------------------------------------+\n" ;
            std::cout << "|         Order Berhasil Dihapus!!!        |\n" ;
            std::cout << "+------------------------------------------+\n" ;
        }

        else
        {
            temp = start_ptr;
            q = start_ptr->next;

            while ((!found) && (q != nullptr))
            {
                if (q->orderID != num)
                {
                    temp = q;
                    q = q->next;
                }

                else {
                    found = true;
                }                
            }

            if (found)
            {
                temp->next = q->next;
                hitung--;

                if (last == q) {
                    last = temp;
                } delete q;

                std::cout << "\n+------------------------------------------+\n" ;
                std::cout << "|         Order Berhasil Dihapus!!!        |\n" ;
                std::cout << "+------------------------------------------+\n" ;
            }

            else
            {
                std::cout << "\n+------------------------------------------+\n" ;
                std::cout << "|          Order Tidak Ditemukan!!         |\n" ;
                std::cout << "+------------------------------------------+\n" ;
            }
        }
    }

}