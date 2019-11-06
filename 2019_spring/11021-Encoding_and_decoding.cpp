#define DEBUG
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>


using namespace std;

char alpha[] = {"0ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

class Codec {
public:
    virtual void encode() = 0;
    virtual void decode() = 0;
    virtual ~Codec() { } // Do nothing
    virtual void show(std::ostream& os) const = 0;
    virtual bool is_encoded() const = 0;
};

class DummyCodec: public Codec {
public:
    DummyCodec(std::string s): encoded{false}, code_str{s} { }

    void encode() {
        encoded = true;
    }

    void decode() {
        encoded = false;
    }

    void show(std::ostream& os) const {
        os << code_str;
    }

    bool is_encoded() const { return encoded; }

private:
    bool encoded;
    std::string code_str;
};

class RleCodec: public Codec
{
public:
    RleCodec(std::string s): encoded{false}, code_str{s} { }


    void encode();

    void decode();

    void show(std::ostream& os) const {
        os << code_str;
    }

    bool is_encoded() const { return encoded; }


private:
    bool encoded;
    std::string code_str;
};



std::ostream& operator<<(std::ostream& os, Codec& data)
{
    data.show(os);
    return os;
}

void encode_decode(Codec & data)
{
    if (!data.is_encoded())
        data.encode();
    else
        data.decode();
}


int main()
{
    #ifdef DEBUG
    freopen ("in.in", "r", stdin);
    #endif

    std::string input_string;
    std::cin >> input_string;

    DummyCodec dummy{input_string};
    encode_decode(dummy);
    std::cout << "Dummy encoding: ";
    std::cout << dummy << std::endl;
    encode_decode(dummy);
    std::cout << "Dummy decoding: ";
    std::cout << dummy << std::endl;

    RleCodec rle{input_string};
    encode_decode(rle);
    std::cout << "RLE encoding: ";
    std::cout << rle << std::endl;
    encode_decode(rle);
    std::cout << "RLE decoding: ";
    std::cout << rle << std::endl;
}

/*
    below are what you need to submit
    and you need to notice that 
    char alpha [] is at the begin of this code 
    when submit , you also need to copy char alpha[]
*/

void RleCodec::encode()
{
    std::stringstream os;
    char compare = '1';
    int cnt = 0;
    for (auto c : code_str) {
        
        if (compare == '1') {
            compare = c;
            cnt = 1;
        }
        else if (c == compare) {
            cnt++;
        }
        else {
            // think about cnt = 237465
            // so need to use for loop 
            
            if (cnt >= 27) {
                for (int i = 0; i < cnt/26; ++i) {
                    os << 'Q';
                    os << alpha[26] << compare;
                }
                os << 'Q' << alpha[cnt%26] << compare;
            }
            else {
                os << 'Q';
                os << alpha[cnt];
                os << compare;
            } 
            cnt = 1;
            compare = c;
        }
    }
    if (cnt >= 27) {
        for (int i = 0; i < cnt/26; ++i) {
            os << 'Q';
            os << alpha[26] << compare;
        }
        os << 'Q' << alpha[cnt%26] << compare;
    }
    else {
        os << 'Q';
        os << alpha[cnt];
        os << compare;
    } 


    code_str = os.str();
    encoded = true;
}

void RleCodec::decode()
{
    std::stringstream os;
    std::string int_str;
    char q = 'A';
    char number = ' ';
    int cnt = 0;
    for (auto c : code_str) {
        // QCA
        if (q=='A') { // Q
            q = c;
        }else if(number == ' '){ // C
            number = c;
        }
        else { // A
            int_str.push_back(c);
            int cnt = 0;
            cnt = number - 'A' +1;
            for (int i=0; i<cnt; ++i)
                    os << c;
            int_str.clear();
            number = ' ';
            q = 'A';
        }
    }

    code_str = os.str();
    encoded = false;
}


