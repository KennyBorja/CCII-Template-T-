#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class DynamicArray {

private:
    T* array;
    int size;

public:
    DynamicArray() {
        array = nullptr;
        size = 0;
    }



    DynamicArray(const T *arr, int size){
        this->size=size;
        array = new T [size];
        for(int i=0;i<size;i++)
            array[i] =arr[i];
    }


     DynamicArray(const DynamicArray& other) {
        size = other.size;
        array = new T[size];
        for (int i = 0; i < size; i++) {
            array[i] = other.array[i];
        }
    }




    ~DynamicArray() {
        delete[] array;
    }

    void pushBack(T element) {
        T* tempArray = new T[size + 1];
        for (int i = 0; i < size; i++) {
            tempArray[i] = array[i];
        }
        tempArray[size] = element;
        delete[] array;
        array = tempArray;
        size++;
    }


    T getElementAt(int index) {
        return array[index];
    }


    int getSize() {
        return size;
    }

    void print() {
        cout<<"[";
        for(int i =0;i<size;i++)
            cout<<array[i]<<" ";
            cout<<"]";
    }

};

class NuevaClase {
private:
    int valor;
public:
    NuevaClase() {
        valor = 0;
    }

    NuevaClase(int valor) {
        this->valor = valor;
    }

    int getValor() const {
        return valor;
    }

    void setValor(int valor) {
        this->valor = valor;
    }
};






int main() {


    DynamicArray<int> numeint;
    numeint.pushBack(100);
    numeint.pushBack(200);
    numeint.pushBack(300);


    char  letras[]="hello";
    string palabras[]={"hola","como","estas"};


    float * numbers=new float[5];
    for (int i=0;i<5;i++){
        numbers[i]=i+10.14;
    }


    DynamicArray<char> arreglletra(letras,5);
    DynamicArray<string> arreglpalabra(palabras,3);
    DynamicArray<float> arregldecimales(numbers,5);




    numeint.print();cout<<endl;
    arreglletra.print();cout<<endl;
    arreglpalabra.print();cout<<endl;
    arregldecimales.print();cout<<endl;



    DynamicArray<NuevaClase> miArray;

    miArray.pushBack(NuevaClase(10));
    miArray.pushBack(NuevaClase(20));
    miArray.pushBack(NuevaClase(30));


    NuevaClase * dato1=new NuevaClase(1000);

    DynamicArray<NuevaClase> tdatos(dato1,1);

    for (int i = 0; i < miArray.getSize(); i++) {
        cout << "Elemento " << i << ": " << miArray.getElementAt(i).getValor() <<endl;
    }


    cout<<tdatos.getElementAt(0).getValor();


    delete dato1;
    delete[] numbers;

    return 0;
}
