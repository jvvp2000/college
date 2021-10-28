=begin
  %--------------------------------------------------%
  % UENF-CCT-LCMAT-CC                                %
  % Disciplina:   Programacao Orientada a Objetos    %
  % Prof.:        Annabell                           %
  % Data:         06/out/2021                        %
  % Aluno:        João Vítor Fernandes Dias          %
  % Aluno:        João Víttor Vieira Pinto           %
  % Arquivo:      atividade3_RAI.rb                  %
  %--------------------------------------------------%
=end

#PARTE 1
  =begin COMPLETA
    Um órgão de levantamento meteorológico possui equipamentos para medir a pluviosidade (pluviômetros),
    onde cada unidade é representada por um objeto da classe "Pluviometro" que contém os seguintes métodos:
      construtor que recebe como parâmetro o tipo de equipamento;
      getTipo que retorna o tipo do pluviômetro;
      getPeso que retorna o peso do pluviômetro em quilos.

    Este peso é calculado automaticamente pela classe a partir do tipo;
    getCapacidade que retorna à capacidade do pluviômetro em mililitros.
    Esta capacidade é calculada automaticamente pela classe a partir do tipo.
    Os pluviômetros são carregados por caminhões que são representados genericamente por objetos da classe Caminhao
    (esta classe não deve ser implementada nesta questão).

    A classe define os seguintes métodos:
      Construtor que recebe como parâmetro a quantidade de equipamentos que o caminhão irá carregar e
      inserePluviometro que recebe como parâmetro um objeto da classe Pluviometro e
        o coloca dentro do caminhão se a capacidade do mesmo permitir.
          
    Cada objeto da classe representa um caminhão.
    Esta classe não possui nenhum atributo e seus métodos não possuem implementação,
    pois serão implementados nas subclasses.
    Escreva duas classes herdeiras da classe Caminhao que representam dois tipos deste veículo com capacidades diferentes:
    Caminhão Alfa que consegue carregar no máximo 5 toneladas de pluviômetros, independentemente da quantidade e tipo.
    Caminhão Beta que consegue carregar qualquer quantidade e peso de pluviômetros,
    no entanto, não é capaz de carregar mais do que um pluviômetro de cada tipo.
    Ambas as classes devem sobrescrever o método inserePluviometro.
  =end

  =begin PLUVIOMETROS
    Um órgão de levantamento meteorológico possui equipamentos para medir a pluviosidade (pluviômetros), onde
    cada unidade é representada por um objeto da classe "Pluviometro"
    que contém os seguintes métodos:
      construtor que recebe como parâmetro o tipo de equipamento;

      getTipo que retorna o tipo do pluviômetro;

      getPeso que retorna o peso do pluviômetro em quilos.
        Este peso é calculado automaticamente pela classe a partir do tipo;

      getCapacidade que retorna à capacidade do pluviômetro em mililitros.
        Esta capacidade é calculada automaticamente pela classe a partir do tipo.
  =end
  class Pluviometro  #OK #DISCLAIMER: Má formulação da questão
    # Um órgão de levantamento meteorológico possui equipamentos para medir a pluviosidade (pluviômetros),
    # onde cada unidade é representada por um objeto da classe "Pluviometro"
    #que contém os seguintes métodos:
    attr_accessor: tipo
    def initializer (tipoDeEquipamento) #OK
      # construtor que recebe como parâmetro o tipo de equipamento;
      @tipo=tipoDeEquipamento
    end

    def getTipo ()  #OK
      #getTipo que retorna o tipo do pluviômetro;
      return @tipo
    end

    def getPeso ()  #OK #DUVIDA: DE QUE FORMA O TIPO INFLUENCIA NO PESO? NÃO É EXPLICADO
      #getPeso que retorna o peso do pluviômetro em quilos.
      # Este peso é calculado automaticamente pela classe a partir do tipo;
      
      =begin  #disclaimer
        #Segundo o que é pedido, o que precisamos fazer é isto:
        return pesoCalculadoAutomaticamentePelaClasseAPartirDoTipo()
        #Porém, não explica de que forma esse cálculo ocorre, então optamos por fazer da forma abaixo
      =end
      if    (getTipo ()== 1)
            return        1
      elsif (getTipo ()== 2)
            return        2
      elsif (getTipo ()== 3)
            return        3
      elsif (getTipo ()== 4)
            return        4
      else
            return        5
      end
    end

    def getCapacidade ()  #OK #DUVIDA: DE QUE FORMA O TIPO INFLUENCIA NA CAPACIDADE?
      #getCapacidade que retorna à capacidade do pluviômetro em mililitros.
      #Esta capacidade é calculada automaticamente pela classe a partir do tipo.
      
      =begin  #disclaimer
        #Segundo o que é pedido, o que precisamos fazer é isto:
        return capacidadeCalculadaAutomaticamentePelaClasseAPartirDoTipo()
        #Porém, não explica de que forma esse cálculo ocorre, então optamos por fazer da forma abaixo
      =end
      if    (getTipo ()== 1)
            return        1
      elsif (getTipo ()== 2)
            return        2
      elsif (getTipo ()== 3)
            return        3
      elsif (getTipo ()== 4)
            return        4
      else
            return        5
      end
    end
  end

  =begin CAMINHOES
    Os pluviômetros são carregados por caminhões que são representados genericamente por objetos da classe Caminhao
      (esta classe não deve ser implementada nesta questão).
    A classe define os seguintes métodos:
      Construtor que recebe como parâmetro a quantidade de equipamentos que o caminhão irá carregar e
      
    inserePluviometro que recebe como parâmetro um objeto da classe Pluviometro e
      o coloca dentro do caminhão se a capacidade do mesmo permitir.

    Cada objeto da classe representa um caminhão.
    Esta classe não possui nenhum atributo e
    seus métodos não possuem implementação,
    pois serão implementados nas subclasses.
  =end
  class Caminhao  #OK
    #caminhões que são representados genericamente por objetos da classe Caminhao
    # A classe define os seguintes métodos:
    #attr_accessor: capacidadePluviometros
    =begin
      #É pedido que se inicialize a classe com a quantidade de equipamentos, mas isso só se sabe durante a criação da lista
      #pluviometros, então faremos de outra forma:
      def initialize (quantidadeDeEquipamentosQueOCaminhaoIraCarregar)  #OK
        #Construtor que recebe como parâmetro a quantidade de equipamentos que o caminhão irá carregar
        #@capacidadePluviometros = quantidadeDeEquipamentosQueOCaminhaoIraCarregar
      end
    =end

    def initialize ()  #OK
      # Construtor que recebe como parâmetro a quantidade de equipamentos que o caminhão irá carregar
      #@capacidadePluviometros = quantidadeDeEquipamentosQueOCaminhaoIraCarregar
    end

    #attr_accessor: quantidadeAtual
    #attr_accessor: listaPluviometros
    def inserePluviometro (pluviometro) #DUVIDA: Não sei como fazer append em uma lista
      #inserePluviometro que recebe como parâmetro um objeto da classe Pluviometro
      #e o coloca dentro do caminhão se a capacidade do mesmo permitir.
      #if (pluviometro.volume < (@capacidadePluviometros - @quantidadeAtual))  #DUVIDA: COMO CALCULAR O LIMITE DE CAPACIDADE?
        #@quantidadeAtual++                       #aumenta em 1 a quantidade atual de pluviometros
        #listaPluviometros.append(pluviometro)   #DUVIDA: COMO ADICIONA UM OBJETO A UMA LISTA?
      #end
    end
  end
  
  =begin Classes herdeiras de Caminhao
    Escreva duas classes herdeiras da classe Caminhao
    que representam dois tipos deste veículo com capacidades diferentes:
    Ambas as classes devem sobrescrever o método inserePluviometro.
  =end
  class CaminhaoAlfa < Caminhao #OK #DISCLAIMER: Má formulação da questão
    
    #  Caminhão Alfa que consegue carregar no máximo 5 toneladas de pluviômetros,
    # independentemente da quantidade e tipo.
    =begin  #disclaimer
      # Seguindo o que se é pedido, o seguinte método estaria correto:
      attr_accessor: quantidadeEquipamentos
      def initialize (quantidadeDeEquipamentosQueOCaminhaoIraCarregar)  #OK
        # Construtor que recebe como parâmetro a quantidade de equipamentos que o caminhão irá carregar
        @quantidadeEquipamentos = quantidadeDeEquipamentosQueOCaminhaoIraCarregar
      end
      #Porém, não faz sentido dizer a quantidade de equipamentos (pluviometros) vai carregar
      #antes de colocar cada um dos pluviometros e testar.
      #por isso, optamos por fazer o código abaixo
    =end
    
    attr_accessor: capacidadeMaximaKG
    attr_accessor: listaPluviometros
    attr_accessor: pesoatual
    def initialize (listaPluviometrosExterna)  #OK
      @capacidadeMaximaKG = 5000
      @listaPluviometros = listaPluviometrosExterna
      @pesoatual = 0
    end
    
    def inserePluviometro (pluviometro)
      #inserePluviometro que recebe como parâmetro um objeto da classe Pluviometro
      #e o coloca dentro do caminhão se a capacidade do mesmo permitir.
      if (pluviometro.getPeso() <= (@capacidadeMaximaKG - @pesoAtual))
        listaPluviometros.append(pluviometro)
      end
    end
  end
  
  class CaminhaoBeta < Caminhao #OK
    #  Caminhão Beta que consegue carregar qualquer quantidade e peso de pluviômetros,
    
    =begin  #disclaimer
      # Seguindo o que se é pedido, o seguinte método estaria correto:
      attr_accessor: quantidadeEquipamentos
      def initialize (quantidadeDeEquipamentosQueOCaminhaoIraCarregar)  #OK
        # Construtor que recebe como parâmetro a quantidade de equipamentos que o caminhão irá carregar
        @quantidadeEquipamentos = quantidadeDeEquipamentosQueOCaminhaoIraCarregar
      end
      #Porém, não faz sentido dizer a quantidade de equipamentos (pluviometros) vai carregar
      #antes de colocar cada um dos pluviometros e testar.
      #por isso, optamos por fazer o código abaixo
    =end
    
    attr_accessor: listaPluviometros
    attr_accessor: limiteDeTipo
    def initialize ()  #OK
      #  no entanto, não é capaz de carregar mais do que um pluviômetro de cada tipo.
      @listaPluviometros = []
      @limiteDeTipo = 1
    end

    def quantidadeDePluviometrosDoMesmoTipo (tipoDoPluviometroASerInserido) #OK
      pluviometrosIguais = 0
      for (i=0; i<=listaPluviometros.length(); i++)
        if (listaPluviometros[i].getTipo()==tipoDoPluviometroASerInserido)
          pluviometrosIguais++ 
        end
      end
      return pluviometrosIguais
    end

    def inserePluviometro (pluviometro) #OK
      #inserePluviometro que recebe como parâmetro um objeto da classe Pluviometro
      #e o coloca dentro do caminhão se a capacidade do mesmo permitir.
      if (quantidadeDePluviometrosDoMesmoTipo(pluviometro.getTipo())<@limiteDeTipo)
        listaPluviometros.append(pluviometro)   #DUVIDA: COMO ADICIONA UM OBJETO A UMA LISTA?
      end
    end
  end
# FINAL DA PARTE 1
# PARTE 2
  =begin  COMPLETA
    Dada uma classe denominada Controle, definida em um sistema de controle de transporte de pluviômetros,
    que possui dois métodos estáticos:
      leString()  que solicita ao usuário uma String pelo teclado       e a retorna através do método e 
      leInteiro() que solicita ao usuário um valor inteiro pelo teclado e o retorna através do método.
      
    Escreva uma classe herdeira de Controle que acrescente
      um método estático responsável pela seleção do caminhão mais apto a distribuição de pluviômetros.
        O caminhão será aquele capaz de conduzir pluviômetros cuja soma de capacidade seja a maior,
        independentemente do tipo de cada um deles.
          
    O programa irá solicitar uma lista de caminhões.
    Para cada caminhão ele pergunta:
      
      Tipo do caminhão (‘Alfa’ ou ‘Beta’);

      Número de pluviômetros a ser transportados;

      Lista dos pluviômetros a ser transportados no caminhão
        (para cada pluviômetro é digitado apenas seu tipo).

    A lista encerra quando é digitado ‘Fim’ para o Tipo do caminhão.

    Depois de digitada toda a lista o programa imprime na tela os seguintes dados do caminhão mais apto:
      Tipo do caminhão (Alfa ou Beta);
      Lista dos pluviômetros transportados no caminhão.

    Em ambas as questões, devem ser criados os atributos que se fizerem necessários.
  =end

  =begin  Controle  OK
    Dada uma classe denominada Controle, definida em um sistema de controle de transporte de pluviômetros, que
    possui dois métodos estáticos:
      leString() que solicita ao usuário uma string pelo teclado e a retorna através do método e
      leInteiro() que solicita ao usuário um valor inteiro pelo teclado e o retorna através do método.
  =end
  class Controle  OK
    #Dada uma classe denominada Controle, definida em um sistema de controle de transporte de pluviômetros, que
    #possui dois métodos estáticos:

    def leString ()
      # leString() que solicita ao usuário uma string pelo teclado e a retorna através do método e
      #puts("Digite uma String")
      return gets.chomp
    end

    def leInteiro ()
      # leInteiro() que solicita ao usuário um valor inteiro pelo teclado e o retorna através do método.
      #puts("Digite um inteiro")
      return gets.chomp.to_i
    end
  end

  =begin  #truck
    class Truck
      do {                             
        GetListaDePluviometros()
      } while (tipo de caminhão!="Fim")
      
      def GetTipoCaminhao ()
        puts("Digite o tipo do caminhao (Alfa ou Beta) ou 'Fim' para cancelar:")
        tipoCaminhao=gets.chomp
          if tipoCaminhao == "Alfa" || tipoCaminhao == "Beta"
            return tipoCaminhao
          elseif tipoCaminhao == "Fim"
            puts("Po meu parceiro...")
          end   
      end
      def GetQuantidadePluviometros
        puts("Digite a quantidade de pluviometros a ser transportada:")
        quantPluviometros=gets.chomp.to_i
        if quantPluviometros > 0
          return quantPluviometros
        else
          puts("Ai nao da meu gente fina")
        end
      end
      def GetListaPluviometros
        puts("Digite em sequencia os tipos de pluviometros:")
          
      end

      def initialize ()
        @variavelDeVetor = GetListaCaminhao()
      end


    end
  =end

  =begin classeHerdeira
    Escreva uma classe herdeira de Controle que acrescente
    um método estático responsável pela
    seleção do caminhão mais apto a distribuição de pluviômetros.

      O caminhão será aquele capaz de conduzir pluviômetros cuja soma de capacidade seja a maior,
      independente do tipo de cada um deles.
  =end
  class HerdeiraDeControle < Controle   #OK
    # Escreva uma classe herdeira de Controle que acrescente

    def selecionarCaminhaoMaisApto (listaDeCaminhoes) #OK
      # um método estático responsável pela
      # seleção do caminhão mais apto a distribuição de pluviômetros.
      # O caminhão será aquele
      # capaz de conduzir pluviômetros
      # cuja soma de capacidade seja a maior,
      # independente do tipo de cada um deles.
      
      capacidadeTotal=0
      maiorCapacidade=0
      for (i = 0; i<listaDeCaminhoes.length(); i++)                   #percorrendo a lista inteira de caminhoes
        caminhaoAtual = listaDeCaminhoes[i]                           #caminhao na posicao i da lista
        for (j = 0; j<caminhaoAtual.listaPluviometros.length(); j++)  #percorrendo pluviometros do caminhao[i]
          pluviometroAtual = listaPluviometros[j]                     #pluviometro na posicao j da lista
          capacidadeTotal += pluviometroAtual.getCapacidade()         #acumula a capacidade dos pluviometros da lista
        end
        if (capacidadeTotal > maiorCapacidade)                        #se a capacidade acumulada for maior que a maior
          maiorCapacidade  = capacidadeTotal                          #substitui a maior
          caminhaoMaisApto = caminhaoAtual                            #substitui o melhor caminhao
        end
      end
      return caminhaoMaisApto                                         #retorna o caminhao com maior capacidade
    end
  end

  =begin
    O programa irá solicitar uma lista de caminhões.
    Para cada caminhão ele pergunta:
      
      Tipo do caminhão (‘Alfa’ ou ‘Beta’);

      Número de pluviômetros a ser transportados;

      Lista dos pluviômetros a ser transportados no caminhão
        (para cada pluviômetro é digitado apenas seu tipo).

    A lista encerra quando é digitado ‘Fim’ para o Tipo do caminhão.

    Depois de digitada toda a lista o programa imprime na tela os seguintes dados do caminhão mais apto:
      Tipo do caminhão (Alfa ou Beta);
      Lista dos pluviômetros transportados no caminhão.

    Em ambas as questões, devem ser criados os atributos que se fizerem necessários.
  =end
  class Programa

    def GetListaPluviometros (numeroDePluviometros)
      #Lista dos pluviômetros a ser transportados no caminhão
      #(para cada pluviômetro é digitado apenas seu tipo).
      
      ListaDePluviometros=[]
      contador=0
      puts("Digite em sequencia os tipos de pluviometros:")
      do
        break if (contador==numeroDePluviometros)                     #o programa roda até chegar na quantidade dos pluviometros
        do                                                            
          puts("pluviometro N.#{contador}, tipo:")
          tipoDePluviometro = gets.chomp.to_i
          break if ((tipoDePluviometro>0)&&(tipoDePluviometro<6))
        end
        objetoPluviometro = Pluviometro.new(tipoDePluviometro)  
        listaDePluviometros.append(objetoPluviometro)                #alocando os pluviomeros na lista
        contador++
      end
      return ListaDePluviometros
    end

    def GetQuantidadePluviometros ()
      #Número de pluviômetros a ser transportados;
      do
        puts("Digite a quantidade de pluviometros a ser transportada:")
        quantPluviometros=gets.chomp.to_i                                 #Pedindo ao usuario a quantidade de pluviometros e transformando em integral
        break if (quantPluviometros>0)                                    #Parar se a quantidade de pluviometros for maior que 0
      end
      return quantPluviometros
    end

    def GetTipoCaminhao ()
      #O programa irá solicitar uma lista de caminhões.
      #Tipo do caminhão (‘Alfa’ ou ‘Beta’);
      #A lista encerra quando é digitado ‘Fim’ para o Tipo do caminhão.
      
      do
        puts("Digite o tipo do caminhao (Alfa ou Beta) ou 'Fim' para cancelar:")
        tipoCaminhao=gets.chomp
        break if (tipoCaminhao == "Alfa" || tipoCaminhao == "Beta" || tipoCaminhao == "Fim")
      end
      return tipoCaminhao
    end

    def obterCaminhao ()
      # Para cada caminhão ele pergunta:
      #Tipo do caminhão (‘Alfa’ ou ‘Beta’);
      tipo = GetTipoCaminhao ()
      if (tipo=="Fim")
        return tipo
      end
      
      if (tipo=="Alfa")
        objetoCaminhao = CaminhaoAlfa.new()
      else
        objetoCaminhao = CaminhaoBeta.new()
      end

      numeroDePluviometros = GetQuantidadePluviometros ()       #Número de pluviômetros a ser transportados;
      #Lista dos pluviômetros a ser transportados no caminhão
      #(para cada pluviômetro é digitado apenas seu tipo).
      listaPluviometros = GetListaDePluviometros (numeroDePluviometros, objetoCaminhao)
      
    end

    #O programa irá solicitar uma lista de caminhões.
    def solicitarListaDeCaminhoes ()
      listaDeCaminhoes=[]
      do
        caminhao = obterCaminhao ()
        break if (caminhao=="Fim")
        listaDeCaminhoes.append(caminhao)
      end 
      return listaDeCaminhoes
    end    

    def initialize ()
      @variavelDeVetor = GetListaCaminhao()
    end
  end
  
  =begin 
    Depois de digitada toda a lista o programa imprime na tela os seguintes dados do caminhão mais apto:
      Tipo do caminhão (Alfa ou Beta);
      Lista dos pluviômetros transportados no caminhão.
      
    Em ambas as questões, devem ser criados os atributos que se fizerem necessários.
  =end

  class Funcoes
    def printarCaminhao (OBJETOCAMINHAO)
      
    end
    
    def obterMelhorCaminhao (LISTADECAMINHOES)
      
    end
  end

  if __FILE__ == $0
    listaDeCaminhoes = obterListaDeCaminhoes.new()
    func = Funcoes.new()
    func.printarCaminhao(func.obterMelhorCaminhao(listaDeCaminhoes))
  end

# FINAL DA PARTE 2
