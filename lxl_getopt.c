/*************************************************************************
	> File Name: lxl_getopt.c
	> Author: Lin
	> Mail: 1010361011@qq.com
	> Created Time: Mon 03 Dec 2018 03:31:08 PM CST
 ************************************************************************/
#include "lxl_misc.h"
#include <getopt.h>

static struct option long_option[] = 
{
    {"help"     , 0, NULL, 'h'},
    {"version"  , 0, NULL, 'v'}
};

static const char * help_message = "-s source file \n" \
                            "-d destination file \n" \
                            "-f the first match string \n" \
                            "-l the last match string\n";
static const char * version_message = "0.0.1\n";
static const char * invalid_message = "invalid message\n";


extern char *source_name;
extern char *dest_name;
extern char *first_match;
extern char *last_match;


int lxl_getopt_long(int argc,char * const argv[])
{

    int32_t c;
    int32_t fun_stat = 0;

    while((c = getopt_long(argc, argv, "s:d:f:l:hv", long_option,NULL)) != -1)
    {
        switch (c)
        {
            case 's':
                source_name = strdup(optarg);
                if (source_name == NULL)
                    goto out;
                printf("source file name:%s\n",source_name);
                break;
            case 'd':
                dest_name = strdup(optarg);
                
                if(dest_name == NULL)
                    goto out;
                printf("output destination file name:%s\n",dest_name);

                break;
            case 'f':
                first_match = strdup(optarg);

                if(first_match == NULL)
                    goto out;

                printf("first match string:%s\n",first_match);
                break;
            case 'l':
                last_match = strdup(optarg);

                if(last_match == NULL)
                    goto out;
                printf("second match string:%s\n",optarg);
                break;
            case 'h':
                printf("%s",help_message);
                break;
            case 'v':
                printf("%s",version_message);
                break;
            default:
                goto out;
                printf("%s",invalid_message);
                break;
        }
    }


    return fun_stat;
out:

    fun_stat = -1;

    return fun_stat;
}


#ifdef _MAIN
int main (int argc, char *argv[])
{
    return lxl_getopt_long(argc,argv);
}
#endif
