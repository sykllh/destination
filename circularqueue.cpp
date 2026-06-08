/**
 * @mainpage Documentation Circular Queues
 *
 * @section Introduction
 * Project ini memiliki beberapa operasi antara lain:
 * 1. Insert
 * 2. Delete
 * 3. Display
 *
 * @section Cara Penggunaan
 * Berikut beberapa menu yang bisa digunakan:
 * 1. en queue
 * 2. de queue
 * 3. Display
 * 4. Exit
 *
 * @author Profil
 * - nama : Syakiilah Aaliyah Idmi
 * - nim : 20250140186
 * - kelas : D

 * @brief
 * @version 0.1
 * @date 2026-06-08
 *
 * @copyright aaliyah.idmi.ft25@mail.umy.ac.id (d) 2026
 *
 *
 */

#include  <iostream>
using namespace std;
/** 
* @class Queues
* @brief class ini untuk operasi lengkap queus
*
*
*/

class Queues
{
private:
    int FRONT; ///< variabel private front untuk menyimpan posisi depan antrian
    int REAR; ///< variabel private rear untuk menyimpan posisi belakang antrian
    int max = 5; ///< variabel private max untuk menyimpan ukuran maximum antrian
    int queue_array[5]; ///< variabel private queue_array untuk menyimpan elemen antrian
public:
    /**
    * @brief Construct a new Queues object
    * set default queues null
    * with front = -1 and rear = -1
    */
    Queues()
    {
        FRONT = -1;
        REAR = -1;
    }

    /**
    * @brief method untuk memasukkan data dalam antrian
    * data dimasukkan dalam variabel queue_array
    */

    void insert()
    {
        int num;///< variabel num untuk menyimpan nilai
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        // cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n";
            return;
        } 

        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0;
            REAR = 0;
        }
        else
         {
            // jika rear berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array [REAR] = num;
    }

    /**
    * @brief method untuk menghapus data dalam antrian
    * data dihapuskan dari dalam variable queue_array
    */

    void remove()
    {
        // Cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is: " << queue_array [FRONT] << "\n";

        //cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
        // jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

    /**
    * @brief method untuk menampilkan data dalam antrian
    * data ditampilan yang berada dalam variable queue_array
    */

    void display()
    {

        int FRONT_Position = FRONT; ///< variable front_position untuk menandakan posisi element pertama pada variable front
        int REAR_Position = REAR; ///< variable rear_position untuk menandakan posisi element terakhir pada variable rear

        // cek apakah antrian kosong
        if (FRONT_Position == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are....\n";

        // jika FRONT <= REAR, iterasi dari FRONT hingga REAR
        if (FRONT_Position <= REAR_Position)
        {
            while (FRONT_Position <= REAR_Position)
            {
                cout << queue_array [FRONT_Position] << "  ";
                FRONT_Position++;
            }
            cout << endl;
        }
        else
        {
            // jika FRONT <= REAR, iterasi dari FRONT hingga akhir array
            while (FRONT_Position <= max - 1)
            {
                cout << queue_array [FRONT_Position] << "  ";
                FRONT_Position++;
            }

            FRONT_Position = 0;

            // iterasi dari awal array hingga REAR
            while (FRONT_Position <= REAR_Position)
            {
                cout << queue_array [FRONT_Position] << "  ";
                FRONT_Position++;
            }
            cout << endl;
        }
    }
};

/**
* @brief method utama untuk menjalankan program
*
* @return int
*/

int main()
{
    Queues q;///< objek untuk menggunakan member yang ada pada class queues
    char ch;///< variable ch untuk menyimpan pilihan pada menu yang diberikan

    while (true)
    {
        try
        {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement Delete Operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {
                
                q.insert();
                break;
            }
            case 2:
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << "Invalid option!!!" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "check for the values entered." << endl;
        }
    }
    return 0;
}