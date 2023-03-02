#include <cstdint>
#include <iostream>
#include <memory>

using namespace std;

template <class T>
struct nod{

    nod *next,*prev;
    uint32_t prioritate;
    T obiect;
};

template <class T>
class PriorityQueue {

private:
    struct nod<T>* head;
    uint32_t prioritateMax;
public:
    /**
     * Constructorul va crea un PriorityQueue.
     *
     * @param maxPriorityValue prioritatatea cea mai mica din coada (valoarea maxima).
     */


    PriorityQueue(uint32_t maxPriorityValue) {
        this->prioritateMax=maxPriorityValue;
        this->head=NULL;

    }

    /**
     * Functia va intoarce numarul de elemente din coada.
     * @return numarul de elemente din coada.
     */
    uint32_t size() {
    
        nod<T>* currnod=this->head;
        int size=0;
        while(currnod!=NULL){
            size++;
            currnod=currnod->next;
        }
        return size;
        
    }

    /**
     * Functia va intoarce true daca coada este goala.
     * @return true dacă coada este goala, altfel false
     */
    bool empty() {
       return head==NULL;
    }

    /**
     * Functia va insera in coada elementul cu prioritatea specificata.
     * @param value elementul care trebuie adaugat in coada.
     * @param priority prioritatea cu care se adauga in coada elementul.
     */

    void push(T value, uint32_t priority)
    {

        nod<T>* start = head;
        nod<T>* temp = new nod<T>;
        temp->prioritate=priority;
        temp->obiect=value;
        if (head == NULL) {
            head = temp;
            temp->next=NULL;
            return;
        }
        if (head->prioritate > priority)
        {
            temp->next = head;
            head = temp;
        }
        else
        {
            while(start->next !=NULL && start->next->prioritate <= priority)
            {
                start = start->next;
            }
            temp->next = start->next;
            start->next = temp;
        }
    }

    /**
     * Functia va extrage si elimina din coada pacientul cu prioritatea maxima.
     * @return elementul cu prioritatea maxima
     */
    T pop() {
        T curr = head->obiect;
        head = head->next;
        return curr;
    }

    /**
     * Destructorul dezaloca memoria utilizata de coada, daca s-a alocat in
     * constructor. Altfel, lasat-l gol.
     */
    ~PriorityQueue() {
        // TODO: scrieti codul aici
        delete head;
    }



};