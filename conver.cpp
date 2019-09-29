#include <iconv.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char* code_convert(char *source_charset, char *to_charset, char* sourceStr)
{
    /*1.iconv_t句柄*/
    iconv_t handle = iconv_open(to_charset, source_charset);
    if(NULL == handle)
    {
        printf("handle error! \n");
        return -1;
    }

    char outbuf[255];
    memset(outbuf,0,sizeof(outbuf));
    char *poutbuf = outbuf;

    size_t inlen = sizeof(sourceStr);
    size_t outlen = 255;

    /*2.转换*/
    if(iconv(handle,&sourceStr,&inlen,&poutbuf,&outlen) == -1)
    {
        printf("iconv error!\n");
        return -2;
    }

    /*3.关闭句柄*/
    iconv_close(handle);

    return poutbuf;

}

int main(int argc,char* argv[])
{

#if 0
    if(argc != 4)
    {
        printf("input param invalid！\n");
        exit(-1);
    }

    char *to_charset = argv[1];
    char *source_charset = argv[2];
    char* sourceStr = argv[3];
#endif


    char *result = code_convert("utf-8","gbk","你好");

    printf("conver finally:[%s]\n",result);
    //printf("conver from [%s] to [%s],finally:[%s]\n",argv[2],argv[1],result);

    return 0;
}


