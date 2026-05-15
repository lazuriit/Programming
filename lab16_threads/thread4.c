#include <stdio.h>
#include <pthread.h>

void* thread_f(void* arg) {
    int num = *(int*)arg;
    
    for (int i = 1; i <= 10; i++) {
        printf("Поток - %d, строка - %d\n", num, i);
        sleep(3);
    }
    
    return NULL;
}

int main() {
    pthread_t tid[4];
    int numbers[4];
    
    for (int i = 0; i < 4; i++) {
        numbers[i] = i + 1;
        pthread_create(&tid[i], NULL, thread_f, &numbers[i]);
    }
    
    printf("Основной поток ждет 2 секунды...\n");
    sleep(2);
    
    printf("\nОтмена потоков\n");
    for (int i = 0; i < 4; i++) {
        pthread_cancel(tid[i]);
    }
    
    printf("Все потоки остановлены. Программа завершена.\n");
    
    return 0;
}