#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define input_buf_size 80
#define SIZE( x ) (sizeof( x )/sizeof( *x ))

char *gets_s(char *s, size_t buf_size)
{
    char *result;
    result = fgets(s, buf_size, stdin);
    result[strlen(s) - 1] = '\0';
    return result;
}

typedef struct student {
    char name[100];
    char surname[100];
    char facaul[100];
    char spec[100];
    int group[50];
    int marks[50];
} stud;

int prog_menu(void)
{
    char s[input_buf_size];
    int N;
    

    printf("=> 1 <= Enter student data");
    printf("=> 2 <= Look primed student");
    printf("=> 3 <= Exit");
    do {
        printf("Enter your choise");
        gets_s(s, input_buf_size);
        c=atoi(s);
    }
    while(0 > c || c > 3)
    return c;


}


int main()
{


    printf("Hello world");

}

end.
