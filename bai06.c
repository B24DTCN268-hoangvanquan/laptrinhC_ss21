
#include <stdio.h>
#include <string.h>
struct Student {
  char name[50];
  int age;
  float grade;
};

void findStudentByName(struct Student students[], int size, const char *name) {
  for (int i = 0; i < size; i++) {
    if (strcmp(students[i].name, name) == 0) {
      printf("Thong tin hoc sinh tim thay:\n");
      printf("Ten: %s", students[i].name);
      printf("Tuoi: %d\n", students[i].age);
      printf("Diem trung binh: %.2f\n", students[i].grade);
      return;
    }
  }
  printf("Khong tim thay hoc sinh voi ten: %s\n", name);
}
int main() {
  struct Student students[5];
  for (int i = 0; i < 5; i++) {
    printf("Nhap thong tin cho hoc sinh thu %d:\n", i + 1);
    printf("Nhap ten hoc sinh: ");
    getchar();
    fgets(students[i].name, sizeof(students[i].name), stdin);
    printf("Nhap tuoi hoc sinh: ");
    scanf("%d", &students[i].age);
    printf("Nhap diem trung binh cua hoc sinh: ");
    scanf("%f", &students[i].grade);
  }
  char searchName[50];
  printf("\nNhap ten hoc sinh can tim: ");
  getchar();
  fgets(searchName, sizeof(searchName), stdin);
  size_t len = strlen(searchName);
  if (len > 0 && searchName[len - 1] == '\n') {
    searchName[len - 1] = '\0';
  }
  findStudentByName(students, 5, searchName);
  return 0;
}