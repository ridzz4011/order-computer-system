#include <iostream>
#include <string>

#include "../../include/classItem.h"

#include "../../include/pauseconsole.hpp"
#include "../../include/clearscreen.hpp"

void katalogItem::editOrder() {
    
    PauseConsole();
    ClearScreen();

    int oid;
    bool found = false;
    
    node* temp = start_ptr;

    if (temp == nullptr || oid == 0) {
        std::cout << "\t\t\t+================================================+\n" 
                  << "\t\t\t|   Tidak ada Order yang dapat dimodifikasi!!!   |\n" 
                  << "\t\t\t+================================================+\n" << std::endl ;
    }

    else {
        std::cout << "\nMasukkan nomor struk pembayaran yang ingin diubah: " ;
        std::cin >> oid;

        while (temp != nullptr && !found) {
            if (temp->orderID == oid) {
                found = true;
            } else {
                temp = temp->next;
            }

            if (found) {
                std::cout << "Ubah nomor struk pembayaran: " ;
                std::cin >> temp->orderID;

                std::cout << "Ubah nama: " ;
                std::getline(std::cin >> std::ws, temp->namaCustomer);

                std::cout << "Ubah tanggal (DD/MM/YY): " ;
                std::getline(std::cin >> std::ws, temp->tggl);

                std::cout << "\nBerapa banyak Item yang ingin anda ubah? (Maks 10)\n" ;
                std::cout << "Jumlah item: " ;
                std::cin >> temp->x;

                std::cout << "\n" ;

                if (temp->x <= 0) {
                    std::cout << "\nMasukkan jumlah!!!\n" ;
                }

                else if (temp->x > temp->z) {
                    std::cout << "\nJumlah Item terlalu banyak!!!\n" ;
                }

                else {

                    std::cout << "\nMasukkan ID untuk barang yang ingin anda ubah!\n" ;

                    for (int i = 0; i < temp->x; i++) {
                        std::cout << "ID: " ;
                        std::cin >> temp->menu3[i];

                        std::cout << "Nama Item: " << temp->namaKomputer[temp->menu3[i] - 1] << "\n" ;

                        std::cout << "Ingin membeli berapa: " ;
                        std::cin >> temp->stokItem[i];

                        temp->jumlah[i] = temp->stokItem[i] * temp->harga[temp->menu3[i] - 1];
                        std::cout << "Harga yang harus dibayar setelah diubah: Rp" << temp->jumlah[i] << "/-\n" ;

                        std::cout << std::endl;

                        PauseConsole();
                    }

                    temp = temp->next;

                    ClearScreen();
                }

                std::cout << "\t\t\t+================================================+\n" 
                          << "\t\t\t|              Order Berhasil Diubah!            |\n" 
                          << "\t\t\t+================================================+\n" << std::endl ;                
            }

            else {
                if (temp != nullptr && temp->orderID != oid) {
                    std::cout << "\t\t\t+================================================+\n" 
                              << "\t\t\t|          Nomor Struk Tidak Ditemukan...        |\n" 
                              << "\t\t\t+================================================+\n" << std::endl ;
                }
            }
        }
    }
}