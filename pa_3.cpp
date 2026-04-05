#include<iostream>
using namespace std;

class node{
    public:
    string name;
    double score;
    node *link;
    void set_data(string s, double score);
};

void node ::set_data(string s, double d){
    name =s;
    score =d;
}

class my_list{
    node *head, *tail;
    public:
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    int num_nodes();
    bool list_empty();
    double score_sum();
    double get_score(string t_name);
    int remove_a_node(string t_name);
};

my_list::my_list(){
    head =NULL;
    tail = NULL;

}
void my_list ::add_to_head(node t){
    node *p;
    p = new node;
    (*p) = t;
    p->link = head;
    head =p;
    if(tail==NULL){
        tail = p;
    }
}
void my_list :: add_to_tail(node t){
    node *p;
    p =new node;
    (*p) =t;

    p->link = NULL;
    if(tail!= NULL){
        tail ->link = p;

    }
    else
    head =p;
    tail =p;

}
 node my_list :: delete_from_head(){
    node temp;
    node *t;
    t=head;
    temp = *head;
    head = head ->link;
    delete t;
    return temp;
 }

 int my_list:: num_nodes(){
    node *t;
    int count =0;
    for(t=head; t!= NULL; t=t->link){
        count ++;
    }
    return count;
 }

 bool my_list ::list_empty(){
    if(head ==NULL)
    return true;
    else 
    return false;
 }

 double my_list ::score_sum(){
    node *t;
    double sum=0.0;

    for(t=head; t!=NULL; t= t->link){
        sum += t->score;
    }
    return sum;

 }

 double my_list :: get_score(string t_name){
    node *t;
    for(t=head; t !=NULL; t= t->link){
        if(t->name == t_name){
            return t->score;
        }
    }
    return -1.0;//해당 이름이 없을때

 }

int my_list :: remove_a_node(string t_name){
    node *t;
    node *prev =NULL;

    while(t!= NULL){
        if(t->name == t_name){
            if(prev ==NULL){
                head =t->link;
            }
            else prev ->link = t ->link;

            if(t->link ==NULL)
            tail = prev;
            

            delete t;
            return 1;
        }
        prev =t;
        t = t->link;
    }
    return 0;
}

