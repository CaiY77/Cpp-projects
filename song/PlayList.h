/*
Cai Hui Yang
*/

#ifndef PLAYLIST_H_
#define PLAYLIST_H_
#include <iostream>
#include "Set.h"
#include "Song.h"
#include <vector>
#include <cstddef>


class PlayList {

public:
	PlayList(); // default constructor 

	PlayList(const Song& a_song); // perameter constructor

	// find number of song
	int getNumberOfSongs() const;

	// check if empty
	bool isEmpty() const;

	// add song
	bool addSong(const Song& new_song);

	// remove song
	bool removeSong(const Song& a_song);

	void clearPlayList(); // clear playlist

	void displayPlayList() const; // print playlist

private:
	Set<Song> playList_;

};


#endif