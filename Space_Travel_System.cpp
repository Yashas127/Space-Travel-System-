
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Traveller{
    public:
        int travellerId;
        string name;
        Traveller (string name1, int traveller_id1){
        travellerId = traveller_id1;
        name = name1;
    }

};

class Planet{
    
public:
    string name;
    int x;
    int y;
    int z;
friend class SpaceTravel;
    

    int getX(){
        return x; 
    }

     int getY(){
        return y; 
    }
   
    int getZ(){
        return z; 
    }

    void updateCoordinates(int x1, int y1, int z1){
        x=x1;
        y=y1;
        z=z1;
    }

    Planet (int x1, int y1, int z1, string name1){
        x=x1;
        y=y1;
        z=z1;
        name=name1;
    }
};
class Passenger: public Traveller{
    public:
        Passenger(string name1, int traveller_id1 ): Traveller ( name1,traveller_id1){}
};


class Ticket{
    public:
        Planet* sourceStation;
        Planet* destinationStation;
        int date;
        Passenger* passenger;
        int ticketId;
        int validity;
        int price;
        bool isBooked;
        static int ticket_id_generator;
        Ticket (Planet * source1, Planet* dest1, int date1, Passenger* p1, bool returnTicket, int ticket_id1){
        sourceStation = source1;
        destinationStation = dest1;
        date = date1;
        validity = 10;
        price =  13;
        passenger = p1;
        ticketId = ticket_id1;
        bool isBooked = false;
    }

    ~Ticket(){
    cout << "Ticket Destructor is called, this ticket is now deleted" << endl;    
    }

    void bookTicket(){
        this->isBooked =true;
        cout<<"Your ticket is booked!"<<endl;
    }

    void updateTicket( Planet *dest1, int date1){
        this->date = date1;
        this->destinationStation = dest1;
        this->price = 13;
    }
    void deleteTicket(){
        this->~Ticket();
        return;
    }
};



class Astronaut: public Traveller{
public:
    int experience;
    friend class SpaceTravel;
    friend class STcheck;
    Astronaut(string name1, int experience1, int license_id1): Traveller (   name1,license_id1){
        experience = experience1;
    }
};


class Commander: public Traveller{
    public:
        bool authority;
        int experience;
    Commander(string name1, int experience1, int license_id1, bool authority1): Traveller ( name1,license_id1  ){
        experience = experience1;
        authority = authority1;
    }
    
    friend class SpaceTravel;
    // static vector <SpaceTravel> list_of_space_travels;
};


class SpaceTravel{
    public:
        int spaceTravelId;
        vector <Passenger *> listOfPassengers;
        Astronaut * astronaut;
        Commander *commander;
        Planet * sourcePlanet;
        Planet * destPlanet;
        int departureDate;
        
        SpaceTravel(){
            astronaut = nullptr;
                commander = nullptr;
        }

        SpaceTravel(int spaceTravelId1, Planet * sourcePlanet1, Planet * destPlanet1, int departureDate1){
                spaceTravelId = spaceTravelId1;
                sourcePlanet = sourcePlanet1;
                destPlanet = destPlanet1;
                departureDate = departureDate1;
                astronaut = nullptr;
                commander = nullptr;
        }

        void addPassenger(Passenger * p1){
            if(listOfPassengers.size()>10){
                cout<<"The Space Travel object is full. Pl&ease wa&it for more people to book tickets to get a new Space Travel object"<<endl;
                return;
            }
            listOfPassengers.push_back(p1);
        }

        void setAstronaut( Astronaut * a1){
            if(astronaut==nullptr){
                astronaut = a1;
                return;
            }
            else{
                cout<<"Astronaut is already assigned to this Space Travel Object. Use updatechangeAstronaut() to change the astronaut"<<endl;
                return;
            }
        }

        void updateAstronaut( Astronaut *a1){
            astronaut = a1;
            cout<<"Astronaut changed"<<endl;
        }

        void setCommander( Commander * a1){
            if(commander==nullptr){
                commander = a1;
                return;
            }
            else{
                cout<<"Commander is already assigned to this Space Travel Object. Use updatechangeCommander() to change the Commander"<<endl;
                return;
            }
        }

        void updateCommander( Commander *a1){
            commander = a1;
            cout<<"Commander changed"<<endl;
        }

};










int main(){
    Planet Earth (0,0,0,"earth");
    Planet Mars (1,1,1,"mars");
    Planet Venus (3,3,3,"venus");

    vector <Ticket *> listOfAllTickets;

    Passenger p1 ("Taylor", 131989);
    Passenger p2 ("Swift", 198913);
    Passenger p3 ("Halsey", 298913);
     Passenger p4 ("Coldplay", 399913);
    Astronaut a1 ("Eminem", 31, 2345);
    Commander c1 ("Lorde", 9, 345, true);

    Ticket t1 (&Earth, &Mars, 23032023, &p1, false, 12345678);
    t1.bookTicket(); listOfAllTickets.push_back(&t1); 
    Ticket t2 (&Earth, &Venus, 23052022, &p1, true, 12976678);
    t2.bookTicket(); listOfAllTickets.push_back(&t2); 
    Ticket t3 (&Earth, &Mars, 23032023, &p2, false, 34612378);
    t3.bookTicket(); listOfAllTickets.push_back(&t3); 
    Ticket t4 (&Earth, &Mars, 23032023, &p3, true, 78045678);
    t4.bookTicket(); listOfAllTickets.push_back(&t4); 
    
    SpaceTravel st1;
int i=0,j=0, k=0, flag = 0;
cout << listOfAllTickets.size()<<endl;
cout<<(listOfAllTickets[0]->sourceStation)->name<<endl;
for (i = 0; i< listOfAllTickets.size(); i++){
    for ( j = 0; j< listOfAllTickets.size(); j++){
        if(i==j)continue;
        for (k = 0; k< listOfAllTickets.size(); k++){
            if(j==k || i==k)continue;
    if((listOfAllTickets[i]->sourceStation)->name == (listOfAllTickets[j]->sourceStation )->name
   && (listOfAllTickets[i]->sourceStation)->name == (listOfAllTickets[k]->sourceStation )->name
   && (listOfAllTickets[i]->destinationStation)->name == (listOfAllTickets[j]->destinationStation)->name
   && (listOfAllTickets[i]->destinationStation )->name== (listOfAllTickets[k]->destinationStation)->name
   && listOfAllTickets[i]->date == listOfAllTickets[j]->date
   && listOfAllTickets[i]->date == listOfAllTickets[k]->date){
            
            flag = 1;
            break;

    }
    
}
if(flag)break;
    
}
if(flag)break;
}
cout<<flag<<endl;
if(flag){
    st1.spaceTravelId=4362872; st1.sourcePlanet= listOfAllTickets[i]->sourceStation; st1.destPlanet= listOfAllTickets[i]->destinationStation; st1.departureDate = listOfAllTickets[i]->date ;
    st1.addPassenger(listOfAllTickets[i]->passenger);
            st1.addPassenger(listOfAllTickets[j]->passenger);
            st1.addPassenger(listOfAllTickets[k]->passenger);
            st1.setAstronaut(&a1);
            st1.setCommander(&c1);
}
Ticket t5 (&Earth, &Venus, 23082023, &p3, true, 78040980);
t5.bookTicket(); listOfAllTickets.push_back(&t5);

if(st1.sourcePlanet==t5.sourceStation && st1.destPlanet == t5.destinationStation && st1.departureDate == t5.date){
    st1.addPassenger(t5.passenger);
}

Ticket t6 (&Earth, &Mars, 23032023, &p4, true, 89040980);
t6.bookTicket(); listOfAllTickets.push_back(&t6);

if(st1.sourcePlanet==t6.sourceStation && st1.destPlanet == t6.destinationStation && st1.departureDate == t6.date){
    st1.addPassenger(t6.passenger);
}

for (int i =0; i<st1.listOfPassengers.size();i++){
    cout<<(st1.listOfPassengers[i])->name<<endl;
    
}

return 0;
}