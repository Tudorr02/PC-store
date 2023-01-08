#include "Motherboard.h"
#include "exceptions.h"
Motherboard::Motherboard(const string& _brand,const string &_name,float _price,bool _gaming,
                         CPU_Socket _m_compatible_socket, int  _m_ram_slots, Format _m_format, bool  _m_LED_light):
        Component(_brand,_name,_price,_gaming),
        m_compatible_socket(_m_compatible_socket),m_ram_slots(_m_ram_slots),m_format(_m_format),m_LED_light(_m_LED_light){

    ID_product.insert(0,"MO");

    if(_m_ram_slots<2 || _m_ram_slots>8)
        throw constructor_error_invalid_attribute(" m_ram_slots can't be smaller than 2 / bigger than 8",_m_ram_slots);
}

std::shared_ptr<Component> Motherboard::clone() {return std::make_shared<Motherboard>(*this);}

float Motherboard::get_market_price() {return get_price()*float(1.8);}
int Motherboard::get_product_warranty() {
    int manufacturer_warranty=8;
    return warranty+manufacturer_warranty;
}

void Motherboard:: print(std::ostream& out) {
    out<<"->Compatible Socket : ";
    switch (this->m_compatible_socket) {

        case CPU_Socket::LGA_1700 :out<<"LGA 1700"; break;
        case CPU_Socket::LGA_1151 : out<<"LGA 1151";break;
        case CPU_Socket::LGA_1200 : out<<"LGA 1200"; break;
        case CPU_Socket::AM4 : out<<"AM4";break;

    }
    out<<"\n";
    out<<"->RAM Slots : "<<this->m_ram_slots<<"\n";
    out<<"->Format : ";

    switch (this->m_format) {

        case Format::ATX: out<<"ATX";break;
        case Format::mATX: out<<"mATX";break;
        case Format::eATX: out<<"eATX"; break;
        case Format::mITX: out<<"mITX"; break;
    }

    out<<"\n";
    out<<"->LED Lights : ";

    if(this->m_LED_light) out<<"true";
    else
        out<<"false";
    out<<"\n";
}

