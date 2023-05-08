#include "functionhandler.h"

FunctionHandler::FunctionHandler()
{
	;
}

// saves file
void FunctionHandler::save(UI* ui)
{
	cout << "saving" << endl;
	ui->getselimageptr()->savefile();
	cout << "save complete" << endl;
}
