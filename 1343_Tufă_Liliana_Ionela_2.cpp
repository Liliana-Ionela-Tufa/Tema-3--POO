#include<iostream>
#include<list>
#include<exception>
using namespace std;

class Animal
{
    protected:
        string denumire;
        int ani_viata;
        bool tip;

    public:
        Animal()
        {
            denumire = "";
            ani_viata = 0;
            tip = -1;
        }

        Animal(string denumire, bool tip, int ani_viata)
        {
            this->denumire = denumire;
            this->tip = tip;
            this->ani_viata = ani_viata;
        }

        Animal(const Animal&a)
        {
            this->denumire = a.denumire;
            this->tip = a.tip;
            this->ani_viata = a.ani_viata;
        }

        virtual void afisare()
        {
            cout<<"Denumirea animalului este "<<this->denumire<<"."<<endl;
            cout<<"Acesta este un animal ";
            if (this->tip == 0)
                cout<<"salbatic.";
            else
                if(this->tip==1)
                    cout<<"domestic.";
            cout<<endl;
            cout<<"Traieste in medie "<<this->ani_viata<<" ani."<<endl;
        }

        friend istream &operator >> (istream &input, Animal &a)
        {
            cout<<"Denumire: "; input>>a.denumire;
            cout<<endl;
            cout<<"Tip animal (0-salbatic, 1-domestic): "; input>>a.tip;
            cout<<endl;
            cout<<"Numar ani:"; input>>a.ani_viata;
            cout<<endl;

            return input;
        }
        friend ostream &operator << (ostream &output, Animal &a)
        {
            a.afisare();
            return output;
        }

        Animal& operator= (const Animal &a)
        {
            this->denumire = a.denumire;
            this->tip = a.tip;
            this->ani_viata = a.ani_viata;

            return *this;
        }

            virtual ~Animal()
        {

        }


};


class Nevertebrate : public Animal
{
    public:
        Nevertebrate():Animal()
        {

        }

        Nevertebrate(string denumire, bool tip, int ani_viata):Animal(denumire, tip, ani_viata)
        {

        }

        Nevertebrate(const Nevertebrate&n ) : Animal(n)
        {

        }

        virtual void afisare()
        {
            Animal::afisare();

        }

        friend istream &operator >> (istream &input, Nevertebrate&n)
        {
            input>>(Animal&)n;
            return input;
        }

        friend ostream &operator << (ostream &output, Nevertebrate&n)
        {
            n.afisare();
            return output;
        }

        Nevertebrate& operator=(const Nevertebrate &n)
        {
            if(this!= &n)
                Animal::operator=(n);

            return *this;
        }


        virtual ~Nevertebrate()
        {

        }

};

class Vertebrate : public Animal
{
    protected:
        string alimentatie;

    public:
        Vertebrate(): Animal()
        {
            alimentatie = "";
        }

        Vertebrate (string denumire, bool tip, int ani_viata) : Animal(denumire, tip, ani_viata)
        {
            this-> alimentatie = alimentatie;
        }

        Vertebrate (const Vertebrate &v) : Animal(v)
        {
            this->alimentatie = v.alimentatie;
        }

        virtual void afisare()
        {
            Animal::afisare();
            cout<<"Se hraneste cu "<<this->alimentatie<<"."<<endl;
        }

        friend istream &operator >> (istream &input, Vertebrate&n)
        {
            input>>(Animal&)n;
            cout<<"Alimentatie: "; input>>n.alimentatie;
            cout<<endl;
            return input;
        }

        friend ostream &operator << (ostream &output, Vertebrate&n)
        {
            n.afisare();
            return output;
        }

        Vertebrate& operator=(const Vertebrate &n)
        {
            if(this!= &n)
                {
                    Animal::operator=(n);
                    this->alimentatie = n.alimentatie;
                }

            return *this;
        }


        virtual ~Vertebrate()
        {

        }

};

class Pesti : public Vertebrate
{
    protected:
        bool tip_peste;
        int lungime;
    public:
        Pesti() : Vertebrate()
        {
            tip_peste = -1;
            lungime = 0;
        }

        Pesti(string denumire, bool tip, int ani_viata) : Vertebrate(denumire, tip, ani_viata)
        {
            this->tip_peste = tip_peste;
            this->lungime = lungime;
        }

        Pesti(const Pesti&p) : Vertebrate(p)
        {
            this->tip_peste = p.tip_peste;
            this->lungime = p.lungime;
        }

        virtual void afisare()
        {
            Vertebrate::afisare();
            if(this->tip_peste==0)
                cout<<"Nu este un peste rapitor";
            else
                if(this->tip_peste==1)
                cout<<"Este rapitor";
            cout<<endl;

        }


        friend istream &operator >> (istream &input, Pesti&p)
        {
            input>>(Vertebrate&)p;
            cout<<"Tip de peste (0-nu este rapitor, 1-rapitor) "; input>>p.tip_peste;
            cout<<endl;
            return input;
        }

        friend ostream &operator << (ostream &output, Pesti&p)
        {
            p.afisare();
            return output;
        }

        Pesti& operator=(const Pesti&p)
        {
            if(this!= &p)
                {
                    Vertebrate::operator=(p);
                    this->tip_peste = p.tip_peste;
                }

            return *this;
        }


        virtual ~Pesti()
        {

        }
};
class Pasari : public Vertebrate
{
    public:
        Pasari() : Vertebrate()
        {

        }
        Pasari(string denumire, bool tip, int ani_viata) : Vertebrate(denumire, tip, ani_viata)
        {

        }

        Pasari(const Pasari&p) : Vertebrate(p)
        {

        }

        virtual void afisare()
        {
            Vertebrate::afisare();
        }

        friend istream &operator >> (istream &input, Pasari&p)
        {
            input>>(Vertebrate&)p;
            return input;
        }

        friend ostream &operator << (ostream &output, Pasari&p)
        {
            p.afisare();
            return output;
        }

        Pasari& operator=(const Pasari&p)
        {
            if(this!= &p)
                    Vertebrate::operator=(p);

            return *this;
        }
        virtual ~Pasari()
        {

        }

};

class Mamifere: public Vertebrate
{
    public:
        Mamifere() : Vertebrate()
        {

        }
        Mamifere(string denumire, bool tip, int ani_viata) : Vertebrate(denumire, tip, ani_viata)
        {

        }

        Mamifere(const Mamifere&m) : Vertebrate(m)
        {

        }

        virtual void afisare()
        {
            Vertebrate::afisare();
        }

        friend istream &operator >> (istream &input, Mamifere&m)
        {
            input>>(Vertebrate&)m;
            return input;
        }

        friend ostream &operator << (ostream &output, Mamifere&m)
        {
            m.afisare();
            return output;
        }

        Mamifere& operator=(const Mamifere&m)
        {
            if(this!= &m)
                    Vertebrate::operator=(m);

            return *this;
        }
        virtual ~Mamifere()
        {

        }

};
class Reptile : public Vertebrate
{
    public:
        Reptile() : Vertebrate()
        {

        }
        Reptile(string denumire, bool tip, int ani_viata) : Vertebrate(denumire, tip, ani_viata)
        {

        }

        Reptile(const Reptile&r) : Vertebrate(r)
        {

        }

        virtual void afisare()
        {
            Vertebrate::afisare();
        }

        friend istream &operator >> (istream &input, Reptile&r)
        {
            input>>(Vertebrate&)r;
            return input;
        }

        friend ostream &operator << (ostream &output, Reptile&r)
        {
            r.afisare();
            return output;
        }

        Reptile& operator=(const Reptile&r)
        {
            if(this!= &r)
                    Vertebrate::operator=(r);

            return *this;
        }
        virtual ~Reptile()
        {

        }

};

class Exceptie: public exception{
public:
    const char* what() const throw(){

        return "Nu puteti afisa animale deoarece lista este goala.";

    }


};
template <typename T>
class AtlasZoologic
{
    private:
        T* regn;
        int nr;
    public:
        AtlasZoologic()
        {
            regn = new T[100];
        }

        AtlasZoologic(int nr, T* regn)
        {
            regn = new T[100];
            this->nr = nr;
            for(int i=0; i<nr; i++)
                this->regn[i] = regn[i];
        }

        AtlasZoologic(const AtlasZoologic &at)
        {
            regn = new T[100];
            nr = at.nr;
            for(int i=0; i<nr; i++)
                regn[i] = at.regn[i];
        }

        ~AtlasZoologic()
        {
            delete[] regn;
        }

};

int main()
{
    list <Animal*> lista;
    int  n, tip_animal, k = 1;
    while(k==1)
    {
        cout<<"\n Apasa tasta 1 pentru a adauga animalele in lista.\n";
        cout<<"\n Apasa tasta 2 pentru a afisa animalele din lista.\n";
        cout<<"\n Apasa tasta 3 pentru a iesi din program.\n";


        int comanda;
        cin>>comanda;

        switch(comanda)
        {


        case 1:
            {
                cout<<"Numar animale:"; cin>>n;
                for(int i=0; i<n; i++)
                {
                    cout<<"Alegeti tipul animalului(1-nevertebrate, 2-pesti, 3-pasari, 4-mamifere, 5-reptile):";
                    cin>>tip_animal;
                    if(tip_animal==1)
                    {
                        Nevertebrate *x;
                        x = new Nevertebrate;
                        cin>>*x;
                        lista.push_back(x);
                    }
                    else
                        if(tip_animal==2)
                    {
                        Pesti *x;
                        x = new Pesti;
                        cin>>*x;
                        lista.push_back(x);
                    }
                    else
                        if(tip_animal==3)
                    {
                        Mamifere *x;
                        x = new Mamifere;
                        cin>>*x;
                        lista.push_back(x);
                    }
                    else
                    {
                        Reptile *x;
                        x = new Reptile;
                        cin>>*x;
                        lista.push_back(x);
                    }
                    }
                    break;
                    }

        case 2:
            {
                list <Animal*>::iterator i;

                if(lista.size()==0)
               {
                   try
                   {
                        throw Exceptie();
                   }

                   catch(const Exceptie &e)
                   {
                       cout<<e.what();
                   }
               }

                for(i=lista.begin(); i!=lista.end(); i++)
                {
                    cout<<**i<<endl;
                }

                break;
            }
        case 3:
            {
                k = 0;
                break;
            }
        default:
            {
                cout<<"\n Comanda incorecta.";
                break;
            }

        }

    }
    return 0;


}


