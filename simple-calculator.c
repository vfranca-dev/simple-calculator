/* */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUMBERS 100

int menu();                 //using functions to keep my code cleaner
void addition();            //and simpler to read
void subtraction();
void multiplication();
void division();


int main(){
    int option = -1;

    printf("\n\nHow can I help you today?\n");
    while (option != 0) {
        option = menu(); 

        switch (option) {
            case 1:
                printf("\nSELECTED OPTION: Addition.\n\n");
                addition();
                break;
            case 2:
                printf("SELECTED OPTION: Subtraction.\n");
                subtraction();
                break;
            case 3:
                printf("SELECTED OPTION: Multiplication.\n");
                multiplication();
                break;
            case 4:
                printf("SELECTED OPTION: Division.\n");
                division();
                break;
            case 0:
                printf("ByeBye!\n");
                break;
            default:
                printf("Invalid option. Please choose a valid option\n");
        }
    }

}


int menu() {
    int R=-1;
    printf("##########################################\n");
    printf("#              CALCULATOR                 #\n");
    printf("#                                         #\n");
    printf("#  1- Addition                            #\n");
    printf("#  2- Subtraction                         #\n");
    printf("#  3- Multiplication                      #\n");
    printf("#  4- Division                            #\n");
    printf("#  0- Quit                                #\n");
    printf("#                                         #\n");
    printf("###########################################\n");
    scanf("%d", &R);
    return R;
}

void addition() {
    int numbers[MAX_NUMBERS];   
    int count = 0; 
    int sum = 0;
    char addMore; 

    do {
        if (count >= MAX_NUMBERS) {
            printf("Maximum number of inputs (%d) reached.\n", MAX_NUMBERS);
            break;
        }

        printf("\nPlease type an integer number: ");
        scanf("%d", &numbers[count]); 
        count++; 

        printf("Do you want to add another number? (y/n): "); //could've been like in subtraction, but i'm exploring 
        scanf(" %c", &addMore);                               //and practising other stuff here        

    } while (addMore == 'y' || addMore == 'Y');

    if (count == 0) {
        printf("\nNo numbers were entered.\n");
        return;
    }

    printf("\nCalculating the sum...\n");

    
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
        printf("%d", numbers[i]);

        if (i < count - 1) {    
            printf(" + ");
            
        }
    }
    printf(" = %d\n", sum);
    printf("\n\n\n");
}
void subtraction() {
    int total, numberToSubtract;
    
    printf("\nPlease enter the starting number: ");
    scanf("%d", &total);

    while (true) {
        printf("\nCurrent total: %d. Enter number to subtract (or 0 to finish): ", total);
        scanf("%d", &numberToSubtract);

        if (numberToSubtract == 0) {
            break; // exits if user typed 0
        }

        total -= numberToSubtract; 
        printf("New total is: %d\n", total);
    }
    printf("\nFinal result: %d\n", total);
}

void multiplication(){
    int InputA, InputB;
    bool Answer = true; //not needed at all, but using
    int userAnswer=1;
    do{
        printf("\nPlease enter two integer numbers to multiply A * B:\n"); //keeping it minimal
        scanf("%d",&InputA);
        printf("%d * ",InputA);
        scanf("%d",&InputB);
        printf("= %d",InputA * InputB);
        printf("\n\n");
        printf("Would you like to do another calculation?\n(Answer 1 for yes, and 0 for no):");
        scanf("%d",&userAnswer);
        Answer = (userAnswer != 0);
         
    }while(Answer);
}

void division() {
    float InputA, InputB; // using float to allow float results
    bool keepGoing = true;
    int userAnswer;

    do {
        printf("\nPlease enter two numbers to divide A / B:\n");
        printf("Enter A: ");
        scanf("%f", &InputA);
        printf("Enter B: ");
        scanf("%f", &InputB);

        if (InputB == 0) {
            printf("\nError: Division by zero is not allowed!\n");
        } else {
            printf("%.2f / %.2f = %.2f\n", InputA, InputB, InputA / InputB);
        }
        
        printf("\nWould you like to do another calculation? (1 for yes, 0 for no): ");
        scanf("%d", &userAnswer);
        keepGoing = (userAnswer != 0);

    } while (keepGoing);
}