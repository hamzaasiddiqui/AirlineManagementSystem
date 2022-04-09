#include "../inc/Reservations.hpp"

ReservationNode::ReservationNode (int pi, int fi) {
    this->passengerID = pi;
    this->flightID = fi;
    this->next = NULL;
}

Reservations::Reservations () {
    rHead = NULL;
}

void Reservations::makeReservation () {
    int passID, flightID;
    string fname, lname;
    
    cout << "Enter Passenger ID: ";
    cin >> passID;
    cout << "Enter Passenger First Name: ";
    cin >> fname;
    cout << "Enter Passenger Last Name: ";
    cin >> lname;

    cout << "Book Following Flight:" << endl;
    flightID = flightRes();

    ReservationNode* newNode = new ReservationNode(passID, flightID);
    addPassenger (passID, fname, lname);

    if (rHead == NULL) {
        rHead = newNode;
        return;
    }

    ReservationNode* temp = rHead;

    if (rHead == NULL) {
        rHead = newNode;
        return;
    }

    //ReservationNode* temp = rHead;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void Reservations::findReservation (int searchPassID) {
    ReservationNode* temp;
    bool passIDFound = false;
    int idFlight;

    for (temp = rHead; temp != NULL; temp = temp->next) {
        if (searchPassID == temp->passengerID) {
            passIDFound = true;
            idFlight = temp->flightID;
            break;
        }
    }
    if (passIDFound == false) {
        cout << "No such passenger found." << endl;
        return;
    }

    PassengerNode* ptr1;

    for (ptr1 = pHead; ptr1 != NULL; ptr1 = ptr1->next) {
        if (searchPassID == ptr1->id) {
            cout << "Passenger ID:\t" << ptr1->id << endl;
            cout << "Passenger First Name:\t" << ptr1->firstName << endl;
            cout << "Passenger Last Name:\t" << ptr1->lastName << endl;
            cout << "--" << endl;
        }
    }
    cout << "Flight No: " << idFlight << endl;
}

void Reservations::deleteReservation (int pID, int fID) {
    ReservationNode* prev = rHead;
    ReservationNode* ptr;

    if (rHead->passengerID == pID && rHead->flightID == fID) {
        ptr = rHead;
        rHead = prev->next;
        delete ptr;

        return;
    }

    for (ptr = prev->next; ptr != NULL; ptr = ptr->next) {
        if (ptr->passengerID == pID && ptr->flightID == fID) {
            prev->next = ptr->next;
            delete ptr;
        }
        prev = prev->next;
    }
}

void Reservations::passengerOnFlight (int searchFlightID) {
    ReservationNode* temp = rHead;
    
    cout << "Passengers in flight:" << endl;
    for (temp = rHead; temp != NULL; temp = temp->next) {
        if (searchFlightID == temp->flightID) {
            cout << temp->passengerID << endl;
        }
    }
}