#Classe Pessoa: Crie uma classe que modele uma pessoa:
#Atributos: nome, idade, peso e altura
#Métodos: Envelhecer, engordar, emagrecer, crescer. Obs: Por padrão, a cada ano que nossa pessoa envelhece, sendo a idade dela menor que 21 anos, ela deve crescer 0,5 cm.

class Pessoa
    def initialize(nome, idade, peso, altura)
        @nome=nome
        @idade=idade
        @peso=peso
        @altura=altura
    end
    attr_accessor :nome, :idade, :peso, :altura
    def envelhecer
        if @idade < 21 
            crescer(0.5)
        end
        @idade=idade+1
    end
    def engordar
        @peso=peso+1
    end
    def emagrecer
        @peso=peso-1
    end
    def crescer(quant)
        @altura=altura+quant
    end
end

pessoa1=Pessoa.new("Joao",18,90,180)
puts "idade: #{pessoa1.idade} altura: #{pessoa1.altura} peso: #{pessoa1.peso} nome: #{pessoa1.nome}" 
pessoa1.envelhecer
puts "idade: #{pessoa1.idade} altura: #{pessoa1.altura} peso: #{pessoa1.peso} nome: #{pessoa1.nome}" 
pessoa1.envelhecer
puts "idade: #{pessoa1.idade} altura: #{pessoa1.altura} peso: #{pessoa1.peso} nome: #{pessoa1.nome}"
pessoa1.envelhecer
puts "idade: #{pessoa1.idade} altura: #{pessoa1.altura} peso: #{pessoa1.peso} nome: #{pessoa1.nome}" 
pessoa1.envelhecer
puts "idade: #{pessoa1.idade} altura: #{pessoa1.altura} peso: #{pessoa1.peso} nome: #{pessoa1.nome}" 
pessoa1.engordar
puts "idade: #{pessoa1.idade} altura: #{pessoa1.altura} peso: #{pessoa1.peso} nome: #{pessoa1.nome}" 