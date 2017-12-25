# Detecção de rodas de caminhão

## Descrição do problema

O objetivo desse exercício programa consiste em ler um vídeo que mostra a movimentação de veículos numa praça de pedágio, e a partir dele, gerar um outro vídeo onde os pneus de veículos grandes são detectados e marcados com círculos amarelos. 

Dividindo a resolução do problema em diversos sub-programas, foi possível obter um vídeo que detecta de forma razoável rodas de veículos grandes.

Para ler a descrição completa do problema, acessar o documento [Enunciado.pdf](https://github.com/matheusrmorgado/Truck-Wheels-Detection/blob/master/Enunciado.pdf).

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
  <img src="https://github.com/matheusrmorgado/QRCode/blob/master/images/operation-example.png">
</p>

## Direitos autorais

O trabalho aqui publicado fez uso da biblioteca Cekeikon5 para processamento de imagens e visão computacional.

Mais informações sobre essa biblioteca pode ser encontrado em: http://www.lps.usp.br/~hae/software