#include <stdio.h>
#include <stdbool.h>

// Khai báo các hàm
int nhapMang(int arr[]);
int inMang(int arr[], int n);
bool laSoHoanHao(int n);
int demsophantu(int arr[], int n);
int timgiatrinhothu2(int arr[], int n);
int themPhanTu(int arr[], int n, int value, int pos);
int xoaPhanTu(int arr[], int n, int pos);
int sapXepTangDan(int arr[], int n);
int timKiemPhanTu(int arr[], int n, int value);
int kiemtramangtang(int arr[], int n);
int sapXepLeChan(int arr[], int n);

int main() {
    int arr[100];
    int n = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nh?p m?ng\n");
        printf("2. In m?ng\n");
        printf("3. Ð?m s? lu?ng s? hoàn h?o trong m?ng\n");
        printf("4. Tìm giá tr? nh? th? 2 trong m?ng\n");
        printf("5. Thêm m?t ph?n t? vào v? trí ng?u nhiên trong m?ng\n");
        printf("6. Xóa ph?n t? t?i m?t v? trí c? th?\n");
        printf("7. S?p x?p m?ng theo th? t? tang d?n\n");
        printf("8. Tìm ki?m ph?n t? t?n t?i\n");
        printf("9. S?p x?p l?i m?ng sao cho s? l? d?ng tru?c, s? ch?n d?ng sau\n");
        printf("10. Ki?m tra xem m?ng có ph?i m?ng tang d?n hay không\n");
        printf("11. Thoát\n");
        printf("L?a ch?n c?a b?n: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                n = nhapMang(arr);
                break;
            case 2:
                inMang(arr, n);
                break;
            case 3:
                printf("S? lu?ng s? hoàn h?o trong m?ng: %d\n", demsophantu(arr, n));
                break;
            case 4: {
                int result = timgiatrinhothu2(arr, n);
                if (result != __INT_MAX__)
                    printf("Giá tr? nh? th? 2: %d\n", result);
                else
                    printf("Không có giá tr? nh? th? 2!\n");
                break;
            }
            case 5: {
                int value, pos;
                printf("Nh?p giá tr? thêm: ");
                scanf("%d", &value);
                printf("Nh?p v? trí thêm: ");
                scanf("%d", &pos);
                n = themPhanTu(arr, n, value, pos);
                break;
            }
            case 6: {
                int pos;
                printf("Nh?p v? trí c?n xóa: ");
                scanf("%d", &pos);
                n = xoaPhanTu(arr, n, pos);
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
                if (kiemtramangtang(arr, n))
                    printf("M?ng là tang d?n.\n");
                else
                    printf("M?ng không ph?i tang d?n.\n");
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

// Nh?p m?ng
int nhapMang(int arr[]) {
    int n;
    printf("Nh?p s? lu?ng ph?n t?: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Ph?n t? [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    return n;
}

// In m?ng
int inMang(int arr[], int n) {
    printf("Các ph?n t? trong m?ng: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return n;
}

// Ki?m tra s? hoàn h?o
bool laSoHoanHao(int n) {
    if (n <= 0) return false;
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) sum += i;
    }
    return sum == n;
}

// Ð?m s? lu?ng s? hoàn h?o
int demsophantu(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (laSoHoanHao(arr[i])) count++;
    }
    return count;
}

// Tìm giá tr? nh? th? 2
int timgiatrinhothu2(int arr[], int n) {
    if (n < 2) return __INT_MAX__;
    int min = arr[0], secondMin = __INT_MAX__;
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            secondMin = min;
            min = arr[i];
        } else if (arr[i] < secondMin && arr[i] != min) {
            secondMin = arr[i];
        }
    }
    return secondMin;
}

// Thêm ph?n t?
int themPhanTu(int arr[], int n, int value, int pos) {
    if (pos < 0 || pos > n) {
        printf("V? trí không h?p l?!\n");
        return n;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    return n + 1;
}

// Xóa ph?n t?
int xoaPhanTu(int arr[], int n, int pos) {
    if (pos < 0 || pos >= n) {
        printf("V? trí không h?p l?!\n");
        return n;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}

// S?p x?p tang d?n
int sapXepTangDan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return n;
}

// Tìm ki?m ph?n t?
int timKiemPhanTu(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Ki?m tra m?ng tang d?n
int kiemtramangtang(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) return 0;
    }
    return 1;
}

// S?p x?p s? l? tru?c, s? ch?n sau
int sapXepLeChan(int arr[], int n) {
    int temp[100], k = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) temp[k++] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) temp[k++] = arr[i];
    }
    for (int i = 0; i < n; i++) arr[i] = temp[i];
    return n;
}

