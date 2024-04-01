#ifndef CLASSITEM_H
#define CLASSITEM_H

#include <string>

struct node {
    int orderID, x, z;

    std::string namaCustomer, tggl;

    int stokItem[10], menu2[10], menu3[10], jumlah[10], total;

    int itemID[10];

    std::string tipe[10];

    std::string strg[10];

    std::string vga[10];

    std::string proci[10];

    std::string namaKomputer[10];

    int harga[10];

    node* next;

};

class katalogItem {
    private:
        node* start_ptr;
        node* head;
        node* last;
    
    public:
        katalogItem() {
            start_ptr = nullptr;
            head = nullptr;
            last = nullptr;
        }

    void addItem();
    void orderItem();
    void editOrder();
    void removeOrder();
    void displayReceipt();
};

#endif