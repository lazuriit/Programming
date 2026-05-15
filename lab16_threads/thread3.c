#include <stdio.h>
#include <pthread.h>

struct data {
    int number;
    char string[5][100];
};

void* thread_f(void* arg) {
    int num = *(int*)arg; 
    
    for (int i = 1; i <= 5; i++) {
        printf("Поток - %d, строка - %d\n", num, i);
    }
    return NULL;
}

int main() {
    pthread_t tid[4];
    int numbers[4];
    
    for (int t = 0; t < 4; t++) {
        numbers[t] = t + 1;
        pthread_create(&tid[t], NULL, thread_f, &numbers[t]);
    }
    
    for (int t = 0; t < 4; t++) {
        pthread_join(tid[t], NULL);
    }
    
    return 0;
}