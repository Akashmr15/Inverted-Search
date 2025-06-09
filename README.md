# Inverted-Search
**Abstract:**

An inverted index is an index data structure storing a mapping from content, such as words or numbers, to its locations in a database file, or in a document or a set of documents. The purpose of an inverted index is to allow fast full text searches, at the cost of increased processing when a document is added to the database. The inverted file may be the database file itself, rather than its index. It is the most popular data structure used in document retrieval systems, used on a large scale for example in search engines.

**Description:**

Forward Indexing - It is a data structure that stores mapping from documents to words i.e. directs you from document to word.

Eg. - Table of contents in book.

**Inverted Indexing** - It is a data structure that stores mapping from words to documents or set of documents i.e. directs you from word to document.

Eg. - Index at the back of the book

**Requirement Specification**
Implementing this search program mainly consists two important functions.
* ```Indexing```
* ```Searching```
  
**```Indexing:```**
By Indexing, we are creating a database file which contains the index of all words. So this can be termed as Database Creation also. All the files whose index are to be created are selected and inputed to this function. All the files are parsed and words are separated and indexed. They are arranged in sorted order. For this a sorted Linked List or Hashing is used which will store the words and the related file details. The index thus created is then stored in the file as database. This file is later used in Querying. While the files are removed or added this index file is updated.

![image](https://github.com/user-attachments/assets/0dbbf392-6f93-436e-a5e5-ee687b325fd3)

**```Searching:```**

Once the Indexing is over we have the Querying or Searching. The text to be searched is inputed which is parsed into words and those words are searched in the index file. To avoid the overhead of reading the file again, the file is converted back to a linkedList or hashing program, in which the words are searched. The information about the files which contain the words are collected. The ones with more matches are filtered and produced as the result.

![image](https://github.com/user-attachments/assets/1e547297-a760-4c56-a944-6cd8b3352091)

**Operations:**

1) ```Create Database```
   ![Screenshot (39)](https://github.com/user-attachments/assets/8dc0b1d0-fb06-426f-8167-294fdfdfb52d)
2) ```Display Database```
   ![Screenshot (40)](https://github.com/user-attachments/assets/35f58dfb-379b-4881-98f4-aee9117246cb)
3) ```Search Database```
![Screenshot (41)](https://github.com/user-attachments/assets/eaeb99db-3ef9-4593-99ff-30062cf30f96)

4) ```Update Database```
5) ```Save Database```


An inverted index is an index data structure storing a mapping from content, such as words or numbers, to its locations in a database file, or in a document or a set of documents. The purpose of an inverted index is to allow fast full text searches, at a cost of increased processing when a document is added to the database.
