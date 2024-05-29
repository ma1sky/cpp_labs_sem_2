#ifndef CLINIC_H
#define CLINIC_H

class clinic {
private:
    char* fam;
    char* name;
    int specialty;
    static int count;

public:
    clinic();
    clinic(int specialty, const char* fam, const char* name);
    clinic(const clinic& other);
    ~clinic();

    int getSpec();
    char* getFam();
    char* getName();
    void setFam(const char* fam);
    void setName(const char* name);
    void setSpec(const int specialty);
    void printMedic();

    static int getCount();
    clinic& operator=(const clinic& other);
    bool isSpec(int spec);
    bool isMedic(char* fam, char* name);
};

#endif