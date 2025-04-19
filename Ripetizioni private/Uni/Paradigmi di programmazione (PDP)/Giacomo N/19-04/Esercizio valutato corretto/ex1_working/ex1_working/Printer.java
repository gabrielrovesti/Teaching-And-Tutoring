package it.unipd.pdp2023.ex1;

/** Prints the partial score at regular intervals. */
public class Printer implements Runnable {

  private final ScoreBoard score;
  private boolean stop;
  private Thread printing;

  Printer(ScoreBoard score) {
    this.score = score;
    printing = new Thread(this);
  }

@Override
public void run() {
  try {
    while (!stop) {
      if (score.result != null) {
        CurrentResult result = score.result.get();
        System.out.println(format(result.elements(), result.total()));
      }
      Thread.sleep(1000);
    }
  } catch (InterruptedException ex) {
    ex.printStackTrace();
  }
}

  /** Starts the printer */
  void start() {
    this.printing.start();
  }

  /** Asks the printer to stop */
  void stop() {
    this.stop = true;
  }
  
  /***
   * Format the partial score
   * @param elements
   * @param total
   * @return formatted string
   */
  static String format(String elements, float total) {
    return "%s %4.2f".formatted(elements, total);
  }
}
