//
// Created by Ephrathah Gebremichael on 11/28/2021.
//

#ifndef PIZZA_DRIVER_HPP
#define PIZZA_DRIVER_HPP

#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include <queue>
#include "Order.hpp"

using namespace std;
class Driver {
public:
    Driver(string name);
    void login() throw(logic_error);
    void logout() throw(logic_error);
    void depart(Time time, Order o) throw(logic_error);
    Order deliver(Time time, float tip) throw(logic_error);
    void arrive(Time time) throw(logic_error);
    string getName();
    bool isLoggedIn();
    int getTotalDeliveries();
    int getTotalMinDelivering();
    int getTotalMinDriving();
    float getTotalTips();
    Order * getOrder() throw(logic_error);
    string toString();

private:
    string driver_name;
    bool driver_atrestaurant;
    bool driver_departed;
    bool driver_delivered;
    bool driver_arrived;
    bool driver_loggedIn;
    Order current_order;
    float total_tips;
    int total_deliveries;
    int total_min_driving;
    int total_min_delivering;
    Time depart_time;
    Time deliver_time;
    Time arrive_time;
};

/*
 * Pre: None
 * Post: Constructor. Creates a logged-in driver with the given name.
 */
Driver::Driver(string name){
    driver_name=name;
    driver_departed=false;
    driver_delivered=false;
    driver_arrived=false;
    driver_loggedIn = false;
    total_tips=0;
    total_deliveries=0;
    total_min_driving=0;
    total_min_delivering=0;

}

/*
 * Pre: Driver is not logged in.
 * Post: Logs the driver in.
 */
void Driver:: login() throw(logic_error){
    if (driver_loggedIn==true) {
        throw logic_error("This driver has already logged in");
    }
    driver_loggedIn = true;
    driver_arrived= true;
    driver_atrestaurant = true;
}

/*
 * Pre: Driver is logged in and at the restaurant.
 * Post: Logs the driver out.
 */
void Driver:: logout() throw(logic_error){
    if (driver_loggedIn==false) {
        throw logic_error("This driver has already been logged out");
    }

    driver_loggedIn = false;
    driver_arrived= false;
}

/*
 * Pre: Driver is logged in and at the restaurant.
 * Post: Driver is delivering. Departure time is recorded.
 */
void Driver::depart(Time time, Order o) throw(logic_error){
    if (driver_loggedIn==false||driver_arrived==false) {
        throw logic_error("Driver is not logged in or not at the restaurant");
    }
    driver_atrestaurant = false;
    current_order = o;
    driver_arrived = false;
    depart_time = time;
    driver_departed = true;

    current_order.depart();

}

/*
 * Pre: Driver is delivering. Tip must be >= 0.
 * Post: Driver is not delivering. Driver’s stats are updated.
 */
Order Driver::deliver(Time time, float tip) throw(logic_error){

    if (driver_delivered==false && driver_arrived==false && tip>=0) {
        current_order.deliver(time);// change the status of the order to deliver

        driver_delivered=true;
        total_tips = total_tips+tip;
        deliver_time = time;

        total_min_delivering= Time::elapsedMin(depart_time, deliver_time);

        total_deliveries = total_deliveries+1;
        return current_order;
    }
    else
        throw logic_error("This driver is not delivering or the tip is less than 0");

}

/*
 * Pre: Driver is driving but not delivering.
 * Post: Driver is at the restaurant. Driver’s stats are updated
 */
void Driver::arrive(Time time) throw(logic_error){
    if (driver_arrived==false&&driver_delivered==true) {
        arrive_time=time;
        driver_atrestaurant = true;
        driver_arrived= true;
        driver_delivered=false;
        driver_departed = false;
        total_min_driving=  Time::elapsedMin(depart_time, arrive_time);
    }
    else throw logic_error("This driver is at the restaurant or is delivering");
}

/*
 * Pre: Driver's name must exist
 * Post: Returns the drivers name
 */
string Driver::getName(){
    return driver_name;
}

/*
 * Pre: None
 * Post: Returns true if and only if driver is logged in.
 */
bool Driver::isLoggedIn(){
    if (driver_loggedIn==true) {
        return true;
    }
    return false;
}

/*
 * Pre: None
 * Post: Returns the total number of completed deliveries.
 */
int Driver::getTotalDeliveries(){
    return total_deliveries;
}

/*
 * Pre: None
 * Post: Returns the total minutes spent delivering
 */
int Driver::getTotalMinDelivering(){
    return total_min_delivering;
}

/*
 * Pre: None
 * Post: Returns the total minutes spent driving
 */
int Driver::getTotalMinDriving(){
    return total_min_driving;
}

/*
 * Pre: None
 * Post: Returns the total tips received, in dollars
 */
float Driver:: getTotalTips(){
    return total_tips;
}

/*
 * Pre: Driver is delivering.
 * Post: Returns the order being delivered.
 */
Order * Driver::getOrder() throw(logic_error){
    if (driver_arrived!=false&&driver_delivered!=false){
        throw logic_error("The driver is not delivering yet");
    }

    Order *orderptr = &current_order;
    return orderptr;
}

/*
 * Pre: None
 * Post: Returns a string containing the driver’s name, state
 *       (e.g., not logged in), and, if the driver is delivering an
 *       order, the departure time and toString of the order being delivered.
 */
string Driver::toString(){
    string loginstatus;

    if(driver_loggedIn==true) { // driver is logged in
        loginstatus = " ";
        if(driver_atrestaurant)
            loginstatus=" is logged in ";
        if(driver_arrived==false) { // driver is out delivering order
            if(!driver_delivered)
                return driver_name+loginstatus+current_order.toString();
            else
                return driver_name + " is returning from a delivery";
        }
        else { // driver is at the restaurant
            return driver_name+loginstatus.append("and currently at the restaurant");
        }
    }
    if(driver_loggedIn == false) {
        loginstatus = " is not logged in"; // driver
    }
    return driver_name.append(loginstatus);
}


#endif
