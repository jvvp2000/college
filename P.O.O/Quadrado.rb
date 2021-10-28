#Classe Quadrado: Crie uma classe que modele um quadrado:
#Atributos: Tamanho do lado
#Métodos: Mudar valor do Lado, Retornar valor do Lado e calcular Área;

class Quadrado
    def initialize(tamanhoLado)
        @tamanhoLado=tamanhoLado
    end
    attr_accessor :tamanhoLado
    def mudarLado(tamanhoLado)
        @tamanhoLado=tamanhoLado
    end
    def retornarLado
        puts @tamanhoLado
    end
    def calcularArea
        @tamanhoLado = @tamanhoLado.chomp.to_i
        puts @tamanhoLado**2
    end
end

quadrado1=Quadrado.new("4")
puts quadrado1.tamanhoLado
quadrado1.mudarLado("6")
quadrado1.retornarLado
quadrado1.calcularArea