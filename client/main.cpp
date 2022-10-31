#include <iostream>
#include <string.h>
#include <sys/errno.h>
#include <stdio.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <vector>
#include <unistd.h>
#include </home/avn/practice/Utils/mqhelper.h>

#define APPROVAL 0666

using namespace std;

mq_attr attr;
mqd_t mqdes;
char buff[1024];
unsigned int prio;
string msg;
MqHelper helper;

struct def {
    int a = 0;
    int b = 1;
};

void connect () {
    mqdes = helper.connect();
}

void *send(void*) {
        memset(buff, '\0', sizeof(buff));
        memcpy(buff, "hello", sizeof("hello"));
        connect();
        cout << buff << endl;
        while (true) {
            if (helper.send(mqdes, buff) == -1)
                perror("Logger Message: \n");
            sleep(1);
        }
}

int main() {
//    memset(buff, '\0', sizeof(buff));
//    memcpy(buff, "hello", sizeof("hello"));
//    char c;
//    c = 'a';
//    connect();
//    cout << buff << endl;
//    while (true) {
//        if (mq_send(mqdes, buff,  sizeof("hello"), 0) == -1)
//            perror("Logger Message: \n");
//        sleep(1);
//    }

    pthread_t thr;
    int r = pthread_create(&thr, NULL, send, NULL);


    int sh_des = shm_open("/my_shm", O_CREAT | O_RDWR, APPROVAL);
    if (sh_des < 0)
        perror("shm_open: ");
    ftruncate(sh_des, 4096);
    def* a;
    a = (def*) mmap(0, 4096, PROT_READ , MAP_SHARED, sh_des, 0);
    for (int i = 0; i < 5; i++) {
        cout << a[i].a << " " << a[i].b << endl;
    }
    munmap(a, 4096);
    close(sh_des);
    shm_unlink("/my_shm");
    pthread_join(thr, NULL);
    return 0;
}
