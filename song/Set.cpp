/*
Cai Hui Yang
*/

#include "Set.h" 
#include <cstddef>

template<class ItemType>
Set<ItemType>::Set() {
	item_count_ = 0;
	max_items_ = DEFAULT_SET_SIZE;
}

// return Size
template<class ItemType>
int Set<ItemType>::getCurrentSize() const {
	return item_count_;
}

// Empty or not
template<class ItemType>
bool Set<ItemType>::isEmpty() const {
	if (item_count_ == 0) {
		return true;
	}
	return false;
}

// add a new Entry 
// only if there is space
template<class ItemType>
bool Set<ItemType>::add(const ItemType& newEntry) {
	bool enough_space = (item_count_ < max_items_);
	if (enough_space) {
		items_[item_count_] = newEntry;
		item_count_++;
	}
	return enough_space;
}

// remove an Entry
// return if it can remove or not
template<class ItemType>
bool Set<ItemType>::remove(const ItemType& anEntry) {
	int locate_index = getIndexOf(anEntry);
	bool can_remove_item = !isEmpty() && (locate_index > -1);
	if (can_remove_item) {
		item_count_--;
		items_[locate_index] = items_[item_count_];
	}
	return can_remove_item;
}

// empty the set
template<class ItemType>
void Set<ItemType>::clear() {
	item_count_ = 0;
}

// see if entry contains
template<class ItemType>
bool Set<ItemType>::contains(const ItemType& anEntry) const {
	return getIndexOf(anEntry) > -1;
}

// search index
template<class ItemType>
int Set<ItemType>::getIndexOf(const ItemType& target) const {
	bool found = false;
	int result = -1;
	int search_index = 0;
	while (!found && search_index < item_count_) {
		if (items_[search_index] == target) {
			found = true;
			result = search_index;
		}
		else {
			search_index++;
		}

	}
	return result;
}

template<class ItemType>
std::vector<ItemType> Set<ItemType>::toVector() const {
	std::vector<ItemType> Set_contents;
	for (int i = 0; i < item_count_; i++) {
		Set_contents.push_back(items_[i]);
	}
	return Set_contents;
}
