#include <iostream>
#include <fstream>

using namespace std;

void Escritura(string m);

int main()
{
  string factura;
  cout<<"\t\t\t\t\tASOCIACIÓN DE VINICULTORES\n"<<endl;
  cout<<"Escriba el nombre de la factura: ";
  getline(cin,factura);
  cout<<"\n";
  Escritura(factura);
}

void Escritura(string m)
{
 char op;
 string TI;
 float P, GA=0;
 int K, TA, i=0;
 bool c;
 ofstream uvarchivo;
 string texto;
 uvarchivo.open(m, ios::out);
 
 if(uvarchivo.fail())
 {
  cout<<"NO SE PUDO ESCRIBIR EN EL ARCHIVO";
  exit(1);
 }

 do{
  cout<<"\nDigite el precio inicial del kilo de uva:"<<endl;
  cin>>P;
  cout<<"\nDigite cuantos kilos se produjeron:"<<endl;
  cin>>K;
  do{
  cout<<"\nDigite el tipo de uva (A/B):"<<endl;
  cin>>TI;
  if(TI!="A" && TI!="B"){
    cout<<"\t\t\t\t\tOPCIÓN NO VÁLIDA"<<endl;
  }

  } while(TI!="A" && TI!="B");

  do{
  cout<<"\nDigite el tamaño de las uvas (1/2):"<<endl;
  cin>>TA;
  if(TA!=1 && TA!=2){
    cout<<"\t\t\t\t\tOPCIÓN NO VÁLIDA"<<endl;
  }

  } while(TA!=1 && TA!=2);

  if(TI=="A")
  {
      if(TA==1)
      {
       GA= ((P + 0.20)*K);
       c=true;
      }
      else 
      {
        GA=((P + 0.30)*K);
        c=true;
      }
  }
  else if (TI=="B")
  {
      if(TA==1)
      {
       GA= ((P - 0.30)*K);
       c=true;
      }

      else 
      {
        GA=((P - 0.50)*K);
        c=true;
      }
  }
  else cout<<"\n\t\t\t\tOPCIÓN NO VÁLIDA!";
  
  if(c==true){
  cout<<"\nLa ganancia obtenida por los "<<K<<" kilos de uvas es: "<<GA<<endl;
  i++;
  }

 uvarchivo<<"\n\t\t\t\tVINICULTOR "<<i<<"\nPRECIO INICIAL: "<<P<<"$\n"<<"KILO PRODUCIDO: "<<K<<"\n"<<"TIPO DE UVA: "<<TI<<"\n"<<"TAMAÑO DE UVA: "<<TA<<"\n"<<"GANANCIA OBTENIDA: "<<GA<<"$\n ";
 cout<<"\n\n\t\t\tDesea ingresar más datos a la factura? (s/n)"<<endl;
 cout<<"OPCIÓN: ";
 cin>>op;

 cin.ignore();
 
}while(op!='N' && op!='n');

uvarchivo.close();

}






