// Esercizio 1: Fattoriale ricorsivo
int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}
/* 
Parametro di ricorsione: n
Misura di complessità: n (coincide con il parametro)
Decrescita: La misura decresce di 1 ad ogni chiamata ricorsiva
Fattore minimo di decrescita: 1
*/

// Esercizio 2: Sequenza di Fibonacci
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
/*
Parametro di ricorsione: n
Misura di complessità: n
Decrescita: La misura decresce di 1 o 2 ad ogni chiamata ricorsiva
Fattore minimo di decrescita: 1
*/

// Esercizio 3: Somma delle cifre
int sumOfDigits(int num) {
    if (num == 0) return 0;
    return (num % 10) + sumOfDigits(num / 10);
}
/*
Parametro di ricorsione: num
Misura di complessità: numero di cifre in num
Decrescita: La misura decresce di 1 ad ogni chiamata (rimuovendo l'ultima cifra)
Fattore minimo di decrescita: 1 cifra
*/

// Esercizio 4: Potenza ricorsiva
int power(int x, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        int half = power(x, n / 2);
        return half * half;
    }
    return x * power(x, n - 1);
}
/*
Parametro di ricorsione: n
Misura di complessità: n
Decrescita: La misura decresce di 1 o si dimezza ad ogni chiamata
Fattore minimo di decrescita: 1 (quando n è dispari), ma in media è n/2
*/

// Esercizio 5: Ricerca binaria ricorsiva
int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid;
    if (arr[mid] > target)
        return binarySearch(arr, low, mid - 1, target);
    return binarySearch(arr, mid + 1, high, target);
}
/*
Parametro di ricorsione: high - low (dimensione dell'intervallo di ricerca)
Misura di complessità: high - low
Decrescita: La misura si dimezza (circa) ad ogni chiamata ricorsiva
Fattore minimo di decrescita: (high - low) / 2
*/