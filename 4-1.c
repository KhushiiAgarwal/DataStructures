#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TICKET_TIME 5 // time it takes to process a ticket
#define ARRIVAL_INTERVAL 3 // average time between customer arrivals
#define SIMULATION_TIME 60 // duration of the simulation in minutes

int main() {
    srand(time(NULL)); // initialize random seed

    int regular_wait_time = 0; // total wait time for regular customers
    int regular_customers_served = 0; // number of regular customers served
    int frequent_wait_time = 0; // total wait time for frequent flyers
    int frequent_customers_served = 0; // number of frequent flyers served

    int regular_queue = 0; // number of regular customers waiting in line
    int frequent_queue = 0; // number of frequent flyers waiting in line

    int clock = 0; // current time in minutes
    while (clock < SIMULATION_TIME) {
        // determine if a regular customer arrives
        if (rand() % ARRIVAL_INTERVAL == 0) {
            regular_queue++; // add customer to regular queue
        }

        // determine if a frequent flyer arrives
        if (rand() % (ARRIVAL_INTERVAL * 3) == 0) {
            frequent_queue++; // add customer to frequent queue
        }

        // serve a customer if the ticket agent is free
        if (regular_queue > 0 || frequent_queue > 0) {
            int is_frequent = 0; // flag to indicate whether customer is a frequent flyer
            if (frequent_queue > 0 && (regular_queue == 0 || rand() % 2 == 0)) {
                is_frequent = 1; // serve a frequent flyer if one is available and random number is even
            }

            if (is_frequent) {
                frequent_wait_time += frequent_queue * TICKET_TIME; // add wait time for all frequent flyers in line
                frequent_customers_served++; // increment number of frequent flyers served
                frequent_queue--; // remove customer from frequent queue
            } else {
                regular_wait_time += regular_queue * TICKET_TIME; // add wait time for all regular customers in line
                regular_customers_served++; // increment number of regular customers served
                regular_queue--; // remove customer from regular queue
            }
        }

        clock++; // increment time
    }

    // calculate average wait times
    float avg_regular_wait_time = (float) regular_wait_time / regular_customers_served;
    float avg_frequent_wait_time = (float) frequent_wait_time / frequent_customers_served;

    // print results
    printf("Regular customers served: %d\n", regular_customers_served);
    printf("Average wait time for regular customers: %.2f minutes\n", avg_regular_wait_time);
    printf("Frequent flyers served: %d\n", frequent_customers_served);
    printf("Average wait time for frequent flyers: %.2f minutes\n", avg_frequent_wait_time);

    return 0;
}
