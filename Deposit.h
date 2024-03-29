#ifndef OOP_DEPOSIT_H
#define OOP_DEPOSIT_H

#include <unordered_map>
#include "Component.h"
#include "Case.h"
#include "CPU.h"
#include "GPU.h"
#include "Motherboard.h"
#include "Power_Supply.h"
#include "RAM.h"
#include "Storage.h"
#include "Monitor.h"

class Deposit{

    //vector<std::shared_ptr<Component>> components;
    static int number_of_products;
    static int number_of_orders;

public:
    vector<std::shared_ptr<Component>> components;
    bool search_product_by_ID(const string &_id);
    void delete_product_by_ID(const string& _id, int& count);
    void add_product(const std::shared_ptr<Component>& item);
    void add_product_by_ID(const string &ID);
    void add_products(const vector<std::shared_ptr<Component>>& items);
    void show_products();
    static void show_all_products(const vector<Deposit>& deposits);
    static int get_number_of_products();

    string promo_code_();
    Deposit()=default;
    Deposit(const Deposit& other);
    Deposit& operator=(Deposit other);
    friend void swap(Deposit& d1, Deposit& d2);


    ///from customer
    static void market(const vector<Deposit>& deposits);
    static int get_number_of_orders();
    static void order(const string & _id,const vector<Deposit>& deposits);

};


#endif
