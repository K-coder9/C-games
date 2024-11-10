#include <stdio.h>

size_t my_strlen(const char *s);
size_t my_strlen_condensed(const char *s);
char *my_strcat(char *s1,const char *s2);

int main(void){
    int i =2;
    int *p=&i;
    
    printf("%p",(void*)p);


    return 0;
}

size_t my_strlen(const char *s){
    size_t n=0;
    while(*s++)
      n++;
    return n;
}

size_t my_strlen_condensed(const char *s){
    const char *p=s;
    //starts at address for s then increments until end 
    while(*s)
      s++;

    return s-p;
}

char *my_strcat(char *s1,const char *s2)
{   //*s1 is already a pointer so the pointer pe doesn't need to be assigned to &s1, p will 
    // point to the first value of s1
    char *p = s1;
    while(*p != '\0')
     p++;
    while(*s2 != '\0')
      *p = s2;
      p++;
      s2++;
    *p = '\0';
    return s1;


}