#include <fmt/color.h>
#include <QCoreApplication>
using my_data_type = std::string_view;

namespace internals
{
	template <class T>
	concept acceptable = std::convertible_to<T, my_data_type>;

	class persona: public QObject
	{
	protected:
		const my_data_type my_name = "N/A";
		constexpr explicit persona(const auto& data) : my_name(data) {}
	};
}


struct my_self: internals::persona
{
	constexpr my_self(internals::acceptable auto const& data) : persona(data) {}
	Q_OBJECT
signals:
	void call_students(my_data_type) const;
	void call_partners(my_data_type) const;
	void call_everyone(my_data_type) const;
};


struct student: internals::persona
{
	constexpr student(internals::acceptable auto const& data) : persona(data) {}
	Q_OBJECT

public slots:
	void respond(my_data_type msg) const
	{
		fmt::print("[ {:10} ] - Sir, Yes Sir! Responding to: [ {} ]\n", my_name, msg);
	}
};


struct partner: internals::persona
{
	constexpr partner(internals::acceptable auto const& data) : persona(data) {}
	Q_OBJECT

public slots:
	void respond(my_data_type msg) const
	{
		fmt::print("[ {:10} ] - Respected Sir, we are available. Responding to: [ {} ]\n", my_name, msg);
	}
};