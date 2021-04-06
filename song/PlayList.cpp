/*
Cai Hui Yang
*/
#include "PlayList.h" 
#include "Set.h"
#include "Song.h"
#include <vector>
#include <string>
using namespace std;

// default constructor
PlayList::PlayList() {}

// parameter constructor
PlayList::PlayList(const Song& a_song) {
	playList_.add(a_song);
}

int PlayList::getNumberOfSongs() const {
	return playList_.getCurrentSize();
}

bool PlayList::isEmpty() const {
	if (getNumberOfSongs() == 0) {
		return true;
	}
	return false;
}

// if song exist, false
// if it can be added then add, true
bool PlayList::addSong(const Song& new_song) {
	if (playList_.contains(new_song)) {
		return false;
	}
	else {
		playList_.add(new_song);
		return true;
	}
}

// remove a song if it exist
bool PlayList::removeSong(const Song& a_song) {
	if (playList_.contains(a_song)) {
		playList_.remove(a_song);
		return true;
	}
	else {
		return false;
	}
}

// empty playlist
void PlayList::clearPlayList() {
	playList_.clear();
}

// print playlist
void PlayList::displayPlayList() const {
	vector<Song> f = playList_.toVector();
	for (int i = 0; i < getNumberOfSongs(); i++) {
		cout << "* " << "Title: " << f[i].getTitle() << "* " << "Author : " << f[i].getAuthor() << " * " << "Album : " << f[i].getAlbum() << " * " << endl;
	}
	cout << "End of playlist" << endl;
}
