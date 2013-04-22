#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define input_buf_size 85
#define SIZE( x ) (sizeof( x )/sizeof( *x ))

char * gets_s(char *s, size_t buf_size)
{
    char *result;
    result = fgets(s, buf_size, stdin);
    result[strlen(s) - 1 ] = '\0';
    return result;
}

typedef struct student {
    char name[100];
    char surname[100];
    char facul[100];
    char specialty[100];
    int group[50];
    int marks[50];
    int total_marks;
    float pts;
} student;

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
        N=atoi(s);
    }
    while(0 > N || N > 3);
    return N;


}


int faculty_exists(student * stud_list, int num_of_students,char *faculty)
{
int i ;
    for (i = 0; i < num_of_students; i++){
        if (!strcmp(faculty, stud_list[i].facul)){
            return 1;
		}
    return 0;
	}
}


int enter_student(struct student *stud_list,int num_of_students,int max_number_of_students)
{
    int j;
    char input_buffer[input_buf_size];
    char *strtoul_end_ptr;
    int max_marks = 5;
    char s[input_buf_size];
    int name_size = SIZE (stud_list[num_of_students].name);
    int surname_size = SIZE(stud_list[num_of_students].surname);
    int facul_size = SIZE(stud_list[num_of_students].facul);
    int specialty_size = SIZE(stud_list[num_of_students].specialty);
    int group_size = SIZE(stud_list[num_of_students].group);
     
    
    if (num_of_students > max_number_of_students) {
        printf("Max number of students (%d) reached",max_number_of_students);
        return num_of_students;
    }
    
    printf("Enter the name of the student: ");
    gets_s(stud_list[num_of_students].name,name_size);

    printf("Enter the surname of the student: ");
    gets_s(stud_list[num_of_students].surname, surname_size);

    printf("Enter the name of the faculty:");

    gets_s(stud_list[num_of_students].facul, facul_size);

    printf("Enter the name of the specialty student: ");
    gets_s(stud_list[num_of_students].specialty, specialty_size);

    printf("Enter a group of student: ");
    gets_s(stud_list[num_of_students].group, group_size);

    stud_list[num_of_students].total_marks = max_marks;
    
    for (j = 0; j < max_marks; j++) {
        printf("Enter mark number %d:\n", j+1);
        gets_s(input_buffer, input_buf_size);
        stud_list[num_of_students].marks[j] = strtoul(input_buffer, &strtoul_end_ptr, 10);
}
    num_of_students++;
    return num_of_students;


}


int is_premialist(student current_student)
{
    int i;
    for (i = 0; i <5; i++) {
        if (current_student.marks[i] < 4){
            return 0;
		}
    }
  return 1;
}


void show_list(struct student *stud_list, int num_of_students)
{
    int i, j;
	for(i = 0; i < num_of_students; i++){
		if(i==0){
			printf("Faculty %s:\n", stud_list[i].facul);
            printf("Premialists:\n");
		}
		else{
			if((strcmp(stud_list[i].facul,stud_list[i-1].facul)!=0)){
				printf("Faculty %s:\n", stud_list[i].facul);
                printf("Premialists:\n");
			}
		}
        for(j = 0; j < num_of_students; j++) {
			if((strcmp(stud_list[i].facul,stud_list[i-1].facul)==0))
				break;
            if((strcmp(stud_list[j].facul,stud_list[i].facul)==0)){
				if (is_premialist(stud_list[j])){
					printf("%s\n", stud_list[j].surname);
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
    struct student stud_list[150];
    char choise;
    while (1) {
	choise = prog_menu();
	switch (choise) {
	case 1:	    
            num_of_students = enter_student(stud_list,num_of_students,(sizeof(stud_list)/sizeof(stud_list[0])));
            break;
	case 2:	    
            qsort(stud_list, num_of_students, sizeof(struct student), sort_f);
            show_list(stud_list, num_of_students);
            break;
	case 3:
	    exit(0);
	    break;
	}
    }
}



















