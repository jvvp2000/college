#Classe Retangulo: Crie uma classe que modele um retangulo:
#Atributos: LadoA, LadoB (ou Comprimento e Largura, ou Base e Altura, a escolher)
#Métodos: Mudar valor dos lados, Retornar valor dos lados, calcular Área e calcular Perímetro;
#Crie um programa que utilize esta classe. Ele deve pedir ao usuário que informe as medidas de um local. Depois, deve-se criar um objeto com as medidas e calcular a quantidade de pisos e de rodapés necessários para o local.

class Retangulo
    def initialize(ladoA, ladoB)
        @ladoA=ladoA
        @ladoB=ladoB
    end
    attr_accessor :ladoA, :ladoB
    def mudarValor(ladoA,ladoB)
        @ladoA=ladoA
        @ladoB=ladoB
    end
    def retornarValor
        puts @ladoA
        puts @ladoB
    end
    def calculoArea(ladoA,ladoB)
        puts ladoA*ladoB
    end
    def calculoPerimetro(ladoA,ladoB)
        puts (ladoA+ladoB)*2
    end
end

puts "Digite em seguida o comprimento e a largura:"
ladoA=gets.chomp.to_i
ladoB=gets.chomp.to_i

retangulo1=Retangulo.new("ladoA","ladoB")
# retangulo.mudarValor(ladoA,ladoB)
retangulo1.calculoArea(ladoA,ladoB)
retangulo1.calculoPerimetro(ladoA,ladoB)
