#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <time.h>

using namespace std;

int main()
{
    //Declaracion de variables
    unsigned int *n, i, j;
    double cput;
    clock_t start, endp;
    ofstream salida;

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

    //Escribir secuencia
    for(j = 0; j <= i; j++)
        cout << n[j] << " ";
    cout << "\n";

    //Reportar el teste
    salida.open("Reporte.html");
    salida << "<!DOCTYPE html>" << endl;
    salida << "<html lang = \"es\">\n" << endl;
    salida << "<head>" << endl;
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
    salida << "\t\tvar myJSON = '{\"n";
    for(j = 0; j < i; j++)
    {
        salida << j + 1 << "\":\"";
        salida << n[j] << "\", \"n";
    }
    salida << i + 1 << "\":\"";
    salida << n[i] << "\"}';" << endl;
    salida << "\t\tvar myObj = JSON.parse(myJSON);" << endl;
    salida << "\t\tdocument.getElementById(\"demo\").innerHTML = myObj.n";
    for(j = 0; j < i; j++)
        salida << j + 1 << " + \" \" + myObj.n";
    salida << i + 1 << ";" << endl;
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
