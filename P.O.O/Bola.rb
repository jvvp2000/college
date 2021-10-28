#Classe Bola: Crie uma classe que modele uma bola:
#Atributos: Cor, circunferência, material
#Métodos: trocaCor e mostraCor

class Bola
    def initialize(cor,circunferencia,material)
        @cor=cor
        @circunferencia=circunferencia
        @material=material
    end
    attr_accessor :cor, :circunferencia, :material
    def trocaCor(cor)
        @cor=cor
    end
    def mostraCor
        puts @cor
    end
end

bola1=Bola.new("Amarelo ","52 ","Plastico ")
puts bola1.cor + bola1.circunferencia + bola1.material
bola1.trocaCor("Vermelho")
bola1.mostraCor()
