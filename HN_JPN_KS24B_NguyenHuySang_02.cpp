#include <stdio.h>
#include <stdbool.h>

// Khai báo các hàm
void nhapMang(int arr[], int *n);
void inMang(int arr[], int n);
bool laSoHoanHao(int n);
int demsophantu(int arr[], int n);
void timgiatrinhothu2(int arr[], int n);
void themPhanTu(int arr[], int *n, int value, int pos);
void xoaPhanTu(int arr[], int *n, int pos);
void sapXepTangDan(int arr[], int n);
int timKiemPhanTu(int arr[], int n, int value);
void kiemtramangtang(int arr[], int n);
void sapXepLeChan(int arr[], int n);

int main() {
    int arr[100];
    int n = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap mang\n");
        printf("2. In mang\n");
        printf("3. dem so luong so hoan hao trong mang\n");
        printf("4. tim gia tri nho thu 2 trong mang \n");
        printf("5. them 1 phan tu vao vi tri ngau nhien trong mang\n");
        printf("6. xoa phan tu tai vi tri cu the\n");
        printf("7. sap xep theo thu tu tang dan\n");
        printf("8. tim kiem phan tu co ton tai khong\n");
        printf("9. sap xep lai mang so le truoc so chan sau\n");
        printf("10. kiem tra xem mang co phai mang tang dan khong\n");
        printf("11. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(arr, &n);
                break;
            case 2:
                inMang(arr, n);
                break;
            case 3:
                printf("S? lu?ng s? hoàn h?o trong m?ng: %d\n", demsophantu(arr, n));
                break;
            case 4:
                timgiatrinhothu2(arr, n);
                break;
            case 5: {
                int value, pos;
                printf("Nh?p giá tr? thêm: ");
                scanf("%d", &value);
                printf("Nh?p v? trí thêm: ");
                scanf("%d", &pos);
                themPhanTu(arr, &n, value, pos);
                break;
            }
            case 6: {
                int pos;
                printf("Nh?p v? trí c?n xóa: ");
                scanf("%d", &pos);
                xoaPhanTu(arr, &n, pos);
                break;
            }
            case 7:
                sapXepTangDan(arr, n);
                printf("M?ng sau khi s?p x?p: ");
                inMang(arr, n);
                break;
            case 8: {
                int value;
                printf("Nh?p giá tr? c?n tìm: ");
                scanf("%d", &value);
                int index = timKiemPhanTu(arr, n, value);
                if (index != -1)
                    printf("Ph?n t? %d n?m ? v? trí %d\n", value, index);
                else
                    printf("Không tìm th?y ph?n t? %d\n", value);
                break;
            }
            case 9:
                sapXepLeChan(arr, n);
                printf("M?ng sau khi s?p x?p s? l? tru?c, s? ch?n sau: ");
                inMang(arr, n);
                break;
            case 10:
                kiemtramangtang(arr, n);
                break;
            case 11:
                printf("Thoát chuong trình.\n");
                break;
            default:
                printf("L?a ch?n không h?p l?!\n");
        }
    } while (choice != 11);

    return 0;
}

void nhapMang(int arr[], int *n) {
    printf("Nh?p s? lu?ng ph?n t?: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Ph?n t? [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void inMang(int arr[], int n) {
    printf("Các ph?n t? trong m?ng: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

bool laSoHoanHao(int n) {
    if (n <= 0) return false;
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) sum += i;
    }
    return sum == n;
}

int demsophantu(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (laSoHoanHao(arr[i])) count++;
    }
    return count;
}

void timgiatrinhothu2(int arr[], int n) {
    if (n < 2) {
        printf("M?ng không d? ph?n t?!\n");
        return;
    }
    int min = arr[0], secondMin = __INT_MAX__;
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            secondMin = min;
            min = arr[i];
        } else if (arr[i] < secondMin && arr[i] != min) {
            secondMin = arr[i];
        }
    }
    if (secondMin == __INT_MAX__)
        printf("Không có giá tr? nh? th? 2!\n");
    else
        printf("Giá tr? nh? th? 2: %d\n", secondMin);
}

void themPhanTu(int arr[], int *n, int value, int pos) {
    if (pos < 0 || pos > *n) {
        printf("V? trí không h?p l?!\n");
        return;
    }
    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
}

void xoaPhanTu(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) {
        printf("V? trí không h?p l?!\n");
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void sapXepTangDan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int timKiemPhanTu(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

void kiemtramangtang(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            printf("M?ng không ph?i tang d?n.\n");
            return;
        }
    }
    printf("M?ng là tang d?n.\n");
}

void sapXepLeChan(int arr[], int n) {
    int temp[100], k = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) temp[k++] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) temp[k++] = arr[i];
    }
    for (int i = 0; i < n; i++) arr[i] = temp[i];
}

