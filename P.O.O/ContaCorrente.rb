# Classe Conta Corrente: Crie uma classe para implementar uma conta corrente. A classe deve possuir os seguintes atributos: número da conta, nome do correntista e saldo. Os métodos são os seguintes: alterarNome, depósito e saque; No construtor, saldo é opcional, com valor default zero e os demais atributos são obrigatórios.

class Conta
    def initialize(numConta,nome)
        @numConta=numConta
        @nome=nome
        @saldo=0
    end
    attr_reader :saldo, :numConta
    attr_accessor :nome
    def alterarNome(nome)
        @nome=nome
        puts @nome
    end
    def deposito(valor)
        @saldo+=valor
        puts @saldo
    end
    def saque(valor)
        @saldo-=valor
        puts @saldo
    end
end

conta1=Conta.new("151518","JoaoPinto")
conta1.deposito(3000)
conta1.saque(1500)
conta1.saque(500)
conta1.saque(1000)
puts conta1.nome
conta1.alterarNome("JoaoVieira")