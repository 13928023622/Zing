//
// Created by genius on 18-8-10.
//

#ifndef ZING_TIMER_H
#define ZING_TIMER_H

#include "http_request.h"

#include "priority_queue.h"


#define TIMEOUT_DEFAULT 500 //ms

typedef int (*time_handler_pt)(z_http_request_t* request);

typedef struct z_timer{
    size_t key;         //标记超时时间
    int deleted;        //标记是否删除
    time_handler_pt handler; //超时处理， add时指定
    z_http_request_t* request;   //指定对应的request请求
}z_timer_t;

extern z_pq_t z_timer;
extern size_t z_current_msec;

int z_timer_init();
int z_find_timer();
void z_handle_expire_timers();
void z_add_timer(z_http_request_t* request, size_t timeout, time_handler_pt handler);
void z_del_timer(z_http_request_t* request);
int timer_comp(void *ti, void *tj);




#endif //ZING_TIMER_H
