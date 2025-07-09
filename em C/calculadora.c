/* i've made this directory to gather my knowledge in a single place and keep studying different prog languages*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100

int menu();
void addition();

int main(){
    int R;
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
                break;
            case 3:
                printf("SELECTED OPTION: Multiplication.\n");
                break;
            case 4:
                printf("SELECTED OPTION: Division.\n");
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

        printf("Do you want to add another number? (y/n): ");
        
        scanf(" %c", &addMore);

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