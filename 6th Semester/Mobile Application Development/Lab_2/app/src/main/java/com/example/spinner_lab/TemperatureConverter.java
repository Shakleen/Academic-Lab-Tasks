package com.example.spinner_lab;

/**
 * Class used for temperature unit conversion.
 */
public class TemperatureConverter extends UnitConverter {
    /**
     * Converts inputted value to an output of specific unit.
     * @param input the inputted value.
     * @param inputUnit the unit of the unit.
     * @param outputUnit the unit of the output.
     * @return output value.
     */
    @Override
    double convert(double input, String inputUnit, String outputUnit) {
        // Conversion between Celsius and Kelvin units
        if (inputUnit.equals("Celsius") && outputUnit.equals("Kelvin"))
            return convertFromCelsiusToKelvin(input);
        if (inputUnit.equals("Kelvin") && outputUnit.equals("Celsius"))
            return convertFromKelvinToCelsius(input);

        // Conversion between Celsius and Fahrenheit units
        if (inputUnit.equals("Celsius") && outputUnit.equals("Fahrenheit"))
            return convertFromCelsiusToFahrenheit(input);
        if (inputUnit.equals("Fahrenheit") && outputUnit.equals("Celsius"))
            return convertFromFahrenheitToCelsius(input);

        // Conversion between Fahrenheit and Kelvin units
        if (inputUnit.equals("Fahrenheit") && outputUnit.equals("Kelvin"))
            return convertFromFahrenheitToKelvin(input);
        if (inputUnit.equals("Kelvin") && outputUnit.equals("Fahrenheit"))
            return convertFromKelvinToFahrenheit(input);

        return input;
    }

    private double convertFromKelvinToFahrenheit(double input) {
        final double inputInCelsius = convertFromKelvinToCelsius(input);
        return convertFromCelsiusToFahrenheit(inputInCelsius);
    }

    private double convertFromFahrenheitToKelvin(double input) {
        final double inputInCelsius = convertFromFahrenheitToCelsius(input);
        return convertFromCelsiusToKelvin(inputInCelsius);
    }

    private double convertFromFahrenheitToCelsius(double input) {
        return (32 - input) * (5.0 / 9.0);
    }

    private double convertFromCelsiusToFahrenheit(double input) {
        return (9.0 / 5.0) * input + 32;
    }

    private double convertFromKelvinToCelsius(double input) {
        return input - 273.15;
    }

    private double convertFromCelsiusToKelvin(double input) {
        return input + 273.15;
    }
}
