#include <iostream>
#include "../inc/Graph.hpp"

using namespace std;

DestNode::DestNode (int id, int d, string name){
    this->dest_id = id;
    this->duration = d;
    this->dest_name = name;
    this->next = NULL;
}

Cities::Cities(){   
    this->city_id = 0;
    this->city_name = "";
    this->next = NULL;
    this->last = NULL;
}

// Overloaded Constructor
Cities::Cities (int id, string name){
    this->city_id = id;
    this->city_name = name;
    this->next = NULL;
    this->last = NULL;
}

Graph::Graph(int n, string city[]){
    this->size = n;
    this->node = new Cities[size];
    this->setData(city);
}

void Graph::setData(string city[]){
    if(size <= 0){
        cout << "ERROR: Empty graph!" << endl; 
    }
    else{
        for(int i = 0; i < size; i++){
            this->node[i].city_id = i;
            this->node[i].city_name = city[i];
        }
    }
}

//addEdge (source, city name, destination, destination name, flight duration)
void Graph::addEdge (int src, string srcName, int dest, string destName, int dur) {
    if (src >= 0 && src < this->size && dest >= 0 && dest < this->size) {
        DestNode *destination = new DestNode(dest, dur, destName);

        if (this->node[src].next == NULL) {
            this->node[src].next = destination;
        }
        else {
            this->node[src].last->next = destination;
        }

        this->node[src].last = destination;
    }
    else {
        cout << "ERROR: Edge could not be added." << endl;
    }
}

void Graph::displayGraph (string city[]) {
    if (this->size > 0) {
        for (int i = 0; i < this->size; ++i) {
            cout << "\nAdjency list of vertex " << i << " : " << city[i] << " -> ";

            DestNode *temp = this->node[i].next;

            while (temp != NULL) {
                cout << " " << this->node[temp->dest_id].city_id << " : " << this->node[temp->dest_id].city_name << " -> ";
                temp = temp->next;
            }

            cout << endl;
        }
    }
}

void Graph::displayCities (string city[]) {
    cout << "\nCities Serviced by Airline: " << endl;

    for (int i = 0; i < this->size; ++i) {
        cout << city[i] << endl;
    }
}

void Graph::reachAdjCity (int vertex, string city[]) {
    if (vertex > this->size || this->size <= 0) {
        cout << "ERROR: Vertex not found." << endl;
        return;
    }

    cout << "List of cities reached by " << vertex << " : " << city[vertex] << ": " << endl;

    DestNode *temp = this->node[vertex].next;

    if (temp == NULL) {
        cout << "No available flights from this city!" << endl;
    }

    while (temp != NULL) {
        cout << " " << this->node[temp->dest_id].city_id << " : " << this->node[temp->dest_id].city_name << " -> ";
        temp = temp->next;
    }
}

void Graph::dijkstra (string start, string city[], string dest) {
    string visited[5];
    int destIndex;
    int w[5];
    int index;
    
    for (int i=0; i<5; i++) {
        visited[i] = city[i];
        w[i] = 1000; //infinite

        if (start == city[i]) {
            index = i; 
        }
        if (city[i] == dest) {
            destIndex = i;
        }
    }
    
    w[index] = 0;
    
    while (visited[index] != "") {

            string min = "";
            int minIndex;
            visited[index] = "";

            DestNode* temp = node[index].next;
            int min_w = 1000, min_v=1000;
            while (temp != NULL) {
                int indexNext;
                string next;
                
                next = temp->dest_name;
                indexNext = temp->dest_id;
                
                if(visited[temp->dest_id] != "" && w[index] + temp->duration < w[temp->dest_id]){
                    w[indexNext] = w[index] + temp->duration;

                    if(min_w > w[indexNext]){
                        
                        min_w = w[indexNext];
                        min = temp->dest_name;
                        minIndex = indexNext;
                    }
                }
                
                temp = temp->next;
            }

            if (destIndex == index) {
                break;
            }

            if (min != "") {
                cout<<city[index]<<" ";
                index = minIndex;
            }

            else {
                index = 2;
            }
        }

        for(int i=0; i<5; i++){
            if(city[i] == dest){
                cout<<city[i] << "  ; Duration: " << w[i] << " hours" <<endl;
            }
        }
    }