#include <iostream>
#include <cstring>


using namespace std;


class ZooAnimal
{
private:
    char *name;
    int cageNumber;
    int weightDate;
    int weight;
public:
    void Create(char * N, int CageNum, int Wd, int W)
    {
        this->name = N;
        this->cageNumber = CageNum;
        this->weightDate = Wd;
        this->weight = W;
    }
    void Print()
    {
        cout << this->name << " " << this->cageNumber << " " << this->weightDate << " " << this->weight << endl;
    }
    void Destroy (); // destroy function
    char* reptName ();
    int daysSinceLastWeighed (int today)
    {
        int startday, thisday;
        thisday = today/100*30 + today - today/100*100;
        startday = weightDate/100*30 + weightDate - weightDate/100*100;
        if (thisday < startday)
            thisday += 360;
        return (thisday-startday);
    }
};

void ZooAnimal::Destroy ()
{
    delete [] name;
}

// -------- member function to return the animal's name
char* ZooAnimal::reptName ()
{
    return name;
}


int main()
{
    ZooAnimal za;
    za.Create("Dog", 15, 120,60);
    za.Print();
    cout << za.daysSinceLastWeighed(170) << endl;

    ZooAnimal bozo;
    bozo.Create ("Bozo", 408, 1027, 400);
    cout << "This animal's name is " << bozo.reptName() << endl;

    return 0;

}
