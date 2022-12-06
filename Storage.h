
#ifndef OOP_STORAGE_H
#define OOP_STORAGE_H
#include "Component.h"

enum Storage_Type { HDD,SSD};

class Storage: public Component{

    Storage_Type storage_type;
    int storage_capacity;
    void print(std::ostream& out) override;
    string promo_code;

public:

    Storage(const string& _brand,const string &_name,float _price,bool _gaming,
            Storage_Type _storage_type, int  _storage_capacity);


    std::shared_ptr<Component> clone()override;
    float get_market_price() override;
    int get_product_warranty() override;
    string promo_code_() override;

};

#endif
