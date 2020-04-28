#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <common_hdr.h>

#define STR_SIZE 100 

#include <unistd.h>
// 截断文件，若文件当前长度大于length，丢弃超出部分，若小于则填充空字节或者文件空洞（hole）
// Both return 0 on success, or -1 on error
int truncate(const char *pathname, off_t length);
int ftruncate(int fd, off_t length);

int
main(int argc, char *argv[])
{
    int fd;
    struct iovec iov[3];
    struct stat myStruct; /* first buffer */
    int x;                /* second buffer */
    char str[STR_SIZE];   /* third buffer */
    ssize_t numRead, totRequired;

    if (argc != 2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s file \n", argv[0]);
    
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        errExit("open");
    
    totRequired = 0;
    iov[0].iov_base = &myStruct;
    iov[0].iov_len = sizeof(struct stat);
    totRequired += iov[0].iov_len;

    iov[1].iov_base = &x;
    iov[1].iov_len = sizeof(x);
    totRequired += iov[1].iov_len;

    iov[2].iov_base = str;
    iov[2].iov_len = STR_SIZE;
    totRequired += iov[2].iov_len;

    numRead = readv(fd, iov, 3);
    if (numRead == -1)
        errExit("readv");
    if(numRead < totRequired)
        printf("Read fewer bytes than requested\n");
    printf("total bytes requestd: %ld; bytes read: %ld\n", (long)totRequired, (long)numRead);

    exit(EXIT_SUCCESS);
}