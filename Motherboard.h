
#ifndef OOP_MOTHERBOARD_H
#define OOP_MOTHERBOARD_H


#include "Component.h"
#include "CPU.h"

enum Format { ATX, eATX,mATX,mITX};

class Motherboard:public Component{

    CPU_Socket m_compatible_socket;
    int m_ram_slots;
    Format m_format;
    bool m_LED_light;
    void print(std::ostream& out) override;
public:

    Motherboard(const string& _brand,const string &_name,float _price,bool _gaming,
                CPU_Socket _m_compatible_socket, int _m_ram_slots, Format  _m_format, bool  _m_LED_light);

    std::shared_ptr<Component> clone() override;
    float get_market_price() override;
    int get_product_warranty() override;
    string promo_code_() override;
};


#endif
