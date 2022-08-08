#include "MyLibrary.h"

int main()
{
	const my_self TheMR = "TheMR";

	const student my_students[] = { "Gray", "FTM", "Hanzala" };
	const partner my_partners[] = { "Gray", "Harris", "Shaban", "Noman" };

	for (const auto& my_student : my_students)
	{
		using std_t = std::remove_cvref_t<decltype(my_student)>;
		QObject::connect(&TheMR, &decltype(TheMR)::call_everyone, &my_student, &std_t::respond);
		QObject::connect(&TheMR, &decltype(TheMR)::call_students, &my_student, &std_t::respond);
	}

	for (const auto& my_partner : my_partners)
	{
		using ptr_t = std::remove_cvref_t<decltype(my_partner)>;
		QObject::connect(&TheMR, &decltype(TheMR)::call_everyone, &my_partner, &ptr_t::respond);
		QObject::connect(&TheMR, &decltype(TheMR)::call_partners, &my_partner, &ptr_t::respond);
	}

	TheMR.call_everyone("Comrades!");
}