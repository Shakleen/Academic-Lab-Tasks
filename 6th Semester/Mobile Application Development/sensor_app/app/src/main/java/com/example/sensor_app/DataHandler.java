package com.example.sensor_app;

import com.opencsv.CSVWriter;

import java.io.IOException;
import java.io.Writer;
import java.nio.file.Files;
import java.nio.file.Paths;

public class DataHandler {
    static private final String fileName = "./sensor-data.csv";

    static void writeSensorData(String time, String reading) {
        try (
                Writer writer = Files.newBufferedWriter(Paths.get(fileName));

                CSVWriter csvWriter = new CSVWriter(
                        writer,
                        CSVWriter.DEFAULT_SEPARATOR,
                        CSVWriter.NO_QUOTE_CHARACTER,
                        CSVWriter.DEFAULT_ESCAPE_CHARACTER,
                        CSVWriter.DEFAULT_LINE_END
                );
        ) {
            csvWriter.writeNext(new String[]{time, reading});
        } catch (IOException e) {
            // TODO Implement exception handling.
        }
    }
}
