#include <pthread.h>
#include "8.2.common.h"

struct apple {
    unsigned long long a;
    unsigned long long b;
};

struct orange {
    int a[ORANGE_MAX_VALUE];
    int b[ORANGE_MAX_VALUE];
};

static struct apple apple_test;
static struct orange orange_test = {
        {0}, {0}
};

void *apple_operation(void *_unused) {
    for(unsigned long long sum = 0; sum < APPLE_MAX_VALUE; sum ++) {
        apple_test.a += sum;
        apple_test.b += sum;
    }
}

int main(void) {

    pthread_t apple_thread;
    pthread_create(&apple_thread, NULL, apple_operation, NULL);
    unsigned long long result = 0ULL;

    for(unsigned long long index = 0; index < ORANGE_MAX_VALUE; index ++) {
        result += orange_test.a[index] + orange_test.b[index];
    }
    
    pthread_join(apple_thread, NULL);
    return 0;
}