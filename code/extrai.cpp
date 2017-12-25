#include <cekeikon.h>

int main(int argc, char** argv)
{ 
	if (argc!= 2)
	{
		printf("\nExemplo de entrada: extrai video.avi\n");
		erro("Erro: Numero de argumentos invalido");
	}

	Mat_<COR> a;

	VideoCapture vi(argv[1]); 
	int frames = vi.get(CV_CAP_PROP_FRAME_COUNT);

	printf("\nOutput files:\n");

	for (int i = 1; i <= frames; i++)
	{	
		string image = format("quad%d.png", i);
		vi >> a;
		if(i % 150 == 0){
			imp(a, image);
			cout << "\t\t" + image << endl;
		}
	}
}