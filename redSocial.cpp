#include<iostream>
#include<string>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>

#include<fstream>


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

struct redSocial{
  int size = 0;
  perfil red[TRED];
}redSocial;

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

bool existe(string correo) {
  for (int i = 0; i < redSocial.size; i++) {
    if (redSocial.red[i].correo == correo) {
      return true;
    }
    return false;
  }
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
  visualizarPerfiles(p);
  int id = 999;
  while (id >redSocial.size) {
    cout << "Cual persona quieres agregar a tus amigos? (digita su ID para agregarlo)" << '\n';
    cin >> id;
    if(id > redSocial.size){cout << "Ingresa un ID existente" << '\n';}
  }

  perfil * nAmigo = &redSocial.red[id];

  p.amigos[p.size] = nAmigo;
  nAmigo->amigos[nAmigo->size] = &p;
  nAmigo->size++;
  p.size++;
}

void visualizarAmigos(perfil &p) {
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
}

void eliminarAmigos(perfil &p) {
  int id;
  int idAux;
  visualizarAmigos(p);
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

void comunAmigos(perfil &p, perfil &h) {
  for (int i = 0; i < p.size; i++) {
    for (int j = 0; j < h.size; j++) {
      if (p.amigos[i] == h.amigos[j]) {
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
}

void enviarMensaje(perfil &d, perfil &p) {

  FILE * FileMensaje;
  char correoReceptor[50];
  char correoEmisor[50];
  char nombreEmisor[50];
  string mensaje;

  strcpy(correoReceptor, (p.correo).c_str());
  strcpy(correoEmisor, (p.correo).c_str());
  strcpy(nombreEmisor, (p.nombre).c_str());

  FileMensaje = fopen(correoReceptor,"a+");

  if (FileMensaje == NULL) {
    cout << "No se puede crear el archivo" << '\n';
  }
  fprintf(FileMensaje, "Has recibido nuevo mensaje de ");
  fprintf(FileMensaje, "%s(%s)\n",nombreEmisor,correoEmisor );
  fprintf(FileMensaje, "\n");
  getline(cin,mensaje);
  fprintf(FileMensaje, "%s\n",mensaje.c_str() );
  fprintf(FileMensaje, "-------------------------------------------\n");
  fclose(FileMensaje);

}

void leerMensaje(perfil &p) {
  FILE * FileMensaje;
  char correo[50];

  strcpy(correo, (p.correo).c_str());
  long lSize;
  char * texto;
  size_t result;

  FileMensaje = fopen ( correo , "rb" );
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

  std::cout << texto << '\n';

  // terminate
  fclose (FileMensaje);
  free (texto);
}

int main(int argc, char const *argv[]) {
  crearPerfil("alg@jdjdjf,com","1234567","Adolfo Hitler", "Indefinido","12","Munich");
  crearPerfil("1213443.com","varias","Carl Sagan", "Masculino","49","California");
  crearPerfil("maruja.com","otro","Pepito perez", "Masculino","19","Pereira");
  crearPerfil("Pelado@htomail.com","contrasena","Vago libertario", "Masculino","20","Dosquebradas");
  crearPerfil("jdii@htomail.com","contrasena","Mamerto libertario", "Masculino","20","Somalia");
  crearPerfil("ertyo@htomail.com","contrasena","Nerdo de clase", "Masculino","20","Somalia");
  //visualizarPerfiles();
  /*eliminarPerfiles(0);
  visualizarPerfiles();
  cout<<"1111111111111111111111111111111"<<endl;*/
  //modificarPerfiles(0);
  //visualizarPerfiles();
  perfil* persona1 = &redSocial.red[0];
  perfil* persona2 = &redSocial.red[1];

  enviarMensaje(*persona1,*persona2);
  leerMensaje(*persona2);

  /*cout<<"Agregando amigos de persona 1 : "<<persona1->nombre<<endl;
  agregarAmigos(*persona1);
  agregarAmigos(*persona1);
  agregarAmigos(*persona1);
  cout<<"Agregando amigos de persona 2 : "<<persona2->nombre<<endl;
  agregarAmigos(*persona2);
  agregarAmigos(*persona2);
  cout<<"Visualizando amigos en comun de persona 1 y persona 2"<<endl;
  comunAmigos(*persona1,*persona2);*/

  /*cout<<"Visualizando amigos de la persona 1"<<endl;
  visualizarAmigos(*persona1);
  cout<<"Visualizando amigos de la persona 2"<<endl;
  visualizarAmigos(*persona2);
  cout<<"Eliminar amigos ahora"<<endl;
  eliminarAmigos(*persona1);
  cout<<"Visualizando amigos de la persona 1 despues de eliminar"<<endl;
  visualizarAmigos(*persona1);
  cout<<"Visualizando amigos de la persona 2 despues de eliminar"<<endl;
  visualizarAmigos(*persona2);*/
  return 0;
}
