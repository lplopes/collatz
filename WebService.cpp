#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <time.h>
#include "/home/leandro/Desktop/rapidjson-master/include/rapidjson/document.h"
#include "/home/leandro/Desktop/rapidjson-master/include/rapidjson/writer.h"
#include "/home/leandro/Desktop/rapidjson-master/include/rapidjson/stringbuffer.h"

using namespace std;
using namespace rapidjson;

int main()
{
    //Declaracion de variables
    unsigned int *n, i, j;
    float cput;
    string a;
    clock_t start, endp;
    ofstream salida;
    Document d;

    //Alocar memoria
    n = (unsigned int *) malloc(sizeof(unsigned int));

    //Entrada del numero
    cout << "n: ";
    cin >> n[0];

    //Tiempo de procesameinto
    start = clock();

    //Definir la secuencia
    i = 0;
    while(n[i] != 1)
    {
        n = (unsigned int *) realloc(n, (++i + 1) * sizeof(unsigned int));
        if(n[i - 1] % 2)
            n[i] = n[i - 1] * 3 + 1;
        else
            n[i] = n[i - 1] / 2;
    }
    
    //Almacenar el arreglo JSON
    a = "{\"n\":[";
    for(j = 0; j < i; j++)
        a += to_string(n[j]) + ", ";
    a += to_string(n[i]) + "]}";
    salida.open("Arreglo.json");
    salida << a;
    salida.close();
    
    //Entrega del arreglo JSON
    const char* json = a.c_str();
    d.Parse(json);
    Value& s = d["n"];
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);
    cout << buffer.GetString() << endl;

    //Reportar el teste
    salida.open("reporte.html");
    salida << "<!DOCTYPE html>\n<html lang = \"es\">\n\n<head>" << endl;
    salida << "\t<meta charset = \"UTF-8\">" << endl;
    salida << "\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">" << endl;
    salida << "\t<title>Secuencia de Collatz</title>" << endl;
    salida << "\t<link href=\"https://fonts.googleapis.com/css?family=Roboto+Mono&display=swap\" rel=\"stylesheet\">" << endl;
    salida << "\t<style>" << endl;
    salida << "\t\tbody{font-family: 'Roboto Mono', monospace;}" << endl;
    salida << "\t</style>" << endl;
    salida << "</head>\n" << endl;
    salida << "<body>" << endl;
    salida << "\t<h2>Secuencia de Collatz para n = " << n[0] << ".</h2>" << endl;
    salida << "\t<p id=\"demo\"></p>" << endl;
    salida << "\t<script>" << endl;
    salida << "\t\tvar myJSON = '" + a + "';" << endl;
    salida << "\t\tvar myObj = JSON.parse(myJSON);" << endl;
    salida << "\t\tdocument.getElementById(\"demo\").innerHTML = myObj.n[";
    for(j = 0; j < i; j++)
        salida << j << "] + \" \" + myObj.n[";
    salida << i << "];" << endl;
    salida << "\t</script>" << endl;
    salida << "</body>" << endl;
    salida << "</html>" << endl;
    salida.close();

    //Liberar memoria
    free(n);

    //Calcula o tempo de processamento e imprime na tela
    endp = clock();
    cput = ((float)(endp - start)) / CLOCKS_PER_SEC;
    cout << "Tiempo de procesamiento: " << setprecision(3) << cput << " s.\n";

    return 0;
}
