/*
Cai Hui Yang
*/

#ifndef PLAYLIST_H_
#define PLAYLIST_H_
#include <vector>
#include <iostream>
#include "Song.h"
#include "Node.h"
#include "LinkedSet.h"


class PlayList : public LinkedSet<Song> {

public:

	PlayList(); //default constructor

	PlayList(const Song& a_song); //param constructor

	PlayList(const PlayList& a_play_list); // copy constructor

	~PlayList(); //Destructor

	bool add(const Song& new_song) override;

	bool remove(const Song& a_song)override;

	void loop();

	void unloop();

	void displayPlayList();


private:
	Node<Song> *tail_ptr_; // Last node pointer

	Node<Song> *getPointerToLastNode() const;



	// post: previous_ptr is null if target is not in PlayList or if target is the
	// first node, otherwise it points to the node preceding target
	// return: either a pointer to the node containing target
	// or the null pointer if the target is not in the PlayList.
	Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const;

};


#endif
