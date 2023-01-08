
#ifndef OOP_CPU_H
#define OOP_CPU_H
#include "Component.h"

enum CPU_Socket { AM4,LGA_1151,LGA_1200,LGA_1700};
enum CPU_Series {Intel_Celeron,Intel_Pentium,Intel_I3,Intel_I5,Intel_I7,Intel_I9,
    AMD_Ryzen_3,AMD_Ryzen_5,AMD_Ryzen_7,AMD_Ryzen_9};

class CPU : public Component{
private:
    void print(std::ostream& out) override;
protected:
    int cpu_cores;
    int cpu_threads;
    int cpu_frequency;
    CPU_Socket cpu_socket;
    CPU_Series cpu_series;

public:
    CPU(const string& _brand,const string &_name,float _price,bool _gaming,
        int _cpu_cores,int _cpu_threads,int _cpu_frequency,CPU_Socket _cpu_socket, CPU_Series _cpu_series );

    std::shared_ptr<Component> clone()override;
    float get_market_price() override;
    int get_product_warranty() override;




};


#endif
