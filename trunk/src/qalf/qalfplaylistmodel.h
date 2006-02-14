/*******************************************************
**
** Definition of QalfPlaylistModel
**
** Copyright (C) 2006 Francois Gaudin.
**
** QalfPlaylistModel is free software; you can redistribute
** it and/or modify it under the terms of the GNU
** Library General Public License as published by the
** Free Software Foundation; either version 2, or (at
** your option) any later version.
**
********************************************************/

#ifndef QalfPLAYLISTMODEL_H
#define QalfPLAYLISTMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include "qalfaudiofile.h"

class QalfPlaylistModel : public QAbstractTableModel
{
	Q_OBJECT

	public:
		QalfPlaylistModel();
		QModelIndex index(int row,int column,const QModelIndex & parent = QModelIndex()) const;
		int rowCount (const QModelIndex & parent = QModelIndex()) const = 0;
		int columnCount (const QModelIndex & parent = QModelIndex()) const = 0;
		QVariant data (const QModelIndex & index, int role = Qt::DisplayRole) const = 0;
		QVariant headerData (int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
// 		bool setData (const QModelIndex & index, const QVariant & value, int role = Qt::EditRole ) ;
// 		Qt::ItemFlags flags (const QModelIndex & index) const ;
// 		bool insertRows (int row, int count, const QModelIndex & parent = QModelIndex());
// 		bool removeRows (int row, int count, const QModelIndex & parent = QModelIndex());

	signals:
		void songChanged() ;

	public slots:
		void next();
		void previous() ;
		void clear();
	
	private:
		QList<QalfAudioFile> * playlist;
		QVariant getColumn(const int column, const QalfAudioFile & song) const ;

};

#endif // QalfPLAYLISTVIEW_H
