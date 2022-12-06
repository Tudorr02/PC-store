#include "RAM.h"
#include "exceptions.h"

RAM::RAM(const string& _brand,const string &_name,float _price,bool _gaming,
         RAM_type _ram_type, RAM_Frequency _ram_frequency, int  _ram_capacity, bool  _ram_LED_light):
        Component(_brand,_name,_price,_gaming),
        ram_type(_ram_type),ram_frequency(_ram_frequency),ram_capacity(_ram_capacity),ram_LED_light(_ram_LED_light){

    ID_product.insert(0,"RA");

    if(_ram_capacity<2 || _ram_capacity>64)
        throw constructor_error("ram_capacity can' be smaller than 2/ bigger than 64",_ram_capacity);
}


std::shared_ptr<Component>RAM::clone() {return std::make_shared<RAM>(*this);}

float RAM::get_market_price() {return get_price()*float(1.8);}
int RAM::get_product_warranty() {
    int manufacturer_warranty=8;
    return warranty+manufacturer_warranty;
}

void RAM:: print(std::ostream& out) {

    out<<"->Type : ";

    switch (this->ram_type) {

        case RAM_type::DDR4 : out<<"DDR4";break;
        case RAM_type::DDR3 : out<<"DDR3";break;
        case RAM_type::DDR5 : out<<"DDR5";break;

    }

    out<<"\n";
    out<<"->Frequency : ";

    switch (this->ram_frequency) {

        case RAM_Frequency::MHz_1333: out<<"1333";break;
        case RAM_Frequency::MHz_1866: out<<"1866";break;
        case RAM_Frequency::MHz_2400: out<<"2400";break;
        case RAM_Frequency::MHz_2666: out<<"2666";break;
        case RAM_Frequency::MHz_5200: out<<"5200";break;
        case RAM_Frequency::MHz_5600: out<<"5600";break;

    }
    out<<" MHz\n";
    out<<"->Capacity : "<<this->ram_capacity<<" GB\n";
    out<<"->LED Lights : ";
    if(this->ram_LED_light) out<<"true";
    else
        out<<"false";
    out<<"\n";
}

string RAM::promo_code_() {return "";}