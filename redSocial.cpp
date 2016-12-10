#include<iostream>
#include<string>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

#define TRED 100

using namespace std;

struct perfil{
  string correo;
  string pass;
  string nombre;
  string sexo;
  string edad;
  string ciudad;
  perfil* amigos[30];
  int size = 0;
};

perfil * principal; //Para inicio de sesion

struct redSocial{
  int size = 0;
  perfil red[TRED];
}redSocial;

void visualizarPerfiles(perfil &p) {
  for (int i = 0; i < redSocial.size; i++) {
    if(p.correo != redSocial.red[i].correo){
      cout << "----------------------------------------" << '\n';
      cout << "ID : " << i << '\n';
      cout <<"Nombre: "<<redSocial.red[i].nombre<< '\n';
      cout <<"Sexo: "<<redSocial.red[i].sexo<< '\n';
      cout <<"Edad: "<<redSocial.red[i].edad<< '\n';
      cout <<"Ciudad: "<<redSocial.red[i].ciudad<< '\n';
      cout <<"Correo: "<<redSocial.red[i].correo<< '\n';
      cout << "----------------------------------------" << '\n';
    }
  }
}

int validacion(perfil &p){
  visualizarPerfiles(p);
  int id = 999;
  while (id >redSocial.size) {
    cout << "¿Con cual persona? (digita su ID)" << '\n';
    cin >> id;
    if(id > redSocial.size){cout << "Ingresa un ID existente" << '\n';}
  }
  return id;
}

void crearPerfil(string correo, string pass, string nombre, string sexo, string edad, string ciudad) {
  perfil p;
  p.correo = correo;
  p.pass = pass;
  p.nombre = nombre;
  p.sexo = sexo;
  p.edad = edad;
  p.ciudad = ciudad;
  redSocial.red[redSocial.size] = p;
  redSocial.size++;
}

void eliminarPerfiles(int id) {
  for (int i = id; i < redSocial.size; i++) {
    redSocial.red[id] = redSocial.red[id+1];
  }
  redSocial.size--;
}

bool actualizar(string aux){
  return (aux != "NO" && aux != "nO" &&aux != "No" && aux != "no");
}

void modificarPerfiles(int id) {
  string aux;
  cout << "Ingresa el nuevo correo (si no desea cambialo digite 'NO' )"<<'\n';
  cin >> aux;
  if(actualizar(aux)){redSocial.red[id].correo = aux;}
  cout << "Ingresa el nuevo password (si no desea cambialo digite 'NO' )"<<'\n';
  cin >> aux;
  if(actualizar(aux)){redSocial.red[id].pass = aux;}
  cout << "Ingresa el nuevo nombre (si no desea cambialo digite 'NO' )"<<'\n';
  cin >> aux;
  if(actualizar(aux)){redSocial.red[id].nombre = aux;}
  cout << "Ingresa el nuevo sexo (si no desea cambialo digite 'NO' )"<<'\n';
  cin >> aux;
  if(actualizar(aux)){redSocial.red[id].sexo = aux;}
  cout << "Ingresa la nueva edad (si no desea cambialo digite 'NO' )"<<'\n';
  cin >> aux;
  if(actualizar(aux)){redSocial.red[id].edad = aux;}
  cout << "Ingresa la nueva ciudad (si no desea cambialo digite 'NO' )"<<'\n';
  cin >> aux;
  if(actualizar(aux)){redSocial.red[id].ciudad = aux;}
}

void agregarAmigos(perfil &p) {
  int id = validacion(p);

  perfil * nAmigo = &redSocial.red[id];

  p.amigos[p.size] = nAmigo;
  nAmigo->amigos[nAmigo->size] = &p;
  nAmigo->size++;
  p.size++;
}

bool visualizarAmigos(perfil &p) {
  if (p.size != 0) {
    for (int i = 0; i < p.size; i++) {
      cout << "----------------------------------------" << '\n';
      cout <<"ID de amigo : "<< i<< '\n';
      cout <<"Nombre: "<<p.amigos[i]->nombre<< '\n';
      cout <<"Sexo: "<<p.amigos[i]->sexo<< '\n';
      cout <<"Edad: "<<p.amigos[i]->edad<< '\n';
      cout <<"Ciudad: "<<p.amigos[i]->ciudad<< '\n';
      cout <<"Correo: "<<p.amigos[i]->correo<< '\n';
      cout << "----------------------------------------" << '\n';
    }
    return true;
  }
  else{
    cout << "No tienes ningun amigo." << '\n';
    return false;
  }
}

void eliminarAmigos(perfil &p) {
  int id;
  int idAux;
  if(visualizarAmigos(p)){
    cout << "digita el ID del amigo que quieres eliminar" << '\n';
    cin >> id;
    idAux = id;
    perfil *rAmigo = p.amigos[id];

    for (int i = 0; i < rAmigo->size; i++) {
      if (&p == rAmigo->amigos[i]) {
        for (int i = idAux; i < rAmigo->size; i++) {
          rAmigo->amigos[i] = rAmigo->amigos[i+1];
        }
        rAmigo->size--;
        break;
      }
    }

    for (int i = id; i < p.size; i++) {
      p.amigos[i] = p.amigos[i+1];
    }
    p.size--;
  }
}

void comunAmigos(perfil &p) {
  int id = validacion(p);
  perfil h = redSocial.red[id];
  int contador = 0;
  for (int i = 0; i < p.size; i++) {
    for (int j = 0; j < h.size; j++) {
      if (p.amigos[i] == h.amigos[j]) {
        contador++;
        cout << "----------------------------------------" << '\n';
        cout <<"Nombre: "<<p.amigos[i]->nombre<< '\n';
        cout <<"Sexo: "<<p.amigos[i]->sexo<< '\n';
        cout <<"Edad: "<<p.amigos[i]->edad<< '\n';
        cout <<"Ciudad: "<<p.amigos[i]->ciudad<< '\n';
        cout <<"Correo: "<<p.amigos[i]->correo<< '\n';
        cout << "----------------------------------------" << '\n';
      }
    }
  }
  cout << "Tienes "<<contador <<" Amigos en comun."<<'\n';
}

void enviarMensaje(perfil &d) {

  int id = validacion(d);

  perfil p = redSocial.red[id];

  FILE * FileMensaje;
  char correoReceptor[50];
  char correoEmisor[50];
  char nombreEmisor[50];
  string mensaje;

  strcpy(correoReceptor, (p.correo).c_str());
  strcpy(correoEmisor, (d.correo).c_str());
  strcpy(nombreEmisor, (d.nombre).c_str());

  FileMensaje = fopen(correoReceptor,"a+");

  if (FileMensaje == NULL) {
    cout << "No se puede crear el archivo" << '\n';
  }
  fprintf(FileMensaje, "--------------Inicio del mensaje-----------------------------\n");
  fprintf(FileMensaje, "Has recibido nuevo mensaje de ");
  fprintf(FileMensaje, "%s(%s)\n",nombreEmisor,correoEmisor );
  fprintf(FileMensaje, "\n");
  cout << "Escribe el mensaje para tu amigo:" << '\n';
  cin.ignore();
  getline(cin,mensaje);
  fprintf(FileMensaje, "%s\n",mensaje.c_str() );
  fprintf(FileMensaje, "--------------Final del mensaje-----------------------------\n");
  fclose(FileMensaje);

}

void leerMensaje(perfil &p) {
  FILE * FileMensaje;
  char correo[50];

  strcpy(correo, (p.correo).c_str());
  std::cout << correo << '\n';
  long lSize;
  char * texto;
  size_t result;

  FileMensaje = fopen ( correo , "r+" );
  if (FileMensaje==NULL) {fputs ("File error",stderr); exit (1);}

  // obtain file size:
  fseek (FileMensaje , 0 , SEEK_END);
  lSize = ftell (FileMensaje);
  rewind (FileMensaje);

  // allocate memory to contain the whole file:
  texto = (char*) malloc (sizeof(char)*lSize);
  if (texto == NULL) {fputs ("Memory error",stderr); exit (2);}

  // copy the file into the texto:
  result = fread (texto,1,lSize,FileMensaje);
  if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

  cout << texto << '\n';

  // terminate
  fclose (FileMensaje);
  free (texto);
}

bool inicio(string correo, string contrasena){
  for (int i = 0; i < redSocial.size; i++) {
    if (!correo.compare(redSocial.red[i].correo) && !contrasena.compare(redSocial.red[i].pass)) {
      principal = &redSocial.red[i];
      return true;
    }
  }
  return false;
}

bool sesion() {
  string correo,contrasena;

    cout << "--Bienvenido a la Red Social de consola--" << '\n';
    cout << "Inicia sesion con tu correo y password:" << '\n';
    cout << "Ingresa tu correo :" << '\n';
    cin >> correo;
    cout << "Ingresa tu password:" << '\n';
    cin >> contrasena;

    if (inicio(correo, contrasena)) {
      return true;
    }
    else{
      sesion();
    }
}

void opciones() {
  bool repeat = true;
  int op;
  while (repeat) {
    cout << "Presione 1 para ver sus amigos" << '\n';
    cout << "Presione 2 para agregar un nuevo amigo" << '\n';
    cout << "Presione 3 para eliminar un amigo" << '\n';
    cout << "Presione 4 para ver los amigos en comun con otro amigo" << '\n';
    cout << "Presione 5 para enviar un mensaje a un amigo" << '\n';
    cout << "Presione 6 para leer mis mensajes recibidos" << '\n';
    cout << "Presione 7 para salir" << '\n';
    cout << "Ingresa la opcion: " << '\n';
    cin >> op;

    switch (op) {
      case 1: visualizarAmigos(*principal); break;
      case 2: agregarAmigos(*principal);break;
      case 3: eliminarAmigos(*principal);break;
      case 4: comunAmigos(*principal);break;
      case 5: enviarMensaje(*principal);break;
      case 6: leerMensaje(*principal);break;
      case 7: repeat = false;break;
      default:cout << "Ingresa una opcion correcta." << '\n';
    }
  }
}

void menu() {
  string op;
  bool repeat = true;
  while(repeat){
    sesion();
    opciones();
    cout << "Quieres iniciar sesion con otra cuenta? (si|no)" << '\n';
    cin >> op;
    if (op == "no") {
      repeat = false;
    }
  }
}

int main(int argc, char const *argv[]) {
  crearPerfil("alg@jdjdjf,com","1234567","Adolfo Hitler", "Indefinido","12","Munich");
  crearPerfil("carl@ciencia.com","123456","Carl Sagan", "Masculino","49","California");
  crearPerfil("maruja.com","otro","Pepito perez", "Masculino","19","Pereira");
  crearPerfil("Pelado@htomail.com","contrasena","Vago libertario", "Masculino","20","Dosquebradas");
  crearPerfil("jdii@htomail.com","contrasena","Mamerto libertario", "Masculino","20","Somalia");
  crearPerfil("ertyo@htomail.com","contrasena","Nerdo de clase", "Masculino","20","Somalia");
  crearPerfil("w.as.g@utp.edu.co","123456","William Salazar", "Masculino","23","Pereira");

  menu();
  return 0;
}
