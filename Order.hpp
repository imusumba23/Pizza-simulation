//
// Created by Ephrathah Gebremichael on 11/28/2021.
//

#ifndef PIZZA_ORDER_HPP
#define PIZZA_ORDER_HPP

#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include "Time.hpp"

class Order{
public:
    Order();
    Order(Time time, string info);
    void serve();
    void depart() throw (logic_error);
    void deliver(Time time) throw (logic_error);
    int getMinToDelivery() throw (logic_error);
    string toString();

private:
    Time time_placed;
    Time time_delivered;
    string order_info;
    bool order_is_out_for_delivery;
    bool order_is_at_the_restaurant;
    bool order_is_delivered;


};


/*
 * Pre: None
 *Post: creates an order with default values for data members
 */
Order::Order(){

}



/*
 * Pre: None
 * Post: creates an order with the given order time and information
 */
Order::Order(Time placed, string info){
    order_info = info;
    order_is_out_for_delivery = false;
    order_is_delivered= false;
    order_is_at_the_restaurant = true;
    time_placed = placed;
}

/*
 * Pre: Order is at restaurant
 * Post: Order is out for delivery
 */
void Order::depart() throw (logic_error){
    if(!order_is_at_the_restaurant){
        throw logic_error("Order is not at the restaurant");
    }
    order_is_out_for_delivery = true;
    order_is_at_the_restaurant = false;
}

/*
 * Pre: Order is out for delivery
 * Post: Order is delivered. Time to delivery is recorded
 */
void Order::deliver(Time time)throw (logic_error){
    if(!order_is_out_for_delivery){
        throw logic_error("The order is not out for delivery");
    }

    time_delivered = time;
    order_is_delivered = true;
}

/*
 * Pre: Order is delivered
 * Post: Returns the minutes until the order is delivered
 */
int Order::getMinToDelivery() throw (logic_error){
    if(order_is_delivered==false)
        throw logic_error("The order has not been delivered");
    return Time::elapsedMin(time_placed, time_delivered);
}


/*
 * Precondition: None
 * Post: Returns a string containing the order time and info
 */
string Order::toString(){
    string status;
    status = time_placed.toString()+" "+ order_info;
    return status;
}

#endif
