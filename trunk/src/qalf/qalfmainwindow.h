/*******************************************************
**
** Definition of QalfMainWindow
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

#ifndef QalfMAINWINDOW_H
#define QalfMAINWINDOW_H

#include <QMainWindow>
#include <QDirModel>
#include <QListView>

class QalfMainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		QalfMainWindow();
		void setFileModel(QDirModel *) ;

	protected:

	private slots:
	
	private:
		QListView *fileList;
};

#endif // QalfMAINWINDOW_H
