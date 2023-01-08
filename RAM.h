
#ifndef OOP_RAM_H
#define OOP_RAM_H

#include "Component.h"


enum RAM_type {DDR3,DDR4,DDR5};
enum RAM_Frequency {MHz_1333,MHz_1866,
    MHz_2400,MHz_2666,
    MHz_5200,MHz_5600,};


class RAM:public Component{

    RAM_type ram_type;
    RAM_Frequency ram_frequency;
    int ram_capacity;
    bool ram_LED_light;
    void print(std::ostream& out) override;

public:

    RAM(const string& _brand,const string &_name,float _price,bool _gaming,
        RAM_type _ram_type, RAM_Frequency _ram_frequency, int  _ram_capacity, bool  _ram_LED_light);

    std::shared_ptr<Component> clone()override;
    float get_market_price() override;
    int get_product_warranty() override;

};


#endif
