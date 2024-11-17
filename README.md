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
4. Run the program using:

   ```bash
   ./shopping_cart

### Sample Output

Upon running the program, the user will be presented with a main menu that offers options like creating an account, logging in, managing products, and more. After logging in, users can view the product list, add items to their cart, and check out.

#### Example Interaction:

```text
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
------------------------
Total: Rs. 80.00
```
## How It Works

### 1. **Creating an Account**:
- Users are prompted to enter a **username** and **password**.
- The password must be confirmed by re-entering it to ensure accuracy.
- If both passwords match, the account is successfully created. If they don't, the user will be asked to re-enter the passwords.

### 2. **Logging In**:
- After the account has been created, users can log in with their **username** and **password**.
- If the login credentials match an existing account, the user is logged in successfully.
- Upon successful login, the user is welcomed and presented with the main menu to proceed with further actions.

### 3. **Viewing Products**:
- Once logged in, the user can view a list of all available products categorized into **Fruits** and **Vegetables**.
- The product list displays the **name**, **category**, and **price** of each product.
- The user can browse these products and select items to add to their cart.

### 4. **Shopping Cart**:
- The user can add products to their cart by selecting the product number from the list.
- The program will ask the user for input and add the chosen products to the cart. Users can keep selecting products until they choose to finish (by selecting option 0).
- After the user has finished selecting products, the system generates an **invoice**, listing the products selected and their respective prices.
- The total price of the cart is calculated and displayed in the invoice.

### 5. **Product Suggestions**:
- The program tracks the user’s previous purchases and suggests products that the user is most likely to buy again based on their purchase history.
- These suggestions are shown after a successful login, before the user begins shopping.
- The user can choose to add any of the suggested products to their cart or skip this step.

### 6. **Inventory Management (Admin)**:
- The **admin** has special privileges to add, update, or delete products in the inventory at any time.
- Admin can:
  - Add new products by entering the product name, category (Fruit or Vegetable), and price.
  - Update existing products by changing their details (name, category, or price).
  - Delete products if they are no longer needed or available.
  
- The admin can also categorize products into **Fruits** and **Vegetables**, making it easier for users to browse and select products from these categories.

### 7. **Purchase History**:
- The system keeps track of all user purchases.
- After each transaction, the user’s purchase history is updated.
- Users can view their purchase history anytime by logging in, which can also help suggest products they might want to purchase again in the future.

---

### Workflow Summary:

1. **Account Creation**: A user creates a new account with a unique username and password.
2. **Login**: User logs in with credentials.
3. **Product Browsing**: User views products categorized as Fruits or Vegetables.
4. **Adding to Cart**: User adds selected products to their cart.
5. **Invoice Generation**: Once finished, an invoice is generated with the total price.
6. **Purchase History**: All purchases are tracked, and suggestions are made for future shopping based on purchase history.
7. **Inventory Management (Admin)**: Admin manages the products in the inventory.

