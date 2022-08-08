#include <iostream>
#include <iomanip>
#include <chrono>
#include <sstream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <direct.h>

#define CLEAR cin.clear(); cin.sync()
#define t_CLEAR temp_s.clear(); temp_i = 0; temp_f = 0.0f
using namespace std;



enum colour { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };

struct setcolour
{
	colour _c;
	HANDLE _console_handle;


	setcolour(colour c, HANDLE console_handle)
		: _c(c), _console_handle(0)
	{
		_console_handle = console_handle;
	}
};

basic_ostream<char>& operator<<(basic_ostream<char>& s, const setcolour& ref)
{
	SetConsoleTextAttribute(ref._console_handle, ref._c);
	return s;
}

struct Subject
{
	int ID;
	string name;
	float o_marks;
	int t_marks;

	Subject() {}

	Subject( string& name, int&& t )
		: name(move(name)), t_marks(move(t)) {}
};

struct Profile
{
	int ID;
	string name;
	string roll;
	vector<Subject> subjects;
};

class Tracer
{
	Tracer() {}
	Tracer(const Tracer& any) = delete;

	uint32_t TotalAllocated = 0;
	uint32_t TotalFreed = 0;
	HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);

	static Tracer& Get()
	{
		static Tracer s_Tracer;
		return s_Tracer;
	}

	uint32_t I_CurrentUsage()
	{
		return (TotalAllocated - TotalFreed);
	}

	void I_PrintCurrentUsage()
	{
		cout << setcolour(RED, chandle) << " [ ! ] " << setcolour(DARKTEAL, chandle) << "- Currunt Allocation   : " << setcolour(RED, chandle) << TotalAllocated - TotalFreed << setcolour(DARKTEAL, chandle) << " Bytes" << endl;
		cout << setcolour(RED, chandle) << " [ ! ] " << setcolour(DARKTEAL, chandle) << "- Total Allocations    : " << setcolour(RED, chandle) << TotalAllocated << setcolour(DARKTEAL, chandle) << " Bytes" << endl;
		cout << setcolour(RED, chandle) << " [ ! ] " << setcolour(DARKTEAL, chandle) << "- Total De-Allocations : " << setcolour(RED, chandle) << TotalFreed << setcolour(DARKTEAL, chandle) << " Bytes" << endl;
	}

public:

	static uint32_t CurrentUsage()
	{
		return Get().I_CurrentUsage();
	}

	static void PrintCurrentUsage()
	{
		Get().I_PrintCurrentUsage();
	}


	friend void* operator new(size_t size);
	friend void operator delete(void* mem, size_t size);

};

void* operator new(size_t size)
{
	Tracer::Get().TotalAllocated += size;
	return malloc(size);
}

void operator delete(void* mem, size_t size)
{
	Tracer::Get().TotalFreed += size;
	free(mem);
}



static float temp_f = 0.0f;
static int temp_i = 0;
static string temp_s;
static string roll_prefix = "";
static const Subject* sub_ref;
static bool debug = 0;




namespace Utilities
{
	void Write(const vector<Subject>& sbj, const string&& filename)
	{
		ofstream o_file("Data\\" + filename);

		for (int i = 0; i < sbj.size(); i++)
		{
			o_file << sbj[i].name << endl;
			o_file << sbj[i].t_marks << endl;
		}

		o_file.close();
	}

	vector<Subject> Scan(const string&& filename)
	{
		// Initialization

			vector<string> data;
			vector<Subject> subjects;
			ifstream i_file("Data\\" + filename);

		// Scanning (Memorizing)

			while (getline(i_file, temp_s))
			{
				data.push_back(temp_s);
			}

		// Filling Subjects

			subjects.reserve( data.size() / 2 );

			for (int i = 0; i < data.size(); i += 2)
			{
				subjects.emplace_back(Subject(data[i], stoi(data[i + 1])));
			}

		// Finalization

			i_file.close();
			return subjects;
	}
	
	int no_random()
	{
		srand(time(NULL));
		return (rand() % 101);
	}

	string HighScore(const int& comp)
	{
		temp_i = 99999;
		ifstream iHS("Data\\HighScore.txt");
		iHS >> temp_i;

		if (comp < temp_i)
		{
			ofstream oHS("Data\\HighScore.txt");
			oHS << comp;

			if (oHS.is_open())
			{
				return to_string(comp);
			}
			else
			{
				return "Unable to Update High Score File";
			}
		}
		else
		{
			return to_string(temp_i);
		}
	}

	void spaces(ostream &FILE, const int size_in, const int required = 30)
	{
		int loop = required - size_in;

		for (int i = 0; i < loop; i++)
		{
			FILE << " ";
		}

	}

	size_t float_count(const float& f)
	{
		stringstream out;
		out << f;

		return out.str().length();
	}

	float Sub_Sum(const vector<Subject> &sbj, const bool&& op)
	{
		float sum = 0;

		if (op == 0)
		{
			for (int i = 0; i < sbj.size(); i++)
			{
				sum += sbj[i].o_marks;
			}
			return sum;
		}
		else
		{
			for (int i = 0; i < sbj.size(); i++)
			{
				sum += sbj[i].t_marks;
			}
			return sum;
		}

	}

	float PT_AGE(const float obt, const float& total)
	{
		// return ((obt * 100) / total);
		return ((float)(int)((((obt * 100) / total)) * 100)) / 100;
	}

	void sort(vector<Profile> &students, const int&& op, const int& i = 0)
	{
		// Key for Operation
		// 1 for General List
		// 2 for Student Wise
		// 3 for Subject Wise

		int replacer;
		vector<float> receptor;

		switch (op)
		{
		case 1:
		{
			for (int i = 0; i < students.size(); i++)
			{
				receptor.push_back(Utilities::Sub_Sum(students[i].subjects, false));
			}

			for (int i = 0; i < (receptor.size() - 1); i++)
			{
				for (int j = (i + 1); j < receptor.size(); j++)
				{
					if (receptor[j] > receptor[i])
					{
						replacer = receptor[j];
						receptor[j] = receptor[i];
						receptor[i] = replacer;

						replacer = students[j].ID;
						students[j].ID = students[i].ID;
						students[i].ID = replacer;
					}
				}
			}

			break;
		}

		case 2:
		{
			for (int i = 0; i < students.size(); i++)
			{
				for (int j = 0; j < students[i].subjects.size(); j++)
				{
					receptor.push_back(students[i].subjects[j].o_marks);
				}

				for (int j = 0; j < (receptor.size() - 1); j++)
				{
					for (int k = (j + 1); k < receptor.size(); k++)
					{
						if (receptor[k] > receptor[j])
						{
							replacer = receptor[k];
							receptor[k] = receptor[j];
							receptor[j] = replacer;

							replacer = students[i].subjects[k].ID;
							students[i].subjects[k].ID = students[i].subjects[j].ID;
							students[i].subjects[j].ID = replacer;
						}
					}
				}
				receptor.clear();
			}
			break;
		}

		case 3:
		{
			for (int j = 0; j < students.size(); j++)
			{
				receptor.push_back(students[j].subjects[i].o_marks);
			}

			for (int j = 0; j < (receptor.size() - 1); j++)
			{
				for (int k = (j + 1); k < receptor.size(); k++)
				{
					if (receptor[k] > receptor[j])
					{
						replacer = receptor[k];
						receptor[k] = receptor[j];
						receptor[j] = replacer;

						replacer = students[k].ID;
						students[k].ID = students[j].ID;
						students[j].ID = replacer;
					}
				}
			}
			receptor.clear();
			break;
		}
		}
	}
}

namespace Result_External
{
	void Result_Gen(const vector<Profile> &students)
	{
		// Initializing Temporary Stuff

			_mkdir("Data\\General List");
			ofstream General_File("Data\\General List\\General_List.txt");
			t_CLEAR;
			float flt_o, flt_t;

		if ( !General_File.is_open() )
		{
			cout << "Couldn't write the External file. Possible fixes:" << endl;
			cout << " - Try running the Program as Administrator" << endl;
			cout << " - Check the directory is writable" << endl;
			cout << " - Check for special characters in the Path of current directory" << endl;
			cout << "   If there exist, change the path of the Program" << endl;
			cout << " - If none of them works, try changing the directory of the Program" << endl;
		}
		else
		{
			cout << " +-------------------------------------------------------------+" << endl;
			cout << " | [ OK ]        List(s) Generated!                            |" << endl;
			cout << " +-------------------------------------------------------------+" << endl;
		}


		// Result Card

		General_File << endl;
		General_File << " +----------------------------------------------------------------------------------------------------+" << endl;
		General_File << " | General List for all Students                                                       ////////////// |" << endl;
		General_File << " +----------------------------------------------------------------------------------------------------+" << endl;
		General_File << " | Names of Students" << "             " << "Obtained Marks" << "   " << "From (Marks)" << "     " << "%age" << "      " << "Roll_Number" << "              |" << endl;
		General_File << " |                                                                                                    |" << endl;

		for (int i = 0; i < students.size(); i++)
		{
			// Name Generation

			General_File << " | " << students[students[i].ID].name;
			Utilities::spaces(General_File, students[students[i].ID].name.size());

			// Obtained Marks

			flt_o = Utilities::Sub_Sum(students[students[i].ID].subjects, false);
			General_File << flt_o;
			Utilities::spaces(General_File, Utilities::float_count(flt_o), 17);

			// Total Marks

			flt_t = Utilities::Sub_Sum(students[students[i].ID].subjects, true);
			General_File << flt_t;
			Utilities::spaces(General_File, Utilities::float_count(flt_t), 17);

			// Percentage

			temp_f = Utilities::PT_AGE(flt_o, flt_t);
			General_File << temp_f;
			Utilities::spaces(General_File, Utilities::float_count(temp_f), 10);

			// Roll_Number

			General_File << students[i].roll;
			Utilities::spaces(General_File, students[i].roll.size(), 25);
			General_File << "|" << endl;

			// Flushing

			t_CLEAR;
			flt_o = 0.0f;
			flt_t = 0.0f;
		}

		General_File << " |                                                                                                    |" << endl;
		General_File << " +----------------------------------------------------------------------------------------------------+" << endl;
		General_File << endl;
		General_File.close();
	}

	void Subject_wise(vector<Profile> &students)
	{
		// Initializing Temporary Stuff

			_mkdir("Data\\Subject wise list");
			t_CLEAR;

		// Result Card

		for (int i = 0; i < students[0].subjects.size(); i++)
		{
			ofstream Brilliant_Student("Data\\Subject wise list\\" + (students[0].subjects[i].name + ".txt"));

			Utilities::sort(students, 3, i);
			Brilliant_Student << endl;
			Brilliant_Student << " +----------------------------------------------------------------------------------------------------+" << endl;
			Brilliant_Student << " | Subject [ " << i + 1 << " / " << students[0].subjects.size() << " ] - " << students[0].subjects[i].name; Utilities::spaces(Brilliant_Student, students[0].subjects[i].name.size(), 70); Brilliant_Student << "//////// |" << endl;
			Brilliant_Student << " +----------------------------------------------------------------------------------------------------+" << endl;
			Brilliant_Student << " | Names of Students" << "             " << "Obtained Marks" << "   " << "From (Marks)" << "     " << "%age" << "      " << "Roll_Number" << "              |" << endl;
			Brilliant_Student << " |                                                                                                    |" << endl;

			for (int j = 0; j < students.size(); j++)
			{
				// Creating a Reference

				sub_ref = &students[students[j].ID].subjects[i];
				
				// Name Generation

				Brilliant_Student << " | " << students[students[j].ID].name;
				Utilities::spaces(Brilliant_Student, students[students[j].ID].name.size());

				// Obtained Marks

				Brilliant_Student << sub_ref->o_marks;
				Utilities::spaces(Brilliant_Student, Utilities::float_count(sub_ref->o_marks), 17);

				// Total Marks

				Brilliant_Student << sub_ref->t_marks;
				Utilities::spaces(Brilliant_Student, Utilities::float_count(sub_ref->t_marks), 17);

				// Percentage

				temp_f = Utilities::PT_AGE(sub_ref->o_marks, sub_ref->t_marks);
				Brilliant_Student << temp_f;
				Utilities::spaces(Brilliant_Student, Utilities::float_count(temp_f), 10);

				// Roll_Number

				Brilliant_Student << students[students[j].ID].roll;
				Utilities::spaces(Brilliant_Student, students[j].roll.size(), 25);
				Brilliant_Student << "|" << endl;

				// Flushing

				t_CLEAR;
			}

			Brilliant_Student << " |                                                                                                    |" << endl;
			Brilliant_Student << " +----------------------------------------------------------------------------------------------------+" << endl;
			Brilliant_Student << endl;
			Brilliant_Student.close();

			for (int i = 0; i < students.size(); i++)
			{
				students[i].ID = i;
			}
		}

	}

	void Student_wise(const vector<Profile> &students)
	{
		// Initializing Temporary Stuff

		_mkdir("Data\\Student wise List");
		t_CLEAR;

		// Result Card

		for (int i = 0; i < students.size(); i++)
		{
			ofstream Genius_Student("Data\\Student wise List\\" + (students[i].name + ".txt"));

			Genius_Student << endl;
			Genius_Student << " +----------------------------------------------------------------------------------------------------+" << endl;
			Genius_Student << " | Student [ " << i + 1 << " / " << students.size() << " ] - " << students[i].name; Utilities::spaces(Genius_Student, students[i].name.size(), 70); Genius_Student << "//////// |" << endl;
			Genius_Student << " +----------------------------------------------------------------------------------------------------+" << endl;
			Genius_Student << " | Names of Subjects" << "             " << "Obtained Marks" << "   " << "From (Marks)" << "     " << "%age" << "      " << "Grade | Points" << "           |" << endl;
			Genius_Student << " |                                                                                 |                  |" << endl;

			for (int j = 0; j < students[i].subjects.size(); j++)
			{
				// Creating a Reference

				sub_ref = &students[i].subjects[students[i].subjects[j].ID];
				
				// Name Generation

				Genius_Student << " | " << sub_ref->name;
				Utilities::spaces(Genius_Student, sub_ref->name.size());

				// Obtained Marks

				Genius_Student << sub_ref->o_marks;
				Utilities::spaces(Genius_Student, Utilities::float_count(sub_ref->o_marks), 17);

				// Total Marks

				Genius_Student << sub_ref->t_marks;
				Utilities::spaces(Genius_Student, Utilities::float_count(sub_ref->t_marks), 17);

				// Percentage

				temp_f = Utilities::PT_AGE(sub_ref->o_marks, sub_ref->t_marks);
				Genius_Student << temp_f;
				Utilities::spaces(Genius_Student, Utilities::float_count(temp_f), 10);

				// Roll_Number

				if (temp_f >= 85 && temp_f <= 100)
				{
					temp_s = "A     | 4.00";
				}
				else if (temp_f >= 80 && temp_f <= 84)
				{
					temp_s = "A-    | 3.70";
				}
				else if (temp_f >= 75 && temp_f <= 79)
				{
					temp_s = "B+    | 3.30";
				}
				else if (temp_f >= 70 && temp_f <= 74)
				{
					temp_s = "B     | 3.00";
				}
				else if (temp_f >= 65 && temp_f <= 69)
				{
					temp_s = "B-    | 2.70";
				}
				else if (temp_f >= 61 && temp_f <= 64)
				{
					temp_s = "C+    | 2.30";
				}
				else if (temp_f >= 58 && temp_f <= 60)
				{
					temp_s = "C     | 2.00";
				}
				else if (temp_f >= 55 && temp_f <= 57)
				{
					temp_s = "C-    | 1.70";
				}
				else if (temp_f >= 50 && temp_f <= 54)
				{
					temp_s = "D     | 1.00";
				}
				else
				{
					temp_s = "F     | 0.00";
				}


				Genius_Student << temp_s;
				Utilities::spaces(Genius_Student, temp_s.size(), 25);
				Genius_Student << "|" << endl;

				// Flushing

				temp_s.clear();
				temp_f = 0.0;
			}

			Genius_Student << " |                                                                                                    |" << endl;
			Genius_Student << " +----------------------------------------------------------------------------------------------------+" << endl;
			Genius_Student << endl;
			Genius_Student.close();
		}
	}

}

namespace Result
{
	void Result_Gen(const vector<Profile> &students)
	{
		// Initializing Temporary Stuff

		t_CLEAR;
		float flt_o, flt_t;

		// Result Card

		cout << endl;
		cout << " +----------------------------------------------------------------------------------------------------+" << endl;
		cout << " | General List for all Students                                                       ////////////// |" << endl;
		cout << " +----------------------------------------------------------------------------------------------------+" << endl;
		cout << " | Names of Students" << "             " << "Obtained Marks" << "   " << "From (Marks)" << "     " << "%age" << "      " << "Roll_Number" << "              |" << endl;
		cout << " |                                                                                                    |" << endl;

		for (int i = 0; i < students.size(); i++)
		{
			// Name Generation

			cout << " | " << students[students[i].ID].name;
			Utilities::spaces(cout, students[students[i].ID].name.size());

			// Obtained Marks

			flt_o = Utilities::Sub_Sum(students[students[i].ID].subjects, false);
			cout << flt_o;
			Utilities::spaces(cout, Utilities::float_count(flt_o), 17);

			// Total Marks

			flt_t = Utilities::Sub_Sum(students[students[i].ID].subjects, true);
			cout << flt_t;
			Utilities::spaces(cout, Utilities::float_count(flt_t), 17);

			// Percentage

			temp_f = Utilities::PT_AGE(flt_o, flt_t);
			cout << temp_f;
			Utilities::spaces(cout, Utilities::float_count(temp_f), 10);

			// Roll_Number

			cout << students[i].roll;
			Utilities::spaces(cout, students[i].roll.size(), 25);
			cout << "|" << endl;

			// Flushing

			temp_s.clear();
			temp_f = 0.0;
			flt_o = 0.0;
			flt_t = 0.0;
		}

		cout << " |                                                                                                    |" << endl;
		cout << " +----------------------------------------------------------------------------------------------------+" << endl;
		cout << endl;
	}

	void Subject_wise(vector<Profile> &students)
	{
		// Initializing Temporary Stuff

		t_CLEAR;

		// Result Card

		for (int i = 0; i < students[0].subjects.size(); i++)
		{
			Utilities::sort(students, 3, i);
			students.shrink_to_fit();
			students[i].subjects.shrink_to_fit();
			system("cls");
			cout << endl;
			cout << " +----------------------------------------------------------------------------------------------------+" << endl;
			cout << " | Subject [ " << i + 1 << " / " << students[0].subjects.size() << " ] - " << students[0].subjects[i].name; Utilities::spaces(cout, students[0].subjects[i].name.size(), 70); cout << "//////// |" << endl;
			cout << " +----------------------------------------------------------------------------------------------------+" << endl;
			cout << " | Names of Students" << "             " << "Obtained Marks" << "   " << "From (Marks)" << "     " << "%age" << "      " << "Roll_Number" << "              |" << endl;
			cout << " |                                                                                                    |" << endl;

			for (int j = 0; j < students.size(); j++)
			{
				// Creating a Reference

				sub_ref = &students[students[j].ID].subjects[i];
				
				// Name Generation

				cout << " | " << students[students[j].ID].name;
				Utilities::spaces(cout, students[students[j].ID].name.size());

				// Obtained Marks

				cout << sub_ref->o_marks;
				Utilities::spaces(cout, Utilities::float_count(sub_ref->o_marks), 17);

				// Total Marks

				cout << sub_ref->t_marks;
				Utilities::spaces(cout, Utilities::float_count(sub_ref->t_marks), 17);

				// Percentage

				temp_f = Utilities::PT_AGE(sub_ref->o_marks, sub_ref->t_marks);
				cout << temp_f;
				Utilities::spaces(cout, Utilities::float_count(temp_f), 10);

				// Roll_Number

				cout << students[students[j].ID].roll;
				Utilities::spaces(cout, students[j].roll.size(), 25);
				cout << "|" << endl;

				// Flushing

				temp_s.clear();
				temp_f = 0.0;
			}

			cout << " |                                                                                                    |" << endl;
			cout << " +----------------------------------------------------------------------------------------------------+" << endl;
			cout << endl;
			system("pause");

			for (int i = 0; i < students.size(); i++)
			{
				students[i].ID = i;
			}
		}
	}

	void Student_wise(const vector<Profile> &students)
	{
		// Initializing Temporary Stuff

		t_CLEAR;

		// Result Card

		for (int i = 0; i < students.size(); i++)
		{
			system("cls");
			cout << endl;
			cout << " +----------------------------------------------------------------------------------------------------+" << endl;
			cout << " | Student [ " << i + 1 << " / " << students.size() << " ] - " << students[i].name; Utilities::spaces(cout, students[i].name.size(), 70); cout << "//////// |" << endl;
			cout << " +----------------------------------------------------------------------------------------------------+" << endl;
			cout << " | Names of Subjects" << "             " << "Obtained Marks" << "   " << "From (Marks)" << "     " << "%age" << "      " << "Grade | Points" << "           |" << endl;
			cout << " |                                                                                 |                  |" << endl;

			for (int j = 0; j < students[i].subjects.size(); j++)
			{
				// Creating a Reference

				sub_ref = &students[i].subjects[students[i].subjects[j].ID];
				
				// Name Generation

				cout << " | " << sub_ref->name;
				Utilities::spaces(cout, sub_ref->name.size());

				// Obtained Marks

				cout << sub_ref->o_marks;
				Utilities::spaces(cout, Utilities::float_count(sub_ref->o_marks), 17);

				// Total Marks

				cout << sub_ref->t_marks;
				Utilities::spaces(cout, Utilities::float_count(sub_ref->t_marks), 17);

				// Percentage

				temp_f = Utilities::PT_AGE(sub_ref->o_marks, sub_ref->t_marks);
				cout << temp_f;
				Utilities::spaces(cout, Utilities::float_count(temp_f), 10);

				// Roll_Number

				if (temp_f >= 85 && temp_f <= 100)
				{
					temp_s = "A     | 4.00";
				}
				else if (temp_f >= 80 && temp_f <= 84)
				{
					temp_s = "A-    | 3.70";
				}
				else if (temp_f >= 75 && temp_f <= 79)
				{
					temp_s = "B+    | 3.30";
				}
				else if (temp_f >= 70 && temp_f <= 74)
				{
					temp_s = "B     | 3.00";
				}
				else if (temp_f >= 65 && temp_f <= 69)
				{
					temp_s = "B-    | 2.70";
				}
				else if (temp_f >= 61 && temp_f <= 64)
				{
					temp_s = "C+    | 2.30";
				}
				else if (temp_f >= 58 && temp_f <= 60)
				{
					temp_s = "C     | 2.00";
				}
				else if (temp_f >= 55 && temp_f <= 57)
				{
					temp_s = "C-    | 1.70";
				}
				else if (temp_f >= 50 && temp_f <= 54)
				{
					temp_s = "D     | 1.00";
				}
				else
				{
					temp_s = "F     | 0.00";
				}


				cout << temp_s;
				Utilities::spaces(cout, temp_s.size(), 25);
				cout << "|" << endl;

				// Flushing

				temp_s.clear();
				temp_f = 0.0;
			}

			cout << " |                                                                                                    |" << endl;
			cout << " +----------------------------------------------------------------------------------------------------+" << endl;
			cout << endl;
			system("pause");
		}
	}

}

namespace MAIN
{
	void EasyLoad()
	{
		HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);
		temp_f = 0.0f;

		// Tax Management

		
		ifstream iTax("Data\\TaX.txt");
		iTax >> temp_f;

		if (temp_f <= 0.0f)
		{
			temp_f = 12.5f;
		}

		// Main Code

		EasyLoad:

		int load; char choice;
		cout << setcolour(GREEN, chandle) << "============================================" << endl;
		cout << setcolour(RED, chandle)   << "     ////////" << setcolour(GREEN, chandle) << " Easyload Helper! " << setcolour(RED, chandle) << "////////" << endl;
		cout << setcolour(GREEN, chandle) << "============================================" << endl;

		if(debug)
		{
			cout << setcolour(RED, chandle) << "\n[ X ]" << setcolour(GREEN, chandle) << "  - Key For HEAP Memory Status -  " << setcolour(RED, chandle) << "[ X ]" << endl;
		}

		cout << setcolour(GREEN, chandle) << "\nChoose Operation: \n";

		cout << setcolour(RED, chandle) << "\n1" << setcolour(GREEN, chandle) << ". Input  (Rs. Load)  ->   Output (Account)" << endl;
		cout << setcolour(RED, chandle) << "2" << setcolour(GREEN, chandle) << ". Output (Required)  ->   Input  (Rs.Load)" << endl;
		cout << setcolour(RED, chandle) << "3" << setcolour(GREEN, chandle) << ". To go back to Main Menu" << endl;
		cout << setcolour(RED, chandle) << "0" << setcolour(GREEN, chandle) << ". To Change TAX %age   ( Default: " << temp_f << " % )" << endl;

		cout << setcolour(GREEN, chandle) << "\nYour Choice: " << setcolour(RED, chandle);
		cin >> choice; CLEAR;
		cout << endl;
		system("cls");

		switch (choice)
		{
			case '1':
			{
				cout << setcolour(GREEN, chandle) << "\n- Enter EasyLoad Amount: " << setcolour(RED, chandle);
				cin >> load; CLEAR;
				cout << setcolour(GREEN, chandle) << "--------------------------------------------" << endl;
				cout << setcolour(GREEN, chandle) << " =>>---> Amount you will Recieve: " << setcolour(RED, chandle) << load - ((load * temp_f) / 100) << endl;
				cout << setcolour(GREEN, chandle) << "--------------------------------------------" << endl;
				cout << setcolour(GREEN, chandle) << "Default Tax %age: [ " << temp_f << " % ]" << endl;

				//Continue / Break

				cout << setcolour(GREEN, chandle) << "\n- Enter 1 to Continue,\n- Enter 0 to change Tax Value,\n or Any Other Key to go back to Main Menu - ";
				char decision;
				cin >> decision; CLEAR;

				if (decision == '1')
				{
					system("cls");
					goto EasyLoad;
				}
				else if (decision == '0')
				{
					system("cls");
					cout << "Enter Your TAX %age: ";
					cin >> temp_f; CLEAR;
					system("cls");
					goto EasyLoad;
				}

				system("cls");
				break;
			}

			case '2':
			{
				cout << setcolour(GREEN, chandle) << "\n- Enter amount U wanna Recieve in ur Account: " << setcolour(RED, chandle);
				cin >> load; CLEAR;
				cout << setcolour(GREEN, chandle) << "--------------------------------------------" << endl;
				cout << setcolour(GREEN, chandle) << " =>>---> Amount you have to Load: " << setcolour(RED, chandle) << load + ((load * temp_f) / 100) << endl;
				cout << setcolour(GREEN, chandle) << "--------------------------------------------" << endl;
				cout << setcolour(GREEN, chandle) << "Default Tax %age: [ " << temp_f << " % ]" << endl;

				//Continue / Break

				cout << setcolour(GREEN, chandle) << "\n- Enter 1 to Continue,\n- Enter 0 to change Tax Value,\n or Any Other Key to go back to Main Menu - ";
				char decision;
				cin >> decision; CLEAR;

				if (decision == '1')
				{
					system("cls");
					goto EasyLoad;
				}
				else if (decision == '0')
				{
					system("cls");
					cout << "Enter Your TAX %age: ";
					cin >> temp_f; CLEAR;
					system("cls");
					goto EasyLoad;
				}

				system("cls");
				break;
			}

			case '3':
			{
				break;
			}

			case '0':
			{
				ofstream oTax("Data\\TaX.txt");
				cout << setcolour(GREEN, chandle) << "Default Tax %age: [ " << setcolour(RED, chandle) << temp_f << " %" << setcolour(GREEN, chandle) << " ]" << endl;
				cout << "--------------------------------------" << endl;
				cout << "Enter Your TAX %age: " << setcolour(RED, chandle);
				cin >> temp_f; CLEAR;
				oTax << temp_f;
				system("cls");
				goto EasyLoad;
				break;
			}

			default:
			{
				if(!debug)
				{
					system("cls");
					cout << "Invalid Input!" << endl << endl;
					goto EasyLoad;
					break;
				}
				else
				{
					Tracer::PrintCurrentUsage(); goto EasyLoad;
				}
			}
		}
		system("cls");
	}

	void Extractor()
	{
		// Initialization

			string stg; temp_s.clear();
			vector<int> value;
			int I;

		// Taking Input

			system("cls");
			cout << endl;
			cout << " +----------------------------------------------------+" << endl;
			cout << " |               Enter any String Below               |" << endl;
			cout << " |       Enter \"000\" to return back to MAIN MENU      |" << endl;
			cout << " +----------------------------------------------------+" << endl;
			cout << " | Input : ";
			std::getline(cin, stg); CLEAR;
			// cin >> stg;

		// To Exit

			if (stg == "000")
			{
				system("cls");
				return;
			}

		// Value Extraction Process

			for (int i = 0; i < stg.size(); i++)
			{
				if (stg[i] >= '0' && stg[i] <= '9')
				{
					while (stg[i] >= '0' && stg[i] <= '9')
					{
						temp_s += stg[i];
						i++;
					}
					stringstream(temp_s) >> I;
					value.push_back(I);
					temp_s.clear();
				}
			}

		// Output

			cout << " |----------------------------------------------------|" << endl;

			if (value.empty())
			{
				cout << " | No Value Found in the Entered String!" << endl;
			}
			else
			{
				for (int i = 0; i < value.size(); i++)
				{
					cout << " | Value #" << i + 1 << " : " << value[i] << endl;
				}
			}
			cout << " +----------------------------------------------------+" << endl;


		// Recursive


			if(!debug)
			{
				cout << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << " | Enter \"X\" to check current Allocations on HEAP    |" << endl;
				cout << " |" << endl;
				cout << " +--[Input]--> ";
				getline(cin, temp_s); CLEAR;

				if ( temp_s == "X" )
				{
					cout << " |" << endl;
					cout << " | Memory on HEAP : " << Tracer::CurrentUsage() << " Bytes" << endl;
					cout << " +----------------------------------------------------+" << endl;
					cout << endl;
					system("pause");
					system("cls");
				}
				else
				{
					return;
				}
				
			}


	}

	void Guess_Game_main()
	{
		int rdm = Utilities::no_random(), guess;
		vector<int> Track;


		cout << endl;
		cout << "+---------------------------------------------------------------------+" << endl;
		cout << "| Guess the Number: ";
		cin >> guess; CLEAR;
		Track.push_back(guess);

		loop:
		if (guess == rdm)
		{

			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "|               	       		                             ||" << endl;
			cout << "| Wow! You Got Me! The Number was: \t" << rdm << "		             ||" << endl;
			cout << "|               	       		                             ||" << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "| Your Guessed Numbers:                                              ||" << endl;
			cout << "| ";

			for (int i = 0; i < Track.size(); i++)
			{
				cout << Track[i];

				if (i < (Track.size() - 1))
				{
					cout << ", ";
				}
			}
			cout << endl;

			cout << "+---------------------------------------------------------------------+" << endl;
			cout << "| Total Guesses: " << Track.size() << "\t\tHighScore: " << Utilities::HighScore(Track.size()) << endl;
			cout << "+---------------------------------------------------------------------+" << endl;
			cout << endl;
			system("pause");
		}
		else
		{
			if (guess < rdm)
			{
				cout << "+---------------------------------------------------------------------+" << endl;
				cout << "|               	       		                              |" << endl;
				cout << "| My  Number is 	GREATER		 than Your Number.            |" << endl;
				cout << "|               	       		                              |" << endl;
			}
			else
			{
				if (guess > rdm)
				{
					cout << "+---------------------------------------------------------------------+" << endl;
					cout << "|               	       		                              |" << endl;
					cout << "| My  Number is 	SMALLER		 than Your Number.            |" << endl;
					cout << "|               	       		                              |" << endl;
				}
			}

			cout << "|---------------------------------------------------------------------|" << endl;
			cout << "| Enter Other Number:\t";
			cin >> guess; CLEAR;
			Track.push_back(guess);
			goto loop;
		}
	}

	void Guess_Game_start()
	{
		// Initialization

			temp_s.clear();

		// Main

			do
			{
				system("cls");
				cout << endl;
				cout << "+---------------------------------------------------------------------+" << endl;
				cout << "|                     This is a Guessing Game.                        |" << endl;
				cout << "|    The Number Generated by the System will be in between 0-100.     |" << endl;
				cout << "+---------------------------------------------------------------------+" << endl;
				cout << "| - Enter 0 to go back to The Main Menu                               |" << endl;
				cout << "| - Enter Any other key to \"Play The Game\"                            |" << endl;

				if (debug)
				{
					cout << "| - Enter X to Check HEAP Status                                      |" << endl;
				}

				cout << "+---------------------------------------------------------------------+" << endl;
				cout << "\n- Your Choice: ";
				getline(cin , temp_s); CLEAR;

				if (temp_s != "0" && !debug)
				{
					MAIN::Guess_Game_main();
				}
				else if ( temp_s != "0" && debug )
				{
					if ( temp_s == "X" )
					{
						cout << endl;
						cout << "+---------------------------------------------------------------------+" << endl;
						cout << "| Currently have : " << Tracer::CurrentUsage() << " Bytes in HEAP" << endl;
						cout << "+---------------------------------------------------------------------+" << endl;
						system("pause");
					}
					else
					{
						MAIN::Guess_Game_main();
					}
				}
				else
				{
					break;
				}
			} while (temp_s != "0");

		// Returning

			system("cls");
	}

	void Guess_Game_start_2()
	{
		// Initialization

			temp_s.clear();

		// Main

			do
			{
				system("cls");
				cout << "-------.____________________________________________________________" << endl;
				cout << "| 0111 |                                                      //// ]" << endl;
				cout << "| 1111 | Guessing Game v3 (Futuristic Design)                      ]" << endl;
				cout << "| 0110 |______________________________________________________MR_777" << endl;
				cout << "*\\_______|                                                       |" << endl;
				cout << "  \\                                                              |" << endl;
				cout << "   \\       This is a Guessing Game, with some Futuristic         1" << endl;
				cout << "    1      Start. It will generate a Number between 0-100        1" << endl;
				cout << "    |      Guess the Number if U can. Everything will be         1" << endl;
				cout << "    |      counted, so try to make a HighScore. Your High        |" << endl;
				cout << "    |      score is kept in an External File.                    |" << endl;
				cout << "    |                                                            |" << endl;
				cout << "    |      You may have seen, it was not listed in the Main      |" << endl;
				cout << "    |      menu. It is a Little Secret Prototype of my           |" << endl;
				cout << "    |      Future Programs. I've just Implemented my Ideas       |" << endl;
				cout << "    |      in this little Guessing Game. Enjoy the all new       |" << endl;
				cout << "    |      Futuristic Models of my Future Programs!              |" << endl;
				cout << "    |                                                            |" << endl;
				cout << "    |_________________________                                   |" << endl;
				cout << "    |                         \\__________________________________|" << endl;
				cout << "    |                                                            |" << endl;
				cout << "    1      - Enter 0 to go back to Main Menu                     |" << endl;
				cout << "    1      - Enter ANY other key to \"Play The Game\"              |" << endl;
				cout << "    1                                         ___________________7" << endl;
				cout << "    [________________________________________////////////////////" << endl;
				cout << "\n" << endl;

				cout << "\n- Your Choice: ";
				getline(cin , temp_s); CLEAR;

				if (temp_s != "0")
				{
					MAIN::Guess_Game_main();
				}
				else
				{
					break;
				}
			} while (temp_s != "0");

		// Returning

			system("cls");
	}

	void RCP_Settings(vector<Subject> &subjects)
	{
		// Initialization

		t_CLEAR;
		int total;
		bool same;
		Subject subject_t;

		// Settings Menu

		system("cls");

	Settings:

		cout << endl;
		cout << " +-----------------------------------------------------------------+" << endl;
		cout << " | Select any Option listed below :-                               |" << endl;
		cout << " |                                                                 |" << endl;
		cout << " | [ 1 ] - Set Pre-Configured Settings for Subjects                |" << endl;
		cout << " | [ 2 ] - Set Prefix for Roll Numbers                             |" << endl;
		cout << " | [ 3 ] - Go back to Main Menu                                    |" << endl;
		cout << " |                                                                 |" << endl;
		cout << " +-----------------------------------------------------------------+" << endl;
		cout << " |" << endl;
		cout << " +--[Input]--> ";
		getline(cin, temp_s); CLEAR;
		stringstream(temp_s) >> temp_i;

		system("cls");
		switch (temp_i)
		{
		case 1:
		{
			subjects.clear();

			// Input Menu

			cout << " +-----------------------------------------------------------------+" << endl;
			cout << " | Enter names of the Subjects as asked. Enter \"F\" when finished   |" << endl;
			cout << " | entering names of the subjects.                                 |" << endl;
			cout << " | --------------------------------------------------------------- |" << endl;
			cout << " | Answer a little question first, does all the subjects have same |" << endl;
			cout << " | total markes ?                                                  |" << endl;
			cout << " |" << endl;
			cout << " +--{Y/N}--> ";
			getline(cin, temp_s); CLEAR;

			// If total marks are Identical

			if (temp_s == "Y" || temp_s == "y")
			{
				cout << " |" << endl;
				cout << " | Enter Total marks for all subjects : ";
				getline(cin, temp_s); CLEAR;
				stringstream(temp_s) >> total;
				same = 1;
			}
			else
			{
				same = 0;
			}
			cout << " |" << endl;

			// Inputting begins from here

			for (int i = 0; true; i++)
			{
				cout << " | --------------------------------------------------------------- |" << endl;
				cout << " | Enter name of Subject #" << i + 1 << " : ";
				getline(cin, temp_s); CLEAR;

				if (temp_s != "F" && temp_s != " F" && temp_s != "F " && temp_s != " F " && temp_s != "f" && temp_s != " f" && temp_s != "f " && temp_s != " f ")
				{
					subject_t.name = temp_s;
				}
				else
				{
					Utilities::Write(subjects, "Subjects");
					temp_s.clear();
					break;
				}


				if (same == 0)
				{
					cout << " | Enter Total marks of " << temp_s << " : ";
					getline(cin, temp_s); CLEAR;
					stringstream(temp_s) >> subject_t.t_marks;
				}
				else
				{
					subject_t.t_marks = total;
				}

				subjects.push_back(subject_t);
			}

			cout << " |                                                                 |" << endl;
		}

		case 2:
		{
			cout << " |>---------------------------------------------------------------<|" << endl;
			cout << " |                                                                 |" << endl;
			cout << " | Enter a Prefix for Roll Numbers if you like (to reduce time)    |" << endl;
			cout << " | Like : \"BSCS_F19_M_\"                                            |" << endl;
			cout << " | Or, Enter \"F\" again if you don't want Prefixing Feature         |" << endl;
			cout << " |                                                                 |" << endl;
			cout << " | ----------------------------------------------------------------|" << endl;
			cout << " |" << endl;
			cout << " +--[Prefix]--> ";
			getline(cin, temp_s); CLEAR;

			if (temp_s != "F" && temp_s != " F" && temp_s != "F " && temp_s != " F " && temp_s != "f" && temp_s != " f" && temp_s != "f " && temp_s != " f ")
			{
				roll_prefix = temp_s;
			}

			temp_s.clear();
			break;
		}

		case 3:
		{
			return;
		}

		default:
		{
			cout << " +-----------------------------------------------------------------+" << endl;
			cout << " | [ ERROR ] - Invalid Input                                       |" << endl;
			cout << " +-----------------------------------------------------------------+\a" << endl;
			goto Settings;
			break;
		}
		}
	}

	void RCP_Input(vector<Profile> &students, vector<Subject> &subjects)
	{
		// Initialization

		students.clear();
		Profile std_t;
		int m_limit = 2;

		// Vector Filling

	Filling:

		try
		{
			system("cls");
			cout << endl;
			cout << " +-------------------------------------------------------------+" << endl;
			cout << " | Enter \"F\" when finished entering names of the Students.     |" << endl;
			cout << " |-------------------------------------------------------------|" << endl;

			// ID-ing Students

			for (int i = 0; true; i++)
			{
				// Tagging the Student

				std_t.ID = i;

				// Just a Bar

			ID_ing:

				if (i != 0 || temp_f == 1)
				{
					cout << endl;
					cout << " +-------------------------------------------------------------+" << endl;
				}

				// Inputting Name

				cout << " | Enter Name of Student #" << i + 1 << " : ";
				getline(cin, temp_s);

				if (temp_s != "F" && temp_s != " F" && temp_s != "F " && temp_s != " F " && temp_s != "f" && temp_s != " f" && temp_s != "f " && temp_s != " f ")
				{
					std_t.name = temp_s;
				}
				else
				{
					CLEAR;
					system("cls");
					break;
				}


				// Inputting Roll number

				cout << " |-------------------------------------------------------------|" << endl;
				cout << " | - Enter Roll Number of " << std_t.name << " : " << roll_prefix;
				getline(cin, std_t.roll);
				std_t.roll = roll_prefix + std_t.roll;
				std_t.roll.shrink_to_fit();

				// Inputting Individual Marks

				for (int j = 0; j < subjects.size(); j++)
				{
					subjects[j].ID = j;

					if (i == 0)
					{
						cout << " |-------------------------------------------------------------|" << endl;
					}
					else
					{
						cout << " | ----------------------------------------------------------- |" << endl;
					}

					cout << " | - Enter Obtained Marks of [ " << subjects[j].name << " ] : ";
					cin >> subjects[j].o_marks;

					if (subjects[j].o_marks > subjects[j].t_marks)
					{
						cout << " | ----------------------------------------------------------- |" << endl;
						cout << " | [ ! ] - Obtained Marks can't be higher than Total marks!    | " << endl;
						j--;
						continue;
					}
					else
					{
						std_t.subjects.push_back(subjects[j]);
					}


				}

				// Confirmation

				CLEAR;
				cout << " +-------------------------------------------------------------+" << endl;
				cout << " | Check the above Informaion U entered. Enter 0 to make       |" << endl;
				cout << " | changes, or Enter any other key to Move Forward.            |" << endl;
				cout << " +-------------------------------------------------------------+" << endl;
				cout << " |" << endl;
				cout << " +---> Input : ";
				getline(cin, temp_s);

				// Flushing + Finalization

				temp_f = 0.0f;
				system("cls"); CLEAR;

				if (temp_s == "0")
				{
					temp_f = 1;
					goto ID_ing;
				}
				else
				{
					temp_s.clear();
					students.push_back(std_t);

					std_t.subjects.clear();
				}

			}


		}


		catch (...)
		{
			cout << endl;
			cout << "Something went Wrong! U just Crashed the Program, plz Enter Input as asked only!" << endl;
			cout << endl;
			system("pause");
			goto Filling;
		}
	}

	void RCP()
	{
		// Initialization

			Subject subject_t;
			vector<Subject> subjects;
			vector<Profile> students;

			system("mode 150,40");   //Set mode to ensure window does not exceed buffer size
			SMALL_RECT WinRect = { 0, 0, 150, 40 };   //New dimensions for window in 8x12 pixel chars
			SMALL_RECT* WinSize = &WinRect;
			SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);   //Set new size for window

		// Introduction

			system("cls");
			cout << endl;
			cout << " +-------------------------------------------------------------+" << endl;
			cout << " | It's a Result Card Generator. Only U have to Input the data |" << endl;
			cout << " | of students as asked. The Whole list will be generated as a |" << endl;
			cout << " | text file. Make sure to enter data correctly. I've managed  |" << endl;
			cout << " | to Optimize ID-ing Errors as far as I could in C++ Language |" << endl;
			cout << " +-------------------------------------------------------------+" << endl;
			cout << " |                                                             |" << endl;
			cout << " | [ REMEMBER ] - Config the settings in the \"Settings\" first  |" << endl;
			cout << " |                                                             |" << endl;
			cout << " +-------------------------------------------------------------+" << endl;
			cout << endl;
			system("pause"); system("cls");
			cout << endl;

		// Decision


			MAIN:
		
			cout << " +-------------------------------------------------------------+" << endl;
			cout << " | Integrated Result Card Generator v3.1             ///////// |" << endl;
			cout << " +-------------------------------------------------------------+" << endl;
			cout << " | Select any of the Options below :-                          |" << endl;
			cout << " |                                                             |" << endl;

			if(debug)
			{
				cout << " | [ 0 ] - Show HEAP Status                                    |" << endl;
			}

			cout << " | [ 1 ] - Open Interface to Generate Result Card              |" << endl;
			cout << " | [ 2 ] - Open Settings Menu to Configure Subjects            |" << endl;
			cout << " | [ 3 ] - Go back to Main Menu                                |" << endl;
			cout << " |                                                             |" << endl;
			cout << " +-------------------------------------------------------------+" << endl;
			cout << " |" << endl;
			cout << " +---[Input]---> ";
			getline(cin, temp_s);
			stringstream(temp_s) >> temp_i;
			CLEAR;

			switch (temp_i)
			{
				case 1:
				{
					vector<Subject> subjects = Utilities::Scan("Subjects");
					subjects.shrink_to_fit();
					if (subjects.empty())
					{
						system("cls");
						cout << " +-------------------------------------------------------------+" << endl;
						cout << " | [ ! ] - Please Configure Settings first                     |" << endl;
						cout << " +-------------------------------------------------------------+" << endl;
						cout << " |                                                             |" << endl;
						goto MAIN;
					}
					else
					{
						system("cls");
						MAIN::RCP_Input(students, subjects);
						cout << endl;
						break;
					}

				}

				case 2:
				{
					system("cls");
					MAIN::RCP_Settings(subjects);
					system("cls");

					if (!subjects.empty())
					{
						cout << " +-------------------------------------------------------------+" << endl;
						cout << " | [ OK ] - Settings configured Successfully!                  |" << endl;
						cout << " +-------------------------------------------------------------+" << endl;
						cout << " |                                                             |" << endl;
					}
					else
					{
						cout << " +-------------------------------------------------------------+" << endl;
						cout << " | [ WARNING ] - Subjects are still un-configured!             |" << endl;
						cout << " +-------------------------------------------------------------+\a" << endl;
						cout << " |                                                             |" << endl;
					}

					goto MAIN;
				}

				case 3:
				{
					system("cls");
					return;
				}


				default:
				{
					if(!debug)
					{
						system("cls");
						cout << " +-------------------------------------------------------------+" << endl;
						cout << " | [ ERROR ] - Invalid Input                                   |" << endl;
						cout << " +-------------------------------------------------------------+\a" << endl;
						cout << " |                                                             |" << endl;
					}
					else
					{
						cout << " |\n";
						cout << " +-------------------------------------------------------------+" << endl;
						cout << " | Currently have : " << Tracer::CurrentUsage() << " Bytes in HEAP" << endl;
						cout << " +-------------------------------------------------------------+" << endl;
						system("pause");
						system("cls");
						cout << endl;
					}
					
					goto MAIN;
				}
			}




		// Menu For Type of Result

		Result_Menu:

		cout << " +-------------------------------------------------------------+" << endl;
		cout << " | Console Output Menu for Final Results            ////////// |" << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " | Select any one Option from below                            |" << endl;
		cout << " |                                                             |" << endl;
		cout << " | [ 1 ] - General List for all Students                       |" << endl;
		cout << " | [ 2 ] - Students-Wise List for Every Student                |" << endl;
		cout << " | [ 3 ] - Subject-Wise List, for every Subject                |" << endl;
		cout << " |                                                             |" << endl;
		cout << " | * [ 7 ] - Re-Input Everything                               |" << endl;
		cout << " | * [ 8 ] - Output File Generation                            |" << endl;
		cout << " | * [ 9 ] - Go to MAIN MENU                                   |" << endl;

		if(debug)
		{
			cout << " | * [ X ] - Check HEAP Status                                 |" << endl;
		}

		cout << " |                                                             |" << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " |" << endl;
		cout << " |" << endl;
		cout << " +----[Input]---> ";
		getline(cin, temp_s); CLEAR;

		stringstream(temp_s) >> temp_i;

		switch (temp_i)
		{
			case 1:
			{
				system("cls");
				Utilities::sort(students, 1);
				Result::Result_Gen(students);
				system("pause");
				system("cls");
				goto Result_Menu;
			}

			case 2:
			{
				system("cls");
				Utilities::sort(students, 2);
				Result::Student_wise(students);
				system("cls");
				goto Result_Menu;
			}

			case 3:
			{
				system("cls");
				Result::Subject_wise(students);
				system("cls");
				goto Result_Menu;
			}

			case 7:
			{
				system("cls");
				cout << " +-------------------------------------------------------------+" << endl;
				cout << " |               !!!...Confirmation Message...!!!              |" << endl;
				cout << " +-------------------------------------------------------------+" << endl;
				cout << " | Are U sure u wanna go to back to Input Menu ?               |" << endl;
				cout << " |                                                             |" << endl;
				cout << " | All the data, except what u entered in Settings menu, will  |" << endl;
				cout << " | be lost, When you go to Input Menu.                         |" << endl;
				cout << " |                                                             |" << endl;
				cout << " | - Enter: \"1\" to go to Previous Menu.                        |" << endl;
				cout << " | - Enter Any Key to go back to Input menu                    |" << endl;
				cout << " +-------------------------------------------------------------+" << endl;
				cout << " |" << endl;
				cout << " +---[Confirm]--> ";
				getline(cin, temp_s); CLEAR;
				stringstream(temp_s) >> temp_i;

				system("cls");
				if (temp_i != 1)
				{
					goto MAIN;
				}
				else
				{
					goto Result_Menu;
				}
			}

			case 8:
			{
				system("cls");
				goto Output;
			}

			case 9:
			{
				system("cls");
				cout << " +-------------------------------------------------------------+" << endl;
				cout << " |               !!!...Confirmation Message...!!!              |" << endl;
				cout << " +-------------------------------------------------------------+" << endl;
				cout << " | Are U sure u wanna go to back to MAIN Menu ?                |" << endl;
				cout << " |                                                             |" << endl;
				cout << " | All the data, except what u entered in Settings menu, will  |" << endl;
				cout << " | be lost, When you go to MAIN Menu.                          |" << endl;
				cout << " |                                                             |" << endl;
				cout << " | - Enter: \"1\" to go to Previous Menu.                        |" << endl;
				cout << " | - Enter Any Key to go back to MAIN menu                     |" << endl;
				cout << " +-------------------------------------------------------------+" << endl;
				cout << " |" << endl;
				cout << " +---[Confirm]--> ";
				getline(cin, temp_s); CLEAR;
				stringstream(temp_s) >> temp_i;

				system("cls");
				if (temp_i != 1)
				{
					return;
				}
				else
				{
					goto Result_Menu;
				}
			}

			default:
			{
				if(!debug)
				{
					system("cls");
					cout << endl;
					cout << " +-------------------------------------------------------------+" << endl;
					cout << " | [ ERROR ] - Invalid Input                                   |\a" << endl;
					goto Result_Menu;
				}
				else
				{
					cout << " |\n |\n";
					cout << " +-------------------------------------------------------------+" << endl;
					cout << " | Currently have : " << Tracer::CurrentUsage() << " Bytes in HEAP" << endl;
					cout << " +-------------------------------------------------------------+" << endl;
					cout << endl; system("pause"); system("cls"); goto Result_Menu;
				}
				
			}
		}

		for (int i = 0; i < students.size(); i++)
		{
			students[i].ID = i;
			for (int j = 0; j < students[i].subjects.size(); j++)
			{
				students[i].subjects[j].ID = j;
			}
		}


	Output:
		cout << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " | Output Menu                                          ////// |" << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " | Select any of the options below :-                          |" << endl;
		cout << " |                                                             |" << endl;
		cout << " | [ 1 ] - General List for all Students                       |" << endl;
		cout << " | [ 2 ] - Student-wise List                                   |" << endl;
		cout << " | [ 3 ] - Subject-wise List                                   |" << endl;
		cout << " | [ 4 ] - Generate all lists at the same time                 |" << endl;
		cout << " |                                                             |" << endl;
		cout << " | [ 7 ] - Go back to Result Menu                              |" << endl;
		cout << " | [ 8 ] - Go back to Input Menu                               |" << endl;
		cout << " | [ 9 ] - Go back to MAIN MENU                                |" << endl;

		if(debug)
		{
			cout << " | [ X ] - Check HEAP Status                                   |" << endl;
		}

		cout << " |                                                             |" << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " |" << endl;
		cout << " +---[Input]--> ";
		getline(cin, temp_s); CLEAR;
		stringstream(temp_s) >> temp_i;

		switch (temp_i)
		{
			case 1:
			{
				system("cls");
				Result_External::Result_Gen(students);
				goto Output;
			}

			case 2:
			{
				system("cls");
				cout << " +-------------------------------------------------------------+" << endl;
				cout << " | [ OK ]        Output Files Generated!                       |" << endl;
				cout << " +-------------------------------------------------------------+" << endl;
				Result_External::Student_wise(students);
				goto Output;
			}

			case 3:
			{
				system("cls");
				cout << " +-------------------------------------------------------------+" << endl;
				cout << " | [ OK ]        Output Files Generated!                       |" << endl;
				cout << " +-------------------------------------------------------------+" << endl;
				Result_External::Subject_wise(students);
				goto Output;
			}

			case 4:
			{
				system("cls");
				Result_External::Result_Gen(students);
				Result_External::Student_wise(students);
				Result_External::Subject_wise(students);
				goto Output;
			}

			case 7:
			{
				system("cls");
				goto Result_Menu;
			}

			case 8:
			{
				system("cls");
				cout << " +-------------------------------------------------------------+" << endl;
				cout << " |               !!!...Confirmation Message...!!!              |" << endl;
				cout << " +-------------------------------------------------------------+" << endl;
				cout << " | Are U sure u wanna go to back to Input Menu ?               |" << endl;
				cout << " |                                                             |" << endl;
				cout << " | All the data, except what u entered in Settings menu, will  |" << endl;
				cout << " | be lost, When you go to Input Menu.                         |" << endl;
				cout << " |                                                             |" << endl;
				cout << " | - Enter: \"1\" to go to Previous Menu.                        |" << endl;
				cout << " | - Enter Any Key to go back to Input menu                    |" << endl;
				cout << " +-------------------------------------------------------------+" << endl;
				cout << " |" << endl;
				cout << " +---[Confirm]--> ";
				getline(cin, temp_s); CLEAR;
				stringstream(temp_s) >> temp_i;

				system("cls");
				if (temp_i != 1)
				{
					goto MAIN;
				}
				else
				{
					goto Output;
				}
			}

			case 9:
			{
				system("cls");
				cout << " +-------------------------------------------------------------+" << endl;
				cout << " |               !!!...Confirmation Message...!!!              |" << endl;
				cout << " +-------------------------------------------------------------+" << endl;
				cout << " | Are U sure u wanna go to back to MAIN Menu ?                |" << endl;
				cout << " |                                                             |" << endl;
				cout << " | All the data, except what u entered in Settings menu, will  |" << endl;
				cout << " | be lost, When you go to MAIN Menu.                          |" << endl;
				cout << " |                                                             |" << endl;
				cout << " | - Enter: \"1\" to go to Previous Menu.                        |" << endl;
				cout << " | - Enter Any Key to go back to MAIN menu                     |" << endl;
				cout << " +-------------------------------------------------------------+" << endl;
				cout << " |" << endl;
				cout << " +---[Confirm]--> ";
				getline(cin, temp_s); CLEAR;
				stringstream(temp_s) >> temp_i;

				system("cls");
				if (temp_i != 1)
				{
					return;
				}
				else
				{
					goto Output;
				}
			}

			default:
			{
				if(!debug)
				{
					system("cls");
					cout << " +-------------------------------------------------------------+" << endl;
					cout << " | [ ERROR ] - Invalid Input                                   |" << endl;
					cout << " +-------------------------------------------------------------+\a" << endl;
					goto Output;
				}
				else
				{
					cout << " |\n";
					cout << " +-------------------------------------------------------------+" << endl;
					cout << " | Currently have : " << Tracer::CurrentUsage() << " Bytes in HEAP" << endl;
					cout << " +-------------------------------------------------------------+" << endl;
					cout << endl; system("pause"); system("cls"); goto Output;
				}
			}
		}
	}

}

namespace Secrets
{
	void SecretMSG()
	{
		HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << setcolour(GREEN, chandle);
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " | [ 777 ]                Presented By                 [ 777 ] |" << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " |                                                             |" << endl;
		cout << " |  `7MMM.     ,MMF'`7MM*^*Mq.                                 |" << endl;
		cout << " |    MMMb    dPMM    MM   `MM.                                |" << endl;
		cout << " |    M YM   ,M MM    MM   ,M9    M******A'M******A'M******A'  |" << endl;
		cout << " |    M  Mb  M' MM    MMmmdM9     Y     A' Y     A' Y     A'   |" << endl;
		cout << " |    M  YM.P'  MM    MM  YM.          A'       A'       A'    |" << endl;
		cout << " |    M  `YM'   MM    MM   `Mb.       A'       A'       A'     |" << endl;
		cout << " |  .JML. `'  .JMML..JMML. .JMM.     A'       A'       A'      |" << endl;
		cout << " |                                  A'       A'       A'       |" << endl;
		cout << " |                         mmmmmmm A'       A'       A'        |" << endl;
		cout << " |                                                             |" << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " | [ 777 ]                 Since_2001                  [ 777 ] |" << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		cout << setcolour(TEAL, chandle) << "\n- Congratulations! You found a Secret!" << endl;
		cout << "- It`s " << setcolour(GREEN, chandle) << "MR_777" << setcolour(TEAL, chandle) << " , THE Creator of this Little Program :)" << endl;
		cout << setcolour(TEAL, chandle) << "- If you find any BUGS or Mistakes, Then tell me on my WhatsApp:    " << setcolour(YELLOW, chandle) << "+92 314 5401405" << endl;
		cout << setcolour(TEAL, chandle) << "- I`ve Created some Guides, You may like `em:  " << setcolour(YELLOW, chandle) << "bit.ly/H4ck3R_777" << setcolour(GREEN, chandle) << "  or  " << setcolour(YELLOW, chandle) << "bit.ly/MR_777" << endl;
		cout << setcolour(WHITE, chandle) << "\n  Thank You 4 Using my Script!\n" << endl;
		cout << setcolour(WHITE, chandle);

		cout << endl;
		system("pause");
		system("cls");
	}

	void COVID_19()
	{
		HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << setcolour(RED, chandle);
		cout << "      +-------------------------------------------------------------------------------+" << endl;
		cout << "      | [COVID_19]                 May ALLAH Save us from                  [COVID_19] |" << endl;
		cout << "      +-------------------------------------------------------------------------------+" << endl;
		cout << "      |                                                                               |" << endl;
		cout << "      |  .d8888b.   .d88888b.  888     888 8888888 8888888b.        d888   .d8888b.   | " << endl;
		cout << "      | d88P  Y88b d88P\" \"Y88b 888     888   888   888  \"Y88b      d8888  d88P  Y88b  | " << endl;
		cout << "      | 888    888 888     888 888     888   888   888    888        888  888    888  | " << endl;
		cout << "      | 888        888     888 Y88b   d88P   888   888    888        888  Y88b. d888  | " << endl;
		cout << "      | 888        888     888  Y88b d88P    888   888    888        888   \"Y888P888  | " << endl;
		cout << "      | 888    888 888     888   Y88o88P     888   888    888 888888 888         888  | " << endl;
		cout << "      | Y88b  d88P Y88b. .d88P    Y888P      888   888  .d88P        888  Y88b  d88P  | " << endl;
		cout << "      |  \"Y8888P\"   \"Y88888P\"      Y8P     8888888 8888888P\"       8888888 \"Y8888P\"   | " << endl;
		cout << "      |                                                                               |" << endl;
		cout << "      +-------------------------------------------------------------------------------+" << endl;
		cout << "      | [COVID_19]       One of the Deadliest Pandemics of the World       [COVID_19] |" << endl;
		cout << "      +-------------------------------------------------------------------------------+" << endl;
		cout << "\n" << endl;
		cout << setcolour(GREEN, chandle);
		cout << " - Track COVID-19 Details here : " << setcolour(BLUE, chandle) << "bing.com/covid" << setcolour(GREEN, chandle) << endl;
		cout << " - Watch the Documentary on COVID-19 here : " << setcolour(BLUE, chandle) << "https://www.youtube.com/watch?v=I-Yd-_XIWJg" << setcolour(GREEN, chandle) << endl;
		cout << " - I know the reason Y you entered such INPUT, that's why, I've created this little message" << endl;
		cout << " - There's no need to worry about, we had 4 Major Epidemics in past 400yrs." << endl;
		cout << " - All are gone now, but the there is new thing here," << endl;
		cout << " - Due to connectivity of the whole world, it's everywhere now" << endl;
		cout << " - So, sad to say, no one is safe now." << endl;
		cout << " - ALLAH said, \"To every desease, there is a cure!\"" << endl;
		cout << " - If U R reading this message, Pray for all MUSLIMS of the world!" << endl;
		cout << " - With best wishes, Good Luck! and Be Safe!" << endl;
		cout << "\n" << endl;
		cout << setcolour(WHITE, chandle);

		cout << " By The Way, besides all that, Thank U 4 using my Little Program!" << endl;
		cout << endl;
		system("pause");
		system("cls");
	}
}











int main()
{
	// Window Resize:

		system("mode 100,40");   //Set mode to ensure window does not exceed buffer size
		SMALL_RECT WinRect = { 0, 0, 100, 40 };   //New dimensions for window in 8x12 pixel chars
		SMALL_RECT* WinSize = &WinRect;
		SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);   //Set new size for window

	// Initialization

		system("title MR_777");
		_mkdir("Data");

	// Main Code Below:



		HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << setcolour(GREEN, chandle);
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " | [ 777 ]                Presented By :               [ 777 ] |" << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " |                                                             |" << endl;
		cout << " |  `7MMM.     ,MMF'`7MM*^*Mq.                                 |" << endl;
		cout << " |    MMMb    dPMM    MM   `MM.                                |" << endl;
		cout << " |    M YM   ,M MM    MM   ,M9    M******A'M******A'M******A'  |" << endl;
		cout << " |    M  Mb  M' MM    MMmmdM9     Y     A' Y     A' Y     A'   |" << endl;
		cout << " |    M  YM.P'  MM    MM  YM.          A'       A'       A'    |" << endl;
		cout << " |    M  `YM'   MM    MM   `Mb.       A'       A'       A'     |" << endl;
		cout << " |  .JML. `'  .JMML..JMML. .JMM.     A'       A'       A'      |" << endl;
		cout << " |                                  A'       A'       A'       |" << endl;
		cout << " |                         mmmmmmm A'       A'       A'        |" << endl;
		cout << " |                                                             |" << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " | These are my Some of the Biggest Projects, I ever started,  |" << endl;
		cout << " | in C++. I Just Combined all of them in one Single Project.  |" << endl;
		cout << " | There are some Unique Inputs, which U can use to watch my   |" << endl;
		cout << " | secret messages. Try to find those unique Inputs            |" << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		cout << endl;


		if (debug)
		{
			cout << setcolour(RED, chandle) << " [ ! ] " << setcolour(DARKTEAL, chandle) << "- Memory Tracking      : [ " << setcolour(GREEN, chandle) << "Activated!" << setcolour(DARKTEAL, chandle) << " ]" << endl;
			Tracer::PrintCurrentUsage();
		}


		cout << setcolour(GREEN, chandle);
		cout << endl;
		cout << " - Choose Operation." << endl;
		cout << " ====================" << endl;
		cout << endl;

		MAIN:

		t_CLEAR;
		cout << setcolour(WHITE, chandle);

		if(debug)
		{
			cout << setcolour(BLUE, chandle) << "0" << setcolour(WHITE, chandle) << ". | Check HEAP Memory Status" << endl;
		}

		cout << setcolour(BLUE, chandle) << "1" << setcolour(WHITE, chandle) << ". | EasyLoad Calculator" << endl;
		cout << setcolour(BLUE, chandle) << "2" << setcolour(WHITE, chandle) << ". | Values Extraction from a String" << endl;
		cout << setcolour(BLUE, chandle) << "3" << setcolour(WHITE, chandle) << ". | Guessing Game v3" << endl;
		cout << setcolour(BLUE, chandle) << "4" << setcolour(WHITE, chandle) << ". | Result Card Generator v3.1" << endl;
		cout << endl;
		cout << setcolour(GREEN, chandle) << "- Your Choice : " << setcolour(BLUE, chandle);
		getline(cin , temp_s); CLEAR;

		stringstream(temp_s) >> temp_i;


	// Decision Making & Redirection

		system("cls");
		cout << setcolour(WHITE, chandle);
		if (temp_i != 0)
		{
			switch (temp_i)
			{
				case 1:
				{
					MAIN::EasyLoad();
					break;
				}

				case 2:
				{
					MAIN::Extractor();
					break;
				}

				case 3:
				{
					MAIN::Guess_Game_start();
					break;
				}

				case 4:
				{
					MAIN::RCP();
					system("mode 100,40");
					SMALL_RECT WinRect = { 0, 0, 100, 40 };
					SMALL_RECT* WinSize = &WinRect;
					SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, WinSize);
					break;
				}

				case 5:
				{
					MAIN::Guess_Game_start_2();
					break;
				}

				case 7:
				{
					debug = !debug;
					main();
				}

				case 777:
				{
					Secrets::SecretMSG();
					break;
				}

				case 19:
				{
					Secrets::COVID_19();
					break;
				}

				default:
				{
					cout << setcolour(RED, chandle) << "Invalid Input!" << endl;
					break;
				}
			}
		}
		else
		{
			if (temp_s == "0")
			{
				if (!debug)
				{
					cout << "Why XERO Input ??? - No, there's nothing in Zero!" << endl;

					cout << endl;
					system("pause");
					system("cls");
				}
				else
				{
					Tracer::PrintCurrentUsage();
					cout << endl;
				}
			}
			else if (temp_s == "MR_777" || temp_s == "mr_777" || temp_s == "MR" || temp_s == "mr" || temp_s == "mr777")
			{
				Secrets::SecretMSG();
			}
			else if (temp_s == "COVID" || temp_s == "covid" || temp_s == "COVID-19" || temp_s == "covid-19" || temp_s == "COVID19" || temp_s == "covid19" || temp_s == "corona" || temp_s == "Corona" || temp_s == "CORONA")
			{
				Secrets::COVID_19();
			}
			else if (temp_s == "Elsa Grey" || temp_s == "ElsaGrey" || temp_s == "elsa grey" || temp_s == "elsagrey" || temp_s == "Elsa grey" || temp_s == "Elsagrey" || temp_s == "EG" || temp_s == "eg")
			{
				cout << "Elsa Grey, The Great Future Programmer!" << endl;
				cout << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << setcolour(RED, chandle) << "!!!... Invalid Input ...!!!" << endl;
			}
		}

			

	// Final Message will come 1st

		cout << setcolour(GREEN, chandle);
		cout << "\n" << endl;
		cout << "----------------------------------------" << endl;
		cout << ">-    Script Created by  ./" << setcolour(DARKGREEN, chandle) << "MR_777     -<" << endl;
		cout << ">--    ThanX 4 using my Script!      --<" << endl;
		cout << ">---     Press Ctrl+C to Exit       ---<" << endl;
		cout << "========================================\n" << endl;
		cout << setcolour(WHITE, chandle);

	// Recursive

		goto MAIN;
}




//+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+>
//                                           |
// ------------- Changelog ----------------- >
//                                           |
// - Now all the External files will be      >
//   generated inside of the "Data" folder   >
//                                           |
// - Added NEW Look on all Banners           >
//                                           |
// - Simplified the Namespaces for RCP       >
//                                           |
// - Removed unnecessary Namespaces          >
//                                           |
// - Added all the Arethmatic Functions in   >
//   "Utilities" namespace.                  >
//                                           |
// - Used already initialized temporary      >
//   variables where possible, (everywhere)  >
//                                           |
// - Used lvalues, rvalues, lvalue ref.,     >
//   and rvalue references where possible    >
//                                           |
// - Integrated an all new "Debug Mode" in   >
//   all programs. Enter "7" in the MAIN     >
//   MENU to toggle the "DEBUG MODE".        >
//                                           |
// - Used SINGLETON Design Pattern in tracer >
//                                           |
// - According to BENCHMARK Tests, "endl"    >
//   takes ~33ms to end the line, and '\n'   >
//   takes specifically shorter time. So, I  >
//   have used MACRO to replace every endl   >
//                                           |
// - Guessing game menu fixed a bit.         >
//                                           |
// - Used "rvalue reference" in Write(),     >
//   Scan() and PT_AGE()                     >
//                                           |
// - Used round of technique in PT_AGE()     |
//   to round off number to at least two     |
//   decimal places                          |
//                                           |
// - In Scan() function :                    >
//                                           |
//   (+) Used temp_s string                  >
//   (+) Used Vector Optimization            >
//   (+) Used +2 increment loop for speed    >
//   (-) Used Subject Constructor for Opt.   >
//                                           |
// - Used move semantics in Subject's        >
//   constructor (Overloaded)                >
//                                           |
// - Optimized the Scan() function in terms  >
//   of speed and memory consumption         >
//                                           |
// - Many Performance Improvements           >
//                                           |
// - Updated the Format of Changelog :)      >
// - Added Flaws Section Below               >
//                                           |
//+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+>




//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_->
//                                           |
// ---------------- Flaws ------------------ >
//                                           |
// - One major Memory defect in my program   >
//   is, that it uses the memory for the     >
//   name and total marks of Subjects. This  >
//   program stores the name and total       >
//   marks of each student in its own ID.    >
//   I mean, it was possible to make the     >
//   names of subject static. And deciding   >
//   the nature of total marks. It requires  >
//   a little refactoring, as I dont have    >
//   enough time to think on it. If you      >
//   have any suggestions to improve its     >
//   structure, please inform me. It'll be   >
//   appreciated.                            >
//                                           |
// - Another problem is, that it should      >
//   count the number of Subjects being      >
//   constructed. So that, they can be       >
//   used in the Result loops. It will       >
//   solve ZERO SUBJECT issue. As, if the    >
//   subjects are zero, the program will     >
//   crash at the runtime.                   >
//                                           |
// - Another thing, which needs improvement  >
//   is the sorting algorithm. It malfun-    >
//   ctions sometimes while generating list  >
//   "Subject wise"                          >
//                                           |
//-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_->
