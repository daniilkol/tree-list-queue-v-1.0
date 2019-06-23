#include "student_list.h"
class list_node: public student_list
{
    friend class tree;
private:
    list_node*next,*down;
    int koef;
public:
    list_node(){koef=0;next=down=0;}
    int operator<(list_node&a)
    {
        int k=get_head()<(a.get_head());
        //cout <<"k1= "<< k << endl;
        return k;
    }
    void print(int k=0)
    {
        if(!this) return;
        if(next) next->print(k);
        if(down) down->print(k+1);
        for(int i=1;i<k;i++) printf("      ");
        student_list::print();
    }
    list_node&operator=(const list_node&i)
    {
        *((student_list*)this)=i;
        next=i.next;
        down=i.down;
        return *this;
    }
    list_node* add(list_node *x)
    {
        if(!this) return x;
        if(koef<x->koef) {next=next->add(x);return this;}
        if(koef==x->koef) {x->koef=*this<*x;down=down->add(x);return this;}

        if(koef>x->koef)
        {

            x->next=this;
            return x;
        }
        return this;

    }
    list_node* get_down(){return down;}
    list_node* get_next(){return next;}
    int get_koef() const {return koef;}
    void del()
    {
        if(!this) return ;
        if(next) next->del();
        if(down) down->del();
        delete this;
    }

    int kolvoel()
    {
        int k=0;
        if(!this) return 0;
        if(next) k+=next->kolvoel();
        if(down) k+=down->kolvoel();
        return k+1;
    }
};

