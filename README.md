# Coffee Order Program ☕️

## Description

This **C program** is an interactive console-based system that allows users to order different types of coffee with customizable options. The program presents a list of coffee flavors, asks the user for size preferences, cream and sugar options, and then summarizes the order. It ensures that all coffee flavors are chosen before the program ends.

## Features
- **Coffee Options:**
  - **House Coffee** ☕️
  - **Iced Coffee** 🧊
  - **Vanilla Coffee** 🍦
  - **Hazelnut Coffee** 🌰
  - **Mocha Coffee** 🍫
- **Size Selection:** Choose from Small, Medium, or Large.
- **Customization:** Add cream and/or sugar to your coffee.
- **Order Summary:** Displays a summary of your coffee order and calculates the total price based on size.

## How to Run

1. Clone the repository:
    ```bash
    git clone <repository_url>
    ```

2. Navigate into the project directory:
    ```bash
    cd coffee-order
    ```

3. Compile the C program:
    ```bash
    gcc coffee_order.c -o coffee_order
    ```

4. Run the program:
    ```bash
    ./coffee_order
    ```

## How It Works
- When the program starts, it displays a list of coffee options for the user to choose from.
- The user selects the coffee type (House, Iced, Vanilla, Hazelnut, or Mocha).
- The user then selects whether they want cream and/or sugar added to their coffee.
- The user selects a size (Small, Medium, or Large).
- The program will display the summary of the coffee order, including the chosen size, flavor, and additional options (cream, sugar).
- The program ensures that each coffee flavor is chosen at least once before exiting.

## Notes
- The program will prompt the user if they enter invalid choices for coffee flavors, cream, sugar, or size.
- The total price is calculated based on the size selected (Small, Medium, or Large) and displayed at the end of the order.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Enjoy your coffee and have a great day! ☕️✨
