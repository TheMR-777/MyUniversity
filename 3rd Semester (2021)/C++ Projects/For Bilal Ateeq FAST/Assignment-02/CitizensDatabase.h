#ifndef CITIZENSDB_H
#define CITIZENSDB_H

#include <string>

template <class T>
class DataPipeline {
	/*	A linkedlist based queue to implement databases
		Implement additional functions as per requirement
	*/
public:
	
	DataPipeline () {

	}

	T front() {
		return T();
	}
	T back() {
		return T();
	}

	T enqueue(T) {
	}

	T dequeue() {
		return T();
	}

	bool is_empty() {
		return false;
	}
};

class AD {
	/* Implement a stack for your Alien Database operations */
public:
	AD() {

	}

	void push_roll(int value) {
		
	}

	T& top() {
		
		return ADTop;
	}

	void pop() {

	}

	bool is_empty() {
		return true;
	}

	void empty() {
		while (!is_empty()) {
			pop();
		}
	}
};


struct CBID_NODE {
	CBID_NODE *next, *previous;
};

struct CCID_NODE {
	CCND_NODE *first, *next, *previous;
};

struct CCND_NODE {
	CCND_NODE *next, *previous;
};

class Database {
    
	CBID_NODE CBID;
	CCID_NODE CCID;
	CCND_NODE CCND;
	DataPipeline dataPipeline;
    
public:
	Database(const std::T& filename,const std::T& filename1,const std::T& filename2) {
		/*
			Initialize the data from the given file and populate database
		*/
	}
    /*Return a string in following format "Name FName Gender Address Nationality Crimes(if any) Charges punishment fine number network activation_date deactivation_date status"
     Refer to test cases for further clerification*/
	T& CBID_Search_by_CNIC(int cnic) {
		
		return NULL;
	}
	T& CCID_Search_by_CNIC(int cnic) {

        return NULL;
    }
	T& CCND_Search_by_CNIC(int cnic) {
        
        return NULL;
    }

	bool updateCBIDName(T Name, int cnic) {
		/*update and return true when cnic found else return false*/
		return false;
	}

	bool updateCBIDFName(T Father_Name, int cnic) {
		/*update and return true when cnic found else return false*/
		return false;
	}

	bool updateCBIDAddress(T Address, int cnic) {
		/*update and return true when cnic found else return false*/
		return false;
	}

	bool updateCBIDNationality(T Nationality, int cnic) {
		/*update and return true when cnic found else return false*/
		return false;
	}
    bool addCrime(T cnic, T charges, T punishment, T fine){
        /*update and return true when crime found else return false*/
        return false;
    }

	bool updateCrime(T cnic, T charges, T punishment, T fine) {
		/*update and return true when crime found else return false*/
		return false;
	}

	bool deleteCrime(T cnic, T charges, T punishment, T fine) {
		/*update and return true when crime found else return false*/
		return false;
	}

	int addNumber(T cnic, T number) {
		int number;
		/*return number of cell-numbers registered on given cnic after adding this number*/
		return number;
	}

    int checkRegistred_No(T cnic){
        int number;
        /*return number of cell-numbers registered on given cnic*/
        return number;
    }

     CCND_NODE& swap(T cnic, T cnic1, T number, T number1){
        
        return CCND;
    }	

AD& declareAlien(CBID) {
/*For Implementation of this function, Refer to CBID point 'iv', CCID point 'vi' and CCND point 'vii'. Also,
write test-cases for this function yourself*/
		return top;
	}

bool verifyAlienDBUpdate(T cnic, AD, CBID){
		/*Verify that given CNIC is moved from CBID to AD, Also add test-case for this function yourself*/
	}

    int printcount(){
        int total;
        /*Print count of cell phone numbers registered on each network. For example: (Telenor= 10, Jazz= 5, Ufone= 8, Zong= 9, Total= 32)
         Return total*/
        return total;
    }
    void Display_AD(){
        /*Display data as instructed in point (xiv) of PDF*/
    }

	~Database() {
		/* deallocate and cleanup */
	}
};

#endif
