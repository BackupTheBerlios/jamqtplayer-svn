/*******************************************************
**
** Definition of JamQtPlayer
**
** Copyright (C) 2006 Francois Gaudin.
**
** JamQtPlayer is free software; you can redistribute
** it and/or modify it under the terms of the GNU
** Library General Public License as published by the
** Free Software Foundation; either version 2, or (at
** your option) any later version.
**
********************************************************/
#include <QApplication>

#include "qalf/qalfmainwindow.h"

int main(int argc, char *argv[])
{
	// Initialization of main window
	QApplication app(argc, argv);
	QalfMainWindow mainWin;

	// initialization of file browser
	QDirModel *fileModel = new QDirModel;
	mainWin.setFileModel(fileModel);
	mainWin.show();
	return app.exec();
}
