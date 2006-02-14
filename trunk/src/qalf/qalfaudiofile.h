/*******************************************************
**
** Definition of QalfAudioFile
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

#ifndef QalfAUDIOFILE_H
#define QalfAUDIOFILE_H

#include <QString>

class QalfAudioFile
{
	public:
		QalfAudioFile();
		QalfAudioFile(QString & path);
		const QString & getTitle() const;
		const QString & getArtist() const;
		const QString & getAlbum() const;
		const QString & getStyle() const;
		const QString & getTrack() const;
		const QString & getYear() const;
		const QString & getPath() const;
		const int getNbOfListen() const;
		const int getDuration() const;
		const QString & getFormat() const;

	protected:
		QString title ;
		QString artist ;
		QString album ;
		QString style ;
		QString track ;
		QString year ;
		QString path ;
		int nbOfListen ;
		int duration ;
		QString format ;

		void setInfoFromTag() ;
};

#endif // QalfAUDIOFILE_H
