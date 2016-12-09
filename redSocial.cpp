#include<iostream>
#include<string>

#define TRED 100

using namespace std;

struct perfil{
  string correo = "algo";
  string pass = "algo";
  string nombre = "algo";
  string sexo = "algo";
  string edad = "algo";
  string ciudad = "algo";
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
    cout << redSocial.red[i].nombre<< '\n';
    cout << redSocial.red[i].sexo<< '\n';
    cout << redSocial.red[i].edad<< '\n';
    cout << redSocial.red[i].ciudad<< '\n';
    cout << redSocial.red[i].correo<< '\n';
    cout << "----------------------------------------" << '\n';
  }
}


void agregarAmigos(perfil &p) {

}

int main(int argc, char const *argv[]) {
  crearPerfil("alg@jdjdjf,com","1234567","Adolfo Hitler", "Indefinido","12","Munich");
  visualizarPerfiles();
  return 0;
}
