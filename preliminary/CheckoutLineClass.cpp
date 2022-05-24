/*
 * File: CheckoutLineClass.cpp
 * ----------------------
 * This program duplicates the CheckoutLine program from Chapter 5,
 * but embeds the entire program in a class definition.
 */

#include <iostream>
#include <iomanip>
#include <queue>
#include "random.h"
using namespace std;

/* Constants */

const double ARRIVAL_PROBABILITY = 0.05;
const int MIN_SERVICE_TIME =  5;
const int MAX_SERVICE_TIME = 15;
const int SIMULATION_TIME = 2000;

/*
 * Class: CheckoutLineSimulation
 * -----------------------------
 * This class encapsulates the code and data for the simulation.
 */

class CheckoutLineSimulation {

public:

    void runSimulation() {
        queue<int> q;
        int timeRemaining = 0;
        nServed = 0;
        totalWait = 0;
        totalLength = 0;
        for (int t = 0; t < SIMULATION_TIME; t++) {
            if (randomChance(ARRIVAL_PROBABILITY)) {
                q.push(t);
            }
            if (timeRemaining > 0) {
                timeRemaining--;
            } else if (!q.empty()) {
                totalWait += t - q.front();
                q.pop(); //dequeue
                nServed++;
                timeRemaining = randomInteger(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
            }
            totalLength += q.size();
        }
    }

    void printReport() {
        cout << "Simulation results given the following constants:"
             << endl;
        cout << fixed << setprecision(2);
        cout << "  SIMULATION_TIME:     " << setw(4)
             << SIMULATION_TIME << endl;
        cout << "  ARRIVAL_PROBABILITY: " << setw(7)
             << ARRIVAL_PROBABILITY << endl;
        cout << "  MIN_SERVICE_TIME:    " << setw(4)
             << MIN_SERVICE_TIME << endl;
        cout << "  MAX_SERVICE_TIME:    " << setw(4)
             << MAX_SERVICE_TIME << endl;
        cout << endl;
        cout << "Customers served:      " << setw(4) << nServed << endl;
        cout << "Average waiting time:  " << setw(7)
             << double(totalWait) / nServed << " seconds" << endl;
        cout << "Average queue length:  " << setw(7)
             << double(totalLength) / SIMULATION_TIME << " people" << endl;
    }

private:
    int nServed;        // Number of customers served
    int totalWait;      // Sum of all customers waiting times
    int totalLength;    // Sum of all queue length at each time step

};

/* Main program */

int main() {
    CheckoutLineSimulation simulation;
    simulation.runSimulation();
    simulation.printReport();
    return 0;
}