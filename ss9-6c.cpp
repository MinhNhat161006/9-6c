#include <stdio.h>

int main() {
    int matrix[100][100], rows = 0, cols = 0, choice;

    while (1) {
        printf("\nMENU\n");
        printf("1. Nhập kích cỡ và giá trị các phần tử của mảng\n");
        printf("2. In giá trị các phần tử của mảng theo ma trận\n");
        printf("3. In giá trị các phần tử là lẻ và tính tổng\n");
        printf("4. In ra các phần tử nằm trên đường biên và tính tích\n");
        printf("5. In ra các phần tử nằm trên đường chéo chính\n");
        printf("6. In ra các phần tử nằm trên đường chéo phụ\n");
        printf("7. In ra dòng có tổng giá trị các phần tử là lớn nhất\n");
        printf("8. Thoát\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &choice);

        if (choice == 8) break;

        switch (choice) {
            case 1: {
                printf("Nhập số dòng: ");
                scanf("%d", &rows);
                printf("Nhập số cột: ");
                scanf("%d", &cols);

                if (rows <= 0 || cols <= 0 || rows > 100 || cols > 100) {
                    printf("Kích cỡ không hợp lệ.\n");
                } else {
                    printf("Nhập các phần tử của ma trận:\n");
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < cols; j++) {
                            scanf("%d", &matrix[i][j]);
                        }
                    }
                }
                break;
            }
            case 2: {
                printf("Ma trận:\n");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        printf("%d ", matrix[i][j]);
                    }
                    printf("\n");
                }
                break;
            }
            case 3: {
                int sumOdd = 0;
                printf("Các phần tử lẻ: ");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (matrix[i][j] % 2 != 0) {
                            printf("%d ", matrix[i][j]);
                            sumOdd += matrix[i][j];
                        }
                    }
                }
                printf("\nTổng các phần tử lẻ: %d\n", sumOdd);
                break;
            }
            case 4: {
                long long product = 1;
                printf("Các phần tử nằm trên đường biên: ");
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                            printf("%d ", matrix[i][j]);
                            product *= matrix[i][j];
                        }
                    }
                }
                printf("\nTích các phần tử trên đường biên: %lld\n", product);
                break;
            }
            case 5: {
                printf("Các phần tử trên đường chéo chính: ");
                for (int i = 0; i < rows && i < cols; i++) {
                    printf("%d ", matrix[i][i]);
                }
                printf("\n");
                break;
            }
            case 6: {
                printf("Các phần tử trên đường chéo phụ: ");
                for (int i = 0; i < rows && i < cols; i++) {
                    printf("%d ", matrix[i][cols - i - 1]);
                }
                printf("\n");
                break;
            }
            case 7: {
                int maxSum = -1, maxRow = -1;
                for (int i = 0; i < rows; i++) {
                    int rowSum = 0;
                    for (int j = 0; j < cols; j++) {
                        rowSum += matrix[i][j];
                    }
                    if (rowSum > maxSum) {
                        maxSum = rowSum;
                        maxRow = i;
                    }
                }
                printf("Dòng có tổng lớn nhất là dòng %d với tổng %d: ", maxRow, maxSum);
                for (int j = 0; j < cols; j++) {
                    printf("%d ", matrix[maxRow][j]);
                }
                printf("\n");
                break;
            }
            default:
                printf("Lựa chọn không hợp lệ.\n");
        }
    }

    printf("Chương trình đã thoát.\n");
    return 0;
}
