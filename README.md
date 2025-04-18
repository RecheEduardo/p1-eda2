<h2>Instruções de Colaboração no GitHub para o Projeto</h2>

<h3>1. Clonando o Repositório</h3>
<p>Primeiro, todos os membros do grupo precisam clonar o repositório em suas máquinas locais. Para isso, use o seguinte comando no terminal:</p>

```bash
git clone https://github.com/RecheEduardo/p1-eda2.git
```

<p>Isso cria uma cópia local do repositório em seu computador.</p>

<h3>2. Criando e Mudando para uma Nova Branch</h3>
Cada membro do grupo deve criar uma branch separada para fazer suas alterações, para evitar conflitos no código principal (geralmente chamado de main ou master). Para criar uma nova branch, use:

```bash
git checkout -b nome-da-branch
```

Substitua `nome-da-branch` por algo descritivo, como `adicionar-funcionalidade-x` ou `corrigir-bug-y`.

<h3>3. Fazendo Alterações no Repositório</h3>

<p>Após mudar para a sua branch, faça as alterações necessárias no código, nos arquivos de documentação ou em qualquer outra parte do repositório. Use o editor de sua preferência.</p>

<h3>4. Verificando as Alterações com git status</h3>

<p>Para verificar quais arquivos foram modificados, use o comando:</p>

```bash
git status
```

<h3>5. Adicionando e Comitando as Alterações</h3>

<p>Após fazer as alterações desejadas, adicione os arquivos modificados ao seu repositório local com o comando:</p>

```bash
git add .
```
<p>Em seguida, faça um commit para registrar as alterações:</p>

```bash
git commit -m "Descrição clara das alterações feitas"
```
<p>Use uma mensagem de commit significativa que explique o que você fez (exemplo: "Corrigir bug no processamento de dados").</p>

<h3>6. Atualizando a Branch Principal (Main)</h3>
Antes de enviar suas alterações para o GitHub, é importante garantir que sua branch está atualizada com a versão mais recente da branch principal (geralmente chamada de main ou master). Para isso, execute:

```bash
git checkout main
git pull origin main
git checkout nome-da-branch
git merge main
```

<p>Isso atualiza sua branch com as últimas alterações feitas por outros membros do grupo.</p>

<h3>7. Enviando suas Alterações para o GitHub</h3>
<p>Agora que sua branch está atualizada, você pode enviar suas alterações para o repositório no GitHub. Use o comando:</p>

```bash
git push origin nome-da-branch
```

<p>Isso envia sua branch e alterações para o GitHub.</p>

<h3>8. Criando um Pull Request (PR)</h3>
<p>Depois de enviar as alterações para o GitHub, você deve criar um Pull Request (PR) para que os outros membros do grupo revisem suas alterações antes de integrá-las à branch principal (main). Para isso, vá até a página do seu repositório no GitHub, clique em "Compare & Pull Request" ao lado da sua branch e depois em "Create Pull Request".</p>

<h3>9. Revisando e Aceitando Pull Requests</h3>
<p>Todos os membros do grupo devem revisar os Pull Requests dos outros. Quando estiverem prontos para ser incorporados, um membro do grupo (geralmente o responsável pela manutenção do projeto) pode aceitar o PR clicando em "Merge Pull Request".</p>

<h3>10. Mantendo o Repositório Local Atualizado</h3>
<p>Após a aprovação de um Pull Request e a atualização da branch main, todos os membros devem manter suas cópias locais atualizadas com o repositório remoto. Para fazer isso, execute os seguintes comandos:</p>

```bash
git checkout main
git pull origin main
```

<p>Isso vai garantir que todos tenham a versão mais recente do código.</p>

<h3>11. Resolvendo Conflitos</h3>
<p>Se houver conflitos de merge (quando duas pessoas editam o mesmo trecho de código), o Git pedirá para você resolver os conflitos manualmente. O Git irá marcar as áreas conflitantes no código, e você precisará editar essas partes do código para decidir qual versão deve ser mantida.</p>
<p>Após resolver os conflitos, adicione os arquivos e faça um novo commit:</p>

```bash
git add .
git commit -m "Resolver conflitos de merge"
```

Então, finalize o processo com um `git push`.

<hr>
<h3>Resumo do Fluxo de Trabalho</h3>
<ol>
  <li>Clone o repositório</li>
  
  <li>Crie uma nova branch: git checkout -b nome-da-branch</li>
  
  <li>Faça as alterações</li>
  <li>Verifique o status: git status</li>
  <li>Adicione os arquivos: git add .</li>
  <li>Comite as alterações: git commit -m "Descrição das alterações"</li>
  <li>Puxe as últimas alterações da branch principal: git pull origin main</li>
  <li>Envie suas alterações para o GitHub: git push origin nome-da-branch</li>
  <li>Crie um Pull Request no GitHub</li>
  <li>Revise e aceite Pull Requests</li>
  <li>Mantenha seu repositório local atualizado: git pull origin main</li>
</ol>

<hr>
<h3>Dicas Finais</h3>
<ul>
  <li><strong>Comunique-se bem:</strong> Sempre escreva mensagens de commit claras e significativas.</li>
  <li><strong>Evite trabalhar diretamente na branch main:</strong> Sempre crie uma branch para cada tarefa.</li>
  <li><strong>Peça revisão:</strong> Antes de mesclar qualquer PR, peça a outros membros do grupo para revisar o código.</li>
</ul>
