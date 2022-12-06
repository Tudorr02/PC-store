
#ifndef OOP_POWER_SUPPLY_H
#define OOP_POWER_SUPPLY_H

#include "Component.h"

enum PS_Power{MHz_550,MHz_650,MHz_750,MHz_850,MHz_1000};
enum PS_Certification {Bronze_80,Silver_80,Gold_80,Platinum_80,Titanium_80};
enum PS_Modular {Non_Modular,Semi_Modular,Full_Modular};

class Power_Supply: public  Component{

    PS_Power ps_power;
    PS_Certification ps_certificaiton;
    PS_Modular ps_modular;
    void print(std::ostream& out) override;

public:

    Power_Supply(const string& _brand,const string &_name,float _price,bool _gaming,
                 PS_Power _ps_power, PS_Certification _ps_certification, PS_Modular _ps_modular);

    std::shared_ptr<Component> clone()override;
    float get_market_price() override;
    int get_product_warranty() override;
    string promo_code_() override;
};


#endif
