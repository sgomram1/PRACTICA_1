#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <stdexcept>
#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T>{
	private:
    		Node<T>* first;
    		int n;

    		Node<T>* getNode(int pos) const{
        		Node<T>* current = first;
        		for(int i = 0; i < pos; i++){
            			current = current->next;
        		}
        		return current;
    		}

	public:
    		ListLinked(){
        		first = nullptr;
        		n = 0;
    		}

    		~ListLinked(){
        		while(first != nullptr){
            			Node<T>* aux = first->next;
            			delete first;
            			first = aux;
        		}
    		}

    		void insert(int pos, T e) override{
        		if(pos < 0 || pos > n){
            			throw std::out_of_range("pos");
        		}

        		if(pos == 0){
            			first = new Node<T>(e, first);
        		}else{
            			Node<T>* prev = getNode(pos - 1);
            			prev->next = new Node<T>(e, prev->next);
        		}

        		n++;
    		}

    		void append(T e) override{
        		insert(n, e);
    		}

    		void prepend(T e) override{
        		insert(0, e);
    		}

    		T remove(int pos) override{
        		if(pos < 0 || pos >= n){
            			throw std::out_of_range("pos");
        		}

        		Node<T>* to_delete;
        		T value;

        		if(pos == 0){
            			to_delete = first;
            			first = first->next;
        		}else{
            			Node<T>* prev = getNode(pos - 1);
            			to_delete = prev->next;
            			prev->next = to_delete->next;
        		}

        		value = to_delete->data;
        		delete to_delete;
        		n--;

        		return value;
    		}

    		T get(int pos) override{
        		if(pos < 0 || pos >= n){
            			throw std::out_of_range("pos");
        		}

        		return getNode(pos)->data;
    		}

    		int search(T e) override{
        		Node<T>* current = first;
        		int pos = 0;

        		while(current != nullptr){
            			if(current->data == e){
                			return pos;
            			}
            			current = current->next;
            			pos++;
        		}

        		return -1;
    		}

    		bool empty() override{
        		return n == 0;
    		}

    		int size() override{
        		return n;
    		}

    		T operator[](int pos){
        		return get(pos);
    		}

		friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list){
        		Node<T>* current = list.first;
        		out << "[" << std::endl;

        		while(current != nullptr){
            			out << "  " << current->data << std::endl;
            			current = current->next;
        		}

        		out << "]";
        		return out;
    		}
};

#endif
