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
#include <QObject>

class QalfAudioFile : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString title READ getTitle WRITE setTitle)
	Q_PROPERTY(QString artist READ getArtist WRITE setArtist)
	Q_PROPERTY(QString album READ getAlbum WRITE setAlbum)
	Q_PROPERTY(QString style READ getStyle WRITE setStyle)
	Q_PROPERTY(QString track READ getTrack WRITE setTrack)
	Q_PROPERTY(QString year READ getYear WRITE setYear)
	Q_PROPERTY(QString path READ getPath WRITE setPath)
	Q_PROPERTY(int nbOfListen READ getNbOfListen WRITE setNbOfListen)
	Q_PROPERTY(int duration READ getDuration WRITE setDuration)
	Q_PROPERTY(QString format READ getFormat WRITE setFormat)

	public:
		QalfAudioFile();
		QalfAudioFile(QString & path);
		const QString & getTitle() const;
		void setTitle(const QString title) ;
		const QString & getArtist() const;
		void setArtist(const QString artist) ;
		const QString & getAlbum() const;
		void setAlbum(const QString album) ;
		const QString & getStyle() const;
		void setStyle(const QString style) ;
		const QString & getTrack() const;
		void setTrack(const QString track) ;
		const QString & getYear() const;
		void setYear(const QString year) ;
		const QString & getPath() const;
		void setPath(const QString path) ;
		const int getNbOfListen() const;
		void setNbOfListen(const int nbOfListen) ;
		const int getDuration() const;
		void setDuration(const int duration) ;
		const QString & getFormat() const;
		void setFormat(const QString format) ;

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
