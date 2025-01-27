//Name - Sehjapreet Singh
//ID - 1243204
//email -ssingh1053@gmail.com
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Box.h"
using namespace std;
namespace sdds {
	void Box::setName(const char* Cstr) {

		if (Cstr != nullptr)
		{
			delete[] m_contentName;
			m_contentName = new char[strlen(Cstr) + 1];
			strcpy(m_contentName, Cstr);
		}
	}

	void Box::setUnusable() {
		delete[] m_contentName;
		m_contentName = nullptr;
		m_width = -1;
		m_height = -1;
		m_length = -1;
		m_contentVolume = -1;
	}

	bool Box::isUnusable()const {
		bool flag = false;
		if (m_height == -1)
		{
			flag = true;
		}
		return flag;
	}

	bool Box::hasContent()const {
		bool flag = false;
		if (m_contentVolume > 0) {
			flag = true;
		}
		return flag;
	}

	Box::Box() {
		m_contentName = nullptr;
		m_width = 12;
		m_height = 12;
		m_length = 12;
		m_contentVolume = 0;
	}
	Box::Box(int sideLength, const char* contentName) {
		m_contentName = nullptr;
		if (sideLength < 5 || sideLength > 36)
		{
			setUnusable();
		}
		else
		{
			m_width = sideLength;
			m_height = sideLength;
			m_length = sideLength;
			m_contentVolume = 0;
			setName(contentName);
		}
	}




	Box::Box(int width, int height, int length, const char* contentName) {
		m_contentName = nullptr;
		if ((width < 5 || width > 36) || (height < 5 || height > 36) || (length < 5 || length > 36))
		{
			setUnusable();
		}
		else
		{
			m_width = width;
			m_height = height;
			m_length = length;
			m_contentVolume = 0;
			setName(contentName);
		}
	}
	Box::~Box() {
		delete[] m_contentName;
	}
	int Box::capacity()const {
		return m_width * m_height * m_length;
	}
	int Box::quantity()const {
		return m_contentVolume;
	}

	Box& Box::setContent(const char* contentName) {
		if (hasContent() && m_contentName != nullptr)
		{
			setUnusable();
		}
		else
		{
			setName(contentName);
		}
		return *this;
	}

	std::ostream& Box::display()const {


		if (Box::isUnusable())
		{
			cout << "Unusable box, discard the content, and recycle.";
		}
		else
		{
			char name[100] = "Empty box";
			if (m_contentName != nullptr)
			{
				strcpy(name, m_contentName);
			}
			cout << setw(30) << left << setfill('.') << name << "  "
			<< right << setw(2) << setfill('0') << m_width<<"x"
			<< right << setw(2) << setfill('0') << m_height<< "x"
			<< right << setw(2) << setfill('0') << m_length<< "  "
			<< right << setw(6) << setfill(' ') << quantity() << "/" << capacity() << " C.I.";

		}
		return cout;
	}

	Box& Box::add(int quantity) {


		if (quantity > 0 && quantity + this->quantity() < this->capacity())
		{
			m_contentVolume += quantity;
		}
		else {
			setUnusable();
		}
		return *this;
	}

	Box& Box::add(Box& B) {
		if (m_contentName == nullptr || quantity() == 0) {
			setContent(B.m_contentName);
		}
		if (strcmp(m_contentName, B.m_contentName) == 0) {
			if (quantity() + B.quantity() <= capacity()) {
				add(B.quantity());
				B.m_contentVolume = 0;
			}
			else {
				B.m_contentVolume -= (capacity() - quantity());
				m_contentVolume = capacity();
			}
		}
		else {
			if (quantity() + B.quantity() <= capacity()) {
				B.m_contentVolume = 0;
			}
			else {
				B.m_contentVolume -= (capacity() - quantity());
			}
			setUnusable();
		}
		return *this;
	}


}