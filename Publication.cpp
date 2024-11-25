#include "publication.h"
#include <string>
#include <iostream>




Publication::Publication(const std::string& title, int year, const std::string & authors) : m_title(title), m_year(year), m_authors(authors) {
	m_id = s_nextId++;
};

int Publication::s_nextId = 0;

void Publication::PrintAll() {
	
	std::cout <<"ID: "<< m_id << ",Title: " << m_title << ", Year: " << m_year << ", Author:" << m_authors << std::endl;

};


std::string Publication::GetTitle() const {
	return m_title;
}
std::string Publication::GetAuthor() const {
	return m_authors;
}
int Publication::GetYear() const {
	return m_year;
}
int Publication::GetId() const {
	return m_id;
}
bool Publication::IsRented() const {
	return m_rented; 
}


void Publication::SetRented(bool status) { 
	m_rented = status; 
}
void Publication::SetTitle(const std::string& title) {
	m_title = title;
}
void Publication::SetYear(const int& year) {
	m_year = year;
};
void Publication::SetAuthors(const std::string& authors)  {
	m_authors = authors;
}




Book::Book(const std::string& title, int year, const std::string authors, std::string genre, int edytion) : Publication(title, year, authors), m_genre(genre), m_edytion(edytion)
{

}
Book::~Book() {
	std::cout << "destruktor book";
}

void Book::PrintAll() {
	std::cout << "Title: " << m_title << ", Year: " << m_year << ", Author:" << m_authors << ", Genre :" << m_genre << ", Edition: " << m_edytion << std::endl;
}
std::string Book::GetGenre() const {
	return m_genre;

}
int Book::GetEdition() const{
	return m_edytion;
}

void Book::SetGenre(std::string & genre) {
	m_genre = genre;
}
void Book::SetEditon(int& edition) {
	m_edytion = edition;
}


Article::Article(const std::string& title, int year, const std::string authors, std::string type, int PublicationNumber, int pages) 
	: Publication(title, year, authors), m_type(type), m_PublicationNumber(PublicationNumber), m_pages(pages) 
{

};
Article::~Article() {
	std::cout << "dekonstruktor articcle" << std::endl;
};

void Article::PrintAll() {
	std::cout << "Title: " << m_title << ", Year: " << m_year << ", Author:" << m_authors << ", Type :" << m_type << ", PublicationNumber: " << m_PublicationNumber << ", Pages: "<< m_pages << std::endl;
}

std::string Article::GetType() const {
	return m_type;
};
int Article::GetPubNumber() const {
	return m_PublicationNumber;
};
int Article::GetPages() const {
	return m_pages;
};

void Article::SetType(std::string& type) {
	m_type = type;
};
void Article::SetPubNumber(int & PublicationNumber)  {
	m_PublicationNumber = PublicationNumber;
};
void Article::SetPages(int & pages)  {
	m_pages = pages;
};

