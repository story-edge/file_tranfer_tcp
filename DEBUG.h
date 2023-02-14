

#ifndef FILE_DEBUG_H
#define FILE_DEBUG_H

#define DEBUG_INFO(args...) do{ \
    char b__[1024];              \
    sprintf(b__,args);           \
    fprintf(stderr,"[%s,%s,%d]: %s\n",__FILE__,__FUNCTION__,__LINE__,b__); \
}while (0)

#endif //FILE_DEBUG_H
