#include <stdio.h>
#include <string.h>

// Define struct for account information
struct Account {
  char name[30];
  int acc_Num;
  float balance;
};

// Function to create new account
void createAccount(struct Account *acc) {
  printf("Enter name: ");
  scanf("%s", acc->name);
  printf("Enter account number: ");
  scanf("%d", &acc->acc_Num);
  printf("Enter initial balance: ");
  scanf("%f", &acc->balance);
  printf("\nAccount created successfully!\n\n");
}

// Function to display account information
void displayAccount(struct Account acc) {
  printf("Name: %s\n", acc.name);
  printf("Account number: %d\n", acc.acc_Num);
  printf("Balance: %.2f\n", acc.balance);
  printf("\n");
}

// Function to deposit money
void deposit(struct Account *acc) {
  float amount;
  printf("Enter amount to deposit: ");
  scanf("%f", &amount);
  acc->balance += amount;
  printf("\nDeposit successful!\n\n");
}

// Function to withdraw money
void withdraw(struct Account *acc) {
  float amount;
  printf("Enter amount to withdraw: ");
  scanf("%f", &amount);
  if (amount > acc->balance) {
    printf("\nInsufficient balance!\n\n");
  } else {
    acc->balance -= amount;
    printf("\nWithdrawal successful!\n\n");
  }
}

int main() {
  int choice;
  struct Account acc;

  printf("*** Online Banking System ***\n\n");

  // Loop to display menu and process user choice
  do {
    printf("1. Create new account\n");
    printf("2. Display account information\n");
    printf("3. Deposit money\n");
    printf("4. Withdraw money\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        createAccount(&acc);
        break;
      case 2:
        displayAccount(acc);
        break;
      case 3:
        deposit(&acc);
        break;
      case 4:
        withdraw(&acc);
        break;
      case 5:
        printf("Thank you for using our online banking system!\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  } while (choice != 5);

  return 0;
}
