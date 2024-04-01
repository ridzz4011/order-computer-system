#include <iostream>
#include <string>

#include "../../include/classItem.h"

#include "../../include/pauseconsole.hpp"
#include "../../include/clearscreen.hpp"

void katalogItem::displayReceipt() {
    int num;
    bool found = false;

    ClearScreen();

    node* current = start_ptr;

    if (current == nullptr) {
        std::cout << "\t\t\t+================================================+\n" 
                  << "\t\t\t|    Tidak ada Order yang dapat ditampilkan!!!   |\n" 
                  << "\t\t\t|                 List kosong!!!                 |\n"
                  << "\t\t\t+================================================+" << std::endl ;
    }

    else {
        std::cout << "\nMasukkan nomor struk pembayaran: " ;
        std::cin >> num;
        std::cout << "\n" ;

        while (current != nullptr && !found) {
            if (current->orderID == num) {
                found = true;
            } else {
                current = current->next;
            }

            if (found) {
                std::cout << "================================================================================================\n" ;
                std::cout << "\t\t\t\t\t  Struk Pembayaran\n" ;
                std::cout << "================================================================================================\n\n" ;

                std::cout << "Nomor Struk Pembayaran : " << current->orderID << "\n" ;
                std::cout << "Nama Kustomer          : " << current->namaCustomer << "\n" ;
                std::cout << "Tanggal Order          : " << current->tggl << "\n" << std::endl ;

                std::cout << "+===================+==============================+====================+=======================+\n" ;
                std::cout << "|   Tipe Komputer   |         Nama Komputer        |  Jumlah Pembelian  |     Total Harga (Rp)  |\n" ;
                std::cout << "+===================+==============================+====================+=======================+\n" ;

                for (int i = 0; i < current->x; i++) {
                    std::cout << "\t" << current->tipe[current->menu3[i] - 1] << "  \t\t" ;
                    std::cout << " " << current->namaKomputer[current->menu3[i] - 1] << "\t  " ;
                    std::cout << "\t    " << current->stokItem[i] << "\t" ;
                    std::cout << "\t\t" << current->jumlah[i] << "\n" ;
                    std::cout << "+-------------------+------------------------------+--------------------+-----------------------+\n" ;
                }

                current->total = current->jumlah[0] + current->jumlah[1] + current->jumlah[2] + current->jumlah[3] + current->jumlah[4] + current->jumlah[5] + current->jumlah[6] + current->jumlah[7] + current->jumlah[8] + current->jumlah[9];
                std::cout << "\nTotal Tagihan: Rp" << current->total << "\n\n" ;

                std::cout << "\n" ;
                std::cout << "+------------------------------------------+\n" ;
                std::cout << "|   Terimakasih telah berbelanja disini!   |\n" ;
                std::cout << "+------------------------------------------+\n" ;
                std::cout << "\n================================================================================================\n" << std::endl ;
            }
        }
        
        if (!found) {
            std::cout << "\n+------------------------------------------+\n" ;
            std::cout << "|          Order Tidak Ditemukan!!         |\n" ;
            std::cout << "+------------------------------------------+\n" ;
        }
    }
}