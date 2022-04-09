#pragma once

class FlightNode {
    public:
        int flightNum;
        int arrival;
        int departure;
        FlightNode* next;

        FlightNode (int num, int a, int d);
};

class Flights {
    public:
        FlightNode* fHead;

        Flights ();

        void addFlight (int n, int a, int d);

        void displayFlights ();

        void displayFlightIDs();

        int flightRes();

        void swap(FlightNode* p1, FlightNode* p2);

        void selectionSort_arrival();

        void selectionSort_departure();
};
