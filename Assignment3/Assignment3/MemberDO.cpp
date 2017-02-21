#include "MemberDO.h"
#include <iostream>
#include <fstream>

using namespace std;

MemberDO::MemberDO()
{
}

MemberDO::MemberDO(int k, string ln, char fi, double d)
{
}

int MemberDO::getKey() const
{
return 0;
}

void MemberDO::setKey(int k)
{
}

string MemberDO::getLastName() const
{
return "";
}

void MemberDO::setLastName(string ln)
{
}

char MemberDO::getFirstInitial() const
{
return 0;
}

void MemberDO::setFirstInitial(char fi)
{
}

double MemberDO::getDues() const
{
return 0;
}

void MemberDO::setDues(double d)
{
}

void MemberDO::print() const
{
}

void MemberDO::readFromFile(const char* file, OrderedLinkedList<MemberDO>& ll)
{

    //Delete the following implementation and replace with an implemenation that actually reads the data from the file for extra credit.
    MemberDO data;
    data.key = 6789;
    data.lastName = "Towson";
    data.firstInit = 'J';
    data.dues = 65.25;
    ll.insert(data);
    data.key = 3456;
    data.lastName = "Johns";
    data.firstInit = 'K';
    data.dues = 200.00;
    ll.insert(data);
    data.key = 1123;
    data.lastName = "Stevens";
    data.firstInit = 'M';
    data.dues = 112.35;
    ll.insert(data);
    data.key = 4489;
    data.lastName = "Ellwood";
    data.firstInit = 'B';
    data.dues = 700.25;
    ll.insert(data);
    data.key = 5555;
    data.lastName = "Pryor";
    data.firstInit = 'R';
    data.dues = 99.99;
    ll.insert(data);   
}

