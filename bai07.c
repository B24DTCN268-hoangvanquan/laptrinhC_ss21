#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100
struct Book {
  char code[20];
  char title[100];
  char author[50];
  float price;
  char category[50];
};
void inputBook(struct Book *book) {
  printf("Nhap ma sach: ");
  getchar();
  fgets(book->code, sizeof(book->code), stdin);
  book->code[strcspn(book->code, "\n")] = 0;

  printf("Nhap ten sach: ");
  fgets(book->title, sizeof(book->title), stdin);
  book->title[strcspn(book->title, "\n")] = 0;

  printf("Nhap tac gia: ");
  fgets(book->author, sizeof(book->author), stdin);
  book->author[strcspn(book->author, "\n")] = 0;

  printf("Nhap gia tien: ");
  scanf("%f", &book->price);

  printf("Nhap the loai: ");
  getchar();
  fgets(book->category, sizeof(book->category), stdin);
  book->category[strcspn(book->category, "\n")] = 0;
}
void displayBooks(struct Book books[], int count) {
  printf("\n--- Thong tin sach ---\n");
  for (int i = 0; i < count; i++) {
    printf("Sach %d:\n", i + 1);
    printf("Ma sach: %s\n", books[i].code);
    printf("Ten sach: %s\n", books[i].title);
    printf("Tac gia: %s\n", books[i].author);
    printf("Gia tien: %.2f\n", books[i].price);
    printf("The loai: %s\n", books[i].category);
  }
}
int findBookByCode(struct Book books[], int count, const char *code) {
  for (int i = 0; i < count; i++) {
    if (strcmp(books[i].code, code) == 0) {
      return i;
    }
  }
  return -1;
}
// thêm sách vào vị trí
void addBookAtPosition(struct Book books[], int *count, struct Book newBook,
                       int position) {
  if (position < 0 || position > *count || *count >= MAX_BOOKS) {
    printf("Vi tri khong hop le hoac danh sach da day.\n");
    return;
  }
  for (int i = *count; i > position; i--) {
    books[i] = books[i - 1];
  }
  books[position] = newBook;
  (*count)++;
  printf("Them sach thanh cong.\n");
}
void deleteBookByCode(struct Book books[], int *count, const char *code) {
  int index = findBookByCode(books, *count, code);
  if (index != -1) {
    for (int i = index; i < (*count) - 1; i++) {
      books[i] = books[i + 1];
    }
    (*count)--;
    printf("Xoa sach thanh cong.\n");
  } else {
    printf("Khong tim thay sach voi ma: %s\n", code);
  }
}
// cập nhật thông tin sách theo mã sách
void updateBookByCode(struct Book books[], int count, const char *code) {
  int index = findBookByCode(books, count, code);
  if (index != -1) {
    printf("Nhap thong tin moi cho sach:\n");
    inputBook(&books[index]);
    printf("Cap nhat sach thanh cong.\n");
  } else {
    printf("Khong tim thay sach voi ma: %s\n", code);
  }
}
// sắp xếp sách theo giá (tăng/giam)
void sortBooksByPrice(struct Book books[], int count, int ascending) {
  for (int i = 0; i < count - 1; i++) {
    for (int j = i + 1; j < count; j++) {
      if ((ascending && books[i].price > books[j].price) ||
          (!ascending && books[i].price < books[j].price)) {
        struct Book temp = books[i];
        books[i] = books[j];
        books[j] = temp;
      }
    }
  }
  printf("Sap xep sach theo gia thanh cong.\n");
}
// tìm kiếm sách theo tên sách
void searchBooksByTitle(struct Book books[], int count, const char *title) {
  printf("\n--- Ket qua tim kiem ---\n");
  int found = 0;
  for (int i = 0; i < count; i++) {
    if (strstr(books[i].title, title) != NULL) {
      printf("Ma sach: %s\n", books[i].code);
      printf("Ten sach: %s\n", books[i].title);
      printf("Tac gia: %s\n", books[i].author);
      printf("Gia tien: %.2f\n", books[i].price);
      printf("The loai: %s\n", books[i].category);
      found = 1;
    }
  }
  if (!found) {
    printf("Khong tim thay sach voi ten: %s\n", title);
  }
}
int main() {
  struct Book books[MAX_BOOKS];
  int count = 0;
  int choice;
  do {
    printf("\n--- MENU ---\n");
    printf("1. Nhap so luong va thong tin sach\n");
    printf("2. Hien thi thong tin sach\n");
    printf("3. Them sach vao vi tri\n");
    printf("4. Xoa sach theo ma sach\n");
    printf("5. Cap nhat thong tin sach theo ma sach\n");
    printf("6. Sap xep sach theo gia (tang/giam)\n");
    printf("7. Tim kiem sach theo ten sach\n");
    printf("8. Thoat\n");
    printf("Lua chon cua ban: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1: {
      int n;
      printf("Nhap so luong sach can them: ");
      scanf("%d", &n);
      for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin cho sach thu %d:\n", i + 1);
        inputBook(&books[count++]);
      }
      break;
    }
    case 2:
      displayBooks(books, count);
      break;
    case 3: {
      struct Book newBook;
      int position;
      printf("Nhap thong tin sach can them:\n");
      inputBook(&newBook);
      printf("Nhap vi tri can them (0 den %d): ", count);
      scanf("%d", &position);
      addBookAtPosition(books, &count, newBook, position);
      break;
    }

    case 4: {
      char code[20];
      printf("Nhap ma sach can xoa: ");
      getchar();
      fgets(code, sizeof(code), stdin);
      code[strcspn(code, "\n")] = 0;
      deleteBookByCode(books, &count, code);
      break;
    }
    case 5:
      // Cập nhật thông tin sách theo mã sách
      {
        char code[20];
        printf("Nhap ma sach can cap nhat: ");
        getchar();
        fgets(code, sizeof(code), stdin);
        code[strcspn(code, "\n")] = 0;
        updateBookByCode(books, count, code);

        break;
      }
    case 6: {
      int order;
      printf("Chon kieu sap xep (1: Tang dan, 2: Giam dan): ");
      scanf("%d", &order);
      sortBooksByPrice(books, count, order == 1);
      break;
    }
    case 7: {
      char title[100];
      printf("Nhap ten sach can tim kiem: ");
      getchar();
      fgets(title, sizeof(title), stdin);
      title[strcspn(title, "\n")] = 0;
      searchBooksByTitle(books, count, title);
      break;
    }
    case 8:
      printf("Thoat chuong trinh.\n");
      break;
    default:
      printf("Lua chon khong hop le. Vui long thu lai.\n");
    }
  } while (choice != 8);
  return 0;
}