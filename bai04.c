// Khai báo một struct Book chứa các thành viên:
// title: kiểu char[100] (dùng để lưu tên sách).
// author: kiểu char[50] (dùng để lưu tên tác giả).
// price: kiểu float (dùng để lưu giá của cuốn sách).
// Khai báo một mảng books[3] chứa 3 cuốn sách.
// Nhập thông tin cho từng cuốn sách từ người dùng, bao gồm tên sách, tác giả và
// giá. In thông tin của tất cả các cuốn sách ra màn hình.
#include <stdio.h>
#include <string.h>
struct Book {
  char title[100];
  char author[50];
  float price;
};
int main() {
  struct Book books[3];
  for (int i = 0; i < 3; i++) {
    printf("Nhap thong tin cho cuon sach thu %d:\n", i + 1);
    printf("Nhap ten sach: ");
    getchar();
    fgets(books[i].title, sizeof(books[i].title), stdin);
    printf("Nhap ten tac gia: ");
    fgets(books[i].author, sizeof(books[i].author), stdin);
    printf("Nhap gia sach: ");
    scanf("%f", &books[i].price);
  }
  printf("\n--- Thong tin cac cuon sach ---\n");
  for (int i = 0; i < 3; i++) {
    printf("Cuon sach thu %d:\n", i + 1);
    printf("Ten sach: %s", books[i].title);
    printf("Tac gia: %s", books[i].author);
    printf("Gia sach: %.2f\n", books[i].price);
  }
  return 0;
}
