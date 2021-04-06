/*
Cai Hui Yang
*/

#include <iostream>
#include "Node.h"
#include "PlayList.h"
#include "Song.h"
#include <cstddef>
#include <vector>
#include <string>

using namespace std;


	PlayList::PlayList(){

	tail_ptr_ = nullptr;

	}

	PlayList::PlayList(const Song& a_song) {
		add(a_song);
	}
	
	PlayList::~PlayList() {
	
		clear();
		unloop();
		tail_ptr_ = nullptr;
		
	} // clear & unloop

	PlayList::PlayList(const PlayList& a_play_list):LinkedSet <Song>(a_play_list){

		item_count_ = a_play_list.item_count_;
		Node<Song>* orig_chain_ptr = a_play_list.head_ptr_;

		if(orig_chain_ptr == nullptr){
			head_ptr_ = nullptr;
		} // Empty Original Set

		else {
			// Copy first node
			head_ptr_ = new Node<Song>();
			head_ptr_->setItem(orig_chain_ptr->getItem());
			// Copy remaining nodes
			Node<Song>* new_chain_ptr = head_ptr_;
			orig_chain_ptr = orig_chain_ptr->getNext();

			while (orig_chain_ptr != nullptr) {
			
				// Get next item from original chain
				Song nextItem = orig_chain_ptr->getItem();

				// Create a new node containing the next item
				Node<Song>* new_node_ptr = new Node<Song>(nextItem);

				// Link new node to the end of new chain
				new_chain_ptr->setNext(new_node_ptr);

				// Advance pointer to new last node
				new_chain_ptr = new_chain_ptr->getNext();

				//Advance original-chain pointer
				orig_chain_ptr = orig_chain_ptr->getNext();
			}// while

		}// if

	} // copy constructor

	bool PlayList::add(const Song& new_song)  {
	
		if (!contains(new_song)) {

			if (head_ptr_ == nullptr) {
				head_ptr_ = new Node<Song>();
				head_ptr_->setItem(new_song);
				item_count_++;
				return true;
			}

			else {
				Node<Song>* next_node_ptr = new Node<Song>();
				next_node_ptr->setItem(new_song);
				next_node_ptr->setNext(nullptr);
				Node<Song>* temp = new Node<Song>();
				temp = getPointerToLastNode();
				temp->setNext(next_node_ptr);
				item_count_++;
				return true;
			}

		} // if

		else {
			return false;
		}

	}

	bool PlayList::remove(const Song& a_song)  {
	
		if (a_song == head_ptr_->getItem()) {
			Node<Song>* temp = head_ptr_;
			head_ptr_ = temp->getNext();
			temp = nullptr;
			delete temp;
			item_count_--;
			return true;
		}

		if (contains(a_song)) {

			Node<Song>* previousPtr = nullptr;
			Node<Song>* entryNodePtr = getPointerTo(a_song, previousPtr);
			previousPtr->setNext(entryNodePtr->getNext());
			entryNodePtr = nullptr;
			delete entryNodePtr;
			item_count_--;
			return true;
		}

		return true;
	}

	void PlayList::loop() {

		tail_ptr_ = getPointerToLastNode();
		tail_ptr_->setNext(head_ptr_);

	}

	void PlayList::unloop() {

		tail_ptr_ = nullptr;

	}

	void PlayList::displayPlayList() {
	
		vector<Song> f = toVector();

		for (int i = 0; i < item_count_; i++) {

			cout << "* " << "Title: " << f[i].getTitle() << "* " << "Author : " << f[i].getAuthor() << " * " << "Album : " << f[i].getAlbum() << " * " << endl;
		}
		cout << "End of playlist" << endl;

	}

	Node<Song>* PlayList::getPointerToLastNode() const {
	
		Node<Song>* current = head_ptr_;

		while (current != nullptr && current->getNext() != nullptr) {
			current = current->getNext();
		}

		return current;
	} // Fuc end

	Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>* & previous_ptr) const {
	
		Node<Song>* cur_ptr = head_ptr_;
		if (contains(target)) {
			while (!(cur_ptr->getItem() == target)) {

				previous_ptr = cur_ptr;
				cur_ptr = cur_ptr->getNext();

			}// while
			return cur_ptr;
		} // if


		else {
			return nullptr;
		} // else


	} // Func end
