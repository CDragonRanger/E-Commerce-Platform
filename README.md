# Shopping Cart System

A simple command-line based shopping cart system implemented in C. This program allows users to create accounts, log in, view products, add products to their cart, purchase items, and view their transaction history. The system also supports inventory management, where new products can be added or existing ones can be updated.

## Features

- **User Management**: Users can create accounts, log in, and view their purchase history.
- **Product Management**: Admin can add new products, update existing ones, and categorize products as fruits or vegetables.
- **Shopping Cart**: Users can add products to their cart, generate an invoice, and complete their purchases.
- **Purchase History**: Keeps track of user purchases and suggests products based on their history.

## Project Structure

The project is structured into the following main components:

1. **Product Management**: 
    - Create, add, and update products.
    - Display product details like name, category, and price.

2. **User Management**: 
    - Create and manage user accounts.
    - Users can log in with their credentials.
    - Users can view their purchase history.

3. **Transaction System**:
    - Users can add products to their cart.
    - Generate invoices showing the total price of selected products.
    - Suggest products based on the user's purchase history.

4. **Main Menu**: The system allows users to select from the following options:
    - Create a new account
    - Log in to an existing account
    - Add or update products in the inventory
    - View all users and their purchase history
    - Exit the program

## How to Compile and Run

### Requirements:
- A C compiler (such as `gcc`)

### Steps to Compile:

1. Clone this repository to your local machine.
2. Open a terminal/command prompt and navigate to the project directory.
3. Compile the C program with the following command:

   ```bash
   gcc -o shopping_cart shopping_cart.c
Run the program using:

bash
Copy code
./shopping_cart
Sample Output:
Upon running the program, the user will be presented with a main menu that offers options like creating an account, logging in, managing products, and more. After logging in, users can view the product list, add items to their cart, and check out.

Example Interaction:
text
Copy code
1. Create Account
2. Log In
3. Add/Update Product
4. View All Users
5. Exit
Select an option: 1

Enter username: john_doe
Enter password: password123
Confirm password: password123
Account successfully created.

1. Create Account
2. Log In
3. Add/Update Product
4. View All Users
5. Exit
Select an option: 2

Enter username: john_doe
Enter password: password123
Login successful. Welcome, john_doe
--- Suggested Products ---
1. Apple
2. Banana
--------------------------
Select a product (0 to finish): 1
Select a product (0 to finish): 2
Select a product (0 to finish): 0

--- Invoice ---
Apple - Rs. 50.00
Banana - Rs. 30.00
----------------
Total: Rs. 80.00
How It Works
Creating an Account: Users are prompted to enter a username and password. Passwords must match to successfully create an account.
Logging In: Once the account is created, users can log in with their credentials.
Viewing Products: Once logged in, users can view all available products categorized as Fruits or Vegetables.
Shopping Cart: Users can select products to add to their cart. When they finish selecting items, an invoice is generated, showing the total amount.
Product Suggestions: Based on the user's purchase history, the program suggests products they are most likely to buy again.
Inventory Management: The admin can add or update product details in the inventory at any time.
