#include "nfd.hpp"

#include <iostream>

/* this test should compile on all supported platforms */
/* this demonstrates the thin C++ wrapper */

int main()
{
    // initialize NFD
    NFD::Guard nfdGuard;

    nfdchar_t *outPath = nullptr;

    // prepare filters for the dialog
    nfdfilteritem_t filterItem[2] = { { "Source code", "c,cpp,cc" },{ "Headers", "h,hpp" } };

    // show the dialog
    nfdresult_t result = NFD::OpenDialog(filterItem, 2, nullptr, outPath);
    if (result == NFD_OKAY)
    {
        std::cout << "Success!" << std::endl << outPath << std::endl;
        // remember to free the memory (since NFD_OKAY is returned)
        NFD::FreePath(outPath);
    }
    else if (result == NFD_CANCEL)
    {
        std::cout << "User pressed cancel." << std::endl;
    }
    else
    {
        std::cout << "Error: " << NFD::GetError() << std::endl;
    }

    // NFD::Guard will automatically quit NFD.
    return 0;
}
