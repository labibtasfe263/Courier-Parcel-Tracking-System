#include <stdio.h>

#define BASE_FEE      50.0f
#define RATE_PER_KG   40.0f
#define RATE_PER_KM    0.5f
#define VAT            0.05f

void  banner(void);
int   menu(void);
void  input_parcel(int *parcel_id, char sender[], char receiver[],
                   float *weight_kg, int *distance_km, int *booking_day);
float compute_charge(float weight_kg, int distance_km);
void  display_parcel(int parcel_id, const char sender[], const char receiver[],
                     float weight_kg, int distance_km, int booking_day,
                     float charge);

int main(void)
{
    int   parcel_id, distance_km, booking_day, choice;
    char  sender[50], receiver[50];
    float weight_kg, charge;

    banner();
    choice = menu();
    printf("\nOption %d selected: booking a parcel.\n", choice);

    input_parcel(&parcel_id, sender, receiver,
                 &weight_kg, &distance_km, &booking_day);
    charge = compute_charge(weight_kg, distance_km);
    display_parcel(parcel_id, sender, receiver,
                   weight_kg, distance_km, booking_day, charge);

    return 0;
}

void banner(void)
{
    printf("========================================\n");
    printf("      COURIER PARCEL TRACKING SYSTEM\n");
    printf("   Book it, weigh it, track it home\n");
    printf("========================================\n");
}

int menu(void)
{
    int choice;
    printf("\n1. Book a parcel\n");
    printf("2. Exit\n");
    printf("Choose: ");
    scanf("%d", &choice);
    return choice;
}

void input_parcel(int *parcel_id, char sender[], char receiver[],
                  float *weight_kg, int *distance_km, int *booking_day)
{
    printf("\nParcel ID          : ");
    scanf("%d", parcel_id);
    printf("Sender name        : ");
    scanf(" %49[^\n]", sender);
    printf("Receiver name      : ");
    scanf(" %49[^\n]", receiver);
    printf("Weight (kg)        : ");
    scanf("%f", weight_kg);
    printf("Distance (km)      : ");
    scanf("%d", distance_km);
    printf("Booking day        : ");
    scanf("%d", booking_day);
}

float compute_charge(float weight_kg, int distance_km)
{
    float subtotal = BASE_FEE + RATE_PER_KG * weight_kg
                   + RATE_PER_KM * distance_km;
    return subtotal * (1.0f + VAT);
}

void display_parcel(int parcel_id, const char sender[], const char receiver[],
                    float weight_kg, int distance_km, int booking_day,
                    float charge)
{
    printf("\n------------ PARCEL RECEIPT ------------\n");
    printf("Parcel ID     : %d\n", parcel_id);
    printf("From          : %s\n", sender);
    printf("To            : %s\n", receiver);
    printf("Weight        : %.2f kg\n", weight_kg);
    printf("Distance      : %d km\n", distance_km);
    printf("Booked on day : %d\n", booking_day);
    printf("Status        : Booked\n");
    printf("Total charge  : %.2f taka\n", charge);
    printf("----------------------------------------\n");
}
