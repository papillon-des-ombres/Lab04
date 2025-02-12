#include <stdio.h>
#include <math.h>

enum MainMenu {INVALID, TASK1,TASK2,TASK3,TASK4,BONUS,EXIT};

void taskOne();
void taskTwo();
void taskThree();
void taskFour();
void bonusTask();

int main() {
    int input;
    do {
        printf("------Main Menu------\n");
        printf("1. Task 1\n");
        printf("2. Task 2\n");
        printf("3. Task 3\n");
        printf("4. Task 4\n");
        printf("5. Bonus\n");
        printf("6. Exit\n");
        printf("\nEnter your input: ");
        scanf_s("%d",&input,1);
        switch(input) {
            case TASK1:
                taskOne();
            break;
            case TASK2:
                taskTwo();
            break;
            case TASK3:
                taskThree();
            break;
            case TASK4:
                taskFour();
            break;
            case BONUS:
                bonusTask();
            break;
            case EXIT:
                printf("Exiting the program...\n");
                return 0;
            break;
            default:
                printf("Invalid input.\n");
                input = INVALID;
            break;
        }
        printf("\nPress ENTER to exit...");
        getchar();
        getchar();
    } while (input != EXIT);

    return 0;
}

//calculation functions
double roundToInteger(double x) {
    return floor(x+.5);
}
double roundToTenths(double x) {
    return floor(x*10+0.5)/10;
}
double roundToHundredths(double x) {
    return floor(x*100+0.5)/100;
}

double roundToThousandths(double x) {
    return floor(x*1000+0.5)/1000;
}

bool isEven(int x) {
    return (x%2==0);
}

void anyCharSquare(int l, char c) {
    for (int i = 0; i < l * l; i++) {
        // Print the character
        printf("%c  ", c);

        // Move to the next line after every 'l' characters
        if ((i + 1) % l == 0) {
            printf("\n");
        }
    }
}

int timeSince12(int hh, int ph, int mm, int pm, int ss, int ps) {
    return ((ss-ps) + (60 * (mm-pm)) + (3600 * (hh-ph)) );
}

int daysSinceMarch1(int mm,int dd) {
    int daysInAMonth[] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30, 31, 0};
    int totalDays = 0;
    // Sum up days in completed months since March
    for(int i = 2; i < mm-1; i++) {
        totalDays += daysInAMonth[i];
    }
    // Add days in current month
    totalDays += dd-1;
    return totalDays;
}


//Task functions

void taskOne() {
    double x;
    printf("Task 1: Rounding chosen.\n");
    printf("________________________\n\n");
    printf("Please enter a floating-point number: ");
    scanf_s("%lf",&x);

    //print
    printf("\n| x\t\t| 1\t| 0.1\t| 0.01\t| 0.001  \t|\n");
    printf("| %0.8f\t| %1.f\t| %.1f\t| %.2f\t| %.3f  \t|",x,roundToInteger(x),roundToTenths(x),roundToHundredths(x),roundToThousandths(x));
}

void taskTwo() {
    int x;

    printf("Task 2: Getting Even chosen.\n");
    printf("________________________\n\n");
    printf("Please enter an integer: ");
    scanf_s("%d",&x);

    printf("\n| n\t| Even?\t|\n");
    printf("| %d\t| %s\t|\n",x,isEven(x) ? "Even" : "Odd");
}

void taskThree() {
    int len;
    char ch;

    printf("Task 3: Squaring Up chosen.\n");
    printf("________________________\n\n");
    printf("Please enter an integer for the side length of the square: ");
    scanf_s("%d",&len);
    getchar();
    printf("Please enter a character to print the square with: ");
    scanf("%c",&ch,1);
    getchar();
    printf("\n");
    anyCharSquare(len,ch);

}

void taskFour() {
    int hh,mm,ss;
    int ph,pm,ps;

    do {
        printf("Task 4: Overtime chosen.\n");
        printf("________________________\n\n");
        printf("Please enter the current time (hh:mm:ss): ");
        scanf_s("%d:%d:%d",&hh,&mm,&ss);
        if (!hh && !mm && !ss) {return;}
        printf("Please enter the previous time (hh:mm:ss): ");
        scanf_s("%d:%d:%d",&ph,&pm,&ps);
        if (!ph && !pm && !ps) {return;}

        printf("%d seconds have passed.", timeSince12(hh,ph,mm,pm,ss,ps));
    } while (1);

}

void bonusTask() {
    int mm,dd;
    printf("Bonus task chosen.\n");
    printf("________________________\n\n");
    do {
        printf("Please enter the current day (mm/dd): ");
        scanf_s("%d/%d",&mm,&dd);
        if (mm && dd) {
            printf("%d days left until Expo!",(daysSinceMarch1(5,9) - daysSinceMarch1(mm,dd)));
            return;
        } else {
            printf("Month and day cannot be zero.\n\n");
        }
    } while (!(mm && dd));
}