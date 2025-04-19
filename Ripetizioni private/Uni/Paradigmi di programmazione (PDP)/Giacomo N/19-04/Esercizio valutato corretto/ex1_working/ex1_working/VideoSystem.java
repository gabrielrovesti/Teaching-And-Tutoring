package it.unipd.pdp2023.ex1;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

/**
 * The video system will relay each element to all attached screens.
 *
 * <p>It will stop when it sees the last element.
 */
public class VideoSystem {

  private List<BlockingQueue<Element>> screens = new ArrayList<>();
  private Thread record;

  /**
   * A new video system for this rink
   *
   * @param rink Rink to observe
   */
  public VideoSystem(BlockingQueue<Element> rink) {
    record =
        new Thread(
            () -> {
              String lastElement = "";

              try {
                do {
                  Element e = rink.take();
                  lastElement = e.element();
                  for (BlockingQueue<Element> screen : screens) {
                    screen.put(e);
                  }
                } while (!Element.END.equals(lastElement));
              } catch (InterruptedException e) {
                e.printStackTrace();
              }
            });
  }

  /**
   * Attach a new screen to the system.
   *
   * <p>Do not call after start();
   *
   * @return A new screen that will receive the recorded elements.
   */
  public BlockingQueue<Element> screen() {
    var res = new LinkedBlockingQueue<Element>();
    screens.add(res);
    return res;
  }

  /** Start recording */
  public void start() {
    record.start();
  }

  /** Call to check if the exercise is over */
  boolean done() {
    return !record.isAlive();
  }
}
