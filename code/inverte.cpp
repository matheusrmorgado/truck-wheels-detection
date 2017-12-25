#include <cekeikon.h>

int main(int argc, char** argv)
{ 
	if (argc!= 2)
	{
		printf("\n\tExemplo de entrada: inverte imagem.png\n\n\t");
		erro("Erro: Numero de argumentos invalido");
	}
		
	Mat_<GRY> a;
	string file = argv[1];
	le( a, file );
	
	for (int l=0; l<a.rows; l++)
		for (int c=0; c<a.cols; c++)
		{
			if (a(l,c)==0) a(l,c)=255;
			else a(l,c)=0;
		}

	file.erase( file.end()-4, file.end() );
	file += "-inv.png";
	imp( a, file );
	cout << "\n\tImagem " + file + " gerada com sucesso" << endl;
}