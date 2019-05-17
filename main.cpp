/**
 *
 * @file    TestFunctorAbstrait.cpp
 *
 * @authors M. Laporte, D. Mathieu
 *
 * @date    27/04/2010
 *
 * @version V1.0
 *
 * @brief   functor abstrait
 *
 **/
#include <string>
#include <iostream>
#include <cctype>  // ispunct(), islower(), isalpha()
                   // tolower(), toupper()
#include <cassert>

using namespace std;

namespace
{
    class ITraitCar
    {
    public:
        virtual ~ITraitCar() {}
         virtual int operator () (int caract) const = 0;
    };

    class ToLower : public ITraitCar
    {
      public :
        virtual ~ToLower (void) {}
        virtual int operator () (int caract) const
        {
            return tolower (caract);

        } // operateur()

    }; // CToLower

    class ToUpper : public ITraitCar
    {
      public :
        virtual ~ToUpper (void) {}
        virtual int operator () (int caract) const
        {
            return toupper (caract);

        } // operateur()

    }; // CToLower

    class IgnPunc : public ITraitCar
    {
      public :
        virtual ~IgnPunc (void) {}
        virtual int operator () (int caract) const
        {
            if(ispunct(caract))
                return ' ';
            else {
                return caract;
            }

        } // operateur()

    }; // CToLower

    string & moulinette (string & str, const ITraitCar & transf)
    {
        for (string::size_type i (str.size ()); i--; )
            str [i] = transf (str [i]);

        return str;

    } // moulinette()

    void testFunctor (void)
    {
        cout << "Functor abstrait : ";

        string ligne     ("azert:;,.?GFDSQ");
        string minusc    ("azert:;,.?gfdsq");
        string majusc    ("AZERT:;,.?GFDSQ");
        string sansPunct ("AZERT     GFDSQ");

        // ToDo


        assert (minusc    == moulinette (ligne, ToLower()));
        assert (majusc    == moulinette (ligne, ToUpper()));
        assert (sansPunct == moulinette (ligne, IgnPunc()));

        cout << "OK\n";

    } // testFunctor ()

} // namespace anonyme

int main (void)
{
    /*      */    testFunctor ();     /*           */

    return 0;

} // main()
