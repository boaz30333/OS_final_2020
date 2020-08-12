
#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdlib.h>
#include <stdio.h>

static int
display_info(const char *fpath, const struct stat *sb, int tflag,
             struct FTW *ftwbuf)
{
    if (tflag == FTW_SL)
    {
        return 0;
    }
    else if (tflag == FTW_D)
    {
        printf("D");
    }
    else if (tflag == FTW_F)
    {
        printf("F");
    }
    printf("%ld ", (long)sb->st_ino);
    printf("%s\n", &fpath[ftwbuf->base]);
    return 0;
}
}

int main(int argc, char *argv[])
{

    if (nftw(argv[1], display_info, 20, FTW_PHYS) == -1)
    {
        perror("nftw");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}