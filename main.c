#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int sum_array(const int *arr, int n); // implemented in assembly

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <inputfile>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    int n = 0;
    if (fscanf(fp, "%d", &n) != 1 || n < 0) {
        fprintf(stderr, "Invalid first line (expected non-negative count)\n");
        fclose(fp);
        return 1;
    }

    int *arr = NULL;
    if (n > 0) {
        arr = (int *)malloc((size_t)n * sizeof(int));
        if (!arr) {
            perror("malloc");
            fclose(fp);
            return 1;
        }

        for (int i = 0; i < n; i++) {
            if (fscanf(fp, "%d", &arr[i]) != 1) {
                fprintf(stderr, "Invalid data at index %d\n", i);
                free(arr);
                fclose(fp);
                return 1;
            }
        }
    }

    fclose(fp);

    int sum = sum_array(arr, n);
    printf("Sum = %d\n", sum);

    free(arr);
    return 0;
}