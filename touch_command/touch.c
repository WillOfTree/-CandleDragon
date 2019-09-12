#include <stdio.h>
// open函数
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
//

#define CH_ATIME 1
#define CH_MTIME 2

// 定义创建文件模式，此时对用户，组，其他设置的权限都是可读可写
#define MODE_RW_UGO (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

static int change_times;
static int no_create;

struct timespec {
    time_t tv_sec; // 秒
    long tv_nsec; //纳秒
};
// 定义timespec变量类型
static struct timespec newtime[2];

int main(int args, char **argv)
{
    int c;
    change_times = 0; // 初始化值，用于和CH_ATIME进行运算
    no_create = 0; // 标识是否创建文件

    // 解析输入参数
    while((c = getopt(args, argv, "acm")) != -1)
    {
        switch(c)
        {
        case "a":
            change_times |= CH_ATIME;
            printf("1");
            break;
        case "c":
            no_create = 1;
            printf("2");
            break;
        case "m":
            change_times |= CH_MTIME;
            printf("3");
            break;
        default:
            printf("fault option");
        }
    }
    printf("change_times:%s\n\r", change_times);

    printf("no_create:%s", no_create);



}

/*
主要运行的程序
*/
/*
int mytouch(const char * file)
{
    int fd = -1;
    int a;
    if(!no_create)
    {
        fd = open(file, O_CREAT | O_WRONLY, MODE_RW_UGO);
    }

    if (change_times != (CH_ATIME | CH_MTIME))
    {
        if (change_times == CH_MTIME)
        {
            // 如果change_times == CH_MTIME，既（-m）对应的修改access time
            // 的timespec结构的tv_nsec设置为UTIME_OMIT,
            newtime[0].tv_nsec = UTIME_OMIT;
        }
        else
        {
            // 如果change_times == CH_MTIME，即（-a）,将对应的修改modify time
            // 的timespec结构的tv_nsec设置为UTIME_OMIT;参考utimensat函数的用法
            newtime[1].tv_nsec = UTIME_OMIT;
        }
    }
    // 修改时间
    a = utimensat(AT_FDCWD, file, newtime, 0);
    return a;
}
*/
