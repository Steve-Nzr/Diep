#include "config.h"
#include <iostream>
#include "Window/WindowHandler.hh"

using namespace std;
using namespace Diep::Window;

int main(int argc, char* argv[]) {
    WindowHandler wnd{600, 400, "Hey !"};
    wnd.InitializeSystems();
    wnd.InitializeEntities();
    wnd.Start();
    wnd.Stop();
}