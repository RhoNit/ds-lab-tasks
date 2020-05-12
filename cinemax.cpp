#include <iostream>
#include<stdlib.h>
using namespace std;

class seat {
    int seatno;
    seat *next, *prev;
public:
    seat() {
        seatno = 0;
        next = prev = NULL;
    }
    void setData(int num) { seatno = num; }
    int getData() { return seatno; }
    void setNext(seat *n) { next = n; }
    void setPrev(seat *p) { prev = p; }
    seat* getNext() { return next; }
    seat* getPrev() { return prev; }
};

class theatre {
    seat *head;
    int row, col;
public:
    theatre() { head = NULL; }
    void setTheatre(int r, int c) {
        row = r;
        col = c;
    }
    int getRows() { return row; }

    void bookSeat(int c) {
        seat *nn, *temp;
        nn = new seat();
        nn-> setData(c);

        if(head == NULL) { //seat creation for first time booking
            nn-> setNext(nn);
            nn-> setPrev(nn);
            head = nn;
        }

        else {
            temp = head;
            if(temp == head) { //seat creation while there's already existing bookings
                nn-> setNext(head);
                nn-> setPrev(head-> getPrev());
                head-> getPrev()-> setNext(nn);
                head-> setPrev(nn);
                head = nn;
            }
            do { //cheking the whole set of seats of any row whether there's a seatno. exists matching to the input
                if(temp-> getData() == c) {
                    cout << "\nAlready Booked...Choose another seat\n";
                    return;
                }
                /*if(c > temp->getData()) {
                    cout << "\nYou're exceeding the seat-limits of a row\n";
                    return;
                }*/
                temp = temp-> getNext();
            } while(temp != head);
        }
    }

    void cancelSeat(int c) {
       seat *temp;
       temp = head;

       if(head == NULL) { //Case 1 --> Before any booking (No seat has been created/booked)
           cout << "\nBooking(seat creation) has not been done! Please book a seat first...\n";
           return;
       }

       if(temp-> getNext() == head) { //case 2 --> Only one seat has been booked
           if(temp-> getData() == c)
               head = NULL;
           else {
               cout << "\nNo one booked this seat...Kindly enter a seat that you've booked earlier\n";
               return;
           }
       }
       do { //Checking the whole set of seats of any row and if matching seat with the input one is found then simply cancel it
           if(temp-> getData() == c) {
               temp-> getPrev()-> setNext(temp-> getNext());
               temp-> getNext()-> setPrev(temp->getPrev());
               temp-> setPrev(NULL);
               temp-> setNext(NULL);
               delete(temp);
               break;
           }
           temp = temp-> getNext();
       } while(temp != head);

       if(temp == head) {
           cout << "\nNo one booked this seat...Kindly enter a seat that you've booked earlier\n";
           return;
       }
    }

    void displaySeat() {
        seat *temp;
        if(head == NULL) { // display seats before booking any seat
            for(int i = 1; i <= col; i++) { cout << "[" << i << "|" << "A" << "]" << "   "; }
        }
        else {
            temp = head;
            for(int i = 1; i <= col; i++) {
                int flag = 0;
                do { /* checking the whole set of seats of a row and if any matching seatno. is found with the input value (i.e. i), simply print "B" (i.e. BOOKED) status for that seat */
                    if(temp-> getData() == i) {
                        cout << "(" << i << " " << "B" << ")" << "   ";
                        flag = 1;
                        break;
                    }
                    temp = temp-> getNext();
                } while(temp != head);

                if(temp == head && flag == 0) {
                    cout << "[" << i << "|" << "A" << "]" << "   ";
                }
            }
       }
   }

};
int main() {
   int ch, r, c;
   cout << "\nEnter total number rows and columns of theater:";
   cin >> r >> c;
   theatre obj[r];
   for(int i = 0; i < r; i++)
     obj[i].setTheatre(r,c);
   while(1) {
       cout << "\nEnter:\n1.Book your seat\n2.Cancel your booking\n3.Display seat matrix\n4.Exit\n";
       cin >> ch;
       switch(ch) {
           case 1:
               cout << "\nEnter row and column to book seat:\n";
               cin >> r >> c;
               obj[r].bookSeat(c);
               break;
           case 2:
               cout << "\nEnter row and column to cancel seat:\n";
               cin >> r >> c;
               obj[r].cancelSeat(c);
               break;
           case 3:
               cout << "\n\n*******Welcome to Cinemax Theater*******\n\n";
               for(int i = 0; i < obj[0].getRows(); i++) {
                   cout << "\nRow- " << i << "-> ";
                   obj[i].displaySeat();
               }
               break;
           case 4:
              exit(0);
      }
   }

}

