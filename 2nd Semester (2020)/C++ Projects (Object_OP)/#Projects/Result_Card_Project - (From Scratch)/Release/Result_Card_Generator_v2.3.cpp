#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <direct.h>
using namespace std;

struct Subject
{
	int ID;
	string name;
	float o_marks;
	int t_marks;
};

struct Profile
{
	int ID;
	string name;
	string roll;
	vector<Subject> subjects;
};



static float temp_f = 0.0;
static int temp_i = 0;
static string temp_s = "Unknown";



namespace class_function
{
	float Sub_Sum(const vector<Subject> &sbj, bool op)
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

	float PT_AGE(const float obt, const float total)
	{
		return ((obt * 100) / total);
	}
}

namespace custom
{
	void getline(std::istream& in, std::string& word, char delim = '\n')
	{
		char ch;

		do
		{
			in.get(ch);
			word += ch;
		} while (ch != delim);
	}
}

namespace External
{
	void Write(vector<Subject> sbj, string filename)
	{
		ofstream o_file(filename);

		for (int i = 0; i < sbj.size(); i++)
		{
			o_file << sbj[i].name << endl;
			o_file << sbj[i].t_marks << endl;
		}

		o_file.close();
	}

	vector<Subject> Scan(string filename)
	{
		// Initialization

		string temp_s;
		Subject subject_t;
		vector<string> data;
		vector<Subject> subjects;
		ifstream i_file(filename);

		// Scanning

		while (getline(i_file, temp_s))
		{
			data.push_back(temp_s);
		}

		// Filling Subjects

		for (int i = 0; i < data.size(); i++)
		{
			if (i % 2 == 0)
			{
				subject_t.name = data[i];
				subject_t.t_marks = stoi(data[i + 1]);
				subjects.push_back(subject_t);
			}
		}

		// Finalization

		i_file.close();
		return subjects;
	}
}

namespace Utilities
{

	void spaces(ostream &FILE, int size_in, int required = 30)
	{
		int loop = required - size_in;

		for (int i = 0; i < loop; i++)
		{
			FILE << " ";
		}

	}

	int float_count(float f)
	{
		string s;
		stringstream out;
		out << f;
		s = out.str();

		return s.length();
	}



	void Settings(vector<Subject> &subjects)
	{
		// Initialization

		temp_i = 0;
		temp_s = "";
		subjects.clear();
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
		cout << " | [ 2 ] - Go back to Main Menu                                    |" << endl;
		cout << " |                                                                 |" << endl;
		cout << " +-----------------------------------------------------------------+" << endl;
		cout << " |" << endl;
		cout << " +--[Input]--> ";
		getline(cin, temp_s); cin.clear(); cin.sync();
		stringstream(temp_s) >> temp_i;

		system("cls");
		switch (temp_i)
		{
		case 1:
		{
			// Input Menu

			cout << " +-----------------------------------------------------------------+" << endl;
			cout << " | Enter names of the Subjects as asked. Enter \"F\" when finished   |" << endl;
			cout << " | entering names of the subjects.                                 |" << endl;
			cout << " | --------------------------------------------------------------- |" << endl;
			cout << " | Answer a little question first, does all the subjects have same |" << endl;
			cout << " | total markes ?                                                  |" << endl;
			cout << " |" << endl;
			cout << " +--{Y/N}--> ";
			getline(cin, temp_s); cin.clear(); cin.sync();

			// If total marks are Identical

			if (temp_s == "Y" || temp_s == "y")
			{
				cout << " |" << endl;
				cout << " | Enter Total marks for all subjects : ";
				getline(cin, temp_s); cin.clear(); cin.sync();
				stringstream(temp_s) >> total;
				same = 1;
			}
			else
			{
				same = 0;
			}
			cout << " |" << endl;

			// Inputting begins here

			for (int i = 0; true; i++)
			{
				cout << " | --------------------------------------------------------------- |" << endl;
				cout << " | Enter name of Subject #" << i + 1 << " : ";
				getline(cin, temp_s); cin.clear(); cin.sync();

				if (temp_s != "F" && temp_s != " F" && temp_s != "F " && temp_s != " F " && temp_s != "f" && temp_s != " f" && temp_s != "f " && temp_s != " f ")
				{
					subject_t.name = temp_s;
				}
				else
				{
					External::Write(subjects, "Subjects");
					temp_s = "";
					break;
				}


				if (same == 0)
				{
					cout << " | Enter Total marks of " << temp_s << " : ";
					getline(cin, temp_s); cin.clear(); cin.sync();
					stringstream(temp_s) >> subject_t.t_marks;
				}
				else
				{
					subject_t.t_marks = total;
				}

				subjects.push_back(subject_t);
			}

			break;
		}

		case 2:
		{
			return;
		}

		default:
		{
			cout << " +-----------------------------------------------------------------+" << endl;
			cout << " | [ ERROR ] - Invalid Input                                       |" << endl;
			cout << " +-----------------------------------------------------------------+" << endl;
			goto Settings;
			break;
		}
		}
	}


	void Input(vector<Profile> &students, vector<Subject> &subjects)
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
					cin.clear();
					cin.sync();
					system("cls");
					break;
				}


				// Inputting Roll number

				cout << " |-------------------------------------------------------------|" << endl;
				cout << " | - Enter Roll Number of " << std_t.name << " : ";
				getline(cin, std_t.roll);
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

				cin.clear();
				cin.sync();
				cout << " +-------------------------------------------------------------+" << endl;
				cout << " | Check the above Informaion U entered. Enter 0 to make       |" << endl;
				cout << " | changes, or Enter any other key to Move Forward.            |" << endl;
				cout << " +-------------------------------------------------------------+" << endl;
				cout << " |" << endl;
				cout << " +---> Input : ";
				getline(cin, temp_s);

				// Flushing + Finalization

				temp_f = 0.0;
				system("cls");
				cin.clear();
				cin.sync();

				if (temp_s == "0")
				{
					temp_f = 1;
					goto ID_ing;
				}
				else
				{
					temp_s = "";
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

	void sort(vector<Profile> &students, int op, int i = 0)
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
				receptor.push_back(class_function::Sub_Sum(students[i].subjects, false));
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
		/*
			for (int i=0 ; i < (V.size()-1) ; i++)
			{
				for (int j=(i+1) ; j < V.size() ; j++)
				{
					if (op == 0)
					{
						if (V[j] < V[i])
						{
							temp = V[j];
							V[j] = V[i];
							V[i] = temp;
						}
					}
					else
					{
						if (V[j] > V[i])
						{
							temp = V[j];
							V[j] = V[i];
							V[i] = temp;
						}
					}
				}
			}
		*/
	}
}

namespace Result_External
{
	void Result_Gen(const vector<Profile> &students)
	{
		// Initializing Temporary Stuff

		_mkdir("General List");
		ofstream General_File("General List\\General_List.txt");
		temp_s = "";
		temp_f = 0.0;
		float flt_o, flt_t;

		if (General_File.is_open() != 1)
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

			flt_o = class_function::Sub_Sum(students[students[i].ID].subjects, false);
			General_File << flt_o;
			Utilities::spaces(General_File, Utilities::float_count(flt_o), 17);

			// Total Marks

			flt_t = class_function::Sub_Sum(students[students[i].ID].subjects, true);
			General_File << flt_t;
			Utilities::spaces(General_File, Utilities::float_count(flt_t), 17);

			// Percentage

			temp_f = class_function::PT_AGE(flt_o, flt_t);
			General_File << temp_f;
			Utilities::spaces(General_File, Utilities::float_count(temp_f), 10);

			// Roll_Number

			General_File << students[i].roll;
			Utilities::spaces(General_File, students[i].roll.size(), 25);
			General_File << "|" << endl;

			// Flushing

			temp_s = "";
			temp_f = 0.0;
			flt_o = 0.0;
			flt_t = 0.0;
		}

		General_File << " |                                                                                                    |" << endl;
		General_File << " +----------------------------------------------------------------------------------------------------+" << endl;
		General_File << endl;
		General_File.close();
	}

	void Subject_wise(vector<Profile> &students)
	{
		// Initializing Temporary Stuff

		_mkdir("Subject wise list");
		temp_s = "";
		temp_f = 0.0;

		// Result Card

		for (int i = 0; i < students[0].subjects.size(); i++)
		{
			ofstream Brilliant_Student("Subject wise list\\" + (students[0].subjects[i].name + ".txt"));

			Utilities::sort(students, 3, i);
			Brilliant_Student << endl;
			Brilliant_Student << " +----------------------------------------------------------------------------------------------------+" << endl;
			Brilliant_Student << " | Subject [ " << i + 1 << " / " << students[0].subjects.size() << " ] - " << students[0].subjects[i].name; Utilities::spaces(Brilliant_Student, students[0].subjects[i].name.size(), 70); Brilliant_Student << "//////// |" << endl;
			Brilliant_Student << " +----------------------------------------------------------------------------------------------------+" << endl;
			Brilliant_Student << " | Names of Students" << "             " << "Obtained Marks" << "   " << "From (Marks)" << "     " << "%age" << "      " << "Roll_Number" << "              |" << endl;
			Brilliant_Student << " |                                                                                                    |" << endl;

			for (int j = 0; j < students.size(); j++)
			{
				// Name Generation

				Brilliant_Student << " | " << students[students[j].ID].name;
				Utilities::spaces(Brilliant_Student, students[students[j].ID].name.size());

				// Obtained Marks

				Brilliant_Student << students[students[j].ID].subjects[i].o_marks;
				Utilities::spaces(Brilliant_Student, Utilities::float_count(students[students[j].ID].subjects[i].o_marks), 17);

				// Total Marks

				Brilliant_Student << students[students[j].ID].subjects[i].t_marks;
				Utilities::spaces(Brilliant_Student, Utilities::float_count(students[students[j].ID].subjects[i].t_marks), 17);

				// Percentage

				temp_f = class_function::PT_AGE(students[students[j].ID].subjects[i].o_marks, students[students[j].ID].subjects[i].t_marks);
				Brilliant_Student << temp_f;
				Utilities::spaces(Brilliant_Student, Utilities::float_count(temp_f), 10);

				// Roll_Number

				Brilliant_Student << students[students[j].ID].roll;
				Utilities::spaces(Brilliant_Student, students[j].roll.size(), 25);
				Brilliant_Student << "|" << endl;

				// Flushing

				temp_s = "";
				temp_f = 0.0;
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

		_mkdir("Student wise List");
		temp_s = "";
		temp_f = 0.0;

		// Result Card

		for (int i = 0; i < students.size(); i++)
		{
			ofstream Genius_Student("Student wise List\\" + (students[i].name + ".txt"));

			Genius_Student << endl;
			Genius_Student << " +----------------------------------------------------------------------------------------------------+" << endl;
			Genius_Student << " | Student [ " << i + 1 << " / " << students.size() << " ] - " << students[i].name; Utilities::spaces(Genius_Student, students[i].name.size(), 70); Genius_Student << "//////// |" << endl;
			Genius_Student << " +----------------------------------------------------------------------------------------------------+" << endl;
			Genius_Student << " | Names of Subjects" << "             " << "Obtained Marks" << "   " << "From (Marks)" << "     " << "%age" << "      " << "Grade | Points" << "           |" << endl;
			Genius_Student << " |                                                                                 |                  |" << endl;

			for (int j = 0; j < students[i].subjects.size(); j++)
			{
				// Name Generation

				Genius_Student << " | " << students[i].subjects[students[i].subjects[j].ID].name;
				Utilities::spaces(Genius_Student, students[i].subjects[students[i].subjects[j].ID].name.size());

				// Obtained Marks

				Genius_Student << students[i].subjects[students[i].subjects[j].ID].o_marks;
				Utilities::spaces(Genius_Student, Utilities::float_count(students[i].subjects[students[i].subjects[j].ID].o_marks), 17);

				// Total Marks

				Genius_Student << students[i].subjects[students[i].subjects[j].ID].t_marks;
				Utilities::spaces(Genius_Student, Utilities::float_count(students[i].subjects[students[i].subjects[j].ID].t_marks), 17);

				// Percentage

				temp_f = class_function::PT_AGE(students[i].subjects[students[i].subjects[j].ID].o_marks, students[i].subjects[students[i].subjects[j].ID].t_marks);
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

				temp_s = "";
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

		temp_s = "";
		float flt_o, flt_t;
		temp_f = 0.0;

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

			flt_o = class_function::Sub_Sum(students[students[i].ID].subjects, false);
			cout << flt_o;
			Utilities::spaces(cout, Utilities::float_count(flt_o), 17);

			// Total Marks

			flt_t = class_function::Sub_Sum(students[students[i].ID].subjects, true);
			cout << flt_t;
			Utilities::spaces(cout, Utilities::float_count(flt_t), 17);

			// Percentage

			temp_f = class_function::PT_AGE(flt_o, flt_t);
			cout << temp_f;
			Utilities::spaces(cout, Utilities::float_count(temp_f), 10);

			// Roll_Number

			cout << students[i].roll;
			Utilities::spaces(cout, students[i].roll.size(), 25);
			cout << "|" << endl;

			// Flushing

			temp_s = "";
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

		string temp_s;
		temp_f = 0.0;

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
				// Name Generation

				cout << " | " << students[students[j].ID].name;
				Utilities::spaces(cout, students[students[j].ID].name.size());

				// Obtained Marks

				cout << students[students[j].ID].subjects[i].o_marks;
				Utilities::spaces(cout, Utilities::float_count(students[students[j].ID].subjects[i].o_marks), 17);

				// Total Marks

				cout << students[students[j].ID].subjects[i].t_marks;
				Utilities::spaces(cout, Utilities::float_count(students[students[j].ID].subjects[i].t_marks), 17);

				// Percentage

				temp_f = class_function::PT_AGE(students[students[j].ID].subjects[i].o_marks, students[students[j].ID].subjects[i].t_marks);
				cout << temp_f;
				Utilities::spaces(cout, Utilities::float_count(temp_f), 10);

				// Roll_Number

				cout << students[students[j].ID].roll;
				Utilities::spaces(cout, students[j].roll.size(), 25);
				cout << "|" << endl;

				// Flushing

				temp_s = "";
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

		string temp_s;
		temp_f = 0.0;

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
				// Name Generation

				cout << " | " << students[i].subjects[students[i].subjects[j].ID].name;
				Utilities::spaces(cout, students[i].subjects[students[i].subjects[j].ID].name.size());

				// Obtained Marks

				cout << students[i].subjects[students[i].subjects[j].ID].o_marks;
				Utilities::spaces(cout, Utilities::float_count(students[i].subjects[students[i].subjects[j].ID].o_marks), 17);

				// Total Marks

				cout << students[i].subjects[students[i].subjects[j].ID].t_marks;
				Utilities::spaces(cout, Utilities::float_count(students[i].subjects[students[i].subjects[j].ID].t_marks), 17);

				// Percentage

				temp_f = class_function::PT_AGE(students[i].subjects[students[i].subjects[j].ID].o_marks, students[i].subjects[students[i].subjects[j].ID].t_marks);
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

				temp_s = "";
				temp_f = 0.0;
			}

			cout << " |                                                                                                    |" << endl;
			cout << " +----------------------------------------------------------------------------------------------------+" << endl;
			cout << endl;
			system("pause");
		}
	}

}






int main()
{
	// Initialization

	Subject subject_t;
	vector<Subject> subjects;
	vector<Profile> students;

	// Introduction

	system("cls");
	cout << endl;
	cout << " +-------------------------------------------------------------+" << endl;
	cout << " |                        Presented By                         |" << endl;
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
	cout << " | It's a Result Card Generator. Only U have to Input the data |" << endl;
	cout << " | of students as asked. The Whole list will be generated as a |" << endl;
	cout << " | text file. Make sure to enter data correctly. I've managed  |" << endl;
	cout << " | to Optimize ID-ing Errors as far as I could in C++ Language |" << endl;
	cout << " +-------------------------------------------------------------+" << endl;
	cout << " | [ REMEMBER ] - Config the settings in the \"Settings\" first  |" << endl;
	cout << " +-------------------------------------------------------------+" << endl;
	cout << endl;
	system("pause");
	system("cls");

	// Decision


MAIN:

	cout << endl;
	cout << " +-------------------------------------------------------------+" << endl;
	cout << " | Select any of the Options below :-                          |" << endl;
	cout << " |                                                             |" << endl;
	cout << " | 1. Open Interface to Generate Result Card                   |" << endl;
	cout << " | 2. Open Settings Menu to Configure Subjects                 |" << endl;
	cout << " |                                                             |" << endl;
	cout << " +-------------------------------------------------------------+" << endl;
	cout << " |" << endl;
	cout << " +---[Input]---> ";
	getline(cin, temp_s);
	stringstream(temp_s) >> temp_i;
	cin.clear(); cin.sync();

	system("cls");
	switch (temp_i)
	{
	case 1:
	{
		vector<Subject> subjects = External::Scan("Subjects");
		subjects.shrink_to_fit();
		if (subjects.empty())
		{
			cout << " +-------------------------------------------------------------+" << endl;
			cout << " | [ ! ] - Please Configure Settings first                     |" << endl;
			cout << " +-------------------------------------------------------------+" << endl;
			goto MAIN;
		}
		else
		{
			Utilities::Input(students, subjects);
			cout << endl;
			break;
		}

	}

	case 2:
	{
		Utilities::Settings(subjects);
		system("cls");

		if (!subjects.empty())
		{
			cout << " +-------------------------------------------------------------+" << endl;
			cout << " | [ OK ] - Settings configured Successfully!                  |" << endl;
			cout << " +-------------------------------------------------------------+" << endl;
		}
		else
		{
			cout << " +-------------------------------------------------------------+" << endl;
			cout << " | [ WARNING ] - Subjects are still un-configured!             |" << endl;
			cout << " +-------------------------------------------------------------+" << endl;
		}

		goto MAIN;
		break;
	}


	default:
	{
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " | [ ERROR ] - Invalid Input                                   |" << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		goto MAIN;
		break;
	}
	}




	// Menu For Type of Result

Result_Menu:

	cout << " +-------------------------------------------------------------+" << endl;
	cout << " |          Enter type of the result u wanna Generate          |" << endl;
	cout << " +-------------------------------------------------------------+" << endl;
	cout << " |                                                             |" << endl;
	cout << " | 1. General List for all Students                            |" << endl;
	cout << " | 2. Students-Wise List for Every Student                     |" << endl;
	cout << " | 3. Subject-Wise List, for every Subject                     |" << endl;
	cout << " |                                                             |" << endl;
	cout << " | 8. Go to Main Menu                                          |" << endl;
	cout << " | 9. Output File Generation                                   |" << endl;
	cout << " |                                                             |" << endl;
	cout << " +-------------------------------------------------------------+" << endl;
	cout << " |" << endl;
	cout << " |" << endl;
	cout << " +----[Input]---> ";
	getline(cin, temp_s);
	cin.clear(); cin.sync();

	stringstream(temp_s) >> temp_i;

	system("cls");
	switch (temp_i)
	{
	case 1:
	{
		Utilities::sort(students, 1);
		Result::Result_Gen(students);
		system("pause");
		system("cls");
		goto Result_Menu;
	}

	case 2:
	{
		Utilities::sort(students, 2);
		Result::Student_wise(students);
		system("cls");
		goto Result_Menu;
	}

	case 3:
	{
		Result::Subject_wise(students);
		system("cls");
		goto Result_Menu;
	}

	case 8:
	{
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " |               !!!...Confirmation Message...!!!              |" << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " | Are U sure u wanna go to back to Main Menu ?                |" << endl;
		cout << " |                                                             |" << endl;
		cout << " | All the data, except what u entered in Settings menu, will  |" << endl;
		cout << " | be lost, When you go to Mein Menu.                          |" << endl;
		cout << " |                                                             |" << endl;
		cout << " | - Enter: \"1\" to go to Result Menu.                          |" << endl;
		cout << " | - Enter Any Key to go back to Main menu                     |" << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " |" << endl;
		cout << " +---[Confirm]--> ";
		getline(cin, temp_s); cin.clear(); cin.sync();
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

	case 9:
	{
		goto Output;
	}

	default:
	{
		cout << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " | [ ERROR ] - Invalid Input                                   |" << endl;
		goto Result_Menu;
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
	cout << " | [ 8 ] - Go back to Result Menu                              |" << endl;
	cout << " | [ 9 ] - Go back to Main Menu                                |" << endl;
	cout << " |                                                             |" << endl;
	cout << " +-------------------------------------------------------------+" << endl;
	cout << " |" << endl;
	cout << " +---[Input]--> ";
	getline(cin, temp_s); cin.clear(); cin.sync();
	stringstream(temp_s) >> temp_i;

	system("cls");
	switch (temp_i)
	{
	case 1:
	{
		Result_External::Result_Gen(students);
		goto Output;
	}

	case 2:
	{
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " | [ OK ]        Output Files Generated!                       |" << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		Result_External::Student_wise(students);
		goto Output;
	}

	case 3:
	{
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " | [ OK ]        Output Files Generated!                       |" << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		Result_External::Subject_wise(students);
		goto Output;
	}

	case 4:
	{
		Result_External::Result_Gen(students);
		Result_External::Student_wise(students);
		Result_External::Subject_wise(students);
		goto Output;
	}

	case 8:
	{
		goto Result_Menu;
	}

	case 9:
	{
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " |               !!!...Confirmation Message...!!!              |" << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " | Are U sure u wanna go to back to Main Menu ?                |" << endl;
		cout << " |                                                             |" << endl;
		cout << " | All the data, except what u entered in Settings menu, will  |" << endl;
		cout << " | be lost, When you go to Main Menu.                          |" << endl;
		cout << " |                                                             |" << endl;
		cout << " | - Enter: \"1\" to go to Result Menu.                          |" << endl;
		cout << " | - Enter Any Key to go back to Main menu                     |" << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " |" << endl;
		cout << " +---[Confirm]--> ";
		getline(cin, temp_s); cin.clear(); cin.sync();
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

	default:
	{
		cout << " +-------------------------------------------------------------+" << endl;
		cout << " | [ ERROR ] - Invalid Input                                   |" << endl;
		cout << " +-------------------------------------------------------------+" << endl;
		goto Output;
	}
	}



}








/*

Changelog :

- Fixed : Success message was displaying, even the settings weren't configured
- Fixed : Code Size reduced (57_KB to 41_KB)

- Added : A New WARNING message which will be displayed, when settings aren't configed
		  properly, or if there was a problem with writing of external file.
- Added : Output files are now generated inside of the corresponding folders.
- Added : Temporary Variables are now Statically Global.
- Added : Removed the Overloaded Spaces function, and extended it's functionality,
		  by adding "ostream" as a Parameter.

- Issue : If Roll_Number of every student has large size difference, then it can
		  alter the look of Final Result Card a bit. I'm investigating the issue.
- Issue : The 1st Subject of Subject-wise list sometimes doesn't sort the
		  marks of the students. But later on, this never happens. Don't
		  know what's causing it. Everything seems properly coded

*/