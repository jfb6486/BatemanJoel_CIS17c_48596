/* * File:   customer.h * Author: Joel Bateman * Created on September 26, 2014 * Purpose:  Explore creation of a linked list class */#ifndef Assignment6_Customer_h#define Assignment6_Customer_hclass Customer{private:    int clock;    int transactionTime;    int numberOfArrivals;  public:    Customer(){}        Customer (int clock, int transactionTime, int numberOfArrivals)    {        this->clock = clock;        this->transactionTime = transactionTime;        this->numberOfArrivals = numberOfArrivals;    }        int getTransactionTime()    {        return transactionTime;    }        int getArrivalTime()    {        return clock;    }        int getCustomerNumber()    {        return numberOfArrivals;    }    };#endif