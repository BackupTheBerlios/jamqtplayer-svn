/*******************************************************
**
** Implementation of QalfMainWindow
**
** Copyright (C) 2006 Francois Gaudin.
**
** QalfMainWindow is free software; you can redistribute
** it and/or modify it under the terms of the GNU
** Library General Public License as published by the
** Free Software Foundation; either version 2, or (at
** your option) any later version.
**
********************************************************/ 

#include "qalfmainwindow.h"

QalfMainWindow::QalfMainWindow()
{
	this->fileList = new QListView(this);
	this->playlistView = new QTableView(this);
	this->setCentralWidget(this->playlistView);
}

void QalfMainWindow::setFileModel(QDirModel* model) {
	this->fileList->setModel(model);
	this->fileList->setRootIndex(model->index(QDir::currentPath()));
}

void QalfMainWindow::setPlaylistModel(QalfPlaylistModel* model) {
	this->playlistView->setModel(model);
}
