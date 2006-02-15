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
	this->playlist = new QList<QalfAudioFile*>() ;
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
	Q_UNUSED(parent);

	QalfAudioFile * song = this->playlist->value(row) ;
	const QMetaObject * audioFileClass = song->metaObject() ;
	QMetaProperty property = audioFileClass->property(column);
	QVariant * value = new QVariant(property.read(song)) ;
	return QAbstractItemModel::createIndex(row,column, value) ;
}

int QalfPlaylistModel::rowCount (const QModelIndex & parent) const
{
	Q_UNUSED(parent);
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
		QalfAudioFile * song = this->playlist->at(index.row()) ;
		const QMetaObject * audioFileClass = song->metaObject() ;
		QMetaProperty property = audioFileClass->property(index.column());
		QVariant * value = new QVariant(property.read(song)) ;
		return value ;
	}
	else
		return QVariant();
}

bool QalfPlaylistModel::setData (const QModelIndex & index, const QVariant & value, int role )
{
	if (index.isValid() && role == Qt::EditRole) {
		QalfAudioFile * song = this->playlist->at(index.row()) ;
		const QMetaObject * audioFileClass = song->metaObject() ;
		QMetaProperty property = audioFileClass->property(index.column());
		bool hasWriten = property.write(song, value);
		if(hasWriten)
		{
			emit dataChanged(index, index);
			return true;
		}
	}
	return false;
}

Qt::ItemFlags QalfPlaylistModel::flags (const QModelIndex & index) const
{
	if (!index.isValid())
		return Qt::ItemIsEnabled;

	return Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsEnabled ;
}

bool QalfPlaylistModel::insertRows (int position, int rows, const QModelIndex & parent)
{
	Q_ASSERT(rows > 0);
	Q_ASSERT(position >= 0 && position <= this->playlist->size());
	Q_UNUSED(parent);
	beginInsertRows(QModelIndex(), position, position+rows-1);

	for (int row = 0; row < rows; ++row) {
		this->playlist->insert(position, new QalfAudioFile());
	}

	endInsertRows();
	return true;
}

bool QalfPlaylistModel::removeRows (int position, int rows, const QModelIndex & parent)
{
	Q_UNUSED(parent);
	beginRemoveRows(QModelIndex(), position, position+rows-1);

	for (int row = 0; row < rows; ++row) {
		this->playlist->removeAt(position);
	}

	endRemoveRows();
	return true ;
}

int QalfPlaylistModel::columnCount (const QModelIndex & parent) const
{
	Q_UNUSED(parent);
	QalfAudioFile audioFileObject ;
	const QMetaObject * audioFileClass = audioFileObject.metaObject();
	return  audioFileClass->propertyCount();
}

QVariant QalfPlaylistModel::headerData (int section, Qt::Orientation orientation, int role) const
{
	Q_UNUSED(role);
	if (orientation == Qt::Horizontal)
	{
		QalfAudioFile audioFileObject ;
		const QMetaObject * audioFileClass = audioFileObject.metaObject();
		QMetaProperty property = audioFileClass->property(section) ;
		return QString(property.name()) ;
	}
	return QVariant();
}
