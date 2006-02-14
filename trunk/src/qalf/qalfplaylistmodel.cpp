/*******************************************************
**
** Implementation of QalfPlaylistModel
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

#include "qalfplaylistmodel.h"

QalfPlaylistModel::QalfPlaylistModel()
{
	this->playlist = new QList<QalfAudioFile>() ;
}

void QalfPlaylistModel::next()
{

}

void QalfPlaylistModel::previous()
{

}

void QalfPlaylistModel::clear()
{

}

QModelIndex QalfPlaylistModel::index(int row,int column,const QModelIndex & parent) const
{
	Q_ASSERT(row >= 0);
	Q_ASSERT(column >= 0);

	QalfAudioFile song = this->playlist->at(row) ;
	QVariant item = this->getColumn(column,song) ;
	return QAbstractItemModel::createIndex(row,column, &item) ;
}

int QalfPlaylistModel::rowCount (const QModelIndex & parent) const
{
	return this->playlist->size() ;
}

QVariant QalfPlaylistModel::data (const QModelIndex & index, int role) const
{
	if (!index.isValid())
		return QVariant();

	if (index.row() >= this->playlist->size())
		return QVariant();

	if (role == Qt::DisplayRole)
	{
		QalfAudioFile song = this->playlist->at(index.row()) ;
		return this->getColumn(index.column(),song);
	}
	else
		return QVariant();
}

// bool QalfPlaylistModel::setData (const QModelIndex & index, const QVariant & value, int role )
// {
// // 	if (index.isValid() && role == Qt::EditRole) {
// // 		this->playlist.replace(index.row(), value.toString());
// // 		emit dataChanged(index, index);
// // 		return true;
// // 	}
// 	return false;
// }
// 
// Qt::ItemFlags QalfPlaylistModel::flags (const QModelIndex & index) const
// {
// 	if (!index.isValid())
// 		return Qt::ItemIsEnabled;
// 
// 	return Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsEnabled ;
// }
// 
// bool QalfPlaylistModel::insertRows (int row, int count, const QModelIndex & parent)
// {
// 	Q_ASSERT(count > 0);
// 	Q_ASSERT(row >= 0 && row <= this->playlist->size());
// 	beginInsertRows (parent, row,row+count) ;
// 	
// 	endInsertRows();
// 	return true;
// }
// 
// bool QalfPlaylistModel::removeRows (int row, int count, const QModelIndex & parent)
// {
// 	return true ;
// }

int QalfPlaylistModel::columnCount (const QModelIndex & parent) const
{
	return 5 ;
}

QVariant QalfPlaylistModel::headerData (int section, Qt::Orientation orientation, int role) const
{
	return QString("toto") ;
}

QVariant QalfPlaylistModel::getColumn(const int column, const QalfAudioFile & song) const
{
	switch(column)
	{
		case 0:
			return song.getTrack() ;
		break;
	}
	Q_ASSERT(true) ;
	return QString() ;
}
