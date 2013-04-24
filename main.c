#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#define input_buf_size 85
#define SIZE( x ) (sizeof( x )/sizeof( *x ))


typedef struct student {
    char name[100];
    char surname[100];
    char facul[100];
    char specialty[100];
    char group[50];
    int marks[50];
    int total_marks;
    float pts;
} student;

int my_menu(void)
{
    char s[input_buf_size];
    int N;
    

    printf("\n=> 1 <= Enter student data");
    printf("\n=> 2 <= Look primed student");
    printf("\n=> 3 <= Exit");
    do {
        printf("\nEnter your choise: ");
        my_gets(s, input_buf_size);
	printf("\n");
        N=atoi(s);
    }
    while(0 > N || N > 3);
    return N;


}


int facu_sort(student * st_inf, int num_of_students,char *faculty)
{
int i ;
    for (i = 0; i < num_of_students; i++){
        if (!strcmp(faculty, st_inf[i].facul)){
            return 1;
		}
    
	}
    return 0;
}


int info_enter(struct student *st_inf,int num_of_students,int max_number_of_students)
{
    int j;
    char input_buffer[input_buf_size];
    int max_marks = 5;
    int name_size = SIZE (st_inf[num_of_students].name);
    int surname_size = SIZE(st_inf[num_of_students].surname);
    int facul_size = SIZE(st_inf[num_of_students].facul);
    int specialty_size = SIZE(st_inf[num_of_students].specialty);
    char group_size = SIZE(st_inf[num_of_students].group);
    int mark;
    
    if (num_of_students > max_number_of_students) {
        printf("\nMax number of students (%d) reached",max_number_of_students);
        return num_of_students;
    }
    
    printf("\nEnter the name of the student: ");
    my_gets(st_inf[num_of_students].name,name_size);

    printf("\nEnter the surname of the student: ");
    my_gets(st_inf[num_of_students].surname, surname_size);

    printf("\nEnter the name of the faculty: ");

    my_gets(st_inf[num_of_students].facul, facul_size);

    printf("\nEnter the name of the specialty student: ");
    my_gets(st_inf[num_of_students].specialty, specialty_size);

    printf("\nEnter a group of student: ");
    my_gets(st_inf[num_of_students].group, group_size);

    st_inf[num_of_students].total_marks = max_marks;
    
    for (j = 0; j < max_marks; j++) {
        printf("Enter mark number %d:\n", j+1);
        my_gets(input_buffer, input_buf_size);
	mark=atoi(input_buffer);

	if (mark<0 || mark>5) {
	     printf("ERROR! Please enter number 1-5 !\n");
             j--;
	}
	
        st_inf[num_of_students].marks[j] = mark;
}
    num_of_students++;
    return num_of_students;


}


int premia(student current_student)
{
    int i;
    for (i = 0; i <5; i++) {
        if (current_student.marks[i] < 4){
            return 0;
		}
    }
  return 1;
}


void watch_info(struct student *st_inf, int num_of_students)
{
    int i, j;
        printf("Premialist :\n");
	for(i = 0; i < num_of_students; i++){
		if(i==0){
			printf("Faculty %s:\n", st_inf[i].facul);
		}
		else{
			if((strcmp(st_inf[i].facul,st_inf[i-1].facul)!=0)){
				printf("Faculty %s:\n", st_inf[i].facul);
			}
		}
        for(j = 0; j < num_of_students; j++) {
			if((strcmp(st_inf[i].facul,st_inf[i-1].facul)==0))
				break;
            if((strcmp(st_inf[j].facul,st_inf[i].facul)==0)){
				if (premia(st_inf[j])){
					printf("%s %s\n", st_inf[j].surname, st_inf[j].name);
				}
			}
		}
	}
}


int sort_f(const void *a, const void *b)
{
    const struct student *k = (const struct student *) a;
    const struct student *m = (const struct student *) b;
    return (strcmp(k->facul, m->facul));
}

int main()
{
int num_of_students=0;
    struct student st_inf[150];
    char choise;
    while (1) {
	choise = my_menu();
	switch (choise) {
	case 1:	    
            num_of_students = info_enter(st_inf,num_of_students,(sizeof(st_inf)/sizeof(st_inf[0])));
            break;
	case 2:	    
            qsort(st_inf, num_of_students, sizeof(struct student), sort_f);
            watch_info(st_inf, num_of_students);
            break;
	case 3:
	    exit(0);
	    break;
	}
    }
}



















