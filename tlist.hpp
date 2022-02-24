// *****************************************************************
// * Function Name:  TList()                                       *
// * Description:  Default constructor that creates an empty       *
// * linked list                                                   *
// * Parameter Description:   No parameters                        *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template<typename T>
TList<T>::TList() {
    // Create an empty list
    first = nullptr;
    last = nullptr;
    size = 0;
}
// *****************************************************************
// * Function Name:  TList()                                       *
// * Description: Parametrized constructor that creates a linked   *
// * list of variable size and value depending on parameters       *
// * Parameter Description: T val for the value inside the linked  *
// * list, int num for the number of repeated elements in the list *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template<typename T>
TList<T>::TList(T val, int num) {
    // Create an empty list initially
    first = nullptr;
    last = nullptr;
    size = 0;

    // Insert val to the back num amount of times
    for(int i = 0; i < num; i++){
        InsertBack(val);
    }
}
// *****************************************************************
// * Function Name:  TList()                                       *
// * Description: Copy Constructor that deep copies one list to    *
// * another list.                                                 *
// * Parameter Description: TList &L, object L that is used to     *
// * copy its contents to another object                           *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Dr. Gaitros' Canvas/YouTube video on linked list  *
// * w/ iterators                                                  *
// *****************************************************************
template<typename T>
TList<T>::TList(const TList &L) {
    // Grab L's iterator and create an empty list initially
    auto iterator = L.GetIterator();
    first = nullptr;
    last = nullptr;
    size = 0;

    // Loop through list and grab the iterator's data and insert it to the back of the list, incrementing iterator each time
    for(int i = 0; i < L.GetSize(); i++){
        InsertBack(iterator.GetData());
        iterator.Next();
    }
}
// *****************************************************************
// * Function Name:  ~TList()                                       *
// * Description: Destructor that deallocates the memory at the    *
// * end of the program                                            *
// * Parameter Description: No parameters                          *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Dr. Gaitros' Canvas/YouTube video on linked list  *
// * w/ iterators                                                  *
// *****************************************************************
template<typename T>
TList<T>::~TList() {
    // Grab iterator
    auto iterator = GetIterator();

    // Loop through list, delete the node and increment the iterator until all nodes are deleted
    for(int i = 1; i <= size; i++){
        delete iterator.ptr;
        iterator.Next();
    }
}

// *****************************************************************
// * Function Name:  operator=()                                   *
// * Description: Copy assignment operator, deep copies one        *
// * object to another                                             *
// * Parameter Description: TList &L, object L that is used to     *
// * copy its contents to another object                           *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Dr. Gaitros' Canvas/YouTube video on linked list  *
// * w/ iterators                                                  *
// *****************************************************************
template <class T>
TList<T> &TList<T>::operator=(const TList& L){
    // Grab L's iterator and create an empty list initially
    auto iterator = L.GetIterator();
    first = nullptr;
    last = nullptr;
    size = 0;

    // Loop through list and grab the iterator's data and insert it to the back of the list, incrementing iterator each time
    for(int i = 0; i < L.GetSize(); i++){
        InsertBack(iterator.GetData());
        iterator.Next();
    }
    return *this;
}

// *****************************************************************
// * Function Name:  operator=()                                   *
// * Description: Move assignment operator, moves over all of      *
// * the object's variables to another object                      *
// * Parameter Description: TList<T> &&L, object L that is used to *
// * move its contents to another object                           *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Dr. Gaitros' Canvas/YouTube video on linked list  *
// * w/ iterators                                                  *
// *****************************************************************
template<typename T>
TList<T> &TList<T>::operator=(TList<T> &&L) {
    int tempsize = 0;
    Node<T> *temporary = first;
    // Copy first variable
    first = L.first;
    // Switch around pointers
    L.first = temporary;
    temporary = last;
    // Copy last variable
    last = L.last;
    // Switch around pointers
    L.last = temporary;
    // Copy size to tempsize
    tempsize = size;
    // Copy size variable
    size = L.size;
    // Switch variables
    L.size = tempsize;

    return *this;
}

// *****************************************************************
// * Function Name:  TList()                                       *
// * Description: Move constructor, moves over all of the          *
// * object's variables to another object                          *
// * Parameter Description: TList<T> &&L, object L that is used to *
// * move its contents to another object                           *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No references                                     *
// *****************************************************************
template<typename T>
TList<T>::TList(TList &&L) {
    // Copy corresponding variables
    first = L.first;
    last = L.last;
    size = L.size;
}
// *****************************************************************
// * Function Name:  IsEmpty()                                     *
// * Description: Checks to see if a list is empty                 *
// * Parameter Description: No parameters                          *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No references                                     *
// *****************************************************************
template<typename T>
bool TList<T>::IsEmpty() const {
    return (size == 0); // If size is 0, then the list is empty, else not
}
// *****************************************************************
// * Function Name:  GetSize()                                     *
// * Description: Returns the size of a list                       *
// * Parameter Description: No parameters                          *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No references                                     *
// *****************************************************************
template<typename T>
int TList<T>::GetSize() const {
    return size; // Return size of list
}

// *****************************************************************
// * Function Name:  Clear()                                       *
// * Description: Clears all the nodes in the list                 *
// * Parameter Description: No parameters                          *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No references                                     *
// *****************************************************************
template<typename T>
void TList<T>::Clear() {
    // Loop through and remove the back values
    for(int i = 0; i < size; i++){
        RemoveBack();
    }
    // Set the class variables to default empty values
    first = nullptr;
    last = nullptr;
    size = 0;
}

// *****************************************************************
// * Function Name:  InsertBack()                                  *
// * Description: Inserts a value to the back of the list          *
// * Parameter Description: T &d used to input parameter into list *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Dr. Gaitros' Canvas/YouTube video on linked list  *
// * w/ iterators                                                  *
// *****************************************************************
template<typename T>
void TList<T>::InsertBack(const T &d) {
    auto *node = new Node <T>(d); // Create object from Node class

    // Check if it is empty or not
    if(IsEmpty()){ // If the list is empty...
        // First and last = node;
        first = node;
        last = node;
    }else{ // If the list is not empty...
        // Shift prev/next variables from Node class
        node->prev = last;
        last->next = node;
        last = node;
    }
    size++; // Increment size
}

// *****************************************************************
// * Function Name:  InsertFront()                                 *
// * Description: Inserts a value to the front of the list         *
// * Parameter Description: T &d used to input parameter into list *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Dr. Gaitros' Canvas/YouTube video on linked list  *
// * w/ iterators                                                  *
// *****************************************************************
template<typename T>
void TList<T>::InsertFront(const T &d) {
    auto *node = new Node <T>(d); // Create object from Node class

    // Check if it is empty or not
    if(IsEmpty()){ // If the list is empty...
        // First and last = node;
        first = node;
        last = node;
    }else{ // If the list is not empty...
        // Shift prev/next variables from Node class
        node->next = first;
        first->prev = node;
        first = node;
    }
    size++; // Increment size
}

// *****************************************************************
// * Function Name:  Print()                                       *
// * Description: Prints out stream of data given some delim       *
// * Parameter Description: os - output stream of data, delim -    *
// * character delim to separate data                              *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No references                                     *
// *****************************************************************
template<typename T>
void TList<T>::Print(std::ostream &os, char delim) const {
    // Classify iterator as it's own iterator
    auto iterator = this->GetIterator();
    // Loop through entire list and grab data for each node and shift the iterator.
    for(int i = 0; i<size; i++){
        os << iterator.GetData() << delim;
        iterator.Next();
    }
}

// *****************************************************************
// * Function Name:  TListIterator()                               *
// * Description:  Default constructor that sets ptr to nullpt     *
// * Parameter Description:   No parameters                        *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template <class T>
TListIterator<T>::TListIterator(){
    ptr = nullptr; // Set ptr to nullptr
}

// *****************************************************************
// * Function Name:  GetIterator()                                 *
// * Description:  Returns iterator that points to the first       *
// * element in the list                                           *
// * Parameter Description: No parameters                          *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No references                                     *
// *****************************************************************
template<typename T>
TListIterator<T> TList<T>::GetIterator() const {
    // Define object of class TListIterator and set the ptr value
    // to the first value of the list and return the iterator
    TListIterator<T> iterator;
    iterator.ptr = first;

    return iterator;
}

// *****************************************************************
// * Function Name:  GetIteratorEnd()                              *
// * Description:  Returns iterator that points to the last        *
// * element in the list                                           *
// * Parameter Description: No parameters                          *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No references                                     *
// *****************************************************************
template<typename T>
TListIterator<T> TList<T>::GetIteratorEnd() const {
    // Define object of class TListIterator and set the ptr value
    // to the last value of the list and return the iterator
    TListIterator<T> iterator;
    iterator.ptr = last;

    return iterator;
}

// *****************************************************************
// * Function Name:  GetData()                                     *
// * Description:  Returns the data pointed by the pointer         *
// * Parameter Description:   No parameters                        *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template <class T>
T& TListIterator<T>::GetData() const{
    // Return data of the current node (ptr's data).
    return ptr->data;
}

// *****************************************************************
// * Function Name:  Next()                                        *
// * Description:  Shifts the pointer to the next node             *
// * Parameter Description:   No parameters                        *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template <class T>
TListIterator<T> TListIterator<T>::Next(){
    if(HasNext()){ // If there is a next value, shift ptr values
        ptr = ptr->next;
    }
    return *this;
}

// *****************************************************************
// * Function Name:  Previous()                                    *
// * Description:  Shifts the pointer to the previous node         *
// * Parameter Description:   No parameters                        *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template <class T>
TListIterator<T> TListIterator<T>::Previous(){
    if(HasPrevious()){ // If there is a previous value, shift ptr values
        ptr = ptr->prev;
    }
    return *this;
}

// *****************************************************************
// * Function Name:  HasNext()                                     *
// * Description:  Checks to see if the ptr's next node is there   *
// * Parameter Description:   No parameters                        *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template <class T>
bool TListIterator<T>::HasNext() const{
    // If ptr's next value is not null (next value present), return true, else return false
    if(ptr->next != nullptr)
        return true;
    else
        return false;
}

// *****************************************************************
// * Function Name:  HasPrevious()                                 *
// * Description:  Checks to see if the ptr's prev node is there   *
// * Parameter Description:   No parameters                        *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No References                                     *
// *****************************************************************
template<typename T>
bool TListIterator<T>::HasPrevious() const {
    // If ptr's prev value is not null (previous value present), return true, else return false
    if(ptr->prev != nullptr)
        return true;
    else
        return false;
}

// *****************************************************************
// * Function Name:  RemoveBack()                                  *
// * Description: Removes a value from the back of the list        *
// * Parameter Description: No parameters                          *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Dr. Gaitros' Canvas/YouTube video on linked list  *
// * w/ iterators                                                  *
// *****************************************************************
template<typename T>
void TList<T>::RemoveBack() {
    if(size==0){ // Size = 0
        return; // Nothing to remove, so return
    }else if(size == 1){ // Size = 1
        // Delete first (only) value in list and set first/last to null ptrs and size to 0
        delete first;
        first = nullptr;
        last = nullptr;
        size = 0;
    }else{ // Size > 1
        // Shift pointers and remove last item, decrement size
        Node<T> *dummyptr = last->prev;
        dummyptr->next = 0;
        delete last;
        last = dummyptr;
        size--;
    }
}

// *****************************************************************
// * Function Name:  RemoveFront()                                 *
// * Description: Removes a value from the front of the list       *
// * Parameter Description: No parameters                          *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Dr. Gaitros' Canvas/YouTube video on linked list  *
// * w/ iterators                                                  *
// *****************************************************************
template<typename T>
void TList<T>::RemoveFront() {
    if(size==0){ // Size = 0
        return; // Nothing to remove, so return
    }else if(size == 1){ // Size = 1
        // Delete first (only) value in list and set first/last to null ptrs and size to 0
        delete first;
        first = nullptr;
        last = nullptr;
        size = 0;
    }else{ // Size > 1
        // Shift pointers and remove first item, decrement size
        Node<T> *dummyptr = first->next;
        dummyptr->prev = 0;
        delete first;
        first = dummyptr;
        size--;
    }
}
// *****************************************************************
// * Function Name:  Insert()                                      *
// * Description: Inserts value into list positioned by iterator   *
// * Parameter Description: pos - iterator that points to a        *
// * position in the list, d - value that is being inserted - typeT*
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Dr. Gaitros' Canvas/YouTube video on linked list  *
// * w/ iterators                                                  *
// *****************************************************************
template<typename T>
void TList<T>::Insert(TListIterator<T> pos, const T &d) {
    // Define local pointers
    Node<T> *previous;
    auto *temporary= new Node<T>(d);
    // If the list is empty or if the iterator points to nothing, insert the single item to the back
    if(IsEmpty() || pos.ptr == nullptr){
        InsertBack(d);
        return;
    }
    // If there is a previous node, copy the contents to previous, else set previous to nullptr
    if(pos.HasPrevious()) {
        previous = pos.ptr->prev;
    }else {
        previous = nullptr;
    }
    // Switch pointers
    temporary->next = pos.ptr;
    pos.ptr->prev = temporary;
    // If it is the first of the list, set firs to temporary
    if(previous == nullptr)
        first = temporary;
    // Else switch pointers
    else{
        previous->next = temporary;
        temporary->prev = previous;
    }
    size++; // Increment size
}
// *****************************************************************
// * Function Name:  Remove()                                      *
// * Description: Removes element given by iterator position       *
// * Parameter Description: pos - iterator that is used to remove
// * the value right after that position - type T
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: Dr. Gaitros' Canvas/YouTube video on linked list  *
// * w/ iterators                                                  *
// *****************************************************************
template<typename T>
TListIterator<T> TList<T>::Remove(TListIterator<T> pos) {
    // If the list is empty, there is nothing to delete, so return iterator
    if(IsEmpty()){
        return pos;
    }
    // Define local pointers
    Node<T> *currentposition = pos.ptr;
    Node<T> *previousposition = currentposition->prev;
    Node<T> *nextposition = currentposition->next;
    //Increment iterator to next node
    pos.Next();
    // Switch pointers
    previousposition->next = nextposition;
    nextposition->prev = previousposition;
    // Delete the currentposition (next pointer in reference)
    delete currentposition;
    size--; // Decrement size

    return pos; // Return iterator
}

// *****************************************************************
// * Function Name:  GetFirst()                                    *
// * Description: Returns first element in the list                *
// * Parameter Description: No parameters                          *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No references                                     *
// *****************************************************************
template<typename T>
T &TList<T>::GetFirst() const {
    return first->data;
}

// *****************************************************************
// * Function Name:  GetLast()                                     *
// * Description: Returns last element in the list                 *
// * Parameter Description: No parameters                          *
// * Date:  01/19/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References: No references                                     *
// *****************************************************************
template<typename T>
T &TList<T>::GetLast() const {
    return last->data;
}
