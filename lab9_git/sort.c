void bubble_sort(int size, int arr[size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { // если текущий > следующего, то делаем swap - меняем местами
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main() {
    int a[] = {4, 2};
    int size = sizeof(a) / sizeof(a[0]);
    bubble_sort(size, a);
    return 0;
}