#ifndef FIO_H
#define FIO_H
#include <fstream>
#include <ostream>
using namespace std;

class fio {
private:
    char* fam;
    char* name;
    char* father;
    static int count;

public:
    fio();
    fio(const char* fam, const char* name, const char* father);
    fio(const fio& other);
    ~fio();

    char* getFam();
    char* getName();
    char* getFather();

    void setFam(const char* fam);
    void setName(const char* name);
    void setFather(const char* father);

    static int getCount();
    fio& operator=(const fio& other);
    bool operator==(const fio& other);
    friend ostream& operator<<(ostream& os, fio info);
    void save(ofstream & file);
};

#endif