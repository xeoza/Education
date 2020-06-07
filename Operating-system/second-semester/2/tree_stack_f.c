#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>

typedef struct stack
{
    char **arr;
    int len;
    int alloc;
    int step;
} stack;

stack* createStack(int size)
{
    stack* st = calloc(1, sizeof(stack));
    if (st == NULL)
    {
        printf("Error in calloc st!\n");
        return NULL;
    }
    
    st->alloc = size;
    st->arr = calloc(size, sizeof(char*));
    if (st->arr == NULL)
    {
        printf("Error in calloc st->arr!\n");
        return NULL;
    }
    
    for (int i = 0; i < size; i++)
    {
        st->arr[i] = calloc(PATH_MAX, sizeof(char));
        if (st->arr[i] == NULL)
        {
            printf("Error in calloc st->arr[i]! createStack().\n");
        }
    }
    
    st->len = 0;
    st->step = 2;
    
    return st;
}

void freeStack(stack* st)
{
    for (int i = 0; i < st->len; i++)
    {
        free(st->arr[i]);
    }
    free(st->arr);
    free(st);
}

int pushStack(stack *st, const char *str)
{
    strcpy(st->arr[st->len++], str);
    
    if (st->len >= st->alloc)
    {
        st->alloc *= st->step;
        st->arr = realloc(st->arr, st->alloc*sizeof(char*));
        if (st->arr == NULL)
        {
            printf("Error in realloc!\n");
            return -1;
        }
        
        for (int i = st->len; i < st->alloc; i++)
        {
            st->arr[i] = calloc(PATH_MAX, sizeof(char));
            if (st->arr[i] == NULL)
            {
                printf("Error in calloc st->arr[i]! pushStack().\n");
            }
        }
    }
    
    return 0;
}

const char* pullStack(stack *st)
{
    if (st->len == 0)
    {
        return NULL;
    }
    
    char *str = calloc(strlen(st->arr[st->len-1]), sizeof(char));
    strcpy(str, st->arr[--st->len]);
    
    return str;
}

// Программа
static int my_ftw(char*);

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Использование: ftw <начальный каталог>\n");
        return -1;
    }
    
    int ret = my_ftw(argv[1]);
    
    return ret;
}

static int my_ftw(char* pathname)
{
    struct stat statbuf;
    struct dirent * dirp;
    DIR * dp;
    int ret;
    int depth = 0;
    char* filename;
    stack *stack = createStack(25);
    
    pushStack(stack, pathname);
    
    while (stack->len > 0)
    {
        filename = (char*)pullStack(stack);
        
        if (strcmp("..",filename) == 0)
        {
            chdir("..");
            depth--;
            continue;
        }
        
        if(lstat(filename, &statbuf) < 0)
        {
            switch (errno)
            {
                case EBADF:
                    printf("Ошибка функции stat: Неверный файловый описатель filedes!\n");
                    break;
                case ENOENT:
                    printf("Ошибка функции stat с файлом %s: Компонент полного имени файла file_name не существует или полное имя является пустой строкой!\n",filename);
                    break;
                case ENOTDIR:
                    printf("Ошибка функции stat: Компонент пути не является каталогом!\n");
                    break;
                case ELOOP:
                    printf("Ошибка функции stat: Слишком высокий уровень символьных ссылок!\n");
                    break;
                case EFAULT:
                    printf("Ошибка функции stat: Некорректный адрес!\n");
                    break;
                case EACCES:
                    printf("Ошибка функции stat: Запрещен доступ!\n");
                    break;
                case ENOMEM:
                    printf("Ошибка функции stat: Недостаточно памяти в системе!\n");
                    break;
                case ENAMETOOLONG:
                    printf("Ошибка функции stat: Слишком длинное название файла!\n");
                    break;
                default:
                    break;
            }
            continue;
        }

        for (int i = 0; i < depth; ++i)
            printf("    ");
        
        if (S_ISDIR(statbuf.st_mode) == 0)
        {
            printf("%s\n",filename);
            continue;
        }
        if ((dp = opendir(filename)) == NULL)
        {
            printf("%s [Доступ закрыт]\n",filename);
            continue;
        }
        printf("%s/\n",filename);
        chdir(filename);
        depth++;
        pushStack(stack, "..");
        while ((dirp = readdir(dp)) != NULL)
        {
            if (strcmp(dirp->d_name, ".") == 0 ||
                strcmp(dirp->d_name, "..") == 0 ||
                strcmp(dirp->d_name, ".DS_Store") == 0 )
                continue;
            pushStack(stack, dirp->d_name);
        }
        if (closedir(dp) < 0)
        {
            perror("Невозможно закрыть каталог");
            break;
        }
        
    }
    
    free(filename);
    freeStack(stack);
    return ret;
}
