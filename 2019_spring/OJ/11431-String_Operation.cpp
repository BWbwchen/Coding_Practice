#define DEBUG
#include <bits/stdc++.h>

using namespace std;


class Char{
	friend class Str;
	private:
		Char(char text):next(NULL){
			this->text=text;
		}

		~Char(){
            if(next)
                delete next;
		}

		void print(){
            cout<<text;
            if(next)
                next->print();
		}

		char text;
		Char *next;
};

class Str{
	public:
	    // construct a new Str by linked list of Char
		Str(char*);

		// copy constructor
		// have to copy all Chars of another Str
		Str(const Str &);

		// equality operator
        bool operator==( const Str & ) const;


		/** the following methods are already implemented **/
		Str():head(NULL),tail(NULL){} // default constructor

		~Str(){
            if(head)
                delete head;
		}

		Str& strInsert(const Str &s){
			Str tmp(s);

            tail->next=tmp.head;
            tail=tmp.tail;

            tmp.head=NULL;
            return *this;
		}

		Str& strSwap(Str &s){
			Str tmp(*this);
            this->~Str();

			*this=s;
            s=tmp;

            tmp.head=NULL;
			return *this;
		}

		void strPrint(){
            if(head)
                head->print();
            cout<<endl;
		}

	private:
		Char *head;
		Char *tail;
};


typedef void (*FUNC)(Str &s1,Str &s2);

const int OPnum=5;
typedef struct _OPmap{
    const char *op;
    FUNC fp;
}OPmap;

void func_si(Str &s1,Str &s2){
    s1.strSwap(s2).strInsert(s2);
}

void func_is(Str &s1,Str &s2){
    s1.strInsert(s2).strSwap(s2);
}

void func_s(Str &s1,Str &s2){
    s1.strSwap(s2);
}

void func_i(Str &s1,Str &s2){
    s1.strInsert(s2);
}

void func_t(Str &s1,Str &s2){
    if(s1==s2){
        s1.strInsert(s2);
    }else{
        s1.strSwap(s2);
    }
}

OPmap MAP[OPnum]={{"si",func_si},{"is",func_is},{"s",func_s},{"i",func_i},{"t",func_t}};

void operate(char *op,Str &s1,Str &s2){
    for(int i=0;i<OPnum;i++)
        if(strcmp(MAP[i].op,op)==0){
            MAP[i].fp(s1,s2);
            break;
        }
}




int main (int argc, char **argv)
{
    #ifdef DEBUG
    freopen ("text.in", "r", stdin);
    #endif
    

	int N;
	char input[100];

	int index=0;
	Str *s[100];

	cin>>N;
    for(int i=0;i<N;i++){
    	cin>>input;
    	s[index++]=new Str(input);
    }

    char op[3];//"si" || "is" || "s" || "i" || "t" || "e"
    while(1){
    	cin>>op;
    	if(op[0]=='e')break;

    	int idx1,idx2;
    	cin>>idx1;
    	cin>>idx2;

    	operate(op,*s[idx1],*s[idx2]);
	}

	for(int i=0;i<N;i++){
        s[i]->strPrint();
        delete s[i];
	}


    return 0;
}
/*
    below are what you need to code
*/

Str::Str(char* s)
{
    head = new Char(s[0]);

    int index = 1;

    for (tail = head; s[index] != '\0'; tail = tail->next) {
        tail->next = new Char(s[index++]);
    }
}

Str::Str(const Str& src)
{
    head = new Char(src.head->text);
    Char* temp_char = src.head->next;
    for (tail = head; temp_char != nullptr && temp_char->text != '\0' ; tail = tail->next) {
        tail->next = new Char (temp_char->text);
        temp_char = temp_char->next;
    }
}

bool Str::operator==( const Str & lhs) const 
{
    Char *A = this->head;
    Char *B = lhs.head;
    for (; A&&B; A = A->next, B = B->next) {
        if (A->text != B->text) return false;
        if (A->next == nullptr && B->next || A->next && B->next == nullptr) return false;
    }

    return true;
}