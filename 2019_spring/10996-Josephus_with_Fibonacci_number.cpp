#define DEBUG
#define MAXN 101
#include <bits/stdc++.h>

using namespace std;

class Josephus;

class Node
{
friend class Josephus;
public:
    Node():next( nullptr ) {};
  	Node( const int &info ) :number( info ), next( nullptr ) {};
private:
    int number;
   	Node *next;
};

class Josephus
{
public:
    Josephus();
    ~Josephus();
    Josephus(const int &);
    int kill(void ) ; // return the survival's position
private:
    void generatecircularlinkedList(const int &); // generate circular linked-list
    void generateFib(const int &); // generate a Fibonacci sequence table
    int sequence[50]; // store Fibonacci number
    int noOfPeople;
    Node *head;
};

Node *tail = nullptr;

int main (int argc, char **argv)
{
    #ifdef DEBUG
    freopen ("text.in", "r", stdin);
    #endif

    
	int numofpeople;

	while(cin>>numofpeople){
        //cout << "begin" << endl;
		Josephus Jose(numofpeople);
        //cout << "here\n";
        
		int survival = Jose.kill();
		cout<<survival<<endl;
        //cout << "end" << endl;
    }    

    return 0;
}

Josephus::Josephus() {
    head = nullptr;
}

void Josephus::generateFib(const int &num)
{
    sequence[0] = 1;
    sequence[1] = 1;
    for (int i = 2; i < num-1; ++i) {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }
}

Josephus::Josephus(const int &num) {
    this->generateFib(num);
    
    noOfPeople = num;
    int index = 0;
    head = new Node(index++);
    tail = head;
    while (index != num) {
        tail->next = new Node(index++);
        tail = tail->next;
    }
    tail->next = head;
}
Josephus::~Josephus() {
    delete head;
}

int Josephus::kill(void )
{
    Node *now = head;
    Node *pre = tail;
    int fibindex = 0;
    while ( noOfPeople > 1 ) {
        int m;
        if (sequence[fibindex]%noOfPeople == 0) m = noOfPeople;
        else m = sequence[fibindex]%noOfPeople;  
        for (int i = 1; i < m; ++i) {
            pre = pre->next;
            now = now->next;
        }
        Node *temp = now;
        pre->next = now->next;
        now = now->next;
        fibindex++;
        noOfPeople--;
        //delete temp; if add this will runtime error but i don't know why
    }
    return now->number+1;
}