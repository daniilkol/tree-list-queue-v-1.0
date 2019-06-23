#include "student.h"
class student_node: public student
{
    friend class student_queue;
private:
    student_node *next;
public:
    student_node(const char*in=0,int iv=0): student(in,iv){next=0;}
    student_node(const student_node&i):student(i){next=i.next;}
    student_node&operator=(const student_node&i)
    {
        *((student*)this)=i;
        next=i.next;
        return *this;
    }
    void init(char*in=0,int iv=0)
    {
        student::init(in,iv);
        next=0;
    }
    int read (FILE *fp)
    {
        char b[1000];
        int c;
        if(fscanf(fp,"%s%d",b,&c)==2)
        {
           this->init(b,c);
        }else return -1;
        return 1;
    }
};
