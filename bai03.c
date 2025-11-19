// Khai báo một struct Address với các thành viên:

// street: kiểu char[100] (dùng để lưu tên đường).
// city: kiểu char[50] (dùng để lưu tên thành phố).
// zip: kiểu int (dùng để lưu mã bưu điện).
// Khai báo một struct Person với các thành viên:

// name: kiểu char[50] (dùng để lưu tên của người).
// age: kiểu int (dùng để lưu tuổi của người).
// address: kiểu Address (dùng để lưu thông tin địa chỉ của người, đây là một
// struct lồng nhau). Khai báo một biến person1 kiểu Person, nhập thông tin của
// người này từ người dùng, bao gồm cả thông tin địa chỉ.

// In thông tin của person1 ra màn hình, bao gồm cả thông tin cá nhân và thông
// tin địa chỉ.
#include <stdio.h>
#include <string.h>
struct Address {
  char street[100];
  char city[50];
  int zip;
};
struct Person {
  char name[50];
  int age;
  struct Address address;
};
int main() {
  struct Person person1;
  printf("Nhap ten nguoi: ");
  fgets(person1.name, sizeof(person1.name), stdin);
  printf("Nhap tuoi nguoi: ");
  scanf("%d", &person1.age);
  printf("Nhap dia chi nguoi:\n");
  printf("Nhap ten duong: ");
  getchar();
  fgets(person1.address.street, sizeof(person1.address.street), stdin);
  printf("Nhap ten thanh pho: ");
  fgets(person1.address.city, sizeof(person1.address.city), stdin);
  printf("Nhap ma buu dien: ");
  scanf("%d", &person1.address.zip);
  printf("\n--- Thong tin nguoi ---\n");
  printf("Ten: %s", person1.name);
  printf("Tuoi: %d\n", person1.age);
  printf("Dia chi:\n");
  printf("Duong: %s", person1.address.street);
  printf("Thanh pho: %s", person1.address.city);
  printf("Ma buu dien: %d\n", person1.address.zip);
  return 0;
}