#include <stdbool.h>
#include <stdint.h>

typedef void (*gt_fn)();

struct gt {
  struct gt_ctx {
    uint64_t rsp;
    uint64_t r15;
    uint64_t r14;
    uint64_t r13;
    uint64_t r12;
    uint64_t rbx;
    uint64_t rbp;
  } ctx;
  enum {
    UNUSED,
    RUNNING,
    READY,
  } st;
};

void gt_init();
void gt_ret(int ret);
void gt_stop();
bool gt_yield();
void gt_go(gt_fn);
void gt_switch(struct gt_ctx*, struct gt_ctx*);
