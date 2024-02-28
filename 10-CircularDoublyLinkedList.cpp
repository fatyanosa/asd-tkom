#include <iostream>

using namespace std;

/*
 * The Abstract Data Type of a Linked List
 */
template <typename T>
class LinkedList
{
public:
    virtual int size() = 0;                  // Mendapatkan jumlah node dalam list
    virtual void add(T item) = 0;            // Menambahkan data pada akhir list
    virtual void add(int index, T item) = 0; // Menambahkan data pada index tertentu
    virtual T get(int index) = 0;            // Melihat data pada index tertentu
    virtual T remove(int index) = 0;         // Mengambil data dari index tertentu
    virtual void print() = 0;                // Menampilkan seluruh isi list
};

/*
 * The Singly Linked List Class
 */
template <typename T>
class CircularDoublyLinkedList : public LinkedList<T>
{

private:
    /*
     * Private Attributes and Methods
     */
    class Node
    {
    public:
        T item;
        Node *next;
        Node *prev;
    };

    Node *head;
    Node *iterator;
    int n;

    /* Mendapatkan pointer ke node di index tertentu. Index dimulai dari 0 */
    Node *node_at(int index)
    {
        Node *iter = head;
        for (int i = 1; i <= index; i++)
        {
            iter = iter->next;
        }
        return iter;
    }

    /* Membuat node */
    Node *create_node(T item)
    {
        Node *newNode = new Node();
        newNode->item = item;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        n++;
        return newNode;
    }

    /* Menghapus node */
    T del_node(Node *node)
    {
        T item = node->item;
        node->next = nullptr;
        node->prev = nullptr;
        delete node;
        n--;
        return item;
    }

    /* Menyisipkan node pada bagian awal list */
    void add_front(T item)
    {
        if (head == nullptr)
        {
            Node *newNode = create_node(item);
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        }
        else
        {
            Node *tail = head->prev; // Last Node
            Node *newNode = create_node(item);
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }
    }

    /* Menyisipkan node setelah node tertentu */
    void add_after(T item, Node *node)
    {
        Node *newNode = create_node(item);
        newNode->next = node->next;
        newNode->prev = node;
        node->next->prev = newNode;
        node->next = newNode;
    }

    /* Mengambil data pada bagian awal list */
    T remove_front()
    {
        Node *node = head;
        if (head->next == head)
        {
            head == nullptr;
        }
        else
        {
            Node *tail = head->prev; // Last Node
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }
        return del_node(node);
    }

    /* Mengambil data setelah node tertentu */
    T remove_after(Node *previous)
    {
        Node *node = previous->next;
        previous->next = node->next;
        node->next->prev = previous;
        return del_node(node);
    }

public:
    /*
     * Public methods
     */
    CircularDoublyLinkedList()
    {
        head = nullptr;
        iterator = nullptr;
        n = 0;
    }

    /* Mendapatkan jumlah node dalam list */
    int size()
    {
        return n;
    }

    /* Menambahkan data pada akhir list */
    void add(T item)
    {
        add(n, item);
    }

    /* Menambahkan data pada index tertentu */
    void add(int index, T item)
    {
        if (index < 0 || (index > n))
        {
            throw invalid_argument("Index " + to_string(index) + " of bound. Allowed index: 0 to " + to_string(n));
        }

        if (index == 0)
        { // Jika list kosong atau menyisipkan node pada bagian awal list
            add_front(item);
        }
        else
        { // Jika ingin menyisipkan node pada bagian lain dari list
            add_after(item, node_at(index - 1));
        }
    }

    /* Melihat data pada index tertentu */
    T get(int index)
    {
        if (n == 0)
        {
            throw invalid_argument("List is empty.");
        }

        if (index < 0 || (index >= n))
        {
            throw invalid_argument("Index " + to_string(index) + " of bound. Allowed index: 0 to " + to_string(n - 1));
        }

        Node *pointer = node_at(index);
        return pointer->item;
    }

    /* Mengambil data dari index tertentu */
    T remove(int index)
    {
        if (n == 0)
        {
            throw invalid_argument("List is empty.");
        }

        if (index < 0 || (index >= n))
        {
            throw invalid_argument("Index " + to_string(index) + " of bound. Allowed index: 0 to " + to_string(n - 1));
        }

        T item;
        if (index == 0)
        { // Jika ingin mengambil data pada bagian awal list
            item = remove_front();
        }
        else
        { // Jika ingin mengambil node pada bagian lain dari list
            item = remove_after(node_at(index - 1));
        }

        return item;
    }

    /* Memutar list: node pertama menjadi node terakhri*/
    void rotate()
    {
        if (n == 0)
        {
            throw invalid_argument("List is empty.");
        }

        head = head->next;
    }

    /* Memutar list: node terakhir menjadi node pertama*/
    void reverse_rotate()
    {
        if (n == 0)
        {
            throw invalid_argument("List is empty.");
        }

        head = head->prev;
    }

    /* Mengubah posisi iterator ke head */
    void first()
    {
        iterator = head;
    }

    /* Mengecek apakah ada elemen selanjutnya */
    bool hasNext()
    {
        return (iterator == nullptr) ? false : true;
    }

    /* Mengecek apakah ada elemen selanjutnya */
    T next()
    {
        if (!hasNext())
        {
            throw invalid_argument("End of the list. Call first() to reset the iterator.");
        }

        T item = iterator->item;
        iterator = iterator->next;
        return item;
    }

    /* Menampilkan seluruh isi list */
    void print()
    {
        Node *iter = head;
        for (int i = 0; i < n; i++)
        {
            cout << iter->item << " ";
            iter = iter->next;
        }
        cout << endl;
    }
};

int main()
{
    CircularDoublyLinkedList<string> list;
    list.add("A");
    list.print();
    list.add("B");
    list.print();
    list.add("C");
    list.print();
    list.add("D");
    list.print();

    cout << "Size: " << list.size() << endl;

    list.add(0, "E");
    list.print();
    list.add(1, "F");
    list.print();
    list.add(2, "G");
    list.print();
    list.add(3, "H");
    list.print();

    cout << "Rotate:" << endl;
    list.rotate();
    list.print();

    cout << "Reverse Rotate:" << endl;
    list.reverse_rotate();
    list.print();

    cout << "Get:" << endl;
    for (int i = 0; i < list.size(); i++)
    {
        cout << list.get(i) << " ";
    }
    cout << endl;

    cout << "Remove:" << endl;
    for (int i = list.size() - 1; i >= 0; i--)
    {
        cout << list.remove(i) << " ";
    }
    cout << endl;

    cout << "After Remove:" << endl;
    list.print();

    return 0;
}