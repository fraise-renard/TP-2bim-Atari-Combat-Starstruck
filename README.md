# TP-2bim-Atari-Combat-Starstruck
Atari Combat game reboot named "Starstruck", using SFML and C++. Developed by @nubyoli, @SarahSdSO and me. School assignment made for CEFET Informatics course junior's year second bimester.

## LINGUAGENS E TÉCNICAS DE PROGRAMAÇÃO: INFO-2 (T2)

Jogo recriado: Combat (1977) do Atari 2600
__________________________________________________________________________________________________
Grupo 08: 
- Mel Raposeiras Ricaldoni
- Núbia Torres de Oliveira
- Sarah dos Santos Oliveira
__________________________________________________________________________________________________

INSTRUÇÕES PARA CONFIGURAR O PROJETO DO JOGO E EXECUTÁ-LO

1°) O trabalho foi desenvolvido utilizando o GCC (MingW) na versão 7.3.0, além da biblioteca 
SFML na versão 2.5.1. Dessa forma, para os próximos passos envolvendo as configurações do projeto
na IDE (ambiente de desenvolvimento integrado) serão utilizadas essas versões. 

2°) Primeiramente, será preciso importar o projeto (fornecido em um arquivo zipado) para o Eclipse. 
Em seguida, siga os seguintes passos ao configurar as propriedades deste: 
* Em C/C++ Build siga para a opção Settings. Depois, na opção Includes coloque a SFML com a terminação: \include. Coloque também o diretorio da pasta do projeto. Em libraries adicione as bibliotecas: sfml-graphics, sfml-audio, sfml-window e sfml-system, Além de incluir a SFML com a terminação: \lib.
* Nas propriedades vá em environment e adicione o endereço do MingW baixado na variável correspondente. Para testar se funcionou abra o CMD e digite gcc, se aparecer uma mensagem de Fatal Error significa que a operação foi bem sucedida. No local indicado (com o nome na variavel) forneça o endereço da biblioteca SFML.

3°) Após todas as configurações necessárias estarem corretas basta buildar o código (gerar os executáveis)
Para isso você pode apertar as teclas Ctrl+B do teclado ou selecionar uma das opções para compilar, presentes no Eclipse (a opção com 0101 ou o martelo). 

4°) Por fim, é preciso rodar o código.
Para isso você pode apertar as teclas Ctrl+F11 do teclado (dependendo do teclado: Ctrl+Fn+F11), ou selecionar a opção Run do Eclipse (ao rodar, selecionar a opção Aplication).
