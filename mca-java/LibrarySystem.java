import java.util.*;

class Book {
    private String title;
    private String author;
    private boolean isBorrowed;

    public Book(String title, String author) {
        this.title = title;
        this.author = author;
        this.isBorrowed = false;
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public boolean isBorrowed() {
        return isBorrowed;
    }

    public void borrowedBook() {
        isBorrowed = true;
    }

    public void returnBook() {
        isBorrowed = false;
    }
}

class Member {
    private ArrayList<Book> books = new ArrayList<>();

    public void addBook(String title, String author) {
        books.add(new Book(title, author));
        System.out.println("Book Added: " + title);
    }

    public void removeBook(String title) {
        // Remove a book by its title
        books.removeIf(book -> book.getTitle().equals(title));
        System.out.println("Book removed: " + title);
    }

    public void displayAvailableBooks() {
        System.out.println("Available Books: ");
        for (Book book : books) {
            if (!book.isBorrowed()) {
                System.out.println("Book Name: " + book.getTitle());
                System.out.println("Book Author: " + book.getAuthor());
            }
        }
    }

    public void borrowBook(String title) {
        for (Book book : books) {
            if (book.getTitle().equals(title) && !book.isBorrowed()) {
                book.borrowedBook();
                System.out.println("You have borrowed: " + title);
                return;
            }
        }
        System.out.println("Book is either not available or already borrowed.");
    }

    public void returnBook(String title) {
        for (Book book : books) {
            if (book.getTitle().equals(title) && book.isBorrowed()) {
                book.returnBook();
                System.out.println("You have returned: " + title);
                return;
            }
        }
        System.out.println("This book was not borrowed.");
    }
}

public class LibrarySystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Member member = new Member();
        int choice;

        do {
            System.out.println("Library Management System:");
            System.out.println("1. Add Book");
            System.out.println("2. Remove Book");
            System.out.println("3. Borrow Book");
            System.out.println("4. Return Book");
            System.out.println("5. Display All Books");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();
            sc.nextLine(); // Consume the newline character

            switch (choice) {
                case 1:
                    System.out.print("Enter the book name: ");
                    String title = sc.nextLine();
                    System.out.print("Enter the author name: ");
                    String author = sc.nextLine();
                    member.addBook(title, author);
                    break;
                case 2:
                    System.out.print("Enter the book name to remove: ");
                    String bookToRemove = sc.nextLine();
                    member.removeBook(bookToRemove);
                    break;
                case 3:
                    System.out.print("Enter the book name to borrow: ");
                    String bookToBorrow = sc.nextLine();
                    member.borrowBook(bookToBorrow);
                    break;
                case 4:
                    System.out.print("Enter the book name to return: ");
                    String bookToReturn = sc.nextLine();
                    member.returnBook(bookToReturn);
                    break;
                case 5:
                    member.displayAvailableBooks();
                    break;
                case 6:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 6);

        sc.close();
    }
}
