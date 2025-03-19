#include <stdio.h>
#include <string.h>

void orderCoffee(char *creamChoice, char *sugarChoice, char *coffeeOptions[], char chosenSize[10], int *coffeType, int chosenFlavour[]);
void displayOrder(char creamChoice, char sugarChoice, char *coffeeOptions[], char chosenSize[10], int *coffeType);

int main()
{
    char creamChoice, sugarChoice;
    char chosenSize[10];
    int coffeType;
    char *coffeeOptions[] = {"House", "Iced", "Vanilla", "Hazelnut", "Mocha"};
    int chosenFlavour[5] = {0};  // Array to track chosen flavors (initialized to 0)

    // Continue taking orders until the user has chosen each flavor once
    while (1)
    {
        orderCoffee(&creamChoice, &sugarChoice, coffeeOptions, chosenSize, &coffeType, chosenFlavour);
        displayOrder(creamChoice, sugarChoice, coffeeOptions, chosenSize, &coffeType);

        // Mark the chosen flavor as selected
          chosenFlavour[coffeType - 1] = 1;

        // Check if the user has chosen each flavor once
        int allFlavorsChosen = 1;
        for (int x = 0; x < 5; ++x)
        {
            if (chosenFlavour[x] == 0)
            {
                allFlavorsChosen = 0;
                break;
            }
        }

        if (allFlavorsChosen)
        {
            printf("You have chosen each flavor once. Exiting the program.\n");
            break;
        }
    }

    return 0;
}

void orderCoffee(char *creamChoice, char *sugarChoice, char *coffeeOptions[], char chosenSize[10], int *coffeType, int chosenFlavors[])
{
    float coffePrice = 0;
    float smallCoffePrice = 3.00;
    float mediumCoffePrice = 4.50;
    float largeCoffePrice = 6.00;
    char *coffeSize[3] = {"Small", "Medium", "Large"};

    char *stringcoffee[] = {"House", "Iced", "Vanilla", "Hazelnut", "Mocha"};

    printf("Hello! Welcome to our café!\n  These are the menu options!");
    for (int i = 0; i < 5; ++i)
    {
        printf("\n%d. %s\n", i + 1, stringcoffee[i]);
    }

    printf("\nWhat kind of coffee would you like to order today?");
    scanf("%d", coffeType);

    while (*coffeType < 1 || *coffeType > 5 || chosenFlavors[*coffeType - 1] == 1)
    {
        if (*coffeType < 1 || *coffeType > 5)
        {
            printf("Invalid entry of a flavour. Please choose number 1-5!\n");
        }
        else
        {
            printf("You have already chosen %s. Please choose a different flavor.\n", coffeeOptions[*coffeType - 1]);
        }

        printf("\nWhat kind of coffee would you like to order today?");
        scanf("%d", coffeType);
    }

    printf("\nWould you like cream (Y/N)? ");
    scanf("\n%c", &*creamChoice);
    while (*creamChoice != 'Y' && *creamChoice != 'y' && *creamChoice != 'n' && *creamChoice != 'N')
    {
        printf("Invalid choice for cream. Please choose if you would like cream added to your coffee with a (Y or N)");
        printf("\nWould you like cream (Y/N)? ");
        scanf("\n%c", &*creamChoice);
    }
    printf("\nWould you like sugar (Y/N)? ");
    scanf("\n%c", &*sugarChoice);
    getchar();
    while (*sugarChoice != 'Y' && *sugarChoice != 'y' && *sugarChoice != 'n' && *sugarChoice != 'N')
    {
        printf("Invalid choice for sugar. Please choose if you would like sugar added to your coffee with a (Y or N)");
        printf("\nWould you like sugar (Y/N)? ");
        scanf("\n%c", &*sugarChoice);
    }

    printf("\nWhat size would you like your coffee?");
    fgets(chosenSize, 10, stdin);
    for (int x = 0; chosenSize[x] != '\0'; x++)
    {
        if (chosenSize[x] == '\n')
        {
            chosenSize[x] = '\0';
            break;
        }
    }

    if (strcmp(chosenSize, "small") != 0 && strcmp(chosenSize, "Small") != 0 && strcmp(chosenSize, "medium") != 0 && strcmp(chosenSize, "Medium") != 0 && strcmp(chosenSize, "large") != 0 && strcmp(chosenSize, "Large") != 0)
    {
        printf("You have entered an invalid size. Please re-enter the size you like. Choose either Small, Medium, or Large");
        printf("\nWhat size would you like your coffee?");
        fgets(chosenSize, 10, stdin);
        for (int x = 0; chosenSize[x] != '\0'; x++)
        {
            if (chosenSize[x] == '\n')
            {
                chosenSize[x] = '\0';
                break;
            }
        }
    }
}

void displayOrder(char creamChoice, char sugarChoice, char *coffeeOptions[], char chosenSize[10], int *coffeType)
{
    float coffePrice = 0;
    float smallCoffePrice = 3.00;
    float mediumCoffePrice = 4.50;
    float largeCoffePrice = 6.00;

    char *stringcoffee[] = {"House", "Iced", "Vanilla", "Hazelnut", "Mocha"};

    printf("Your coffee order: \n %s", chosenSize);

    switch (chosenSize[0])
    {
    case 'S':
    case 's':
        if ((creamChoice == 'y' || creamChoice == 'Y') && (sugarChoice == 'y' || sugarChoice == 'Y'))
        {
            printf(" %s coffee with cream and sugar\n", stringcoffee[*coffeType - 1]);
        }
        if ((creamChoice == 'n' || creamChoice == 'N') && (sugarChoice == 'n' || sugarChoice == 'N'))
        {
            printf(" %s  coffee \n", stringcoffee[*coffeType - 1]);
        }
        if ((creamChoice == 'n' || creamChoice == 'N') && (sugarChoice == 'y' || sugarChoice == 'Y'))
        {
            printf(" %s coffee with sugar\n", stringcoffee[*coffeType - 1]);
        }
        if ((creamChoice == 'y' || creamChoice == 'Y') && (sugarChoice == 'n' || sugarChoice == 'N'))
        {
            printf(" %s coffee with cream\n", stringcoffee[*coffeType - 1]);
        }
        printf("\nTotal due: %.2f\n", smallCoffePrice);

        break;

    case 'm':
    case 'M':
        if ((creamChoice == 'y' || creamChoice == 'Y') && (sugarChoice == 'y' || sugarChoice == 'Y'))
        {
            printf("%s coffee with cream and sugar\n", stringcoffee[*coffeType - 1]);
        }
        if ((creamChoice == 'n' || creamChoice == 'N') && (sugarChoice == 'n' || sugarChoice == 'N'))
        {
            printf(" %s  coffee \n", stringcoffee[*coffeType - 1]);
        }
        if ((creamChoice == 'n' || creamChoice == 'N') && (sugarChoice == 'y' || sugarChoice == 'Y'))
        {
            printf(" %s coffee with sugar\n", stringcoffee[*coffeType - 1]);
        }
        if ((creamChoice == 'y' || creamChoice == 'Y') && (sugarChoice == 'n' || sugarChoice == 'N'))
        {
            printf(" %s coffee with cream\n", stringcoffee[*coffeType - 1]);
        }
        printf("\nTotal due: %.2f\n", mediumCoffePrice);
        break;

    case 'l':
    case 'L':
        if ((creamChoice == 'y' || creamChoice == 'Y') && (sugarChoice == 'y' || sugarChoice == 'Y'))
        {
            printf(" %s coffee with cream and sugar\n", stringcoffee[*coffeType - 1]);
        }
        if ((creamChoice == 'n' || creamChoice == 'N') && (sugarChoice == 'n' || sugarChoice == 'N'))
        {
            printf(" %s  coffee\n", stringcoffee[*coffeType - 1]);
        }
        if ((creamChoice == 'n' || creamChoice == 'N') && (sugarChoice == 'y' || sugarChoice == 'Y'))
        {
            printf(" %s coffee with sugar\n", stringcoffee[*coffeType - 1]);
        }
        if ((creamChoice == 'y' || creamChoice == 'Y') && (sugarChoice == 'n' || sugarChoice == 'N'))
        {
            printf(" %s coffee with cream\n", stringcoffee[*coffeType - 1]);
        }
        printf("\nTotal due: %.2f\n", largeCoffePrice);
    }
}


