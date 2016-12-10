#include<iostream>
#include<string>

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

void visualizarPerfiles() {
  for (int i = 0; i < redSocial.size; i++) {
    cout << "----------------------------------------" << '\n';
    cout << "id : " << i << '\n';
    cout <<"Nombre: "<<redSocial.red[i].nombre<< '\n';
    cout <<"Sexo: "<<redSocial.red[i].sexo<< '\n';
    cout <<"Edad: "<<redSocial.red[i].edad<< '\n';
    cout <<"Ciudad: "<<redSocial.red[i].ciudad<< '\n';
    cout <<"Correo: "<<redSocial.red[i].correo<< '\n';
    cout << "----------------------------------------" << '\n';
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

}

int main(int argc, char const *argv[]) {
  crearPerfil("alg@jdjdjf,com","1234567","Adolfo Hitler", "Indefinido","12","Munich");
  crearPerfil("1213443.com","varias","Carl Sagan", "Masculino","49","California");
  visualizarPerfiles();
  cout<<"0000000000000000000000000000000"<<endl;
  /*eliminarPerfiles(0);
  visualizarPerfiles();
  cout<<"1111111111111111111111111111111"<<endl;*/
  modificarPerfiles(0);
  visualizarPerfiles();

  return 0;
}
