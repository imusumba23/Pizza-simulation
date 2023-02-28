//
// Created by Ephrathah Gebremichael on 11/28/2021.
//

#ifndef PIZZA_RESTAURANT_HPP
#define PIZZA_RESTAURANT_HPP


#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include <deque>
#include "Driver.hpp"

using namespace std;

class Restaurant {
public:
    Restaurant();
    void status();
    void summary();
    Driver * getDriver(string name);
    void addDriver(string name);
    void addOrder(Order order);
    void serveNextOrder() throw (logic_error);
    Order departNextOrder() throw (logic_error);
    void deliver(Driver & driver, Time time, float tip);

private:
    list <Driver> drivers;
    deque <Order> tobeCooked;
    deque <Order> served;
    list <Order> delivered;

};


/*Pre: This a default constructor
* Post: Creates a restaurant in an initial state, with no drivers or orders.
*/
Restaurant::Restaurant() {
    list<Driver> drivers;
    list<Order> delivered;
    deque<Order> toCook;
    deque<Order> served;
}
/*
* Pre: None
* Post: Prints status of orders and logged-in drivers, as specified
*      by the “status” command description.
*/
void Restaurant::status(){
    cout << "Orders waiting to cook: " << endl;
    for( auto &cookItr : tobeCooked){
        cout << '\t' << cookItr.toString() << endl;
    }
    cout << "Orders waiting to depart: " << endl;
    for( auto &serveItr : served){
        cout << '\t' << serveItr.toString() << endl;
    }
    cout << "Drivers: " << endl;
    for( auto &driverItr : drivers){
        cout << '\t' << driverItr.toString() << endl;
    }
    cout<<endl;
}

/*
* Pre: None
* Post: Prints summary statistics on orders and drivers, as specified
*       by the “summary” command description.
*/
void Restaurant::summary(){
    cout << "Number of orders completed: ";
    int completed = 0;
    int totalTime = 0;
    for(auto &orderItr : delivered){
        completed++;
        totalTime += orderItr.getMinToDelivery();
    }
    cout << completed << endl;

    float average_time_per_order;

    if (completed==0) {
        average_time_per_order=0.00;
    }
    else{
        average_time_per_order=(float)totalTime/completed;
    }
    cout << "Average time per order: ";
    cout << average_time_per_order << endl;
    cout << endl;

    for(auto &driver : drivers){
        cout << "Driver " << driver.getName() << endl;
        cout << "\tNumber of deliveries completed: " << driver.getTotalDeliveries() << endl;

        int totalmindelivering = driver.getTotalMinDelivering();
        int totaldeliveries = driver.getTotalDeliveries();
        float average_time_per_delivery;
        if (totaldeliveries==0) {
            average_time_per_delivery=0;
        }
        else{
            average_time_per_delivery= totalmindelivering/ totaldeliveries;
        }
        cout << "\tAverage time per delivery: " <<average_time_per_delivery << endl;

        cout << "\tTotal driving time: " << driver.getTotalMinDriving() << endl;
        cout << "\tTotal tips: " << driver.getTotalTips() << endl;

        cout<<endl;
    }
}

/*
* Pre: Drive name is passed in as a string
* Post: If a driver with the given name exists within the system
*       (logged in or not), returns a pointer to that driver.
*       Otherwise, returns a null pointer.
*/
Driver * Restaurant::getDriver(string name){
    for(list<Driver>::iterator it = drivers.begin(); it != drivers.end(); ++it ){
        if(it->getName() == name){
            return &*it;
        }
    }
    return nullptr;
}

/*
* Pre: None
* Post: Adds the given driver to the system
*/
void Restaurant:: addDriver(string name){
    drivers.push_back(Driver(name));
}


/*
* Pre: None
* Post: Adds the given order to the system, enqueuing it for cooking.
*/
void Restaurant::addOrder(Order order){
    tobeCooked.push_back(order);
}

/*
* Pre: Cooking queue isnt empty
* Post: Removes the oldest order from the cooking queue and enqueues
*       it for departure.
*/
void Restaurant::serveNextOrder() throw (logic_error){
    if(tobeCooked.empty()){
        throw logic_error("There are no orders to serve.");
    }

    Order serve_order= tobeCooked.front();
    tobeCooked.pop_front();
    served.push_back(serve_order);
}

/*
* Pre: Departure queue isnt empty
* Post: Removes the oldest order from the departure queue and returns it.
*/
Order Restaurant::departNextOrder() throw (logic_error){
    if (served.empty()) {
        throw logic_error("There are no orders to depart.");
    }

    Order order_depart = served.front();
    served.pop_front();

    return order_depart;
}

/*
* Pre: None
* Post: The order carried by the driver is delivered at the given
*       time. The driver receives the given tip.
*/
void Restaurant::deliver(Driver & driver, Time time, float tip){
    delivered.push_back(driver.deliver(time, tip));
}


#endif
