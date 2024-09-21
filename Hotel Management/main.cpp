#include <bits/stdc++.h>

using namespace std;

class Client {
public:
    string name;
    string contact;
    string checkInDate;
    string checkOutDate;
};

class Feedback {
public:
    string clientName;
    int rating;
    string comment;

    Feedback(string name, int rate, string feedback) : clientName(name), rating(rate), comment(feedback) {}
};

class HotelManagement {
private:
    int quant;
    int choice;
    // Quantity
    int Qrooms = 0, Qpasta = 0, Qburger = 0, Qnoodles = 0, Qshake = 0, Qchicken = 0;
    // Quantity of Sold Food
    int Srooms = 0, Spasta = 0, Sburger = 0, Snoodles = 0, Sshake = 0, Schicken = 0;
    // Total Quantities of Items
    int Total_rooms = 0, Total_pasta = 0, Total_burger = 0, Total_noodles = 0, Total_shake = 0, Total_chicken = 0;

    vector<Feedback> feedbacks;  // To store feedback

public:
    void setInitialQuantities() {
        cout << "\n\t\t\t                           --------------------------- ";
        cout << "\n\t\t\t\t\t \t |{ Hotel Management System }|";
        cout << "\n\t\t\t                           ---------------------------" << endl << endl;
        cout << "\n\t\t\t Enter Quantity of items We have ?";
        cout << "\n\t\t\t**----------------------------**";

        cout << "\n\n\t Number Rooms Available : ";
        cin >> Qrooms;
        cout << "\n\n\t Quantity of pasta Available : ";
        cin >> Qpasta;
        cout << "\n\n\t Quantity of Burger Available : ";
        cin >> Qburger;
        cout << "\n\n\t Quantity of Noodles Available : ";
        cin >> Qnoodles;
        cout << "\n\n\t Quantity of Shake Available : ";
        cin >> Qshake;
        cout << "\n\n\t Quantity of Chicken Available : ";
        cin >> Qchicken;
    }

    void takeClientOrder() {
        Client client;
        cout << "\n\n\t Enter your name : ";
        cin >> client.name;
        cout << "\n\n\t Enter your contact number : ";
        cin >> client.contact;
        cout << "\n\n\t Enter check-in date : ";
        cin >> client.checkInDate;
        cout << "\n\n\t Enter check-out date : ";
        cin >> client.checkOutDate;

        bool continueOrdering = true;
        while (continueOrdering) {
            cout << "\n\t\t\t ***********************************";
            cout << "\n\t\t\t Please Select from The menu options " << endl;
            cout << "\n\t\t\t ***********************************" << endl;
            cout << "\n\t#####################################################";

            cout << "\n\n\t1) Rooms";
            cout << "\n\t2) Pasta ";
            cout << "\n\t3) Burger";
            cout << "\n\t4) Noodles";
            cout << "\n\t5) Shake";
            cout << "\n\t6) Chicken";
            cout << "\n\t7) Information regarding sales and collection ";
            cout << "\n\t8) Show Feedback";
            cout << "\n\t9) Give Feedback ";
            cout << "\n\t10) Exit" << endl;
            cout << "\t#####################################################";

            cout << "\n\n Please Enter Your Choice ==> ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "\n\n Enter the number of Rooms U want ==> ";
                    cin >> quant;
                    if (Qrooms - Srooms >= quant) {
                        Srooms += quant;
                        Total_rooms += quant * 1200;
                        cout << "\n\n\t\t\"" << quant << "\" rooms have been reserved for you!";
                    } else
                        cout << "\n\t Sorry Mr " << client.name << ", Only \"" << Qrooms - Srooms << "\" Rooms remaining in Hotel";
                    break;

                case 2:
                    cout << "\n\n Enter Pasta Quantity : ";
                    cin >> quant;
                    if (Qpasta - Spasta >= quant) {
                        Spasta += quant;
                        Total_pasta += quant * 100;
                        cout << "\n\n\t\t\"" << quant << "\" Pasta is the Order!";
                    } else
                        cout << "\n\t Sorry Mr " << client.name << ", Only \"" << Qpasta - Spasta << "\" Pasta remaining in Hotel";
                    break;

                case 3:
                    cout << "\n\n Enter Burger Quantity : ";
                    cin >> quant;
                    if (Qburger - Sburger >= quant) {
                        Sburger += quant;
                        Total_burger += quant * 200;
                        cout << "\n\n\t\t\"" << quant << "\" Burger is the Order!";
                    } else
                        cout << "\n\t Sorry Mr " << client.name << ", Only \"" << Qburger - Sburger << "\" Burger remaining in Hotel";
                    break;

                case 4:
                    cout << "\n\n Enter Noodles Quantity : ";
                    cin >> quant;
                    if (Qnoodles - Snoodles >= quant) {
                        Snoodles += quant;
                        Total_noodles += quant * 130;
                        cout << "\n\n\t\t\"" << quant << "\" Noodles is the Order!";
                    } else
                        cout << "\n\t Sorry Mr " << client.name << ", Only \"" << Qnoodles - Snoodles << "\" Noodles remaining in Hotel";
                    break;

                case 5:
                    cout << "\n\n Enter Shakes Quantity : ";
                    cin >> quant;
                    if (Qshake - Sshake >= quant) {
                        Sshake += quant;
                        Total_shake += quant * 120;
                        cout << "\n\n\t\t\"" << quant << "\" Shake is the Order!";
                    } else
                        cout << "\n\t Sorry Mr " << client.name << ", Only \"" << Qshake - Sshake << "\" Shake remaining in Hotel";
                    break;

                case 6:
                    cout << "\n\n Enter Chicken Quantity : ";
                    cin >> quant;
                    if (Qchicken - Schicken >= quant) {
                        Schicken += quant;
                        Total_chicken += quant * 150;
                        cout << "\n\n\t\t\"" << quant << "\" Chicken is the Order!";
                    } else
                        cout << "\n\t Sorry Mr " << client.name << ", Only \"" << Qchicken - Schicken << "\" Chicken remaining in Hotel";
                    break;

                case 7:
                    displaySalesDetails();
                    break;

                case 8:
                    showFeedbacks();
                    break;

                case 9:
                    collectFeedback(client.name);
                    break;

                case 10:
                    continueOrdering = false;
                    cout << "\n\t Exiting... Thank you!";
                    char showBill;
                    cout << "\n\n\t Do you want to see your bill? (y/n): ";
                    cin >> showBill;
                    if (showBill == 'y' || showBill == 'Y') {
                        calculateBill();
                    }
                    else cout<<"\n\t\t\t***Thanks A lot***";
                    break;

                default:
                    cout << "\n\t Invalid choice. Please try again.";
                    break;
            }
        }
    }

    void collectFeedback(const string &clientName) {
        int rating;
        string comment;
        cout << "\n\t Please rate your experience (1-5): ";
        cin >> rating;
        cout << "\n\t Please leave your comments: ";
        cin.ignore();  // Clear the input buffer before taking a string with spaces
        getline(cin, comment);
        feedbacks.push_back(Feedback(clientName, rating, comment));
        cout << "\n\t Thank you for your feedback!";
    }

    void showFeedbacks() {
        if (feedbacks.empty()) {
            cout << "\n\t No feedback available yet.\n";
            return;
        }
        cout << "\n\n\n\t Total Feedbacks Collected: " << feedbacks.size()<<"\n\n";
        for (const auto &f : feedbacks) {
            cout << "\n\t Client: " << f.clientName;
            cout << "\n\t Rating: " << f.rating << "/5";
            cout << "\n\t Comments: " << f.comment << "\n";
        }
    }

    void calculateBill() {
        int totalBill = Total_rooms + Total_pasta + Total_burger + Total_noodles + Total_shake + Total_chicken;
        cout << "\n\t\t\t Your Bill Details";
        cout << "\n\n\t Total Rooms: " << Srooms << " * 1200 = " << Total_rooms;
        cout << "\n\t Total Pasta: " << Spasta << " * 100 = " << Total_pasta;
        cout << "\n\t Total Burger: " << Sburger << " * 200 = " << Total_burger;
        cout << "\n\t Total Noodles: " << Snoodles << " * 130 = " << Total_noodles;
        cout << "\n\t Total Shake: " << Sshake << " * 120 = " << Total_shake;
        cout << "\n\t Total Chicken: " << Schicken << " * 150 = " << Total_chicken;
        cout << "\n\t ---------------------------------------------------";
        cout << "\n\t  Total OF BILL : " << totalBill << "\n";
    }

    void displaySalesDetails() {
        cout << "\n\n\t\t\t Details of Sales and Collection ";
        cout << "\n\n\t\t Total Number of Rooms we had : " << Qrooms;
        cout << "\n\t\t Total Number of Rooms booked : " << Srooms;
        cout << "\n\t\t Remaining Rooms : " << Qrooms - Srooms;
        cout << "\n\t\t Total Collection from Rooms : " << Total_rooms;

        cout << "\n\n\t\t Total Number of Pasta we had : " << Qpasta;
        cout << "\n\t\t Total Number of Pasta Ordered : " << Spasta;
        cout << "\n\t\t Remaining Pasta : " << Qpasta - Spasta;
        cout << "\n\t\t Total Collection from Pasta : " << Total_pasta;

        cout << "\n\n\t\t Total Number of Burger we had : " << Qburger;
        cout << "\n\t\t Total Number of Burger Ordered : " << Sburger;
        cout << "\n\t\t Remaining Burger : " << Qburger - Sburger;
        cout << "\n\t\t Total Collection from Burger : " << Total_burger;

        cout << "\n\n\t\t Total Number of Noodles we had : " << Qnoodles;
        cout << "\n\t\t Total Number of Noodles Ordered : " << Snoodles;
        cout << "\n\t\t Remaining Noodles : " << Qnoodles - Snoodles;
        cout << "\n\t\t Total Collection from Noodles : " << Total_noodles;

        cout << "\n\n\t\t Total Number of Shake we had : " << Qshake;
        cout << "\n\t\t Total Number of Shake Ordered : " << Sshake;
        cout << "\n\t\t Remaining Shake : " << Qshake - Sshake;
        cout << "\n\t\t Total Collection from Shake : " << Total_shake;

        cout << "\n\n\t\t Total Number of Chicken we had : " << Qchicken;
        cout << "\n\t\t Total Number of Chicken Ordered : " << Schicken;
        cout << "\n\t\t Remaining Chicken : " << Qchicken - Schicken;
        cout << "\n\t\t Total Collection from Chicken : " << Total_chicken;
        cout << "\n\t --------------------------------------------------";
    }
};

int main() {
    HotelManagement hotel;
    hotel.setInitialQuantities();
    hotel.takeClientOrder();
    return 0;
}
