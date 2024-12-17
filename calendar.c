
#include <stdio.h>

void printMonth(int month, int year);
int getFirstDayOfMonth(int month, int year);
const char* getMonthName(int month);
const char* getDayName(int day);

int main() {
    int year;

    printf("Enter year: ");
    scanf("%d", &year);

    printf("\nCalendar for the year %d\n", year);
    for (int month = 1; month <= 12; month++) {
        printMonth(month, year);
    }

    return 0;
}

void printMonth(int month, int year) {
    int daysInMonth;
    const char* monthName = getMonthName(month);
    int firstDay = getFirstDayOfMonth(month, year);
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            daysInMonth = 29;
        } else {
            daysInMonth = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }
    printf("\n\n  %s %d\n", monthName, year);
    printf("Su Mo Tu We Th Fr Sa\n");
    for (int i = 0; i < firstDay; i++) {
        printf("   ");
    }
    for (int day = 1; day <= daysInMonth; day++) {
        printf("%2d ", day);
        if ((day + firstDay) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int getFirstDayOfMonth(int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;
    int day = (1 + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) - 2 * j) % 7;
    return (day + 6) % 7;
}

const char* getMonthName(int month) {
    const char* monthNames[] = {
        "Invalid", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    return monthNames[month];
}