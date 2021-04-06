/*
Cai Hui Yang
*/

#include "Song.h"
#include "Set.h"
#include <iostream>

//default constructor
Song::Song() {
	title_ = "";
	author_ = "";
	album_ = "";
}

//parameter constructor
Song::Song(const std::string& title, const std::string& author, const std::string& album) {
	title_ = title;
	author_ = author;
	album_ = album;
}

//sets the title
void Song::setTitle(std::string title) {
	title_ = title;
}
//sets the author
void Song::setAuthor(std::string author) {
	author_ = author;
}
//sets the album
void Song::setAlbum(std::string album) {
	album_ = album;
}
//returns the title
std::string Song::getTitle() const {
	return title_;
}
//returns the author
std::string Song::getAuthor() const {
	return author_;
}
//returns the album
std::string Song::getAlbum() const {
	return album_;
}

// compare titles, authors, and albums with '=='
bool operator==(const Song& lhs, const Song& rhs) {
	if (lhs.getTitle() == rhs.getTitle() &&
		lhs.getAuthor() == rhs.getAuthor() &&
		lhs.getAlbum() == rhs.getAlbum()) {
		return true;
	}
	else {
		return false;
	}
}
