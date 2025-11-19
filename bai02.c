// Khai báo một struct có tên Student chứa các thành viên:
// name: kiểu char[50] (dùng để lưu tên của học sinh).
// age: kiểu int (dùng để lưu tuổi của học sinh).
// grade: kiểu float (dùng để lưu điểm trung bình của học sinh).
// Khai báo một biến student1 kiểu Student, sau đó nhập các giá trị từ bàn phím
// cho các thuộc tính: tên, tuổi và điểm trung bình của học sinh từ người dùng.
// In thông tin của học sinh student1 ra màn hình.

#include <stdio.h>
#include <string.h>
struct Student {
  char name[50];
  int age;
  float grade;
};
int main() {
  struct Student student1;
  printf("Nhap ten hoc sinh: ");
  fgets(student1.name, sizeof(student1.name), stdin);
  printf("Nhap tuoi hoc sinh: ");
  scanf("%d", &student1.age);
  printf("Nhap diem trung binh hoc sinh: ");
  scanf("%f", &student1.grade);
  printf("\n--- Thong tin hoc sinh ---\n");
  printf("Ten: %s", student1.name);
  printf("Tuoi: %d\n", student1.age);
  printf("Diem trung binh: %.2f\n", student1.grade);
  return 0;
}