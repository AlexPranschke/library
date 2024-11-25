#pragma once


#include <string>

#ifndef PUBLICATION_H
#define PUBLICATION_H


class Publication {
public:

    
    Publication(const std::string& title, int year, const std::string & authors);
    virtual ~Publication() = default;

    // Getter
    std::string GetTitle() const;
    std::string GetAuthor() const;
    int GetYear() const;
    int GetId() const;
    bool IsRented() const; 

    // Setter
    void SetTitle(const std::string& title);
    void SetYear(const int& year);
    void SetAuthors(const std::string&);
    void SetRented(bool status);
    

    virtual void PrintAll();

    

protected:
    std::string m_title = "";
    std::string m_authors= "";
    int m_year = 0;
    bool m_rented = false;
    int m_id;
    static int s_nextId;

};




class Book : public Publication {
public:

   
    Book(const std::string& title, int year, const std::string authors, std::string genre, int edytion );
    ~Book();

    void PrintAll() override;

    std::string GetGenre() const;
    int GetEdition() const;
   
    void SetEditon(int & edition);
    void SetGenre(std::string & genre);



private:
    std::string m_genre = "";
    int m_edytion = 0;

};

class Article : public  Publication {

public:

    Article(const std::string& title, int year, const std::string authors, std::string type, int m_PublicationNumber, int m_pages);
    ~Article();

    void PrintAll() override;

    std::string GetType() const;
    int GetPubNumber() const;
    int GetPages() const;

    void SetType(std::string & type) ;
    void SetPubNumber(int & pubNumber) ;
    void SetPages(int & pages) ; 

private:

    std::string m_type = "";
    int m_PublicationNumber = 0;
    int m_pages = 0;
    
};

#endif //