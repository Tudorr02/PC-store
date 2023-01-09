#include "Storage.h"
#include "exceptions.h"
#include<cstdlib>

std::string get_random(const int len) {
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

Storage::Storage(const string& _brand,const string &_name,float _price,bool _gaming,
                 Storage_Type _storage_type, int  _storage_capacity):
        Component(_brand,_name,_price,_gaming),
        storage_type(_storage_type),storage_capacity(_storage_capacity){

    this->ID_product.insert(0,"ST");
    this->promo_code= get_random(12);

    if(_storage_capacity<56 || _storage_capacity>4000)
        throw constructor_error_invalid_attribute("storage_capacity can' be smaller than 56/ bigger than 4000",_storage_capacity);

}

std::shared_ptr<Component> Storage::clone() {return std::make_shared<Storage>(*this);}

float Storage::get_market_price() {return get_price()*float(1.8);}
int Storage::get_product_warranty() {
    int manufacturer_warranty=8;
    return warranty+manufacturer_warranty;
}

string Storage::promo_code_() {return this->promo_code;}

void Storage:: print(std::ostream& out) {

    out<<"->Type : ";
    switch (this->storage_type) {

        case Storage_Type::SSD: out<<"SSD";break;
        case Storage_Type::HDD: out<<"HDD";break;
    }
    out<<"\n";

    out<<"->Capacity : "<<this->storage_capacity<<" GB\n";
}