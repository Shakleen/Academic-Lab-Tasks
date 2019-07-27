package com.example.spinner_lab;

import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Spinner;

enum ConversionType {
    Temperature,
    Length,
    Mass
}

public class ConversionController {
    private ArrayAdapter<CharSequence> temperatureUnits, massUnits, lengthUnits;
    private Spinner inputSpinner, outputSpinner;
    private UnitConverter temperatureConverter, massConverter, lengthConverter;
    private ConversionType conversionType;

    /**
     * Default constructor.
     *
     * @param conversionTypes   the types of conversions to take place.
     * @param tempUnits         the units of temperature to convert between.
     * @param massUnits         the units of mass to convert between.
     * @param lengthUnits       the units of length to convert between.
     * @param inputSpinner      the input spinner to choose the inputted unit.
     * @param outputSpinner     the output spinner to choose the inputted unit.
     * @param conversionSpinner the main spinner to choose the type of conversion.
     */
    public ConversionController(
            ArrayAdapter<CharSequence> conversionTypes,
            ArrayAdapter<CharSequence> tempUnits,
            ArrayAdapter<CharSequence> massUnits,
            ArrayAdapter<CharSequence> lengthUnits,
            Spinner inputSpinner,
            Spinner outputSpinner,
            Spinner conversionSpinner
    ) {
        this.temperatureUnits = tempUnits;
        this.massUnits = massUnits;
        this.lengthUnits = lengthUnits;
        this.inputSpinner = inputSpinner;
        this.outputSpinner = outputSpinner;

        conversionSpinner.setAdapter(conversionTypes);
        setSpinnersToTemperatureUnits();
        conversionSpinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> adapterView, View view, int type, long l) {
                setSpinnersAndConversionType(type);
            }

            @Override
            public void onNothingSelected(AdapterView<?> adapterView) {}
        });

        temperatureConverter = new TemperatureConverter();
        massConverter = new MassConverter();
        lengthConverter = new LengthConverter();
    }

    private void setSpinnersAndConversionType(int type) {
        switch (type) {
            case 0:
                conversionType = ConversionType.Temperature;
                setSpinnersToTemperatureUnits();
                break;
            case 1:
                conversionType = ConversionType.Length;
                setSpinnersToLengthUnits();
                break;
            case 2:
                conversionType = ConversionType.Mass;
                setSpinnersToMassUnits();
                break;
        }
    }

    private void setSpinnersToTemperatureUnits() {
        inputSpinner.setAdapter(temperatureUnits);
        outputSpinner.setAdapter(temperatureUnits);
    }

    private void setSpinnersToMassUnits() {
        inputSpinner.setAdapter(massUnits);
        outputSpinner.setAdapter(massUnits);
    }

    private void setSpinnersToLengthUnits() {
        inputSpinner.setAdapter(lengthUnits);
        outputSpinner.setAdapter(lengthUnits);
    }

    public double convert(double input){
        final String inputUnit = inputSpinner.getSelectedItem().toString();
        final String outputUnit = outputSpinner.getSelectedItem().toString();

        switch (conversionType) {
            case Temperature:
                return temperatureConverter.convert(input, inputUnit, outputUnit);
            case Mass:
                return massConverter.convert(input, inputUnit, outputUnit);
            case Length:
                return lengthConverter.convert(input, inputUnit, outputUnit);
            default:
                return 0.0;
        }
    }
}
