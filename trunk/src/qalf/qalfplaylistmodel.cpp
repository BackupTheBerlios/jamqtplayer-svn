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
#include <QDebug>

QalfPlaylistModel::QalfPlaylistModel()
{
	this->playlist = new QList<QalfAudioFile*>() ;
	this->currentSong = -1 ;
}

void QalfPlaylistModel::next()
{
	if(this->currentSong < this->playlist->size()-1) {
		++currentSong ;
	}
}

void QalfPlaylistModel::previous()
{
	if(this->currentSong > -1) {
		--currentSong ;
	}
}

void QalfPlaylistModel::clear()
{
	this->playlist->clear() ;
}

void QalfPlaylistModel::insertSong(int row,QalfAudioFile * song)
{
	beginInsertRows(QModelIndex(), row, row);
	this->playlist->insert(row, song);
	endInsertRows();
}

void QalfPlaylistModel::appendSong(QalfAudioFile * song)
{
	Q_ASSERT(this->playlist->size() >= 0) ;
	beginInsertRows(QModelIndex(), this->playlist->size(), this->playlist->size());
	this->playlist->append(song);
	endInsertRows();
}

void QalfPlaylistModel::prependSong(QalfAudioFile * song)
{
	beginInsertRows(QModelIndex(), 0, 0);
	this->playlist->prepend(song);
	endInsertRows();
}

void QalfPlaylistModel::insertSongAfterCurrent(QalfAudioFile * song)
{
	beginInsertRows(QModelIndex(), this->currentSong, this->currentSong);
	this->playlist->insert(this->currentSong, song);
	endInsertRows();
}

QModelIndex QalfPlaylistModel::index(int row,int column,const QModelIndex & parent) const
{
	Q_ASSERT(row >= 0);
	Q_ASSERT(column >= 0);
	Q_UNUSED(parent);

	QalfAudioFile * song = this->playlist->value(row) ;
	const QMetaObject * audioFileClass = song->metaObject() ;
	QMetaProperty property = audioFileClass->property(column+1);
	QVariant * propertyValue = new QVariant(property.read(song)) ;
	
	qDebug() << "[index] property:" << property.name() << " property value:" << *propertyValue;
	return QAbstractItemModel::createIndex(row,column, propertyValue) ;
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
		QMetaProperty property = audioFileClass->property(index.column()+1);
		QVariant * value = new QVariant(property.read(song)) ;
		qDebug() << "[data] property:" << property.name() << " property value:" << *value;
		return *value ;
	}
	else
		return QVariant();
}

bool QalfPlaylistModel::setData (const QModelIndex & index, const QVariant & value, int role )
{
	if (index.isValid() && role == Qt::EditRole) {
		QalfAudioFile * song = this->playlist->at(index.row()) ;
		const QMetaObject * audioFileClass = song->metaObject() ;
		QMetaProperty property = audioFileClass->property(index.column()+1);
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
	QalfAudioFile * audioFileObject = new QalfAudioFile();
	const QMetaObject * audioFileClass = audioFileObject->metaObject();
	delete(audioFileObject) ;
	return  audioFileClass->propertyCount()-1;
}

QVariant QalfPlaylistModel::headerData (int section, Qt::Orientation orientation, int role) const
{
	Q_UNUSED(role);
	if (orientation == Qt::Horizontal)
	{
		QalfAudioFile audioFileObject ;
		const QMetaObject * audioFileClass = audioFileObject.metaObject();
		QMetaProperty property = audioFileClass->property(section+1) ;
		return QString(property.name()) ;
	}
	return QVariant();
}
