/********* a1_functions.c *********/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "a1_data_structures.h"
#include "a1_functions.h"

void number_of_employees(milestone_t *project_details) {
    float project_budget = project_details[0].cost;
    float duration = project_details[0].time;
    float num_employees = ceil(project_budget / (duration * 40 * 25));
    project_details[0].num_employees = (unsigned short int)num_employees;
}


unsigned short int get_input_usi(void) {
    unsigned short int value;
    int input;

    printf("\nYour choice is: ");

    scanf("%d", &input);

    while (input < 0 || (input > 5)) {
        printf("-------------------------------------------------\n");
        printf("The value you entered is wrong. \n");
        printf("Enter a value between 0 and 5: ");
        scanf("%d", &input);
        
    }

    value = input;
    return value;
}

float get_input_f(void) {
    float value;
    scanf("%f", &value);
    return value;

}

milestone_t init_milestone(char stage_name[], float assigned_budget) {
    milestone_t milestone;
    strcpy(milestone.name, stage_name);
    milestone.cost = assigned_budget;
    milestone.time = 0.0;
    milestone.num_employees = 0;
    milestone.completed = 0;
    return milestone;
}

void print_menu(void) {
    printf("\nWhich milestone do you want to update? (0 to exit):\n");
    printf("1. Technical Requirements\n");
    printf("2. System Design\n");
    printf("3. Software Development\n");
    printf("4. Testing\n");
    printf("5. Product Release\n");
}

void print_stats(milestone_t details) {
    printf("\n------------ Milestone Stats --------------\n");
    printf("Below is \"%s\" current stats:\n", details.name);
    printf("--------------------------------------------\n");
    printf("Actual time: %.2f weeks\n", details.time);
    printf("Actual number of employees: %d\n", details.num_employees);
    printf("Actual cost: %.2f$\n", details.cost);
    printf("Completed: %s\n", (details.completed) ? "Yes" : "No");
}

void update_stats(milestone_t milestone_array[], int milestone_num) {
    milestone_t *milestone = &milestone_array[milestone_num];
    
    if (milestone->completed) {
        printf("\n---------------------------------------------\n");
        printf("%s milestone is completed, \ncannot be updated\n", milestone->name);
        printf("---------------------------------------------\n");
    } else {
        printf("\n------------ Update Stats --------------\n\n");

        printf("Enter the milestone's actual time: ");
        milestone->time = get_input_f();
        printf("Enter the milestone's actual number of employees: ");
        milestone->num_employees = get_input_f();
        printf("Is this milestone complete? (Y/N): ");
        char complete_choice;
        do {
            complete_choice = getchar();
        } while (complete_choice != 'Y' && complete_choice != 'N');
        milestone->completed = (complete_choice == 'Y');
        milestone->cost = milestone->num_employees * milestone->time * 40 * 25;
        printf("Stats Updated!\n");

        print_stats(*milestone);
    }
}

void check_project_completion(milestone_t milestone_array[], int num_milestones) {
    int all_completed = 1;
    for (int i = 0; i <= num_milestones; i++) {
        if (!milestone_array[i].completed) {
            all_completed = 0;
            break;
        }
    }
    if (all_completed) {
        milestone_array[0].completed = 1;
    }
}

