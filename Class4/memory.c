#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    // // test
    // int *x = malloc( 3 * sizeof(int));
    // x[0] = 72;
    // x[1] = 73;
    // x[2] = 33;

    // return 0;

    // valgrind ./memory
    // 会指出内存泄漏的位置
    // 泄漏发生在 memory.c 文件的第 6 行。
    // 具体信息如下：
    //     泄漏大小：12 bytes
    //     分配位置：memory.c:6 中的 malloc 调用
    //     问题：程序结束前没有释放这块内存（总分配 1 次，释放 0 次）

    int *x = malloc(3 * sizeof(int));
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;
    free(x);
}
