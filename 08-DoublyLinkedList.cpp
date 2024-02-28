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
 * The Doubly Linked List Class
 */
template <typename T>
class DoublyLinkedList : public LinkedList<T>
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
        Node *newNode = create_node(item);
        newNode->next = head;
        if (head != nullptr)
        {
            head->prev = newNode;
        }
        head = newNode;
    }

    /* Menyisipkan node setelah node tertentu */
    void add_after(T item, Node *node)
    {
        Node *newNode = create_node(item);
        newNode->next = node->next;
        newNode->prev = node;
        if (node->next != nullptr)
        {
            node->next->prev = newNode;
        }
        node->next = newNode;
    }

    /* Mengambil data pada bagian awal list */
    T remove_front()
    {
        Node *node = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        return del_node(node);
    }

    /* Mengambil data setelah node tertentu */
    T remove_after(Node *previous)
    {
        Node *node = previous->next;
        previous->next = node->next;
        if (previous->next != nullptr)
        {
            previous->next->prev = previous;
        }
        return del_node(node);
    }

public:
    /*
     * Public methods
     */
    DoublyLinkedList()
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

    /* Mengubah posisi iterator ke head */
    void first()
    {
        iterator = head;
    }

    /* Mengubah posisi iterator ke tail */
    void last()
    {
        iterator = node_at(n - 1);
    }

    /* Mengecek apakah ada elemen selanjutnya */
    bool hasNext()
    {
        return (iterator == nullptr) ? false : true;
    }

    /* Mengecek apakah ada elemen sebelumnya */
    bool hasPrev()
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

    /* Mengecek apakah ada elemen sebelumnya */
    T prev()
    {
        if (!hasPrev())
        {
            throw invalid_argument("End of the list. Call last() to reset the iterator.");
        }

        T item = iterator->item;
        iterator = iterator->prev;
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
    DoublyLinkedList<string> list;
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

    cout << "Using iterator:" << endl;
    list.first();
    while (list.hasNext())
    {
        cout << list.next() << " ";
    }
    cout << endl;

    cout << "Using iterator (reverse): " << endl;
    list.last();
    while (list.hasPrev())
    {
        cout << list.prev() << " ";
    }
    cout << endl;

    cout << "Get:" << endl;
    for (int i = 0; i < list.size(); i++)
    {
        cout << list.get(i) << " ";
    }
    cout << endl;

    cout << "Remove: " << endl;
    for (int i = list.size() - 1; i >= 0; i--)
    {
        cout << list.remove(i) << " ";
    }
    cout << endl;

    cout << "After Remove: " << endl;
    list.print();

    return 0;
}