#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <semaphore.h>

int BankAccount = 0;
int Turn = 0;

sem_t mutex;

void DepositMoney() {
  int balance = rand() % 101; // Random balance between 0-100
  if (balance % 2 == 0) {
    BankAccount += balance;
    printf("Dear old Dad: Deposits $%d / Balance = $%d\n", balance, BankAccount);
  } else {
    printf("Dear old Dad: Doesn't have any money to give\n");
  }
}

void WithdrawMoney() {
  int balance = rand() % 51; // Random balance needed between 0-50
  if (balance <= BankAccount) {
    BankAccount -= balance;
    printf("Poor Student: Withdraws $%d / Balance = $%d\n", balance, BankAccount);
  } else {
    printf("Poor Student: Not Enough Cash ($%d)\n", BankAccount);
  }
}

void DearOldDad() {
  srand(time(NULL));
  int account;

  for (int i = 0; i < 25; i++) {
    sleep(rand() % 6); // Sleep 0-5 seconds

    account = BankAccount;

    while (Turn != 0) {} // Busy wait while Turn != 0
      if (account <= 100) {
        DepositMoney();
      } else {
        printf("Dear old Dad: Thinks Student has enough Cash ($%d)\n", account);
      }

      BankAccount = account;
      Turn = 1;
    }
}

void PoorStudent() {
  srand(time(NULL));
  int account;

  for (int i = 0; i < 25; i++) {
    sleep(rand() % 6); // Sleep 0-5 seconds

    account = BankAccount;

    while (Turn != 1) {} // Busy wait while Turn != 1
      int balance = rand() % 51; // Random balance needed between 0-50
      printf("Poor Student needs $%d\n", balance);

      if (balance <= account) {
        WithdrawMoney();
      } else {
        printf("Poor Student: Not Enough Cash ($%d)\n", account);
      }

      BankAccount = account;
      Turn = 0;
    }
}

int main() {
  sem_init(&mutex, 0, 1);

  pid_t pid = fork();

  if (pid < 0) {
    fprintf(stderr, "Fork failed\n");
      return 1;
  } else if (pid == 0) {
    PoorStudent(); // Child process
  } else {
    DearOldDad(); // Parent process
    wait(NULL);
    }

  sem_destroy(&mutex);
  return 0;
}
