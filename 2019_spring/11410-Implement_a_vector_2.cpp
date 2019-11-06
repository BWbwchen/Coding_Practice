#define DEBUG
#include <bits/stdc++.h>

namespace oj
{
	typedef int data_t;

	class Vector
	{
		data_t *begin_;	//begin of array
		data_t *end_;	//end of array
		data_t *last_;	//end of current element
	public:
		Vector();
		
		std::size_t capacity() const;
		std::size_t size() const;
		
		//ignore the keyword "inline"
		//operator[] makes Vector like a C-array, for example
		//int a[2]{2,1};
		//Vector vec;
		//vec.push_back(1);
		//vec.push_back(2);
		//vec[0] is equal to a[1]
		//vec[1] is equal to a[0]
		inline data_t& operator[](const std::size_t pos)
		{
			return begin_[pos];
		}
		inline const data_t& operator[](const std::size_t pos) const
		{
			return begin_[pos];
		}
		
		void pop_back();
		void push_back(data_t val);
		void insert(std::size_t pos,std::size_t count,data_t val);
		
		void reserve(std::size_t new_capacity);
		void resize(std::size_t new_size);
		
		~Vector();
	};

	std::ostream& operator<<(std::ostream &os,const Vector &vec);	//for cout
}

namespace oj
{
    Vector::Vector()
    {
        begin_ = nullptr;
        last_ = nullptr;
        end_ = nullptr;
    }
		
	std::size_t Vector::capacity() const
    {
        size_t num = 0; 
        if (!begin_) return 0;
        data_t* temp = begin_;
        while (temp != end_) {
            temp++;
            num++;
        }
        return ++num;
    }

	std::size_t Vector::size() const
    {
        size_t num = 0; 
        if (begin_ == nullptr) return 0;
        if (last_ + 1 == begin_) return 0;
        data_t* temp = begin_;
        while (temp != last_) {
            temp++;
            num++;
        }
        return ++num;
    }
		
	void Vector::pop_back()
    {
        // nothing
        if (begin_ == nullptr) return;
        
        //one Node
        if (size() > 0) {
            last_ --;
        }
        else return;
    }

	void Vector::push_back(data_t val)
    {
        if (capacity() == size()) {
            //need re-allocate
            data_t index = std::max(capacity() + 1, capacity() * 3);
            data_t* temp = new data_t [index];

            //case 1 nothing
            if (begin_ == nullptr) {
                begin_ = temp;
                begin_[0] = val;
                last_ = begin_;
                end_ = begin_ ;
            }
            //case 2 re-allocate
            else {
                data_t old_size = size();
                
                //copy old data
                for (int i = 0; i < old_size; ++i) temp[i] = begin_[i];
                temp[old_size] = val;
                // re-direct pointer
                data_t* old = begin_;
                begin_ = temp;
                last_ = begin_ + old_size;
                end_ = begin_ + index - 1;
                delete [] old;
            }
            //delete [] temp;
        }
        else {
            *(last_ + 1) = val;
            last_ ++;
        }
    }
    /*insert: inserts elements 
        (If there is no capacity for new elements, 
        the new capacity is 
        max (old capacity + old capacity / 2, old capacity + count of inserting elements).)
        (If a vector has two elements, inserting three elements at position two means push back three times.) 
	*/
    void Vector::insert(std::size_t pos, std::size_t count, data_t val)
    {    
        if (pos > size()) {
            //std::cout << "QQ\n";
            return ;
        }
        if (capacity() <= size() + count) {
            data_t index = std::max(capacity() + capacity()/2, capacity() + count);
            data_t* temp = new data_t [index];
            if (begin_ == nullptr) {
                for (size_t i = 0; i < count; ++i) {
                    temp[i] = val;
                }
                begin_ = temp;
                last_ = begin_ + count - 1 ;
                end_ = begin_ + index - 1;
            }
            else {
                data_t s = size();
                data_t big = std::max(pos+count, size());
                for (size_t i = 0; i < pos; ++i) temp[i] = begin_[i];
                for (size_t i = pos; i < pos + count; ++i) temp[i] = val;
                for (size_t i = pos+count; i < s + count; ++i) temp[i] = begin_[i - count];
                data_t* old = begin_;
                begin_ = temp;
                last_ = begin_ + count + s - 1;
                end_ = begin_ + index - 1;
                delete [] old;
            }
            //delete [] temp;
        }
        else {
            data_t *temp = new data_t [capacity()];
            data_t s = size();
            for (size_t i = 0; i < s; ++i) temp[i] = begin_[i]; 
            for (size_t i = pos; i < pos + count; ++i) begin_[i] = val;
            for (size_t i = pos+count; i < s + count; ++i) begin_[i] = temp[i - count];
            last_ = begin_ + s + count - 1;
            delete [] temp;
        }
    }
    /*
        reserve: reserves storage 
        Increase the capacity of the container to a value that's equal to new capacity.
        If new capacity is greater than the current capacity, new storage is allocated,
        otherwise the method does nothing.
    */
	void Vector::reserve(std::size_t new_capacity)
    {
        if (new_capacity > capacity()) {
            data_t* temp = new data_t [new_capacity];
            if (begin_ == nullptr) {
                begin_ = temp;
                last_ = begin_ - 1;
                end_ = begin_ + new_capacity - 1;
            }
            else {
                data_t s = size();
                for (size_t i = 0; i < s; ++i) temp[i] = begin_[i];
                data_t* old = begin_;
                begin_ = temp;
                last_ = begin_ + s - 1;
                end_ = begin_ + new_capacity - 1;
                delete [] old;
            }
            //delete [] temp;
        }
        else {
            // do nothing
        }
    }
	/*
        resize: changes the number of elements stored 
        if the value of new size is greater than the value of old size,
        the value of new elements will be 0. 
        If the value of new size is greater than the value of old capacity,
        the value of new capacity will be new size.)
    */
	void Vector::resize(std::size_t new_size)
    {
        if (new_size > size()) {
            if (new_size > capacity()) {
                data_t* temp = new data_t [new_size];
                if (begin_ == nullptr) {
                    for (int i = 0; i < new_size; ++i) temp[i] = 0;
                    begin_ = temp;
                    last_ = begin_ + new_size - 1;
                    end_ = begin_ + new_size - 1;
                }
                else {
                    int s  = size();
                    for (size_t i =0; i < s; ++i) temp[i] = begin_[i];
                    for (size_t i = s; i < new_size; ++i) temp[i] = 0;
                    data_t* old = begin_;
                    begin_ = temp;
                    last_ = begin_ + new_size - 1;
                    end_ = begin_ + new_size - 1;
                    delete [] old;
                }
                //delete [] temp;
            }
            else {
                data_t add = new_size - size();
                for (size_t i = 1; i <= add; ++i) last_[i] = 0;
                last_ += add;
            }
        }
        else if (new_size < size()) {
            data_t sub = size() - new_size;
            for (int i = 0; i < sub; ++i) {
                //std::cout << "test\n";
                --last_;
            }
        }
        else return;
        
        
    }
		
	Vector::~Vector()
    {
        if (begin_ != nullptr) delete [] begin_;
    }


	std::ostream& operator<<(std::ostream &os,const Vector &vec)
	{
		for(std::size_t i(0);i!=vec.size();++i) 
			os<<vec[i]<<' ';
        
		return os;
	}
}

int main ()
{
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif 


    using namespace std;
	{
		oj::Vector v;
		string command;

		for(oj::data_t n;cin>>command;)
		{
			if(command=="pop_back")
			{
				v.pop_back();
				cout<<v<<endl;
			}
			else if(command=="push_back")
			{
				cin>>n;
				v.push_back(n);
				cout<<v<<endl;
			}
			else if(command=="insert")
			{
				size_t pos,count;
				cin>>pos>>count>>n;
                //cout << "insert QQ\n";
				v.insert(pos,count,n);
				cout<<v<<endl;
			}
			else if(command=="capacity")
				cout<<v.capacity()<<endl;
			else if(command=="size")
				cout<<v.size()<<endl;
			else if(command=="reserve")
			{
				cin>>n;
                //cout << "reserve QQ\n";
				v.reserve(n);
				cout<<v<<endl;
			}
			else if(command=="resize")
			{
				cin>>n;
                //cout << "resize QQ\n";
				v.resize(n);
				cout<<v<<endl;
			}
		}
		cout<<v<<endl;
	}

    return 0;
}
