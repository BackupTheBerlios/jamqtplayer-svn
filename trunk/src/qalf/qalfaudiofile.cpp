/*******************************************************
**
** Implementation of QalfAudioFile
**
** Copyright (C) 2006 Francois Gaudin.
**
** QalfAudioFile is free software; you can redistribute
** it and/or modify it under the terms of the GNU
** Library General Public License as published by the
** Free Software Foundation; either version 2, or (at
** your option) any later version.
**
********************************************************/ 

#include "qalfaudiofile.h"

QalfAudioFile::QalfAudioFile()
{
	this->title = "";
	this->artist = "";
	this->album = "";
	this->style = "";
	this->track = "";
	this->year = "";
	this->path = "";
	this->nbOfListen = 0;
	this->duration = 0;
	this->format = "";
}

QalfAudioFile::QalfAudioFile(QString & path)
{
	this->path = path ;
	this->title = "";
	this->artist = "";
	this->album = "";
	this->style = "";
	this->track = "";
	this->year = "";
	this->nbOfListen = 0;
	this->duration = 0;
	this->format = "";
}

void QalfAudioFile::setInfoFromTag()
{

}

const QString & QalfAudioFile::getTitle() const
{
	return this->title ;
}

void QalfAudioFile::setTitle(QString title)
{
	this->title = title ;
}

const QString & QalfAudioFile::getArtist() const
{
	return this->artist ;
}

void QalfAudioFile::setArtist(QString artist)
{
	this->artist = artist ;
}

const QString & QalfAudioFile::getAlbum() const
{
	return this->album ;
}

void QalfAudioFile::setAlbum(QString album)
{
	this->album = album ;
}

const QString & QalfAudioFile::getStyle() const
{
	return this->style ;
}

void QalfAudioFile::setStyle(QString style)
{
	this->style = style ;
}

const QString & QalfAudioFile::getTrack() const
{
	return this->track ;
}

void QalfAudioFile::setTrack(QString track)
{
	this->track = track ;
}

const QString & QalfAudioFile::getYear() const
{
	return this->year ;
}

void QalfAudioFile::setYear(QString year)
{
	this->year = year ;
}

const QString & QalfAudioFile::getPath() const
{
	return this->path ;
}

void QalfAudioFile::setPath(QString path)
{
	this->path = path ;
}

const int QalfAudioFile::getNbOfListen() const
{
	return this->nbOfListen ;
}

void QalfAudioFile::setNbOfListen(int nbOfListen)
{
	this->nbOfListen = nbOfListen ;
}

const int QalfAudioFile::getDuration() const
{
	return this->duration ;
}

void QalfAudioFile::setDuration(int duration)
{
	this->duration = duration ;
}

const QString & QalfAudioFile::getFormat() const
{
	return this->format ;
}

void QalfAudioFile::setFormat(QString format)
{
	this->format = format ;
}
