#include "Application.h"
#define main WinMain
using namespace std;

int main()
{
	Application app("2048");
	app.runLoop();
}