#include <iostream>
#include <string>

#include "../../include/classItem.h"

#include "../../include/pauseconsole.hpp"
#include "../../include/clearscreen.hpp"

void katalogItem::addItem() {

    PauseConsole();
    ClearScreen();

    node* temp = new node;

    std::cout << "Masukkan item yang mau ditambahkan!\n" ;

    std::cout << "Masukkan jumlah item (batas 10): " ;
    std::cin >> temp->z;

    std::cout <<"\n==================================================================\n" ;
    
    if (temp->z <= 0) {
        std::cout << "\nMasukkan jumlah!!!\n" ;
    }

    else if (temp->z > 10) {
        std::cout << "\nJumlah Item terlalu Banyak!!!\n" ;
    }

    else {
        for (int i = 0; i < temp->z; i++) {
            std::cout << "ID item ke-" << i + 1 << ": " ;
            std::cin >> temp->itemID[i];

            std::cout << "Tipe item (Laptop/PC): " ;
            std::getline(std::cin >> std::ws, temp->tipe[i]);

            std::cout << "Nama Komputer: " ;
            std::getline(std::cin >> std::ws, temp->namaKomputer[i]);

            std::cout << "Penyimpanan (SSD: 256GB, 512GB, 1TB RAM: 4GB, 8GB, 16GB SSD/RAM): " ;
            std::getline(std::cin >> std::ws, temp->strg[i]);

            std::cout << "Model Prosesor: " ;
            std::getline(std::cin >> std::ws, temp->proci[i]);

            std::cout << "Model VGA: " ;
            std::getline(std::cin >> std::ws, temp->vga[i]);

            std::cout << "Harga Item: Rp" ;
            std::cin >> temp->harga[i];

            std::cout <<"\n==================================================================\n" ;
        }

        std::cout << "\nBerhasil menambahkan Item ke katalog!\n\n" ;

        temp->next = nullptr;

        /* Kode dibawah gunanya agar item yang masuk itu tidak masuk ke index pertama
           tapi masuk ke index terakhir. */

        if (start_ptr == nullptr) {      // Ketika listnya kosong
            start_ptr = temp;            // set start_ptr ke node baru
        }

        else {  // Ketika Listnya tidak kosong

            // Scan keseluruhan list untuk mencari node terakhir
            node* current = start_ptr;

            while (current != nullptr) {
                current = current->next;
            }

            // Menambahkan node baru ke list terakhir
            current->next = temp;
        }
    }
    
}