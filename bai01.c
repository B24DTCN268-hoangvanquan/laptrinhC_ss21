

#include <stdio.h>
#include <string.h>
struct Car {
  char model[50];
  int year;
  float price;
};
int main() {
  struct Car myCar;

  strcpy(myCar.model, "Toyota Camry");
  myCar.year = 2020;
  myCar.price = 24425.50;

  printf("Model: %s\n", myCar.model);
  printf("Year: %d\n", myCar.year);
  printf("Price: %.2f\n", myCar.price);

  return 0;
}
