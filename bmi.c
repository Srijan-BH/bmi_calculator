#include <stdio.h>
#include <windows.h>

// ---------- COLOR FUNCTION ----------
void setColor(int ForgC){
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

// ---------- CLEAR SCREEN ----------
void clearScreen() {
    system("cls");
}

// ---------- PAUSE ----------
void pauseScreen() {
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}

// ---------- WELCOME SCREEN ----------
void welcomeScreen() {
    setColor(14);
    printf("================================================\n");
    printf("||                                            ||\n");
    printf("||        WELCOME TO BMI CALCULATOR           ||\n");
    printf("||                                            ||\n");
    printf("================================================\n\n");
    setColor(15);
}

// ---------- BMI CALCULATION ----------
void bmiCalculator() {
    float weight, heightCm, heightM, bmi;

    clearScreen();
    setColor(11);
    printf("------------- BMI CALCULATION -------------\n\n");
    setColor(15);

    printf("Enter your weight (kg): ");
    scanf("%f", &weight);

    printf("Enter your height (cm): ");
    scanf("%f", &heightCm);

    if(weight <= 0 || heightCm <= 0) {
        setColor(12);
        printf("\nInvalid input! Weight and height must be positive.\n");
        setColor(15);
        pauseScreen();
        return;
    }

    heightM = heightCm / 100; // cm → meters
    bmi = weight / (heightM * heightM);

    setColor(10);
    printf("\nYour BMI is: %.2f\n", bmi);
    setColor(15);

    if(bmi < 18.5)
        printf("Category: Underweight\n");
    else if(bmi < 25)
        printf("Category: Normal weight\n");
    else if(bmi < 30)
        printf("Category: Overweight\n");
    else
        printf("Category: Obese\n");

    pauseScreen();
}

// ---------- BMI INFO ----------
void showBMICategories() {
    clearScreen();
    setColor(13);
    printf("------------- BMI CATEGORIES -------------\n\n");
    setColor(15);

    printf("Below 18.5      : Underweight\n");
    printf("18.5 – 24.9     : Normal weight\n");
    printf("25.0 – 29.9     : Overweight\n");
    printf("30.0 and above  : Obese\n");

    pauseScreen();
}

// ---------- ABOUT ----------
void aboutProject() {
    clearScreen();
    setColor(14);
    printf("------------- ABOUT PROJECT -------------\n\n");
    setColor(15);

    printf("Project Name : BMI Calculator\n");
    printf("Language     : C\n");
    printf("Concepts     : Functions, Loops, Conditions\n");
    printf("Interface    : Console-based (Webpage style)\n\n");

    printf("BMI Formula:\n");
    printf("BMI = Weight(kg) / (Height(m) * Height(m))\n");

    pauseScreen();
}

// ---------- MAIN ----------
int main() {
    int choice;

    do {
        clearScreen();
        welcomeScreen();

        setColor(11);
        printf("MAIN MENU\n");
        printf("1. Calculate BMI\n");
        printf("2. View BMI Categories\n");
        printf("3. About Project\n");
        printf("4. Exit\n");
        setColor(15);

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                bmiCalculator();
                break;
            case 2:
                showBMICategories();
                break;
            case 3:
                aboutProject();
                break;
            case 4:
                clearScreen();
                setColor(10);
                printf("Thank you for using BMI Calculator!\n");
                setColor(15);
                break;
            default:
                setColor(12);
                printf("\nInvalid choice!\n");
                setColor(15);
                pauseScreen();
        }

    } while(choice != 4);

    return 0;
}
