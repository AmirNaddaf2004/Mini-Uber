#include "snap.hpp"

using namespace std;

int main()
{
    Snap* snap = new Snap();
    snap->handle_command();
    delete snap;
    return 0;
}