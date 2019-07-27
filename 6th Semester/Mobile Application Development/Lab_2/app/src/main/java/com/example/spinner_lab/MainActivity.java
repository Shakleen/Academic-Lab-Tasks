package com.example.spinner_lab;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;

public class MainActivity extends AppCompatActivity {
    private ConversionController conversionController;
    private EditText inputTextField, outputTextField;
    private Button convertButton, swapButton, clearButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        setupSpinnerLogic();
        setupTextFields();
        setupButtons();
    }

    private void setupButtons() {
        setupConvertButton();
        setupSwapButton();
        setupClearButton();
    }

    private void setupClearButton() {
        clearButton = findViewById(R.id.clearButton);
        clearButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                inputTextField.setText("0.0");
                outputTextField.setText("0.0");
            }
        });
    }

    private void setupSwapButton() {
        swapButton = findViewById(R.id.swapButton);
        swapButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                final Double inputValue = Double.valueOf(inputTextField.getText().toString());
                final Double outputValue = Double.valueOf(outputTextField.getText().toString());
                inputTextField.setText(outputValue.toString());
                outputTextField.setText(inputValue.toString());
            }
        });
    }

    private void setupConvertButton() {
        convertButton = findViewById(R.id.convertButton);
        convertButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                final double inputValue = Double.valueOf(inputTextField.getText().toString());
                final Double outputValue = conversionController.convert(inputValue);
                System.out.println(outputValue);
                outputTextField.setText(outputValue.toString());
            }
        });
    }

    private void setupTextFields() {
        inputTextField = findViewById(R.id.inputTextField);
        outputTextField = findViewById(R.id.outputTextField);
    }

    private void setupSpinnerLogic() {
        final ArrayAdapter<CharSequence> conversionTypes = ArrayAdapter.createFromResource(
                this,
                R.array.conversion_types,
                android.R.layout.simple_spinner_dropdown_item
        );
        final ArrayAdapter<CharSequence> temperatureUnits = ArrayAdapter.createFromResource(
                this,
                R.array.temperature_units,
                android.R.layout.simple_spinner_dropdown_item
        );
        final ArrayAdapter<CharSequence> massUnits = ArrayAdapter.createFromResource(
                this,
                R.array.mass_units,
                android.R.layout.simple_spinner_dropdown_item
        );
        final ArrayAdapter<CharSequence> lengthUnits = ArrayAdapter.createFromResource(
                this,
                R.array.length_units,
                android.R.layout.simple_spinner_dropdown_item
        );
        conversionController = new ConversionController(
                conversionTypes,
                temperatureUnits,
                massUnits,
                lengthUnits,
                (Spinner) findViewById(R.id.inputUnitSinner),
                (Spinner) findViewById(R.id.outputUnitSpinner),
                (Spinner) findViewById(R.id.conversionTypeSpinner)
        );
    }
}
