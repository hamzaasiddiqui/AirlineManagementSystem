#include <iostream>
#include "../inc/Passenger.hpp"

using namespace std;

PassengerNode::PassengerNode (int i, string fName, string lName) {
    this->id = i;
    this->firstName = fName;
    this->lastName = lName;
    this->next = NULL;
}

Passengers::Passengers () {
    pHead = NULL;
}

void Passengers::addPassenger (int id, string fName, string lName) {
    PassengerNode* newNode = new PassengerNode(id, fName, lName);

    if (pHead == NULL) {
        pHead = newNode;
        return;
    }

    PassengerNode* temp = pHead;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void Passengers::removePassenger (int searchid) {
    PassengerNode* prev = pHead;
    PassengerNode* ptr;

    if (pHead->id == searchid) {
        ptr = pHead;
        pHead = prev->next;
        delete ptr;

        return;
    }

    for (ptr = prev->next; ptr != NULL; ptr = ptr->next) {
        if (ptr->id == searchid) {
            prev->next = ptr->next;
            delete ptr;
        }
        prev = prev->next;
    }
}

void Passengers::Sort_lname(){
    PassengerNode* temp = pHead;
    
    while (temp) {
        PassengerNode* min = temp;
        PassengerNode* ptr = temp->next;

        while (ptr) {
            if (min->lastName > ptr->lastName)
                min = ptr;

            ptr = ptr->next;
        }
        
        int ID = temp->id;			
        string firstname = temp->firstName;
        string lastname = temp->lastName;

        temp->id = min->id;
        temp->firstName = min->firstName;
        temp->lastName = min->lastName;

        min->id = ID;
        min->firstName = firstname;
        min->lastName = lastname;

        temp = temp->next;
    }
}

void Passengers::display() {
    PassengerNode* temp = pHead;
    while (temp != NULL) {
        cout << temp->id << " " << temp->firstName << " " << temp->lastName << endl;
        temp = temp->next;
    }
    cout << "NULL" << endl;
}