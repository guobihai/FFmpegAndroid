//
// Created by frank on 2018/2/3.
//

#ifndef PACKET_QUEUE_H
#define PACKET_QUEUE_H

#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct AVPacketQueue {
    //the size of queue
    int size;
    //packet array
    void **packets;
    //the packet next to write
    int next_to_write;
    //the packet next to read
    int next_to_read;
} AVPacketQueue;

AVPacketQueue *queue_init(int size);

void queue_free(AVPacketQueue *queue);

void *queue_push(AVPacketQueue *queue, pthread_mutex_t *mutex, pthread_cond_t *cond);

void *queue_pop(AVPacketQueue *queue, pthread_mutex_t *mutex, pthread_cond_t *cond);

#endif //PACKET_QUEUE_H

#ifdef __cplusplus
}
#endif