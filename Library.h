#pragma once

#include <memory>
#include <string>
#include <vector>
#include "Publication.h"
#include <iostream>

#ifndef LIBRARY_H
#define LIBRARY_H


class Library {
public:
    void AddPublication(std::shared_ptr<Publication> publication) {
        m_collection.push_back(publication);
        std::cout << "Publication added: " << publication->GetTitle()
            << " (ID: " << publication->GetId() << ")" << std::endl;
    }

    void RentPublication(int id) {
        auto it = FindPublicationById(id);
        if (it != m_collection.end() && !(*it)->IsRented()) {  // 
            (*it)->SetRented(true);  
            std::cout << "Publication rented: " << (*it)->GetTitle()
                << " (ID: " << id << ")" << std::endl;
        }
        else {
            std::cout << "Publication not available for rent with ID: " << id << std::endl;
        }
    }

    void RegetPublication(int id) {
        auto it = FindPublicationById(id);
        if (it != m_collection.end() && (*it)->IsRented()) {  // U¿ycie getter IsRented()
            (*it)->SetRented(false);  // Ustawienie statusu na 'dostêpny'
            std::cout << "Publication returned: " << (*it)->GetTitle()
                << " (ID: " << id << ")" << std::endl;
        }
        else {
            std::cout << "Publication not found or not rented with ID: " << id << std::endl;
        }
    }

    void RemovePublication(int id) {
        auto it = FindPublicationById(id);
        if (it != m_collection.end()) {
            std::cout << "Removing publication: " << (*it)->GetTitle()
                << " (ID: " << id << ")" << std::endl;
            m_collection.erase(it);
        }
        else {
            std::cout << "Publication not found with ID: " << id << std::endl;
        }
    }

    void PrintCollection() const {
        if (m_collection.empty()) {
            std::cout << "The library is empty." << std::endl;
            return;
        }
        std::cout << "Library collection:" << std::endl;
        for (const auto& publication : m_collection) {
            publication->PrintAll();
        }
    }

private:
    std::vector<std::shared_ptr<Publication>> m_collection;

    std::vector<std::shared_ptr<Publication>>::iterator FindPublicationById(int id) {
        return std::find_if(m_collection.begin(), m_collection.end(),
            [id](const std::shared_ptr<Publication>& pub) {
                return pub->GetId() == id;
            });
    }
};

#endif // BOOK_H