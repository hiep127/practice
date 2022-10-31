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

struct mq_attr attr;
mqd_t mqdes;
char buff[1025];
unsigned int prio;
string msg;
MqHelper helper;

void connect () {

    mqdes = helper.connect();
}

struct def {
    int a = 0;
    int b = 1;
};

void *reic(void*) {
        memset(buff, '\0', sizeof(buff));
        while (true) {
            ssize_t res = helper.receive(mqdes, buff);
//            ssize_t res= mq_receive(mqdes, buff, 1025, 0);
//            if (res == -1 ) perror("mq_receive: ");
            if (res > 0) {
                cout << buff << endl;
            }
            //else perror("mq_receive error: ");
        }
        pthread_exit(NULL);
}

int main()
{
    connect();
    pthread_t thr;
    int r = pthread_create(&thr, NULL, reic, NULL);

//    memset(buff, '\0', sizeof(buff));
//    while (true) {
//        ssize_t res = mq_receive(mqdes, buff, 1025, &prio);
//        if (res > 0) {
//            cout << buff << endl;
//        }
//        //else perror("mq_receive error: ");
//    }

    int sh_des = shm_open("/my_shm", O_CREAT | O_RDWR, APPROVAL);
    if (sh_des < 0)
        perror("shm_open: ");
    ftruncate(sh_des, 4096);
    def* a;
    a = (def*) mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, sh_des, 0);
    for (int i = 0; i < 5; i++) {
        a[i].a = i;
        a[i].b = i;
    }
    munmap(a, 4096);
    close(sh_des);
    pthread_join(thr, NULL);
    return 0;
}
