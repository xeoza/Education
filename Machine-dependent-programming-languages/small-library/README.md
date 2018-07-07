# small-library

# USERS

| Task | Status |
| --------- | --------- |
| When you run the program you need to enter a login and password, if they are specified incorrectly the error is displayed | OK |
| If the user has access only to viewing and editing books to display the menu for books (see the description books) | OK |
| If the user has only view and edit access, display the menu for students (see the students description) | OK |
| If the user has access to both books and students - display the top-level menu: 1 - Books, 2 - Students. In the books and students menu, add the function: 0 - return to the main menu | OK |

# STUDENTS
| Task | Status |
| --------- | --------- |
| Add a student (when adding to verify that such a student is not yet by the account number) | OK |
| Delete the student by the account number | OK |
| Make a backup (save the program state to a ".csv" file, the name of the file "students_ <date and time> .csv", display the message successfully or the operation did not succeed) | OK |
| Restore the database from the backup file (the user specifies the name of the backup file, displays the message how the data was recovered) | OK |
Search for the name of the student (the user enters the name of the student, if the library is used by one or several students of the same names, all information is displayed on them, if the student does not, a corresponding message is displayed) OK |
| Quit the program (the current state of the library is saved to a file) | OK |

# BOOKS

| Task | Status |
| --------- | --------- |
| Add a new book (when adding to check whether there is already such a book by the ISBN number) | OK |
| Delete the book by ISBN | OK |
| View all information on the book (here and below the book is selected by the ISBN number, if an incorrect number is entered, a message is displayed that the book was not found) | OK |
| Print information on all books in the form of a table, entries should be sorted by ISBN | OK |