package com.djesc;

public class Bookcase extends Cupboard{
    int numOfBooks;

    @Override
    public void showContent() {
        System.out.println("Количество книг: " + numOfBooks);
    }

    public int getNumOfBooks() {
        return numOfBooks;
    }

    public void setNumOfBooks(int numOfBooks) {
        this.numOfBooks = numOfBooks;
    }
}
