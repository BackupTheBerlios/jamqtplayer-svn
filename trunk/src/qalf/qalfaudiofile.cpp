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
	
}

QalfAudioFile::QalfAudioFile(QString & path)
{
	this->path = path ;
}

void QalfAudioFile::setInfoFromTag()
{

}

const QString & QalfAudioFile::getTitle() const
{
	return this->title ;
}

const QString & QalfAudioFile::getArtist() const
{
	return this->artist ;
}

const QString & QalfAudioFile::getAlbum() const
{
	return this->album ;
}

const QString & QalfAudioFile::getStyle() const
{
	return this->style ;
}

const QString & QalfAudioFile::getTrack() const
{
	return this->track ;
}

const QString & QalfAudioFile::getYear() const
{
	return this->year ;
}

const QString & QalfAudioFile::getPath() const
{
	return this->path ;
}

const int QalfAudioFile::getNbOfListen() const
{
	return this->nbOfListen ;
}

const int QalfAudioFile::getDuration() const
{
	return this->duration ;
}

const QString & QalfAudioFile::getFormat() const
{
	return this->format ;
}
