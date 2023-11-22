# GS-MedConnect-EDGE

# Problema Abordado
O projeto aborda a problematica no contexto da recepção em ambientes médicos, onde o processo de coleta de informações dos pacientes muitas vezes é moroso e propenso a erros. A necessidade de otimizar a eficiência e a precisão nesse fluxo torna-se evidente, uma vez que a agilidade na entrada de dados é crucial para garantir um atendimento médico eficaz. O desafio reside em proporcionar uma solução inovadora que simplifique a coleta de informações, reduzindo o tempo de espera do paciente e melhorando a qualidade do serviço prestado pela recepção.

# Visão Geral da Solução Proposta
A solução proposta neste projeto visa transformar positivamente o processo de recepção em ambientes médicos por meio da implementação de um sistema baseado em cartões RFID simulados. Ao utilizar a tecnologia de identificação por radiofrequência, o paciente pode simplesmente passar seu cartão próximo a um leitor RFID para que suas informações, como nome, CPF e outros detalhes relevantes, sejam instantaneamente exibidas no sistema de recepção. Essa abordagem não apenas agiliza a coleta de dados, reduzindo potencialmente filas e atrasos, mas também minimiza a probabilidade de erros de digitação, proporcionando uma experiência mais eficiente e precisa tanto para a equipe de recepção quanto para os pacientes.

# Instruções Claras Sobre Como Configurar e Executar a Aplicação
 Inicialmente, é necessário configurar o ambiente WiFi do dispositivo, inserindo o SSID e a senha correspondentes. Depois, a conexão MQTT é estabelecida, configurando o servidor, porta, usuário e senha. 
 O hardware do LCD é inicializado, seguido pela definição de pinos para botões, LEDs e trava. Durante a execução, os botões depois de apertados **simulando o RFID** acionam a exibição de informações no LCD, como nome, CPF, telefone e plano de saúde, ao mesmo tempo em que acionam a publicação desses dados no servidor Tago.io. 
 Tendo como informações detalhadas, incluindo a configuração de dashboards na plataforma Tago.io para visualização, proporcionam uma implementação transparente e acessível, garantindo uma experiência fluida para os usuários.

# Link para o Wokwi: 
 https://wokwi.com/projects/381939873475682305 

# Link para o vídeo no YouTube:
https://youtu.be/42jG-TiF0VA 