package com.example.spinner_lab;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.Spinner;

public class MainActivity extends AppCompatActivity {
    private Spinner conversionSpinner, inputSpinner, outputSpinner;
    private ArrayAdapter<CharSequence> temperatureUnits, massUnits, lengthUnits;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final ArrayAdapter<CharSequence> conversionTypes = ArrayAdapter.createFromResource(this, R.array.conversion_types, android.R.layout.simple_spinner_dropdown_item);
        temperatureUnits = ArrayAdapter.createFromResource(this, R.array.temperature_units, android.R.layout.simple_spinner_dropdown_item);
        massUnits = ArrayAdapter.createFromResource(this, R.array.mass_units, android.R.layout.simple_spinner_dropdown_item);
        lengthUnits = ArrayAdapter.createFromResource(this, R.array.length_units, android.R.layout.simple_spinner_dropdown_item);

        conversionSpinner = findViewById(R.id.conversionTypeSpinner);
        inputSpinner = findViewById(R.id.inputUnitSinner);
        outputSpinner = findViewById(R.id.outputUnitSpinner);

        conversionSpinner.setAdapter(conversionTypes);
        inputSpinner.setAdapter(temperatureUnits);
        outputSpinner.setAdapter(temperatureUnits);
    }
}
