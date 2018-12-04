/*************************************************************************
  > File Name: lxl_rename.c
  > Author: Lin
  > Mail: 1010361011@qq.com
  > Created Time: Mon Dec  3 13:52:46 2018
 ************************************************************************/

#include "lxl_misc.h"



char *source_name = NULL;
char *dest_name = NULL;
char *first_match = NULL;
char *last_match = NULL;

void rename_exit();

int main(int argc, char **argv)
{

    FILE *fs = NULL,*fd = NULL;
    int32_t count_bit = 0, fun_stat = -1;
    char buffer_source[1024] = {0};
    char *p_first = NULL,*p_last = NULL;    

    fun_stat = lxl_getopt_long(argc,argv);

    if (fun_stat == 0)
    {

        if((fs = fopen(source_name,"r+")) == NULL)
            goto out;
        if ((fd = fopen(dest_name,"w")) == NULL)
            goto out;
    }


    while(NULL != fgets(buffer_source,1024,fs))
    {

        printf("buffer:%s",buffer_source);

        p_first = strstr(buffer_source,first_match);
        p_last  = strstr(buffer_source,last_match);
        if((p_last != NULL) && (p_last[ 1 + strlen(last_match)] != '\n'))
        {
            p_last[4]= '\n';
            p_last[5]= '\0';
        }
        if(p_first != NULL)
        {
            printf("strstr:%s\n",p_first);
            fwrite(p_first,strlen(p_first),1,fd);
        }
    }



out:
    if(fd != NULL)
        fclose(fd);
    if(fs != NULL)
        fclose(fs);

    rename_exit();

    return 0;
}


void rename_exit()
{

    if(source_name != NULL)
        free(source_name);

    if(dest_name != NULL)
        free(dest_name);

    if(first_match != NULL)
        free(first_match);

    if(last_match != NULL)
        free(last_match);

}
