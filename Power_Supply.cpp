#include "Power_Supply.h"


Power_Supply::Power_Supply(const string& _brand,const string &_name,float _price,bool _gaming,
                           PS_Power _ps_power, PS_Certification _ps_certification, PS_Modular _ps_modular):
        Component(_brand,_name,_price,_gaming),
        ps_power(_ps_power),ps_certificaiton(_ps_certification),ps_modular(_ps_modular){

    ID_product.insert(0,"PO");


}

std::shared_ptr<Component> Power_Supply::clone() {return std::make_shared<Power_Supply>(*this);}

float Power_Supply::get_market_price() {return get_price()*float(1.8);}
int Power_Supply::get_product_warranty() {
    int manufacturer_warranty=8;
    return warranty+manufacturer_warranty;
}


void Power_Supply:: print(std::ostream& out) {

    out<<"->Power : ";

    switch (this->ps_power) {

        case PS_Power::MHz_1000: out<<"1000 MHz";break;
        case PS_Power::MHz_550 : out<<"550 Mhz"; break;
        case PS_Power::MHz_650 : out<<"650 MHz"; break;
        case PS_Power::MHz_750 : out<<"750 MHz"; break;
        case PS_Power::MHz_850 : out<<"850 MHz"; break;

    }
    out<<"\n";
    out<<"->Certificaiton : ";

    switch (this->ps_certificaiton) {

        case PS_Certification::Gold_80 : out<<"GOLD";break;
        case PS_Certification::Bronze_80: out<<"BRONZE"; break;
        case PS_Certification::Platinum_80: out<<"PLATINUM"; break;
        case PS_Certification::Silver_80: out<<"SILVER"; break;
        case PS_Certification::Titanium_80: out<<"TITANUM"; break;

    }

    out<<" 80+\n";
    out<<"->Modular : ";

    switch (this->ps_modular) {

        case PS_Modular::Non_Modular :out<<"No";break;
        case PS_Modular::Full_Modular : out<<"Full-Modular";break;
        case PS_Modular::Semi_Modular:out<<"Semi-Modular";break;
    }
    out<<"\n";
}
