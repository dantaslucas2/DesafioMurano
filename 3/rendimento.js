function rendimento(idedadeAtual, idadeRetirada, valorDesejado, juros) {
  var tempo = (idadeRetirada - idedadeAtual) * 12;
  juros = juros / 100;

  valorMensal =
    (valorDesejado * juros) / ((1 + juros) * (Math.pow(1 + juros, tempo) - 1));

  return valorMensal;
}

var valor = rendimento(18, 50, 3000000, 1);
console.log(valor);

//Formula Aplicação com Depósitos Regulares
//S = (1 + j) * (((1+j)**n -1)/j) * p
//S = Valor final
//n = meses
//j = juros mensal
//p = deposito mensal
