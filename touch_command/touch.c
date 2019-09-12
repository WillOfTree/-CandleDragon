#include <stdio.h>
// open����
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
//

#define CH_ATIME 1
#define CH_MTIME 2

// ���崴���ļ�ģʽ����ʱ���û����飬�������õ�Ȩ�޶��ǿɶ���д
#define MODE_RW_UGO (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

static int change_times;
static int no_create;

struct timespec {
    time_t tv_sec; // ��
    long tv_nsec; //����
};
// ����timespec��������
static struct timespec newtime[2];

int main(int args, char **argv)
{
    int c;
    change_times = 0; // ��ʼ��ֵ�����ں�CH_ATIME��������
    no_create = 0; // ��ʶ�Ƿ񴴽��ļ�

    // �����������
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
��Ҫ���еĳ���
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
            // ���change_times == CH_MTIME���ȣ�-m����Ӧ���޸�access time
            // ��timespec�ṹ��tv_nsec����ΪUTIME_OMIT,
            newtime[0].tv_nsec = UTIME_OMIT;
        }
        else
        {
            // ���change_times == CH_MTIME������-a��,����Ӧ���޸�modify time
            // ��timespec�ṹ��tv_nsec����ΪUTIME_OMIT;�ο�utimensat�������÷�
            newtime[1].tv_nsec = UTIME_OMIT;
        }
    }
    // �޸�ʱ��
    a = utimensat(AT_FDCWD, file, newtime, 0);
    return a;
}
*/
