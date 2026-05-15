#include <stdio.h>
#include <pthread.h>

void* child_thread_f(void* arg) {
    for (int i = 1; i <= 5; i++) {
        printf("Дочерний поток, строка - %d\n", i);
    }
    return NULL;
}

int main() {
    pthread_t tid;
    
    pthread_create(&tid, NULL, child_thread_f, NULL);
    
    pthread_join(tid, NULL);

    for (int i = 1; i <= 5; i++) {
        printf("Родительский поток, строка - %d\n", i);
    }
    return 0;
}