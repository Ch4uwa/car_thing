#include "pch.h"
#include "Application.h"
#include "appStateStart.h"

int main()
{
	Application application;

	application.pushState(new appStateStart(&application));
	application.appLoop();



}

