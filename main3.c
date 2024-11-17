#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item
{
    char name[100];
    double price;
    char category[20]; 
    struct Item *next;
};

struct Trans
{
    char name[100];
    double price;
    struct Trans *next;
};

typedef struct Item P;
typedef struct Trans T;

struct User
{
    char username[100];
    char password[100];
    T *hist;
    struct User *next;
};

typedef struct User U;

P *create_prod(char *name, double price, char *category)
{
    P *new_prod = (P *)malloc(sizeof(P));
    strcpy(new_prod->name, name);
    new_prod->price = price;
    strcpy(new_prod->category, category);
    new_prod->next = NULL;
    return new_prod;
}

void add_prod(P **inv, char *name, double price, char *category)
{
    P *new_prod = create_prod(name, price, category);
    if (*inv == NULL)
    {
        *inv = new_prod;
        return;
    }
    P *curr = *inv;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_prod;
}

void show_prods(P *inv)
{
    printf("\n--- Products ---\n");
    int idx = 1;
    while (inv != NULL)
    {
        printf("%d. %s (%s) - Rs. %.2f\n", idx++, inv->name, inv->category, inv->price);
        inv = inv->next;
    }
    printf("----------------\n");
}

void record_purchase(T **hist, char *name, double price)
{
    T *new_trans = (T *)malloc(sizeof(T));
    strcpy(new_trans->name, name);
    new_trans->price = price;
    new_trans->next = *hist;
    *hist = new_trans;
}

void suggest_products(T *hist)
{
    struct Count
    {
        char name[100];
        int count;
    } p_count[100];

    int total = 0;
    T *curr = hist;

    for (int i = 0; i < 100; i++)
    {
        p_count[i].count = 0;
    }

    while (curr != NULL)
    {
        int found = 0;
        for (int i = 0; i < total; i++)
        {
            if (strcmp(p_count[i].name, curr->name) == 0)
            {
                p_count[i].count++;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            strcpy(p_count[total].name, curr->name);
            p_count[total].count = 1;
            total++;
        }
        curr = curr->next;
    }

    int max_count = 0, second_max_count = 0;
    char *top_prod = NULL, *second_prod = NULL;

    for (int i = 0; i < total; i++)
    {
        if (p_count[i].count > max_count)
        {
            second_max_count = max_count;
            second_prod = top_prod;
            max_count = p_count[i].count;
            top_prod = p_count[i].name;
        }
        else if (p_count[i].count > second_max_count)
        {
            second_max_count = p_count[i].count;
            second_prod = p_count[i].name;
        }
    }

    if (top_prod != NULL && second_prod != NULL)
    {
        printf("\n--- Suggested Products ---\n");
        printf("1. %s\n", top_prod);
        printf("2. %s\n", second_prod);
        printf("--------------------------\n");
    }
}

void show_user_details(U *users)
{
    U *curr_user = users;
    while (curr_user != NULL)
    {
        printf("\n--- User Details ---\n");
        printf("Username: %s\n", curr_user->username);
        printf("Purchase History:\n");
        T *curr_trans = curr_user->hist;
        while (curr_trans != NULL)
        {
            printf("%s - Rs. %.2f\n", curr_trans->name, curr_trans->price);
            curr_trans = curr_trans->next;
        }
        curr_user = curr_user->next;
    }
}

void add_or_update_prod(P **inv, char *name, double price)
{
    char category[20];
    printf("Enter product category (Fruit/Vegetable): ");
    scanf("%s", category);

    P *curr = *inv;
    while (curr != NULL)
    {
        if (strcmp(curr->name, name) == 0)
        {
            printf("Product %s exists. Updating price...\n", name);
            curr->price = price;
            printf("Updated price for %s: Rs. %.2f\n", name, price);
            return;
        }
        curr = curr->next;
    }

    add_prod(inv, name, price, category);
    printf("Added %s in %s category with price Rs. %.2f\n", name, category, price);
}

void move_cart_to_history(T **cart, T **history)
{
    if (*cart == NULL)
        return;
    T *last_trans = *cart;
    while (last_trans->next != NULL)
    {
        last_trans = last_trans->next;
    }
    last_trans->next = *history;
    *history = *cart;
    *cart = NULL;
}

void print_invoice(T *cart)
{
    double total = 0;
    printf("\n--- Invoice ---\n");
    while (cart != NULL)
    {
        printf("%s - Rs. %.2f\n", cart->name, cart->price);
        total += cart->price;
        cart = cart->next;
    }
    printf("----------------\n");
    printf("Total: Rs. %.2f\n", total);
}

int main()
{
    P *inv = NULL;
    U *users = NULL;
    int action;

    add_prod(&inv, "Apple", 50, "Fruit");
    add_prod(&inv, "Banana", 30, "Fruit");
    add_prod(&inv, "Carrot", 40, "Vegetable");
    add_prod(&inv, "Spinach", 50, "Vegetable");
    add_prod(&inv, "Tomato", 30, "Vegetable");
    add_prod(&inv, "Kiwi", 80, "Fruit");
    add_prod(&inv, "Potato", 20, "Vegetable");
    add_prod(&inv, "Mango", 100, "Fruit");
    add_prod(&inv, "Orange", 60, "Fruit");
    add_prod(&inv, "Pineapple", 120, "Fruit");
    add_prod(&inv, "Strawberry", 150, "Fruit");
    add_prod(&inv, "Papaya", 70, "Fruit");
    add_prod(&inv, "Peach", 90, "Fruit");
    add_prod(&inv, "Cucumber", 25, "Vegetable");
    add_prod(&inv, "Onion", 40, "Vegetable");
    add_prod(&inv, "Lettuce", 35, "Vegetable");
    add_prod(&inv, "Bell Pepper", 55, "Vegetable");
    add_prod(&inv, "Zucchini", 45, "Vegetable");
    add_prod(&inv, "Eggplant", 50, "Vegetable");
    add_prod(&inv, "Chili Pepper", 30, "Vegetable");
    add_prod(&inv, "Garlic", 60, "Vegetable");
    add_prod(&inv, "Cauliflower", 65, "Vegetable");
    add_prod(&inv, "Broccoli", 80, "Vegetable");
    add_prod(&inv, "Watermelon", 75, "Fruit");
    add_prod(&inv, "Grapes", 110, "Fruit");
    add_prod(&inv, "Lychee", 130, "Fruit");
    add_prod(&inv, "Plum", 95, "Fruit");

    while (1)
    {
        printf("\n1. Create Account\n2. Log In\n3. Add/Update Product\n4. View All Users\n5. Exit\nSelect an option: ");
        scanf("%d", &action);

        if (action == 1)
        {
            char username[100], password[100], confirm_password[100];
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            printf("Confirm password: ");
            scanf("%s", confirm_password);
            if (strcmp(password, confirm_password) == 0)
            {
                U *new_user = (U *)malloc(sizeof(U));
                strcpy(new_user->username, username);
                strcpy(new_user->password, password);
                new_user->hist = NULL;
                new_user->next = users;
                users = new_user;
                printf("Account successfully created.\n");
            }
            else
            {
                printf("Passwords do not match.\n");
            }
        }
        else if (action == 2)
        {
            char username[100], password[100];
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);

            U *curr_user = users;
            while (curr_user != NULL)
            {
                if (strcmp(curr_user->username, username) == 0 && strcmp(curr_user->password, password) == 0)
                {
                    printf("Login successful. Welcome, %s\n", username);
                    suggest_products(curr_user->hist);

                    T *cart = NULL;
                    show_prods(inv);

                    while (1)
                    {
                        int choice;
                        printf("\nSelect a product (0 to finish): ");
                        scanf("%d", &choice);
                        if (choice == 0)
                            break;

                        P *prod = inv;
                        int idx = 1;
                        while (prod != NULL)
                        {
                            if (choice == idx)
                            {
                                record_purchase(&cart, prod->name, prod->price);
                                break;
                            }
                            prod = prod->next;
                            idx++;
                        }
                    }

                    print_invoice(cart);
                    move_cart_to_history(&cart, &curr_user->hist);
                    break;
                }
                curr_user = curr_user->next;
            }
            if (curr_user == NULL)
            {
                printf("Invalid username or password.\n");
            }
        }
        else if (action == 3)
        {
            char prod_name[100];
            double prod_price;
            printf("Enter product name: ");
            scanf("%s", prod_name);
            printf("Enter product price: ");
            scanf("%lf", &prod_price);
            add_or_update_prod(&inv, prod_name, prod_price);
        }
        else if (action == 4)
        {
            show_user_details(users);
        }
        else if (action == 5)
        {
            break;
        }
        else
        {
            printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}
