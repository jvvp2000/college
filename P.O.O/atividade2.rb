  Dada uma classe denominada Controle, definida em um sistema de controle de transporte de pluviômetros,
    que possui dois métodos estáticos: leString() que solicita ao usuário uma string pelo teclado e a retorna
    através do método e leInteiro() que solicita ao usuário um valor inteiro pelo teclado e o retorna através do método.
  Escreva uma classe herdeira de Controle que acrescente um método estático responsável pela seleção do
    caminhão mais apto a distribuição de pluviômetros. O caminhão será aquele capaz de conduzir pluviômetros
    cuja soma de capacidade seja a maior, independente do tipo de cada um deles.
  O programa irá solicitar uma lista de caminhões. Para cada caminhão ele pergunta:
    Tipo do caminhão (‘Alfa’ ou ‘Beta’);
    Número de pluviômetros a ser transportados;
    Lista dos pluviômetros a ser transportados no caminhão (para cada pluviômetro é digitado apenas seu tipo).

  A lista encerra quando é digitado ‘Fim’ para o Tipo do caminhão.
  Depois de digitada toda a lista o programa imprime na tela os seguintes dados do caminhão mais apto:
    Tipo do caminhão (Alfa ou Beta);
    Lista dos pluviômetros transportados no caminhão.
    
  Em ambas as questões, devem ser criados os atributos que se fizerem necessários.



class controle(){
  def initialize(leInt,leString)
    @leInt=leInt
    @leString
  String leString()}
  
  GetListaCaminhao (){
  GetTipoDeCaminhao()
  GetNumeroDePluviometros()
  Do{
  GetListaDePluviometros()} while(tipo de caminhão!="Fim")
  }
  PrintaInfoCaminhaoMaisApto(){
  PrintTipo()
  printlista()
  }
  Class xxx herdaDeControle(){
  OnStart() {
  GetListaCaminhao()
  }
  DescobrirCaminhaoMaisApto()
  
  PrintaInfoCaminhaoMaisApto()
  }