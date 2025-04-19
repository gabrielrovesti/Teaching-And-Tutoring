package it.unipd.pdp2023.ex1;

import java.util.List;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        AtomicInteger eidx = new AtomicInteger(0);
        List<Element> program = Stream.of(
                "4S", "4T", "3F", "FCCoSp4", "StSq3", "4S+3T", "4T+REP", "3A+1Lo+3S", "3Lo", "3Lz", "FCSSp4", "ChSq1", "CCoSp4")
                .map(s -> new Element(eidx.incrementAndGet(), s))
                .toList();

        var rink = new LinkedBlockingQueue<Element>();

        Athlete hanyuYusuru = new Athlete(rink, program);
        hanyuYusuru.start();

        VideoSystem video = new VideoSystem(rink);
        var votes = new LinkedBlockingQueue<Vote>();

        AtomicInteger jidx = new AtomicInteger(0);
        var judges = List.of(Nation.values()).stream()
                .map(n -> new Judge(n, jidx.incrementAndGet(), video.screen(), votes))
                .toList();
        var techPanel = new TechnicalPanel(video.screen(), votes);

        var score = new ScoreBoard(votes);
        score.start(); 

        var printer = new Printer(score);
        printer.start();

        judges.forEach(Judge::start);
        techPanel.start();
        video.start();

        do {
            Thread.sleep(5000);
        } while (!(hanyuYusuru.done() && judges.stream().allMatch(Judge::done) && techPanel.done() && video.done()));

        printer.stop();
        score.stop();
    }
}