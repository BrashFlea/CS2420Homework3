#include "MemberDO.h"
#include <iostream>
#include <fstream>

using namespace std;

MemberDO::MemberDO()
{
	this->key;
	this->lastName;
	this->firstInit;
	this->dues = 0.00;
	
}

MemberDO::MemberDO(int k, string ln, char fi, double d)
{
	this->key = k;
	this->lastName = ln;
	this->firstInit = fi;
	this->dues = d;
}

int MemberDO::getKey() const
{
	return key;
}

void MemberDO::setKey(int k)
{
	this->key = k;
}

string MemberDO::getLastName() const
{
	return lastName;
}

void MemberDO::setLastName(string ln)
{
	this->lastName = ln;
}

char MemberDO::getFirstInitial() const
{
	return this->firstInit;
}

void MemberDO::setFirstInitial(char fi)
{
	this->firstInit = fi;
}

double MemberDO::getDues() const
{
	return dues;
}

void MemberDO::setDues(double d)
{
	this->dues = d;
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

