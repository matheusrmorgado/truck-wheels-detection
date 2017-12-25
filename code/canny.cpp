#include <cekeikon.h>

int main(int argc, char** argv)
{
	if (argc!= 2)
	{
		printf("\n\tExemplo de entrada: canny imagem.png\n\n\t");
		erro("Erro: Numero de argumentos invalido");
	}
	
    Mat_<COR> image;
    string file = argv[1];
    le( image, file );

    Mat_<GRY> gray;
	Mat_<GRY> edge;
    
    cvtColor( image, gray, CV_BGR2GRAY );
    GaussianBlur( gray, gray, Size(0,0), 2.0, 2.0 );
    Canny( gray, edge, 50, 150, 3 );

    file.erase( file.end()-4, file.end() );
    file += "-canny.png";
    imp( edge, file );
    cout << "\n\tImagem " + file + " gerada com sucesso" << endl;
}