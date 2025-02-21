let list = []; // Array per gestire la lista della spesa

// Funzione per aggiungere un nuovo elemento alla lista
function addElement() {
  let elementValue = document.getElementById("elementBox").value;
  // Piglia il valore dell'elemento
  if (elementValue !== "") {
    // Aggiunge il nuovo elemento alla lista con stato di completamento false
    list.push({ text: elementValue, completed: false });
    // Aggiorna la visualizzazione della lista
    renderList();
    document.getElementById("elementBox").value = ""; // Svuota
  }
}

// Funzione per rimuovere un elemento dalla lista
function removeElement(index) {
  list.splice(index, 1); // Togli l'elemento dalla lista con indice "index"
  renderList(); // Aggiorna graficamente la lista
}

// Funzione per cambiare lo stato di completamento di un elemento
function toggleCompletion(index) {
  // Inverte lo stato di completamento dell'elemento selezionato
  list[index].completed = !list[index].completed;
  // è come fare "se lista = true allora metti false" e viceversa
  renderList(); // Aggiorna graficamente la lista
}

// Funzione per renderizzare la lista sulla pagina
function renderList() {
  let listDiv = document.getElementById("listDiv");
  listDiv.innerHTML = "";
  // Ciclo attraverso gli elementi della lista
  for (let i = 0; i < list.length; i++) {
    let item = list[i];
    let itemDiv = document.createElement("div");
    // Crea una checkbox per ogni elemento e la imposta con lo stato di completamento corrispondente
    let checkbox = document.createElement("input");
    checkbox.type = "checkbox";

    checkbox.checked = item.completed;
    // Aggiunge un gestore di eventi per cambiare lo stato di completamento quando la checkbox viene selezionata
    checkbox.onchange = function() {
      toggleCompletion(i);
    };
    // Crea un'etichetta per l'elemento della lista
    let label = document.createElement("label");
    label.textContent = item.text;
    // Imposta lo stile del testo in base allo stato di completamento dell'elemento
    label.style.textDecoration = item.completed ? "line-through" : "none";
    // aggiungi la sottolineatura

    // Crea un bottone per rimuovere l'elemento dalla lista
    let removeButton = document.createElement("button");
    removeButton.textContent = "Rimuovi";
    removeButton.onclick = function() {
      removeElement(i);
    };
    // Aggiunge la checkbox, l'etichetta e il bottone alla divisione dell'elemento
    itemDiv.appendChild(checkbox);
    itemDiv.appendChild(label);
    itemDiv.appendChild(removeButton);
    // Aggiunge la divisione dell'elemento alla divisione principale della lista
    listDiv.appendChild(itemDiv);
  }
  // Salva lo stato della lista nel Local Storage
  saveToLocalStorage();
}

// Funzione per salvare lo stato della lista nel Local Storage
// = li salva in locale nel browser
function saveToLocalStorage() {
  localStorage.setItem("todoList", JSON.stringify(list));
}

// Funzione per caricare lo stato della lista dal Local Storage
// = quando apri il browser, riprendi tutti i dati
function loadFromLocalStorage() {
  let storedList = JSON.parse(localStorage.getItem("todoList"));
  if (storedList) {
    list = storedList;
    renderList();
  }
}

// Carica lo stato della lista all'avvio della pagina
loadFromLocalStorage();
