#include <iostream>

#include <memory>
#include "Deposit.h"
#include "Customer.h"
#include "exceptions.h"

using std::cout;

int main(){

    vector<Ports> gaming_ports_gpu{Ports::DVI,Ports::DisplayPort,Ports::HDMI};
    vector<Ports> no_gaming_gpu{Ports::VGA,Ports::DVI};

    std::shared_ptr<Component>c1;
    std::shared_ptr<Component>c2;
    std::shared_ptr<Component>c3;
    std::shared_ptr<Component>c4;
    std::shared_ptr<Component>c5;
    std::shared_ptr<Component>c6;
    std::shared_ptr<Component>c7;
    std::shared_ptr<Component>c8;
    std::shared_ptr<Component>c9;
    std::shared_ptr<Component>c10;
    std::shared_ptr<Component>c11;
    std::shared_ptr<Component>c12;
    std::shared_ptr<Component>c13;
    std::shared_ptr<Component>c14;
    std::shared_ptr<Component>c15;
    std::shared_ptr<Component>c16;
    std::shared_ptr<Component>c17;
    std::shared_ptr<Component>c18;
    std::shared_ptr<Component>c19;
    std::shared_ptr<Component>c20;
    std::shared_ptr<Component>c21;
    std::shared_ptr<Component>c22;
    std::shared_ptr<Component>c23;
    std::shared_ptr<Component>c24;
    std::shared_ptr<Component>c25;


    try {
        c1 = std::make_shared<CPU>("Intel", "Intel i7 k40900", 700, true, 8, 16, 15,
                                   CPU_Socket::LGA_1700, CPU_Series::Intel_I7);
        c2=std ::make_shared<Case>("Kingston","Kinston JKQQ",800,false,999,3,true,Case_colors::white);
        c3=std::make_shared<GPU>("Gigabyte","GTX 1500",900,true,4,GPU_Memory_Type::GDDR3,GPU_Series::GTX_1000,gaming_ports_gpu,4);
        c4=std::make_shared<Motherboard>("Gigabye", "ZX 8900", 300, true,CPU_Socket::AM4,3,Format::mITX,false);
        c5=std::make_shared<Power_Supply>("Corsair","CS-800",300,true,PS_Power::MHz_750,PS_Certification::Titanium_80,PS_Modular::Semi_Modular);
        c6=std::make_shared<RAM>("SAMSUNG","SAMSUNG 344",190,true,RAM_type::DDR5,RAM_Frequency::MHz_5600,8,false);
        c7=std::make_shared<Storage>("SAMSUNG","CS 9800",500,true,Storage_Type::SSD,256);
        c8=std::make_shared<Storage>("AMD","CS 9800",500,true,Storage_Type::SSD,256);
        c9=std::make_shared<Storage>("SAMSUNG","CS 6700-S",300,false,Storage_Type::SSD,512);
        c10=std::make_shared<CPU>("AMD","AMD Ryzen5 5500",900,true,8,6,3,CPU_Socket::AM4,CPU_Series::AMD_Ryzen_5);
        c11=std::make_shared<RAM>("Kingston","Kingstone CX67",670,true,RAM_type::DDR3,RAM_Frequency::MHz_1866,16,false);
        c12= std::make_shared<Motherboard>("ASUS","ASUS KC-33",340,true,CPU_Socket::LGA_1151,4,Format::eATX,false);
        c13=std::make_shared<GPU>("ASUS","GeForce RTX 3060",2000,true,16,GPU_Memory_Type::GDDR6,GPU_Series::GTX_3000,gaming_ports_gpu,4);
        c14=std::make_shared<Power_Supply>("Corsair","SQ-890",900,true,PS_Power::MHz_850,PS_Certification::Platinum_80,PS_Modular::Full_Modular);
        c15=std::make_shared<CPU>("Intel","Intel i3-2564",300,false,2,4,4,CPU_Socket::LGA_1700,CPU_Series::Intel_I3);
        c16=std::make_shared<RAM>("ADATA","ADATA T34",700,true,RAM_type::DDR4,RAM_Frequency::MHz_2666,32,true);


    } catch (constructor_error & e) {
        cout << e.what() << "\n";
    } catch (input_error & e) {
        cout<<e.what()<<"\n";
    }catch ( error_app & e){
        cout<<e.what()<<"\n";
    }

    c17=c16->clone();
    c18=c17->clone();
    c19=c18->clone();
    c20=c1->clone();
    c21=c2->clone();
    c22=c3->clone();
    c23=c4->clone();
    c24=c5->clone();
    c25=c5->clone();











}

