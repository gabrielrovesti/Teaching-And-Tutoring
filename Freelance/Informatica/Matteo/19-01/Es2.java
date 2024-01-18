import java.util.Scanner;

class Punto {
  double x, y, z;
  
  public Punto(double x, double y, double z) {
    this.x = x;
    this.y = y; 
    this.z = z;
  }
  
  public Punto(Punto p) {
    this.x = p.x;
    this.y = p.y;
    this.z = p.z;
  }
  
  public boolean equals(Punto p) {
    return this.x == p.x && this.y == p.y && this.z == p.z; 
  }
  
  public double getX() {
    return x;
  }
  
  public void setX(double x) {
    this.x = x;
  }
  
  public double getY() {
    return y;
  }
  
  public void setY(double y) {
    this.y = y;
  }
  
  public double getZ() {
    return z;
  }
  
  public void setZ(double z) {
    this.z = z;
  }
  
  public double distanzaOrigine() {
    return Math.sqrt(x*x + y*y + z*z);
  }
  
  public double distanzaDaAltroPunto(Punto p) {
    double dx = this.x - p.x;
    double dy = this.y - p.y;
    double dz = this.z - p.z;
    return Math.sqrt(dx*dx + dy*dy + dz*dz);
  }

  public String toString() {
    return "[" + x + "," + y + "," + z + "]";
  }
}

class Test {
  public static void main(String[] args) {
    
    Punto[] punti = new Punto[10];
    
    for(int i=0; i<10; i++) {
      punti[i] = new Punto(Math.random()*200 - 100, 
                           Math.random()*200 - 100,
                           Math.random()*200 - 100);
    }
    
    Scanner input = new Scanner(System.in);
    
    System.out.print("Inserisci il primo numero (1-10): ");
    int n1 = input.nextInt() - 1;
    System.out.print("Inserisci il secondo numero (1-10): ");  
    int n2 = input.nextInt() - 1;
    
    System.out.println("Punto 1: " + punti[n1]);
    System.out.println("Punto 2: " + punti[n2]);
    
    double dist = punti[n1].distanzaDaAltroPunto(punti[n2]);
    System.out.println("Distanza tra i punti: " + dist);
    
    double dist1 = punti[n1].distanzaOrigine();
    double dist2 = punti[n2].distanzaOrigine();
    System.out.println("Distanza punto 1 dall'origine: " + dist1);
    System.out.println("Distanza punto 2 dall'origine: " + dist2);
    
    System.out.print("Inserisci il primo numero (1-10): ");
    n1 = input.nextInt() - 1;
    System.out.print("Inserisci il secondo numero (1-10): ");
    n2 = input.nextInt() - 1;
    
    if(punti[n1].equals(punti[n2])) {
      System.out.println("I punti sono uguali");
    } else {
      System.out.println("I punti sono diversi"); 
    }
  }
}