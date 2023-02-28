#include <iostream>
#include "Time.hpp"
#include "Driver.hpp"
#include "Restaurant.hpp"


using namespace std;

void system();

int main() {
    Restaurant Dominatos;
    float tip;
    string command;
    string driver_name;
    string order_info;
    system();

    cout << "Command: ";
    while (cin>>command && command!="quit") {

        //Error message if command is blank
        if(command == "")
            cout << "Please enter a valid command, or type 'help' for help" << endl;

        //Login
        if ( command == "login"  ){
            cin >> driver_name;
            Dominatos.addDriver(driver_name);
            Dominatos.getDriver(driver_name)->login();
        }

            //Logout
        else if (command == "logout"){
            cin >> driver_name;
            Driver * temp = Dominatos.getDriver(driver_name);
            try{
                if(temp != nullptr){
                    temp->logout();
                }else{
                    cout << "Driver not found" << endl;;
                }
            }catch(logic_error& error){
                cout << error.what() << endl;
            }
        }

            //Serving next order
        else if (command == "serve"){
            int hour;
            int min;
            cin>> hour;
            cin.ignore(1); //Used to ignore the separator
            cin >> min;
            try{
                Dominatos.serveNextOrder();
            }catch(logic_error& error){
                cout << error.what() << endl;
            }

        }

            //Add order
        else if (command == "order"){
            int hour;
            int min;
            cin>> hour;
            cin.ignore(1);
            cin >> min;
            cin.ignore(1);
            getline(cin, order_info);
            Order newOrder = Order(Time(hour, min), order_info);
            Dominatos.addOrder(newOrder);
        }

            //Driver departs restaurant
        else if (command == "depart"){
            int hour;
            int min;
            cin>> hour;
            cin.ignore(1);
            cin >> min;
            cin >> driver_name;
            Order to_depart = Dominatos.departNextOrder();
            Dominatos.getDriver(driver_name)->depart(Time(hour, min), to_depart);
        }

            //Driver arrives
        else if (command == "arrive"){
            int hour;
            int min;
            cin>> hour;
            cin.ignore(1);
            cin >> min;
            cin >> driver_name;
            try{
                Dominatos.getDriver(driver_name)->arrive(Time(hour, min));
            }catch(logic_error& error){
                cout << error.what() << endl;
            }
        }

            //Deliver an order
        else if ( command == "deliver" ){
            int hour;
            int min;
            cin>> hour;
            cin.ignore(1);
            cin >> min;
            cin >> driver_name;
            cin >> tip;
            try{
                Dominatos.getDriver(driver_name)->deliver(Time(hour, min), tip);
            }catch(logic_error& error){
                cout << error.what() << endl;
            }
        }

            //Get status
        else if ( command == "status" ){
            Dominatos.status();
        }

            //Get summary
        else if ( command == "summary" ){
            Dominatos.summary();
        }

            //Get help
        else if ( command == "help"  ){
            system();
        }
            // if command doesn't exist
        else{
            cout << "Command not found" << endl;
            system();
        }
        cout << "Command: ";

    }
    return 0;
}

void system(){
    cout << endl << "Commands:" << endl;
    cout << "  help                    : Help " << endl;
    cout << "  login DRIVER            : Logs in the driver" << endl;
    cout << "  logout DRIVER           : Logs out the driver" << endl;
    cout << "  order TIME INFO         : Creates an order with the time ordered and they type of order" << endl;
    cout << "  serve TIME              : Order is ready for delivery" << endl;
    cout << "  depart TIME DRIVER      : Driver is leaving the restaurant for delivery" << endl;
    cout << "  deliver TIME DRIVER TIP : Driver has completed delivery and received a tip"<< endl;
    cout << "  arrive TIME DRIVER      : Driver has returned" << endl;
    cout << "  status                  : View the status of orders and drivers" << endl;
    cout << "  summary                 : View the summary on drivers and orders" << endl;
    cout << "  quit                    : Ends the program" << endl;
    cout << endl;
}