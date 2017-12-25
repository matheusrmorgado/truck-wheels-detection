# Detecção de rodas de caminhão

## Descrição do problema

O objetivo desse exercício programa consiste em ler um vídeo que mostra a movimentação de veículos numa praça de pedágio, e a partir dele, gerar um outro vídeo onde os pneus de veículos grandes são detectados e marcados com círculos amarelos. 

Para ler a descrição completa do problema, acesse: [Enunciado.pdf](https://github.com/matheusrmorgado/Truck-Wheels-Detection/blob/master/Enunciado.pdf).

## Operação

Para executar o programa de detecção, o usuário deve acessar pelo prompt de comando a pasta em que está localizado o arquivo **wheels.cpp**. Caso ainda não tenha compilado, o usuário deve compilar digitando no prompt de comando o seguinte comando: 

```
compila code/wheels.cpp -cek
```

O resultado da compilação será a geração do arquivo **wheels.exe**. Além disso, o usuário deve localizar o vídeo que se deseja detectar as rodas de caminhão, nesse caso é o [video.avi](https://github.com/matheusrmorgado/Truck-Wheels-Detection/blob/master/examples/video.avi).

Para o completo processamento de imagens, deve-se digitar no prompt o seguinte comando:

```
"code/wheels.exe" "examples/video.avi"
```

Após esse processo, será gerado o arquivo [video-detection.avi](https://github.com/matheusrmorgado/Truck-Wheels-Detection/blob/master/examples/video-detection.avi) com a detecção das rodas de caminhão.

<p align="center">
  <img src="https://github.com/matheusrmorgado/Truck-Wheels-Detection/blob/master/examples/operation.png">
</p>

## Técnicas utilizadas para resolução do problema

Nesse programa foi utilizada a biblioteca cekeikon.h para que fosse possível aplicar funções do Cekeikon e do OpenCV. Para fazer download dessa biblioteca é necessário acessar: http://www.lps.usp.br/hae/software/cekeikon5.html.

Para a resolução do problema proposto, foi desenvolvido o programa **wheels.cpp** que receber um vídeo, processa imagens de rodas grandes e gera um novo vídeo mostrando a detecção de rodas. Para explicar melhor como é realizado o processamento de imagens das funções do OpenCV utilizadas nesse programa, foram desenvolvidos alguns subprogramas para estudo.

### Extração de quadros

O programa **extrai.cpp** teve como objetivo ler um vídeo e extrair dele alguns quadros distribuídos ao longo de todo vídeo. O quadro de número 450 foi extraído por esse programa, e por representar bem uma roda, será a figura utilizada para exemplificar processamentos de imagem seguintes.

<p align="center">
  <img src="https://github.com/matheusrmorgado/Truck-Wheels-Detection/blob/master/examples/quad450.png">
</p>

### Detecção de arestas

Após a detecção de quadros, foi implementado o primeiro processamento de imagem. Por meio do algoritmo de Canny, o programa canny.cpp recebe o quadro *quad450.png* do vídeo e detecta as suas arestas gerando o arquivo *quad450-canny.png*.

<p align="center">
  <img src="https://github.com/matheusrmorgado/Truck-Wheels-Detection/blob/master/examples/quad450-canny.png">
</p>

### Detecção de círculos

Após a detecção de arestas, foi implementado um programa que recebe a imagem *quad450-canny-inv.png* em que as arestas já tenham sido detectadas e detecta círculos por meio da transformada de Hough gerando o arquivo *quad450-canny-inv-h110.png*.

<p align="center">
  <img src="https://github.com/matheusrmorgado/Truck-Wheels-Detection/blob/master/examples/quad450-canny-inv-h110.png">
</p>

Para o funcionamento dessa detecção de círculos, foi necessário utilizar primeiramente um programa que inverte preto para branco, pois a função que realiza a tranformada de Hough exige como parâmetro de entrada uma imagem com fundo branco, nesse caso foi gerado o arquivo *quad450-canny-inv.png*.

<p align="center">
  <img src="https://github.com/matheusrmorgado/Truck-Wheels-Detection/blob/master/examples/quad450-canny-inv.png">
</p>

### Cálculo de gradiente

A fim de acelerar a detecção de círculos em imagens, foi implementado o cálculo do gradiente. Por meio da direção e magnitude do gradiente de uma imagem é possível calcular a transformada de Hough de forma mais eficiente.

Para isso, foi desenvolvido um programa que recebe o quadro *quad450.png* e calcula o gradiente. Como a imagem de entrada é colorida, para otimizar o cálculo do gradiente converteu-se a imagem colorida em três imagens em níveis de cinza, calculou-se o gradiente de cada componente de cor e escolheu-se para cada pixel, o gradiente de maior magnitude. O resultado otimizado foi o arquivo *quad450-grad-otimizado.png*.

<p align="center">
  <img src="https://github.com/matheusrmorgado/Truck-Wheels-Detection/blob/master/examples/quad450-grad-otimizado.png">
</p>

### Processamento de vídeo

Após o estudo das diversas funções utilizadas pelo OpenCV, foi desenvolvido o programa **wheels.cpp** que utiliza diretamente a função *HoughCircles()* que otimiza a transformada de Hough para detecção de círculos. O resultado final foi o vídeo com a detecção de rodas de caminhão.

<p align="center">
  <img src="https://github.com/matheusrmorgado/Truck-Wheels-Detection/blob/master/examples/quad450-detection.png">
</p>

## Referências

* Hough Circle Transform: http://docs.opencv.org/2.4/doc/tutorials/imgproc/imgtrans/hough_circle/hough_circle.html

* Feature detection: http://docs.opencv.org/2.4/modules/imgproc/doc/feature_detection.html

* Reading and Writing Images and Video: http://docs.opencv.org/2.4/modules/highgui/doc/reading_and_writing_images_and_video.html

* OpenCV Documentation: https://github.com/opencv/opencv

* Detecção de cantos e arestas: http://www.lps.usp.br/hae/apostila/corner.pdf

* Transformada de Hough: http://www.lps.usp.br/hae/apostila/hough.pdf

## Direitos autorais

O trabalho aqui publicado fez uso da biblioteca Cekeikon5 para processamento de imagens e visão computacional.

Mais informações sobre essa biblioteca pode ser encontrado em: http://www.lps.usp.br/~hae/software