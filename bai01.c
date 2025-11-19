// Khai báo một struct có tên Car, chứa ba thuộc tính:

// model: (dùng để lưu tên mẫu xe).
// year: (dùng để lưu năm sản xuất của xe).
// price: (dùng để lưu giá của xe).
// Khởi tạo một biến myCar kiểu Car, gán giá trị cho các thành viên của struct
// này.

// In thông tin của biến myCar ra màn hình bao gồm các thông tin: mẫu xe, năm
// sản xuất, và giá của xe.

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
