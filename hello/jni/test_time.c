#include <stdio.h>
#include <time.h>
#include <android/log.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>

static struct timespec timespec_diff(const struct timespec* end_time, const struct timespec* start_time){
    struct timespec diff;
    if (end_time->tv_nsec < start_time->tv_nsec){
        diff.tv_sec = end_time->tv_sec - start_time->tv_sec - 1;
        diff.tv_nsec = end_time->tv_nsec + 1000000000 - start_time->tv_nsec;
    }
    else{
        diff.tv_sec = end_time->tv_sec - start_time->tv_sec;
        diff.tv_nsec = end_time->tv_nsec - start_time->tv_nsec;
    }
    return diff;
    
}

static double timespec_diff_d(const struct timespec* end_time, const struct timespec* start_time)
{
    struct timespec diff = timespec_diff(end_time, start_time);
    double ms = diff.tv_sec * 1.0f * 1000 + (diff.tv_nsec * 1.0f / 1000000);
    return ms;
}

static void dump_time(const struct timespec* diff)
{
    int64_t sec = diff->tv_sec;
    int64_t nsec = diff->tv_nsec;
    int64_t ms = sec * 1000 + nsec / 1000000;
    
    double dsec = diff->tv_sec * 1.0f;
    double dnsec = diff->tv_nsec * 1.0f;
    double dms = dsec * 1000 + (dnsec / 1000000);
    
    __android_log_print(ANDROID_LOG_DEBUG, "test-time", "time:%"PRId64" ms|%f ms", ms, dms);
}

int main(){
    
    __android_log_print(ANDROID_LOG_DEBUG, "test-time", "test time v1.0.0(2016/11/15)");
    struct timespec start_time;
    struct timespec cur_time;

    start_time.tv_sec = 109126;
    start_time.tv_nsec = 287341617;
    cur_time.tv_sec = 109126;
    cur_time.tv_nsec = 322507200;
    
    struct timespec diff = timespec_diff(&cur_time, &start_time);
    uint64_t sec = diff.tv_sec;
    uint64_t nsec = diff.tv_nsec;
    uint64_t ms = sec * 1000 + (nsec / 1000000);
    uint64_t us = sec * 1000000 + (nsec / 1000);
    uint64_t ns = sec * 1000000000 + nsec;
    __android_log_print(ANDROID_LOG_DEBUG, "test-time", "time:%"PRIu64" ms, %"PRIu64" us, %"PRIu64" ns\n", ms, us, ns);
    __android_log_print(ANDROID_LOG_DEBUG, "test-time", "time:[%lu s, %lu ns], [%lu s, %lu ns],[%lu s, %lu ns]\n",
        start_time.tv_sec,
        start_time.tv_nsec,
        cur_time.tv_sec,
        cur_time.tv_nsec,
        diff.tv_sec,
        diff.tv_nsec);
    __android_log_print(ANDROID_LOG_DEBUG, "test-time", "time:%f ms\n", timespec_diff_d(&cur_time, &start_time));
    double d_ms = sec * 1.0f * 1000 + (nsec*1.0f / 1000000);
    double d_us = sec * 1.0f * 1000000 + (nsec*1.0f / 1000);
    double d_ns = sec * 1.0f * 1000000000 + nsec;
    __android_log_print(ANDROID_LOG_DEBUG, "test-time", "%f,%f,%f\n", d_ms, d_us, d_ns);
    
    diff.tv_sec = 0;
    diff.tv_nsec = 14411834;
    dump_time(&diff);
    
    
    return 0;
}