#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_SHOWS 3
#define TOTAL_SEATS 20
#define TICKET_PRICE 12.50

typedef struct {
    int id;
    char movie_name[50];
    char time[10];
    int seats[TOTAL_SEATS]; 
} Show;

void initialize_shows(Show shows[]);
void display_shows(Show shows[]);
void view_seats(Show *show);
void book_ticket(Show shows[]);
void clear_input_buffer();

int main() {
    Show shows[TOTAL_SHOWS];
    initialize_shows(shows);
    int choice;

    printf("=== Welcome to the Ticket Booking System ===\n");

    while (1) {
        printf("\n--- MAIN MENU ---\n");
        printf("1. View Available Shows\n");
        printf("2. Book a Ticket\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter numbers only.\n");
            clear_input_buffer();
            continue;
        }

        switch (choice) {
            case 1:
                display_shows(shows);
                break;
            case 2:
                book_ticket(shows);
                break;
            case 3:
                printf("Thank you for using our booking system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid selection! Please choose an option between 1 and 3.\n");
        }
    }
    return 0;
}

void initialize_shows(Show shows[]) {
    shows[0].id = 1;
    strcpy(shows[0].movie_name, "Inception");
    strcpy(shows[0].time, "14:00");
    memset(shows[0].seats, 0, sizeof(shows[0].seats));

    shows[1].id = 2;
    strcpy(shows[1].movie_name, "Interstellar");
    strcpy(shows[1].time, "17:30");
    memset(shows[1].seats, 0, sizeof(shows[1].seats));

    shows[2].id = 3;
    strcpy(shows[2].movie_name, "The Dark Knight");
    strcpy(shows[2].time, "21:00");
    memset(shows[2].seats, 0, sizeof(shows[2].seats));
}

void display_shows(Show shows[]) {
    printf("\n%-5s %-20s %-10s %-15s\n", "ID", "Movie Title", "Time", "Available Seats");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < TOTAL_SHOWS; i++) {
        int available = 0;
        for (int j = 0; j < TOTAL_SEATS; j++) {
            if (shows[i].seats[j] == 0) available++;
        }
        printf("%-5d %-20s %-10s %-15d\n", shows[i].id, shows[i].movie_name, shows[i].time, available);
    }
}

void view_seats(Show *show) {
    printf("\n--- Seating Arrangement for %s (%s) ---\n", show->movie_name, show->time);
    printf("[Screen This Way]\n\n");
    for (int j = 0; j < TOTAL_SEATS; j++) {
        if (show->seats[j] == 0) {
            printf("[%02d] ", j + 1); 
        } else {
            printf("[XX] "); 
        }
        if ((j + 1) % 5 == 0) {
            printf("\n");
        }
    }
    printf("\n[XX] = Taken | [Num] = Available\n");
}

void book_ticket(Show shows[]) {
    int show_id, seat_num;
    display_shows(shows);

    printf("\nEnter the Show ID you want to book: ");
    if (scanf("%d", &show_id) != 1 || show_id < 1 || show_id > TOTAL_SHOWS) {
        printf("Invalid Show ID selection.\n");
        clear_input_buffer();
        return;
    }

    Show *selected_show = &shows[show_id - 1];
    view_seats(selected_show);

    printf("\nEnter the Seat Number you wish to book (1-%d): ", TOTAL_SEATS);
    if (scanf("%d", &seat_num) != 1 || seat_num < 1 || seat_num > TOTAL_SEATS) {
        printf("Invalid choice. Seat number does not exist.\n");
        clear_input_buffer();
        return;
    }

    int seat_index = seat_num - 1;

    if (selected_show->seats[seat_index] == 1) {
        printf("Error: Seat %d is already taken! Try another one.\n", seat_num);
    } else {
        selected_show->seats[seat_index] = 1; 
        printf("\nBooking Success!\n");
        printf("Ticket Cost: $%.2f\n", TICKET_PRICE);
        printf("Reserved Seat %d for '%s' at %s.\n", seat_num, selected_show->movie_name, selected_show->time);
    }
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
