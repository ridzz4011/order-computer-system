#include <iostream>
#include <string>

#include "../../include/classItem.h"

#include "../../include/pauseconsole.hpp"
#include "../../include/clearscreen.hpp"

void katalogItem::orderItem() {

    PauseConsole();
    ClearScreen();

    bool loop1 = true;

    do {

        node* current = start_ptr;

        if (current == nullptr) {
            std::cout << "\t\t\t+================================================+\n" 
                      << "\t\t\t|   Tidak ada Barang yang dapat ditampilkan!!!   |\n" 
                      << "\t\t\t|             List Barang kosong!!!              |\n"
                      << "\t\t\t+================================================+" << std::endl ;
            break;
        }

        else {

            std::string decoL1 = "========================================================================================================================================\n" ;
            std::string decoL2 = "+--------+-----------------+------------------------------+---------------------------------+------------------+-----------------------+\n" ;

            std::cout << decoL1 ;
            std::cout << " ID "
                      << "\t     Tipe Item"
                      << "\t\tNama Item"
                      << "       \t\tProsesor"
                      << "      \t\t\tPenyimpanan"
                      << "         Harga"
                      << "\n" ;

            std::cout << decoL1 ;

            std::cout << decoL2 ;

            while (current != nullptr) {
                for (int i = 0; i < current->z; i++) {
                    std::cout << current->itemID[i] << " "
                              << "\t     "
                              << current->tipe[i]
                              << "\t\t       "
                              << current->namaKomputer[i]
                              << "\t\t"
                              << current->proci[i]
                              << "\t\t"
                              << current->strg[i]
                              << "          Rp"
                              << current->harga[i]
                              << "\n" ;
                    std::cout << decoL2 ;
                }
                std::cout << "\n\n\n" ;
                current = current->next; // Move ke node selanjutnya
            }
            
            bool loop2 = true;

            do {
                int programOrder;

                std::string decoL3 = "-------------------------------------------\n";

                std::cout << decoL3 ;
                std::cout << "1. Cek Spesifikasi Barang\n" ;
                std::cout << "2. Order Barang\n" ;
                std::cout << "3. Back\n" ;

                std::cout << "Masukkan Pilihan: " ;
                std::cin >> programOrder;

                switch (programOrder)
                {
                case 1:
                    {
                        node* current = start_ptr;
                        std::cout << decoL3;

                        while (current != nullptr) {
                            for (int i = 0; i <= 1; i++) {
                                std::cout << "Masukkan ID Item: " ;
                                std::cin >> current->menu2[i];

                                std::cout << "\nSpesifikasi Item:\n\n" ;

                                std::cout << decoL3;

                                std::cout << "Nama Komputer: " << current->namaKomputer[current->menu2[i] - 1] << "\n" ;
                                std::cout << "Tipe: " << current->tipe[current->menu2[i] - 1] << "\n" ;
                                std::cout << "Prosesor: " << current->proci[current->menu2[i] - 1] << "\n" ;
                                std::cout << "Graphic Card: " << current->vga[current->menu2[i] - 1] << "\n" ;
                                std::cout << "Penyimpanan: " << current->strg[current->menu2[i] - 1] << "\n" ;

                            }
                            current = current->next;
                        }
                        
                    }
                    PauseConsole();
                    ClearScreen();
                    break;

                case 2:
                    {
                        node* temp = start_ptr;

                        std::cout << decoL3;

                        std::cout << "Masukkan nomor struk pembayaran: " ;
                        std::cin >> temp->orderID;

                        std::cout << "Masukkan nama Anda: " ;
                        std::getline(std::cin >> std::ws, temp->namaCustomer);

                        std::cout << "Masukkan tanggal (DD/MM/YY): " ;
                        std::getline(std::cin >> std::ws, temp->tggl);

                        std::cout << decoL3;


                        std::cout << "\nBerapa banyak Item yang ingin anda beli? (Maks 10)\n" ;
                        std::cout << "Jumlah item: " ;
                        std::cin >> temp->x;

                        std::cout << "\n" ;

                        if (temp->x <= 0) {
                            std::cout << "\nMasukkan jumlah!!!\n" ;
                            std::cout << decoL3;
                        }

                        else if (temp->x > temp->z) {
                            std::cout << "\nJumlah Item terlalu banyak!!!\n" ;
                            std::cout << decoL3;
                        }

                        else {
                            std::cout << decoL3;

                            std::cout << "\nMasukkan ID untuk barang yang ingin anda beli!\n" ;

                            for (int i = 0; i < temp->x; i++) {
                                std::cout << "ID: " ;
                                std::cin >> temp->menu3[i];

                                std::cout << "Nama Item: " << temp->namaKomputer[temp->menu3[i] - 1] << "\n" ;

                                std::cout << "Ingin membeli berapa: " ;
                                std::cin >> temp->stokItem[i];

                                temp->jumlah[i] = temp->stokItem[i] * temp->harga[temp->menu3[i] - 1];
                                std::cout << "Harga yang harus dibayar: Rp" << temp->jumlah[i] << "/-\n" ;

                                std::cout << decoL3 << std::endl;

                                PauseConsole();
                            }

                            std::cout << "+------------------------------------------+\n" ;
                            std::cout << "|        Order Berhasil Ditambahkan!       |\n" ;
                            std::cout << "+------------------------------------------+\n" ;

                            std::cout << "\n" ;
                            std::cout << "+------------------------------------------+\n" ;
                            std::cout << "|          Silahkan bayar dikasir!         |\n" ;
                            std::cout << "+------------------------------------------+\n" ;

                            temp->next = nullptr;

                            if (start_ptr != nullptr) {
                                temp->next = start_ptr;
                            }

                            start_ptr = temp;
                            
                        }
                    }
                    PauseConsole();
                    ClearScreen();
                    break;
                
                case 3:
                    std::cout << "Kembali..." << std::endl;
                    ClearScreen();
                    loop2 = false;
                    loop1 = false;

                default:
                    std::cout << "Angka yang anda pilih tidak ada di pilihan!" << std::endl ;
                    PauseConsole();
                    ClearScreen();
                    break;
                }
                
            } while (loop2);
            
        }

    } while (loop1);
    
}