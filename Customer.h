
#ifndef OOP_CUSTOMER_H
#define OOP_CUSTOMER_H

#include "Deposit.h"

class Customer {

    static int number_of_orders;

public:

    static void market(vector<Deposit>& deposits);
    static int get_number_of_orders();
    static void order(const string & _id,const vector<Deposit>& deposits);


};


#endif
