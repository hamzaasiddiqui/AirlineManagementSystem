#include <iostream>
#include "../inc/Flight.hpp"

using namespace std;

FlightNode::FlightNode (int num, int a, int d) {
    this->flightNum = num;
    this->arrival = a;
    this->departure = d;
    this->next = NULL;
}


Flights::Flights () {
    fHead = NULL;
}

void Flights::addFlight (int n, int a, int d) {
    FlightNode* newNode = new FlightNode(n, a, d);

    if (fHead == NULL) {
        fHead = newNode;
        return;
    }

    FlightNode* temp = fHead;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void Flights::displayFlights () {
    cout << "Flight Number \t" << "Arrival \t" << "Departure \t" << endl;
    for(FlightNode *ptr = fHead; ptr != NULL; ptr = ptr->next){
        cout << "\t" << ptr->flightNum << "\t  " << ptr->arrival << "\t\t  " << ptr->departure << endl; 
    }
}

void Flights::displayFlightIDs(){
    cout << "1. KHI -> LHR" << endl;
    cout << "2. KHI -> ISL" << endl;
    cout << "3. LHR -> KHI" << endl;
    cout << "4. LHR -> ISL" << endl;
    cout << "5. ISL -> KHI" << endl;
    cout << "6. ISL -> RWP" << endl;
    cout << "7. RWP -> PEW" << endl;
    cout << "8. PEW -> ISL" << endl;
}

int Flights::flightRes(){
    int option = 0;
    cout << "\t Flight Reservation" << endl;
    cout << "---------------------------------" << endl;
    displayFlightIDs();
    cout << "-----------------------" << endl;
    cout << "Choose your flights: ";
    cin >> option;
    cout << endl;

    return option; 
}

void Flights::swap(FlightNode* p1, FlightNode* p2){
    int temp_fNum = p1->flightNum;
    int temp_arrival = p1->arrival;
    int temp_departure = p1->departure;


    p1->flightNum = p2->flightNum;
    p1->arrival = p2->arrival;
    p1->departure = p2->departure;
    

    p2->flightNum = temp_fNum;
    p2->arrival = temp_arrival;
    p2->departure = temp_departure;
}

void Flights::selectionSort_arrival(){
    FlightNode *ptr = fHead;
    FlightNode *min;
    FlightNode *ptr2;

    while(ptr != nullptr){
        min = ptr;
        ptr2 = ptr->next;

        while (ptr2 != nullptr){
            if (ptr2->arrival < min->arrival){
                min = ptr2;
            }
            ptr2 = ptr2->next;
        }
        swap (min, ptr);
        ptr = ptr->next;
    }
}

void Flights::selectionSort_departure(){
    FlightNode* ptr = fHead;
    FlightNode* min;
    FlightNode* ptr2;

    while(ptr != nullptr){
        min = ptr;
        ptr2 = ptr->next;

        while (ptr2 != nullptr){
            if (ptr2->departure < min->departure){
                min = ptr2;
            }
            ptr2 = ptr2->next;
        }
        swap (min, ptr);
        ptr = ptr->next;
    }
}