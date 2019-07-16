package com.example.sensor_app;

import android.app.Activity;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.widget.TextView;

import androidx.constraintlayout.widget.ConstraintLayout;

public class MainActivity extends Activity {
    private SensorManager sensorManager;
    private ConstraintLayout layout;
    private LightSensorHandler lightSensorHandler;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.sensor_layout);
        layout = findViewById(R.id.sensorLayout);
        sensorManager = (SensorManager) getSystemService(SENSOR_SERVICE);
        layout.setKeepScreenOn(true);
        lightSensorHandler = new LightSensorHandler(
                (TextView) findViewById(R.id.timeText),
                (TextView) findViewById(R.id.readingText),
                sensorManager
        );
    }
}
