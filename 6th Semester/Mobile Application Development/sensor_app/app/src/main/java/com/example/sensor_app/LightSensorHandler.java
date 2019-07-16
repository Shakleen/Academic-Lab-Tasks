package com.example.sensor_app;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.widget.TextView;

import java.sql.Timestamp;
import java.text.SimpleDateFormat;
import java.util.Date;

public class LightSensorHandler {
    private final SensorManager sensorManager;
    private final TextView timeText, readingText;
    private final SimpleDateFormat timeFormat = new SimpleDateFormat("MM/dd/yyyy h:mm:ss.SSS a");
    private Sensor lightSensor;
    private SensorEventListener lightSensorListener;

    public LightSensorHandler(TextView time, TextView reading, SensorManager sensorManager) {
        this.timeText = time;
        this.readingText = reading;
        this.sensorManager = sensorManager;
        this.lightSensorListener = new SensorEventListener() {
            @Override
            public void onSensorChanged(SensorEvent sensorEvent) {
                if (sensorEvent.sensor.getType() == Sensor.TYPE_LIGHT) {
                    final Timestamp stamp = new Timestamp(System.currentTimeMillis());
                    final String formattedTime = timeFormat.format(new Date(stamp.getTime()));
                    final String timeString = String.format("Time: %s", formattedTime);
                    timeText.setText(timeString);

                    String value = "";
                    for(Float reading : sensorEvent.values)
                        value += reading.toString();
                    final String valueString = String.format("Intensity Reading: %s", value);
                    readingText.setText(valueString);

                    DataHandler.writeSensorData(formattedTime, value);
                }
            }

            @Override
            public void onAccuracyChanged(Sensor sensor, int i) {
                // TODO Implement accuracy change
            }
        };
        buildLightSensor(sensorManager);
    }

    private void buildLightSensor(SensorManager sensorManager) {
        lightSensor = sensorManager.getDefaultSensor(Sensor.TYPE_LIGHT);
        if (lightSensor != null)
            sensorManager.registerListener(lightSensorListener, lightSensor, SensorManager.SENSOR_DELAY_NORMAL);
         else
            System.out.println("Light sensor isn't available!");
    }
}
