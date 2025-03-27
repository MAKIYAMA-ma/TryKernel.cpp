#include "dummy_runtime.hpp"

extern "C" void _exit(int status) {
    while(1);  // 組み込み環境では通常ここで無限ループにします。
}

extern "C" int _kill(int pid, int sig) {
    return -1;  // 何もしない、エラー返す
}

extern "C" int _getpid() {
    return 1;  // PIDは1として返す（1は通常、最初のプロセス）
}

extern "C" void* _sbrk(int incr) {
    static unsigned char heap[1024];
    static unsigned int heap_pos = 0;
    void* prev = &heap[heap_pos];
    heap_pos += incr;
    return prev;
}
