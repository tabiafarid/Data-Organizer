/********* main.c *********/

#include <stdio.h>
#include "a1_data_structures.h"
#include "a1_functions.h"
#include <stdlib.h> 

int main() {

    milestone_t project_details[6];
    printf("Welcome to ABC Project Tracker\n");
    float project_budget;
    do {
        printf("Enter the total project's budget: ");
        project_budget = get_input_f();
        if (project_budget < 0) {
            printf("The value you entered is wrong\nEnter a positive value\n");
        }
    } while (project_budget < 0);

    float project_duration;
    do {
        printf("Enter the total project's duration in weeks: ");
        project_duration = get_input_f();
        if (project_duration < 0) {
            printf("The value you entered is wrong\nEnter a positive value\n");
        }
    } while (project_duration < 0);


    project_details[0].cost = project_budget;
    project_details[0].time = project_duration;
    number_of_employees(project_details); 
    printf("The planned number of employees needed is: %d\n", project_details[0].num_employees);
    printf("\n----------------------------------------------------------\n");

    char milestone_names[6][100] = {
        "Planned details", "Technical Requirements", "System Design", "Software Development", "Testing", "Product Release"
    };
    for (int i = 0; i <= 5; i++) {
        project_details[i] = init_milestone(milestone_names[i], project_budget / 5.0);
    }

    int choice;
    char finish_choice = 'A';

    while (finish_choice != 'N') {
        print_menu();
        choice = get_input_usi();

        if (choice < 0 || choice > 5) {
            printf("Error: Please enter a valid choice between 0 and 5.\n");
            continue;
        } else if (choice == 0) {
            check_project_completion(project_details, 5);
            float total_project_cost = 0;
            for (int i = 1; i <= 5; i++) {
                total_project_cost += project_details[i].cost;
            }

            int allMilestonesCompleted = 1;  // Assume all are completed initially
            for (int i = 1; i <= 5; i++) {
                if (!project_details[i].completed) {
                    allMilestonesCompleted = 0;  
                    break; 
                }
            }

            if (allMilestonesCompleted)  {
              
                printf("--------------------------------------------\n");
                printf("------ Final Project's Performance -------\n");
                printf("--------------------------------------------\n\n");

                if (total_project_cost <= project_details[0].cost) {
                    printf("The project's cost is below budget!\n");
                } else {
                    printf("The project's cost is above budget!\n");
                }
                printf("Planned budget: %.2f\n", project_details[0].cost);
                printf("Actual Cost: %.2f\n", total_project_cost);
                printf("\n--------------------------------------------\n");
                printf("--- The program will quit now! Goodbye! ---\n");
                printf("--------------------------------------------\n\n");
                exit(0);
            } else {

                printf("\n--------------------------------------------\n");
                printf("---------- Project's Performance -----------\n");
                printf("--------------------------------------------\n");
                print_stats(project_details[0]);
                printf("Do you want to finish the remaining milestones? (Y/N): ");
                do {
                    finish_choice = getchar();
                } while (finish_choice != 'Y' && finish_choice != 'N');

                if (finish_choice == 'Y') {
                    continue;
                } else if (finish_choice == 'N') {
                    float total_project_cost = 0;
                    for (int i = 1; i <= 5; i++) {
                        total_project_cost += project_details[i].cost;
                    }
                    printf("\n");
                    printf("--------------------------------------------\n");
                    printf("------ Final Project's Performance -------\n");
                    printf("--------------------------------------------\n");

                    if (total_project_cost <= project_details[0].cost) {
                        printf("The project's cost is below budget!\n");
                    } else {
                        printf("The project's cost is above budget!\n");
                    }
                    printf("Planned budget: %.2f\n", project_details[0].cost);
                    printf("Actual Cost: %.2f\n", total_project_cost);
                    printf("--------------------------------------------\n");
                    printf("--- The program will quit now! Goodbye! ---\n");
                    printf("--------------------------------------------\n");
                    exit(0);
                }
            }
        } else {
            print_stats(project_details[choice]);
            update_stats(project_details, choice);
        }
    }

    return 0;
}

