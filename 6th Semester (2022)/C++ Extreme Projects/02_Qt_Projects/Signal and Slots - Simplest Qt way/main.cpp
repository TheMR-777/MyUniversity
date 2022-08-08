#include "MyLibrary.hpp"

int main()
{
    Captain TheMR = "TheMR";

    Partner my_partners[] = { "Harris", "Shaban", "Noman" };

    for (const auto& partner : my_partners)
    {
        using ptr_t = std::remove_cvref_t<decltype(partner)>;
        QObject::connect(&TheMR, &decltype(TheMR)::call_everyone, &partner, &ptr_t::respond);
    }

    TheMR.call_everyone("Attention!");
}
