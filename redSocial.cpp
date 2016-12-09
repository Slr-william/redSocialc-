#include<iostream>

#define TRED 100

using namespace std;

struct perfil{
  char* correo = "algo";
  char* pass = "algo";
  char* nombre = "algo";
  char* sexo = "algo";
  char* edad = "algo";
  char* ciudad = "algo";
  perfil* amigos[30];
};

struct redSocial{
  perfil red[TRED];
};

  void crearPerfil(char* correo, char* pass, char* nombre, char* sexo, char* edad, char* ciudad) {
    perfil p;
    p.correo = correo;
    p.pass = pass;
    p.nombre = nombre;
    p.sexo = sexo;
    p.edad = edad;
    p.ciudad = ciudad;
  }

void agregarAmigos(perfil &p) {

}

int main(int argc, char const *argv[]) {
  return 0;
}
