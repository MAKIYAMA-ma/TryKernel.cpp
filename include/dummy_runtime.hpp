#ifndef DUMMY_RUNTIME_HPP
#define DUMMY_RUNTIME_HPP

extern "C" void _exit(int status);
extern "C" int _kill(int pid, int sig);
extern "C" int _getpid();
extern "C" void* _sbrk(int incr);

#endif
