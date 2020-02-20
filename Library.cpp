//
// Created by s41m0n on 2/20/20.
//

#include "Library.h"
Library::Library(int id, int signupProcessDays, int shippableBooksPerDay)
    : id(id), nBooks(0), mediumScore(0), signupProcessDays(signupProcessDays),
      shippableBooksPerDay(shippableBooksPerDay) {}

void Library::addBook(Book &book) {
  this->books.emplace_back(book);
  this->nBooks++;
}
int Library::getNBooks() { return this->nBooks; }

void Library::computeMediumScoreForBook(){
	int scoreTot = 0;
	for (auto & book : this->books){
		scoreTot += book.getScore();
	}

	float medScore = (float) scoreTot / this->books.size();

	this->mediumScore = medScore;
}

float Library::getMediumScore(){
  return this->mediumScore;
}

void Library::computeScore() {
    int scoreTot = 0;
    for (auto & book : this->books){
        scoreTot += book.getScore();
    }
    this->score = scoreTot;
}
int Library::getId() { return this->id; }
