#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <bitset>

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
   //decodificar
   string bloque1(string binario, unsigned long long semilla);
   string Invertir(string bloq1);
   int Numero_de_Regla(string bloque1);
   string bloques_consecutivos (string binary, unsigned long long semilla, unsigned long long contador);
   string Aplicar_Regla(string bloque, int regla);
   void Generar_Archivo_Decodificado(string archivo);
   string leer_archivo(string Rut);
   string metodo_decodificacion_2(string bloque, unsigned long long semilla);
   int De_Binario_Decimal (string bloque_N);
   string metodo_codificacion2(string bloque, unsigned long long semilla);





   // codificacion y descoidificacion de 2 metodos


int main(){

    string textoCodificado, textoDecodificado, texto1;
    string textouser;
    string inclave;
    string clave1;
    int k = 0;

    texto1 = leer("Sudo.txt");

    cout<<"la clave es abcd para decodificar ingresa el texto codificado "<<texto1<<endl;
    //decodifica mejor por el 2 y el texto tiene que estar en el .txt

    cout << "Ingrese clave del administrador: " <<endl;

    cin>>clave1;

   // getline(cin,texto);
   // getline(cin,clave1);
    cout<<texto1<<endl;
    //cout<<clave1<<endl;

    if(texto1 == clave1){
        cout<<"clave correcta"<<endl;



    mainMenu();

    while (k!=6){
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
        string Ruta, Nombre, archivo, binary, archivo_primer_metodo, bloque, guardar_bloque, archivo_segundo_metodo;
            unsigned long long semilla, longitud, contador, repos;
            int regla, metodo;
        cout<<endl;
        cout<<endl;
        string respuesta;
        cout<<" _______________________________________________"<<endl;
        cout<<"|    Desea Decodificar el Archivo  [Y] o [N]  | "<<endl;
        cout<<" _______________________________________________"<<endl;
        cout<<endl;
        cout<<"Ingrese su Respuesta: ";
        cin>>respuesta;
        cout<<endl;

        if(respuesta== "Y"){
            cout<<"Ingrese el Metodo de Codificacion Usado [1] o [2]: ";
            cin>>metodo;
            cout<<endl;

            if(metodo==1){
                //    cout<<endl;
                //    cout<<"Ingresar [Direccion] del Archivo: ";
                //    cin>>Ruta;
                //    cout<<endl;
                //    cout<<"Ingresar [Nombre] del Archivo: ";
                //    cin>>Nombre;
                //    Nombre=Nombre+".txt";
                //    Ruta=Ruta+Nombre;
                //archivo_primer_metodo.erase();
                Ruta="Sudo.txt";
                archivo=archivo_primer_metodo;
                cout<<"Ingrese La Semilla de Codificacion: ";
                cin>>semilla;
                cout<<endl;
                repos=semilla;
                longitud=archivo.length();
                if(semilla>=longitud){
                    for(unsigned long long i=0; i<longitud;i++){
                        if(archivo[i]=='1'){
                            archivo_primer_metodo=archivo_primer_metodo+"0";
                        }
                        else{
                            archivo_primer_metodo=archivo_primer_metodo+"1";
                        }
                    }
                }
                else{
                    bloque=bloque1(archivo, semilla);
                    archivo_primer_metodo=Invertir(bloque);
                    regla=Numero_de_Regla(archivo_primer_metodo);
                    contador= semilla;
                    semilla=semilla+repos;
                    binary=archivo;
                    while(1>0){
                        bloque.erase();
                        guardar_bloque.erase();
                        //Reorganizar:
                        bloque=bloques_consecutivos(binary,semilla,contador);
                        guardar_bloque=Aplicar_Regla(bloque, regla);
                        regla=Numero_de_Regla(guardar_bloque);
                        archivo_primer_metodo=archivo_primer_metodo+ guardar_bloque;

                        contador= semilla;
                        semilla=semilla+repos;

                        if(contador==binary.length()){
                            cout<<endl;
                            cout<<archivo_primer_metodo<<endl;
                            cout<<endl;
                            cout<<"Longitud= "<<archivo_primer_metodo.length()<<endl;
                            //generar_archivo_codificado(archivo_primer_metodo);
                            cout<<"  revisar el Sudo.txt  "<<endl;
                            cout<<"  [----Archivo Decodificado----]  "<<endl;
                            Generar_Archivo_Decodificado(archivo_primer_metodo);
                            break;
                        }

                        if(semilla>binary.length()){
                            bloque.erase();
                            guardar_bloque.erase();
                            while(contador!=(binary.length())){
                                bloque=bloque+binary[contador];
                                contador=contador+1;
                            }
                            guardar_bloque=Aplicar_Regla(bloque, bloque.length());
                            archivo_primer_metodo=archivo_primer_metodo+guardar_bloque;
                            cout<<archivo_primer_metodo<<endl;
                            cout<<endl;
                            //cout<<"Longitu ="<<archivo_primer_metodo.length()<<endl;
                            //generar_archivo_codificado(archivo_primer_metodo);
                            cout<<"  [ [----Archivo Decodificado----]]  "<<endl;
                            Generar_Archivo_Decodificado(archivo_primer_metodo);
                            break;
                        }

                    }

                }

            }
            if(metodo==2){
                archivo_segundo_metodo.erase();
                Ruta="Sudo.txt";
                archivo=leer_archivo(Ruta);
                cout<<"Ingrese La Semilla de Codificacion: ";
                cin>>semilla;
                cout<<endl;
                repos=semilla;
                longitud=archivo.length();
                binary=archivo;
                contador=0;
                while(1>0){
                    bloque=bloques_consecutivos(binary,semilla,contador);
                    guardar_bloque=metodo_decodificacion_2(bloque, repos);
                    archivo_segundo_metodo=archivo_segundo_metodo+guardar_bloque;
                    contador= semilla;
                    semilla=semilla+repos;

                    if(contador==binary.length()){
                        cout<<endl;
                        cout<<archivo_segundo_metodo<<endl;
                        cout<<endl;
                        //cout<<"Longitud= "<<archivo_primer_metodo.length()<<endl;
                        //generar_archivo_codificado(archivo_primer_metodo);
                        cout<<"  [----Archivo Decodificado----]  "<<endl;
                        Generar_Archivo_Decodificado(archivo_segundo_metodo);
                        break;
                    }

                    if(semilla>binary.length()){
                        bloque.erase();
                        guardar_bloque.erase();
                        while(contador!=(binary.length())){
                            bloque=bloque+binary[contador];
                            contador=contador+1;
                        }
                        guardar_bloque=metodo_decodificacion_2(bloque, bloque.length());
                        archivo_segundo_metodo=archivo_segundo_metodo+guardar_bloque;
                        cout<<archivo_segundo_metodo<<endl;
                        cout<<endl;
                        //cout<<"Longitu ="<<archivo_primer_metodo.length()<<endl;
                        //generar_archivo_codificado(archivo_primer_metodo);
                        cout<<"  [ [----Archivo Decodificado----]]  "<<endl;
                        Generar_Archivo_Decodificado(archivo_segundo_metodo);
                        break;

            }


        }



     }
   }
 }

    else if (k==5){


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
           "           ||	4-> desencriptar archivo                ||\n"
           "           ||	5-> Cerrar programa                     ||\n"
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


string bloque1(string binario, unsigned long long semilla){
    string bloque1;
    for(unsigned long long i=0; i!=semilla;i++){
        bloque1=bloque1+binario[i];
    }

    return bloque1;
}

string Invertir(string bloq1){
    string invertido;
    for(unsigned long long i=0; i<bloq1.length();i++){
        if(bloq1[i]=='1'){
            invertido=invertido+"0";
        }
        else{
            invertido=invertido+"1";
        }
    }
    return invertido;
}

int Numero_de_Regla(string bloque1){//Cuenta los 1s y los 0s
    unsigned long long contador_0s=0, contador_1s=0;
    int hg=0;
    for(unsigned long long i=0; i!=bloque1.length();i++){
        if (bloque1[i]=='1'){
            contador_1s=contador_1s+1;
        }
        else{
            contador_0s=contador_0s+1;
        }
    }

    if (contador_0s==contador_1s){

        hg=hg+1;
    }

    if (contador_0s>contador_1s){
        hg=hg+2;
    }
    if(contador_1s>contador_0s){
        hg=hg+3;
    }

    return hg;
}

string bloques_consecutivos (string binary, unsigned long long semilla, unsigned long long contador){
    string bloque_siguiente;
    while (contador!=semilla){
        bloque_siguiente=bloque_siguiente+binary[contador];
        contador=contador+1;
    }
    return bloque_siguiente;
}




string Aplicar_Regla(string bloque, int regla){
    unsigned long long contador=0, col=1;
    string retorno;

    if (regla ==1){
        for(unsigned long long i=0; i<bloque.length(); i++){
            if (bloque[i]=='1'){
                retorno=retorno+'0';
            }
            else{
                retorno=retorno+'1';
            }
        }
    }

    if (regla==2){
        while(contador<bloque.length()){
            if(col==2){
                if (bloque[contador]=='1'){
                    retorno=retorno+'0';
                }
                else{
                    retorno=retorno+'1';
                }
                col=1;
            }
            else{
                retorno=retorno+bloque[contador];
                col=col+1;
            }
            contador=contador+1;

        }
    }

    if (regla==3){
        while(contador<bloque.length()){
            if(col==3){
                if (bloque[contador]=='1'){
                    retorno=retorno+'0';
                }
                else{
                    retorno=retorno+'1';
                }
                col=1;
            }
            else{
                retorno=retorno+bloque[contador];
            }
            contador=contador+1;
            col=col+1;
        }
    }

    return retorno;
}

void Generar_Archivo_Decodificado(string archivo){
    unsigned semilla=8, contador=0, repos, longitud;
    int numero;
    string guardar, generador;
    repos=semilla;
    longitud=archivo.length();
    while(1>0){
        guardar=bloques_consecutivos(archivo, semilla, contador);
        numero=De_Binario_Decimal(guardar);
        contador= semilla;
        semilla=semilla+repos;
        char a=numero;
        generador=generador+a;
        if(contador==longitud){
            break;
        }
        if(semilla>longitud){
            break;
        }
    }

    ofstream archivo2;

    archivo2.open("Sudo.txt",ios::out);
    if(archivo2.fail()){
        cout<<"No se puedo Generar el Archivo Codificado"<<endl;
        exit(1);
    }
    archivo2<<generador;

    archivo2.close();




}


string leer_archivo(string Rut){
        char B;
        string archivo;
        fstream text;
        unsigned long long tama;
        text.open(Rut, ios_base::in | ios_base::binary| ios_base:: ate);
        //Si falla al Abrirn el Archivo:
        if (!text.is_open()){
            archivo=" ";
        }
        else{
            tama=text.tellg();
            text.seekg(0);
            for(unsigned long long i=0; i<tama; i++ ){
                text.get(B);
                archivo+=B;
            }
        }
        text.close();

        return archivo;
    }

string metodo_decodificacion_2(string bloque, unsigned long long semilla){
    string retorno;
    unsigned long long contador=1;
    while (contador!=semilla){
        if (contador==(semilla-1)){
            retorno=retorno+bloque[contador];
            contador=contador+1;
        }
        else{
            retorno=retorno+bloque[contador];
            contador=contador+1;
        }
    }
    retorno=retorno+bloque[0];

    return retorno;

}

int De_Binario_Decimal (string bloque_N){
    int resto=0, resultado;
    int digito[8];
    int binario = std::atoi(bloque_N.c_str());
    for(int i=0; i<8; i++){
        digito[i]=binario%10;
        binario /=10;
    }

    for(int i=7; i>=0; i--){
        resultado= (resto*2)+digito[i];
        resto=resultado;
    }

    return resultado;
}
string metodo_codificacion2(string bloque, unsigned long long semilla){
    string retorno;
    unsigned long long contador=0;
    retorno=retorno+bloque[semilla-1];
    while (contador!=semilla){
        if (contador==(semilla-1)){
            contador=contador+1;
        }
        else{
            retorno=retorno+bloque[contador];
            contador=contador+1;
        }


    }
    return retorno;


}
