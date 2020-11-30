#include <iostream>

using namespace std;

enum scale {ounces, kilograms};

class ZooAnimal
{
private:
    char *name;
    int cageNumber;
    int weightDate;
    int weight;
    ZooAnimal *mother;
public:
    void Create (char*, int, int, int); // create function
    void Destroy (); // destroy function
    void changeWeight (int pounds);
    inline void changeWeightDate (int today){ this->weightDate = today; }
    char* reptName ();
    int reptWeight ();
    void reptWeight (scale which);
    inline int reptWeightDate ();
    int daysSinceLastWeighed (int today);
    void isMotherOf (ZooAnimal& mother) {this->mother=&mother;}
};


void ZooAnimal::Create(char * N, int CageNum, int Wd, int W)
{
    this->name = N;
    this->cageNumber = CageNum;
    this->weightDate = Wd;
    this->weight = W;
}

inline int ZooAnimal::reptWeightDate()
{
    return this->weightDate;
}

char* ZooAnimal::reptName ()
{
    return name;
}

int main()
{
    ZooAnimal child_gorilla, mother_gorilla;
    child_gorilla.Create("princess", 123, 10, 30);
    mother_gorilla.Create("sarah", 503, 80, 130);
    child_gorilla.isMotherOf(mother_gorilla);

    cout << "princess's weightDate : " << child_gorilla.reptWeightDate() << endl;
    cout << "the mother of princess's name is:" << mother_gorilla.reptName() << endl;

}

