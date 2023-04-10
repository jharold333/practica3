#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

using namespace std;


   // Funciones
   //string escribirCrear();
   string leer(string nombre);
   string leer1(string nombre);
   void editar();
   void aniadir();
   string BuscarCedula();
   void mainMenu();
   void main1Menu();
   void main2Menu();
   //void buscarpersona();
   string agregado(string texto, int n);
   string codificacion1(string, int);
   string codificacion2(string, int);
   string forma1(string , string , int , int);
   string forma2(string , string , int , int);
   string forma3(string , string , int , int);
   void escribir(string nombre, string contenido);
   string string2Bin(string nombre);

   // codificacion y descoidificacion de 2 metodos


int main(){

    string textoCodificado, textoDecodificado, texto1;
    string textouser;
    string inclave;
    string clave1;
    int k = 0;

    texto1 = leer("Sudo.txt");

    cout<<"la clave es "<<texto1<<endl;

    cout << "Ingrese clave del administrador: " <<endl;

    cin>>clave1;

   // getline(cin,texto);
   // getline(cin,clave1);
    cout<<texto1<<endl;
    //cout<<clave1<<endl;

    if(texto1 == clave1){
        cout<<"clave correcta"<<endl;



    mainMenu();

    while (k!=5){
        cout<<"ingresa una opcion: "<<endl;
        cin>>k;
        cin.clear();
        cin.ignore();
    if(k==1){

        aniadir();
        break;
        }

    else if(k==2){
        main1Menu();
        //string BuscarCedula();
        string InformacionUsuario;
        InformacionUsuario=BuscarCedula();
        cout<<InformacionUsuario<<endl;

        break;


    }
    else if (k==3){

        main2Menu();

        string textoOriginal;
        string textoBinario;
        string textoCodificado;
        int metodo,semilla;
        string texto;

        cout<<"Escriba el texto a codificar: "; cin>>texto;
        cout<<"Escriba el numero n: ";cin>>semilla;

        escribir("archivo.txt",texto); //texto que se escribio llevarlo a un documento
        textoOriginal = leer("archivo.txt"); //el documento llevarlo a una variable tipo string
        //cout<<"Texto original: "<<textoOriginal<<endl;

        textoBinario = string2Bin("archivo.txt"); // lo que esta en el documento creado anteriormente volverlo binario
        escribir("binario.txt",textoBinario); //el documento en binario llevarlo a una variable tipo string
        //cout<<"Texto binari: "<<textoBinario<<endl;

        cout<<"Ingrese el metodo para codificar: "; cin>>metodo;
        if(metodo==1) textoCodificado = codificacion1("binario.txt",semilla);
        else if (metodo==2) textoCodificado=codificacion2("binario.txt",semilla);


        cout<<"Texto codificado: "<<textoCodificado<<endl;

        escribir("TextoCodificado.txt",textoCodificado);

        //escribir("codificado1.txt",textoCodificado);
        //cout<<"Texto binari: "<<textoCodificado<<endl;

        return 0;



    }

    else if (k==4){

        cout<<"Fin del Programa "<<endl;
        break;
    }

  }


    }
    else{
        cout << "clave incorrecta"<<endl;
    }

    return 0;



}

void mainMenu(){
    cout<< "          ==================== ELIGE =====================\n"
           "           ||                                           ||\n"
           "           ||	1-> Registrar usuarios                  ||\n"
           "           ||	2-> Buscar un usuario                   ||\n"
           "           ||	3-> encriptar archivo                   ||\n"
           "           ||	4-> Cerrar programa                     ||\n"
           "           ||                                           ||\n"
           "          ===============================================\n"<<endl;
}
void main1Menu(){
    cout<< "          ==================== ELIGE ====================================\n"
           "           ||                                                          ||\n"
           "           ||	1-> Consultar saldo.                                   ||\n"
           "           ||   2-> Retirar dinero especificando la cantidad deseada   ||\n"
           "           ||                                                          ||\n"
           "          ===============================================================\n"<<endl;
}
void main2Menu(){

    cout<< "          ==================== ELIGE ====================================\n"
           "           ||                                                          ||\n"
           "           ||	1->Metodo para decodificar 1 0 2.                      ||\n"
           "           ||                                                          ||\n"
           "          ===============================================================\n"<<endl;
}




string leer(string nombre){
    string contenido;
    string linea;
    ifstream archivo;

    archivo.open(nombre);
    if(!archivo.is_open()){
        cout<<"Error abriendo el archivo"<<endl;
        exit(1);
    }
    while (!archivo.eof()) {
        getline(archivo,linea);
        contenido.append(linea);
    }
    archivo.close();
    return contenido;
}
string leer1(string nombre){
    string contenido;
    string linea;
    ifstream archivo;

    archivo.open(nombre);
    if(!archivo.is_open()){
        cout<<"Error abriendo el archivo"<<endl;
        exit(1);
    }
    while (!archivo.eof()) {
        getline(archivo,linea);
        contenido.append(linea+"\n");
    }
    archivo.close();
    return contenido;
}

void aniadir(){
    ofstream archivo;
    string user;
    archivo.open("usuarios.txt",ios::app); //abrimos el archivo en modo añadir texto en el
    if (archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    cout <<" Cree un usuario. El formato de registro sera el siguiente: cedula, clave, saldo (COP).: "<<endl;
    getline(cin,user);

    archivo<<user<<endl;

    archivo.close();// cerramos el archivo

}

string BuscarCedula(){
    ifstream buscar;
    string cedu, cla, sal, cedula, Linea_Correcta, linea, Importar_cedula="";
    int l=0;
    while (Linea_Correcta=="")
    {
        cout<< "ingresa cedula para buscar en la base de datos:  ";
        cin>>cedula;
        l=cedula.size();
        buscar.open("usuarios.txt", ios::in);


        int i=0;
        while (getline(buscar,linea))
        {
            Importar_cedula="";
            i = 0;
            while (linea[i]!=',')
            {
                Importar_cedula+=linea[i];
                i++;
            }
            if (cedula.size()==Importar_cedula.size() && cedula==Importar_cedula)
            {
                Linea_Correcta=linea;
                break;
            }
        }
        if (Linea_Correcta=="") cout<<endl<<"CEDULA NO REGISTRADA"<<endl<<endl;
        buscar.close();
    }
    return Linea_Correcta;
}

string codificacion1(string nombre, int n){
    string codificado;
    int inicio=0,unos,ceros,anterior; //"Inicio" lo tomamos para recorrer y "anterior" es el bloque anterior
    ifstream archivo;
    archivo.open(nombre);
    getline(archivo, codificado);
    codificado=agregado(codificado,n);
    string modificado=codificado; //trabajar con uno y tomarlo el otro para modificarlo
    //cout<<"------------> "<<codificado<<endl;

    for(unsigned int i=1;i<codificado.length()/n + 1;i++){ //Cuantos bloques hay en el codigo binario
        if (i==1){
            for(int k=0; k<n && i==1;k++){ //primera modificacion obligatoria
                if (codificado[inicio+k]=='0') modificado[inicio+k]='1';
                else if (codificado[inicio+k]=='1') modificado[inicio+k]='0';
            }
        }
        else{ // trabajamos en forma
            unos=0,ceros=0; //inicializamos
            anterior=inicio-n; //es el bloque anterior al que estamos trabajando
            for(int j=0;j<n;j++){ //contador para saber cuantos 1s y 0s hay en cada bloque
                if (codificado[anterior+j]=='1') unos++;
                else if (codificado[anterior+j]=='0') ceros++;
            }
            if (unos==ceros) modificado = forma1(codificado, modificado, inicio, n);
            else if (unos<ceros) modificado = forma2(codificado, modificado, inicio, n);
            else if (unos>ceros) modificado = forma3(codificado, modificado, inicio, n);

        }
            inicio=inicio+n; //pasar al siguiente bloque
    }
    archivo.close();

    return modificado;
}


string forma1(string codificado, string modificado, int inicio, int n){
    for(int j=0;j<n;j++){
        if (codificado[inicio+j]=='0') modificado[inicio+j]='1';
        else if (codificado[inicio+j]=='1') modificado[inicio+j]='0';
    }
    return modificado;
}

string forma2(string codificado, string modificado, int inicio,int n){
    for(int i=0;i<n;i++){
        if ((i+1)%2!=0) modificado[inicio+i]=codificado[inicio+i];
        else{
            if (codificado[inicio+i]=='0') modificado[inicio+i]='1';
            else if (codificado[inicio+i]=='1') modificado[inicio+i]='0';
        }
    }
    return modificado;
}

string forma3(string codificado, string modificado, int inicio,int n){
    for(int i=0;i<n;i++){
        if ((i+1)%3!=0) modificado[inicio+i]=codificado[inicio+i];
        else{
            if (codificado[inicio+i]=='0') modificado[inicio+i]='1';
            else if (codificado[inicio+i]=='1') modificado[inicio+i]='0';
        }
    }
    return modificado;
}

string codificacion2(string nombre, int n){
    string codificado, modificado;
    ifstream archivo;
    int recorre=0;
    archivo.open(nombre);
    getline(archivo, codificado);
    codificado=agregado(codificado,n);
    modificado=codificado;

    for(unsigned int i=1;i<codificado.length()/n + 1;i++){
        for(int j=0;j<n;j++){
            if (j<n-1)modificado[recorre+j+1]=codificado[recorre+j]; //se muevan todos un bloque a la derecha
            else if (j==n-1) modificado[recorre]=codificado[recorre+j]; //el ultimo bit queda en el primero
            }
        recorre=recorre+n;
    }

    return modificado;
}

string agregado(string texto, int n){ //añadirle 0 si la longitud de los binarios no es multiplo de n
    while((texto.length())%n!=0) {
        texto.append("0");
    }

    return texto;
}

void escribir(string nombre, string contenido){
    ofstream archivo;
    archivo.open(nombre);

    if(!archivo.is_open()){
        cout<<"Error abriendo el archivo"<<endl;
        exit(1);
    }

    archivo << contenido;
    archivo.close();
}

string string2Bin(string nombre){
    string textoOrig, letraBin, textoBin;
    textoOrig = leer1(nombre);
    int num;

    for (unsigned int i=0; i<textoOrig.length()-1; i++){
        num = textoOrig[i];
        //cout << textoOrig[i]<<" - "<< num <<endl;
        letraBin = "00000000";
        for (int j=7; j>=0; j--){
            letraBin[j]=num%2 + 48;
            num = num/2;
        }
        //cout<<letraBin <<endl;

        textoBin+=letraBin;
    }
    return textoBin;
}
