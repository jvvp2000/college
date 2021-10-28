class MegaAnfitriao
    attr_accessor :nomes
    
    def initialize(nomes="Mundo")
        @nomes=nomes
    end

    def diz_ola
        if@nomes.nil?
            puts "..."
        elsif  @nomes.respond_to? ("each")
            @nomes.each do |nome|
                puts "Ola #{nome}"
            end
        else
            puts "Ola #{@nomes}"
        end
    end
    def diz_adeus
        if @nomes.nil?
            puts "..."
        elsif @nomes.respond_to?("join")
            puts "Adeus #{@nomes.join (", ")}. Voltem em breve"
        else
            puts "Adeus #{@nomes}. Volta em breve."
        end
    end
end

if __FILE__ == $0
    mg = MegaAnfitriao.new
    mg.diz_ola
    mg.diz_adeus
  
    # Alterar o nome para "Diogo"
    mg.nomes = "Diogo"
    mg.diz_ola
    mg.diz_adeus
  
    # Alterar o nome para um vector de nomes
    mg.nomes = ["Alberto", "Beatriz", "Carlos",
      "David", "Ernesto"]
    mg.diz_ola
    mg.diz_adeus
  
    # Alterar para nil
    mg.nomes = nil
    mg.diz_ola
    mg.diz_adeus
  end