// Package yang di butuhkan
#include <iostream>
#include <cstring>

// Membuat variabel yang tidak bisa di ubah
#define MAX 100 // Maskimal ukuran array

using namespace std;

// Program Stack
class ProgramStack
{
private:
    int top;      // Indeks elemen
    int arr[MAX]; // Array untuk menyimpan stack
public:
    ProgramStack()
    {
        top = -1; // Menginisialisasi stack kosong
    }

    // Stack menu
    void stackMenu()
    {
        int choice, value;
        do
        {
            cout << "\n=== Menu Stack ===\n";
            cout << "1. Push\n";
            cout << "2. Pop\n";
            cout << "3. Peek\n";
            cout << "4. Display\n";
            cout << "5. Kembali ke menu utama\n";
            cout << "Masukan pilihan anda: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Masukan nilai yang ingin di tambahkan: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Kembali ke menu utama.\n";
                break;
            default:
                cout << "Pilihan tidak di temukan silahkan coba lagi!\n";
            }
        } while (choice != 5);
    }

    bool isEmpty()
    { // cek stack kosong
        return top == -1;
    }

    bool isFull()
    { // cek stack Full
        return top == MAX - 1;
    }

    // Input new value ke dalam stack
    void push(int value)
    {
        if (isFull()) // Cek apakan stack telah mencapai jumlah maksimal
        {
            cout << "Steak telah mencapai jumlah maxsimal 100! \n";
        }
        else
        {
            arr[++top] = value;
            cout << "Elemen " << value << " berasil di tambahkan.\n";
        }
    }

    // Hapus elemen pada array
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Kosong. \n";
        }
        else
        {
            cout << "Elemen " << arr[top] << " berhasil di hapus dari stack. \n";
            top--;
        }
    }

    // Melihat elemen paling atas
    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack kosong!\n";
        }
        else
        {
            cout << "Elemen teratas pada stack adalah: " << arr[top] << "\n";
        }
    }

    // Menampilkan isi pada array
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack kosong!\n";
        }
        else
        {
            cout << "Isi stack: ";
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
    }
};

// Program Queueu
class ProgramQueue
{
private:
    int front, rear, size; // deklarasi variabel yang hanya dapat di akses pada class program queue
    int arr[MAX];          // deklarasi variabel array set max value

public:
    ProgramQueue()
    {
        front = -1;
        rear = -1;
        size = 0;
    }

    // Queue menu
    void queueMenu()
    {
        int choice, value;
        do
        {
            cout << "\n=== Menu Queue ===\n";
            cout << "1. Enqueue\n";
            cout << "2. Dequeue\n";
            cout << "3. Peek\n";
            cout << "4. Display\n";
            cout << "5. Kembali ke menu utama\n";
            cout << "Masukan pilihan anda: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Masukan nilai yang ingin di tambahkan: ";
                cin >> value;
                equeue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Kembali ke menu utama.\n";
                break;
            default:
                cout << "Pilihan tidak di temukan silahkan coba lagi!\n";
            }
        } while (choice != 5);
    }

    bool isEmpty()
    { // cek value array kosong
        return size == 0;
    }

    bool isFull()
    { // cek value array penuh/mencapai jumlah maskimal
        return size == MAX;
    }

    // input data ke dalam array queue
    void equeue(int value)
    {
        if (isFull())
        {
            cout << "Queue penuh, tidak dapat menambahkan elemen! /n";
        }
        else
        {
            if (isEmpty())
            { // Cek apakah array masih kosong
                front = 0;
            }
            rear = (rear + 1) % MAX;
            arr[rear] = value;
            size++;
            cout << "Elemen " << value << " berhasil di tambahkan kedalam queue. /n";
        }
    }

    // menghapus data dalam array queue
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue kosong! /n";
        }
        else
        {
            cout << "Elemen " << arr[front] << " di hapus. \n";
            front = (front + 1) % MAX;
            size--;
        }
    }

    // melihat elemen yang ada di berada depan
    void peek()
    {
        if (isEmpty())
        {
            cout << "Tidak ada element di depan! \n";
        }
        else
        {
            cout << "Elemet di depan adalah: " << arr[front] << "\n";
        }
    }

    // melihat seluruh list array queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue Kosong \n";
        }
        else
        {
            cout << "Isi Queue: ";
            for (int i = 0; i < size; i++)
            {
                cout << arr[(front + i) % MAX] << " ";
            }
            cout << "\n";
        }
    }
};

// Program Linked List
class ProgramLinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
    };

    Node *head;

public:
    ProgramLinkedList()
    {
        head = nullptr;
    }

    // Menu Linked List
    void linkedListMenu()
    {
        int choice, value;
        do
        {
            cout << "\n=== Menu Linked List ===\n";
            cout << "1. Tambah di Akhir\n";
            cout << "2. Hapus di Awal\n";
            cout << "3. Tampilkan\n";
            cout << "4. Kembali ke menu utama\n";
            cout << "Masukkan pilihan Anda: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Masukkan nilai yang ingin ditambahkan: ";
                cin >> value;
                append(value);
                break;
            case 2:
                remove();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Kembali ke menu utama.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
            }
        } while (choice != 4);
    }

    // Input Linked List
    void append(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Elemen " << value << " berhasil ditambahkan ke linked list.\n";
    }

    // Hpus data linked list
    void remove()
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong! Tidak ada elemen yang dapat dihapus.\n";
        }
        else
        {
            Node *temp = head;
            head = head->next;
            cout << "Elemen " << temp->data << " dihapus dari linked list.\n";
            delete temp;
        }
    }

    // Tampilkan data linked list
    void display()
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong!\n";
        }
        else
        {
            cout << "Isi linked list: ";
            Node *temp = head;
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n";
        }
    }
};

// Program Graph
class ProgramGraph
{
private:
    int adjMatrix[MAX][MAX];
    int vertices;

public:
    ProgramGraph()
    {
        vertices = 0;
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                adjMatrix[i][j];
            }
        }
    }

    // Graph Menu
    void graphMenu()
    {
        int choice, v1, v2; // input value
        do
        {
            cout << "\n=== Menu Graph ===\n";
            cout << "1. Buat Graph Baru\n";
            cout << "2. Tambah Edge\n";
            cout << "3. Tampilkan Matrix Adjacent\n";
            cout << "4. BFS Traversal\n";
            cout << "5. Kembali ke menu utama\n";
            cout << "Masukkan pilihan Anda: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Masukkan jumlah vertices: ";
                cin >> vertices;
                initializeGraph();
                break;
            case 2:
                cout << "Masukkan vertex pertama: ";
                cin >> v1;
                cout << "Masukkan vertex kedua: ";
                cin >> v2;
                addEdge(v1, v2);
                break;
            case 3:
                displayMatrix();
                break;
            case 4:
                if (vertices > 0)
                {
                    cout << "Masukkan vertex awal untuk DFS: ";
                    cin >> v1;
                    DFS(v1);
                }
                else
                {
                    cout << "Graph kosong!\n";
                }
                break;
            case 5:
                cout << "Kembali ke menu utama.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
            }
        } while (choice != 5);
    }

    // inisialisasi graph
    void initializeGraph()
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
        cout << "Graph degan " << vertices << " vertices berhasil dibuat.\n";
    }

    // input graph
    void addEdge(int v1, int v2)
    {
        if (v1 >= 0 && v1 < vertices && v2 >= 0 && v2 < vertices)
        {
            adjMatrix[v1][v2] = 1;
            adjMatrix[v2][v1] = 1;
            cout << "Edge antara vertex " << v1 << " dan " << v2 << " berhasil ditambahkan.\n";
        }
        else
        {
            cout << "vertex tidak valid!\n";
        }
    }

    // Menampilkan display Matrix
    void displayMatrix()
    {
        if (vertices == 0)
        {
            cout << "Graph kosong!\n";
            return;
        }

        cout << "Matrix Adjacnet:\n";
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFSUtil(int vertex, int visted[])
    {
        visted[vertex] = 1;
        cout << vertex << " ";

        for (int i = 0; i < vertices; i++)
        {
            if (adjMatrix[vertex][i] == 1 && !visted[i])
            {
                DFSUtil(i, visted);
            }
        }
    }

    void DFS(int start)
    {
        if (start < 0 || start >= vertices)
        {
            cout << "Vertex awal tidak valid!\n";
            return;
        }

        int visited[MAX] = {0};
        cout << "BFS traversal dimulai dari vertex " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

// Program Tree
class ProgramTree
{
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;

        Node(int value)
        {
            data = value;
            left = right = nullptr;
        }
    };

    Node *root;

    // function helper untuk memasukan value ke dalam node
    Node *insertHelper(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insertHelper(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertHelper(node->right, value);
        }

        return node;
    }

    // function untuk inorder transversal
    void inorderHelper(Node *node)
    {
        if (node != nullptr)
        {
            inorderHelper(node->left);
            cout << node->data << " ";
            inorderHelper(node->right);
        }
    }

public:
    ProgramTree()
    {
        root = nullptr;
    }

    // tree menu
    void treeMenu()
    {
        int choice, value;
        do
        {
            cout << "\n=== Menu Binary Search Tree ===\n";
            cout << "1. Tambah Node\n";
            cout << "2. Tampilkan (Inorder)\n";
            cout << "3. Cari Nilai\n";
            cout << "4. Kembali ke menu utama\n";
            cout << "Masukkan pilihan Anda: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Masukkan nilai yang ingin ditambahkan: ";
                cin >> value;
                insert(value);
                break;
            case 2:
                display();
                break;
            case 3:
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> value;
                if (search(value))
                {
                    cout << "Nilai " << value << " ditemukan dalam tree.\n";
                }
                else
                {
                    cout << "Nilai " << value << " tidak ditemukan dalam tree.\n";
                }
                break;
            case 4:
                cout << "Kembali ke menu utama.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
            }
        } while (choice != 4);
    }

    // input value kedalam tree
    void insert(int value)
    {
        root = insertHelper(root, value);
        cout << "Nilai " << value << " berhasil ditambahkan ke dalam tree.\n";
    }

    // mencari nilai dalam tree
    bool search(int value)
    {
        Node *current = root;
        while (current != nullptr)
        {
            if (value == current->data)
            {
                return true;
            }
            if (value < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        return false;
    }

    // Menampilkan tree
    void display()
    {
        if (root == nullptr)
        {
            cout << "Tree kosong!\n";
            return;
        }
        cout << "Isi tree (Inorder): ";
        inorderHelper(root);
        cout << endl;
    }
};

// Searching Algorithm
class ProgramSearchingAlgorithm
{
private:
    int arr[MAX];
    int size;

public:
    ProgramSearchingAlgorithm()
    {
        size = 0;
    }

    // Menu Searching
    void searchingMenu()
    {
        int choice, key;
        do
        {
            cout << "\n=== Menu Searching Algorithm ===\n";
            cout << "1. Buat Array Baru\n";
            cout << "2. Linear Search\n";
            cout << "3. Binary Search\n";
            cout << "4. Tampilkan Array\n";
            cout << "5. Kembali ke menu utama\n";
            cout << "Masukkan pilihan: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                createArray();
                break;
            case 2:
                cout << "Masukkan nilai yang dicari: ";
                cin >> key;
                linearSearch(key);
                break;
            case 3:
                cout << "Masukkan nilai yang dicari: ";
                cin >> key;
                binarySearch(key);
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Kembali ke menu utama\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
            }
        } while (choice != 5);
    }

    // function untuk membuat array dan input data
    void createArray()
    {
        cout << "Masukan ukuran array (MAX " << MAX << "): ";
        cin >> size;

        if (size > MAX)
        {
            cout << "Ukuran terlalu besar!\n";
            size = 0;
            return;
        }

        cout << "Masukkan " << size << " angka:\n";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }

    // mecari data menggunakan linear search
    void linearSearch(int key)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == key)
            {
                cout << "Nilai " << key << " ditemukan pada index " << i << ".\n";
                return;
            }
        }
        cout << "Nilai " << key << " tidak ditemukan!\n";
    }

    // mencari data mengungunakan binary search
    void binarySearch(int key)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        int left = 0, right = size - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[mid] == key)
            {
                cout << "Nilai " << key << " ditemukan pada index " << mid << ".\n";
                return;
            }
            if (arr[mid] < key)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        cout << "Nilai " << key << " tidak dimukan!\n";
    }

    void display()
    {
        if (size == 0)
        {
            cout << "Array masih kosong!\n";
            return;
        }

        cout << "Array: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Sorting Algorithm
class ProgramSortingAlgorithm
{
private:
    int arr[MAX];
    int size;

    // funtion untuk swap
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    // function quick short
    int partition(int low, int high)
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void quickSortHelper(int low, int high)
    {
        if (low < high)
        {
            int pi = partition(low, high);
            quickSortHelper(low, pi - 1);
            quickSortHelper(pi + 1, high);
        }
    }

public:
    ProgramSortingAlgorithm()
    {
        size = 0;
    }

    // sorting menu
    void sortingMenu()
    {
        int choice;
        do
        {
            cout << "\n=== Menu Sorting Algorithm ===\n";
            cout << "1. Buat Array Baru\n";
            cout << "2. Bubble Sort\n";
            cout << "3. Selection Sort\n";
            cout << "4. Quick Sort\n";
            cout << "5. Tampilkan Array Original\n";
            cout << "6. Kembali ke menu utama\n";
            cout << "Masukkan pilihan: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                createArray();
                break;
            case 2:
                bubbleSort();
                break;
            case 3:
                selectionSort();
                break;
            case 4:
                quickSort();
                break;
            case 5:
                display();
                break;
            case 6:
                cout << "Kembali ke menu utama\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
            }
        } while (choice != 6);
    }

    // function membuat array baru
    void createArray()
    {
        cout << "Masukan ukuran array: ";
        cin >> size;
        if (size > MAX)
        {
            cout << "Ukuran teralu besar!\n";
            size = 0;
            return;
        }
        cout << "Masukkan " << size << " angka:\n";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }

    // soarting menggunakan bubble sort dengan membandingkan dan menukar array secara berpasangan
    void bubbleSort()
    {
        int temp[MAX];
        memcpy(temp, arr, size * sizeof(int));
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (temp[j] > temp[j + 1])
                {
                    swap(temp[j], temp[j + 1]);
                }
            }
        }

        cout << "Array setelah di sorting menggunakan Bubble Sort: ";
        for (int i = 0; i < size; i++)
        {
            cout << temp[i] << " ";
        }
        cout << endl;
    }

    // function selection sort pengurutan data dengan cara mencari nilai dari yang terkecil sampai yang terbesar dan menukarnya ke paling awal
    void selectionSort()
    {
        if (size == 0)
        {
            cout << "Array kosong!\n";
            return;
        }

        int temp[MAX];
        memcpy(temp, arr, size * sizeof(int));
        for (int i = 0; i < size - 1; i++)
        {
            int min_idx = i;
            for (int j = i + 1; j < size; j++)
            {
                if (temp[j] < temp[min_idx])
                {
                    min_idx = j;
                }
            }
            swap(temp[min_idx], temp[i]);
        }

        cout << "Array setelah di sorting menggunakana selection sort: ";
        for (int i = 0; i < size; i++)
        {
            cout << temp[i] << " ";
        }
        cout << endl;
    }

    // function quick short merupakan pengurutan data dengan membagi kumpula data menjadi 2 bagian berdasarkan nilai yang pivot di pilih.
    void quickSort()
    {
        if (size == 0)
        {
            cout << "Array masih kosong!\n";
            return;
        }

        int temp[MAX];
        memcpy(temp, arr, size * sizeof(int));

        ProgramSortingAlgorithm tempObj;
        tempObj.size = size;
        memcpy(tempObj.arr, temp, size * sizeof(int));

        tempObj.quickSortHelper(0, size - 1);

        cout << "Array setelah di sorting menggunakan quick sort: ";
        for (int i = 0; i < size; i++)
        {
            cout << tempObj.arr[i] << " ";
        }
        cout << endl;
    }

    // Menapilkan Array
    void display()
    {
        cout << "Array: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main
int main()
{
    // Deklasrasi class
    ProgramStack stack;
    ProgramQueue queue;
    ProgramLinkedList linkedlist;
    ProgramGraph graph;
    ProgramTree tree;
    ProgramSearchingAlgorithm searching;
    ProgramSortingAlgorithm sorting;
    int choice;

    // List Menu
    do
    {
        cout << "\n===== Pilih Program Yang Ingin Di Jalankan =====\n";
        cout << "1. Stack\n";
        cout << "2. Queue\n";
        cout << "3. Linked List\n";
        cout << "4. Graph\n";
        cout << "5. Tree\n";
        cout << "6. Searching\n";
        cout << "7. Sorting\n";
        cout << "0. Keluar\n";
        cout << "Masukan Pilihan Anda: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            stack.stackMenu();
            break;
        case 2:
            queue.queueMenu();
            break;
        case 3:
            linkedlist.linkedListMenu();
            break;
        case 4:
            graph.graphMenu();
            break;
        case 5:
            tree.treeMenu();
            break;
        case 6:
            searching.searchingMenu();
            break;
        case 7:
            sorting.sortingMenu();
            break;
        case 0:
            cout << "Keluar dari program...\n";
            break;
        default:
            cout << "Pilihan tidak di temukan silahkan coba lagi!\n";
        }
    } while (choice != 0);
    return 0;
}