package com.example.spinner_lab;

/**
 * Class used for mass unit conversion.
 */
public class MassConverter extends UnitConverter {
    /**
     * Converts inputted value to an output of specific unit.
     * @param input the inputted value.
     * @param inputUnit the unit of the unit.
     * @param outputUnit the unit of the output.
     * @return output value.
     */
    @Override
    double convert(double input, String inputUnit, String outputUnit) {
        // Conversion between Kilogram and Pound units
        if (inputUnit.equals("Kilogram") && outputUnit.equals("Pound"))
            return convertFromKilogramToPound(input);
        if (inputUnit.equals("Pound") && outputUnit.equals("Kilogram"))
            return convertFromPoundToKilogram(input);

        // Conversion between Kilogram and Ounce units
        if (inputUnit.equals("Kilogram") && outputUnit.equals("Ounce"))
            return convertFromKilogramToOunce(input);
        if (inputUnit.equals("Ounce") && outputUnit.equals("Kilogram"))
            return convertFromOunceToKilogram(input);

        // Conversion between Ounce and Pound units
        if (inputUnit.equals("Ounce") && outputUnit.equals("Pound"))
            return convertFromOunceToPound(input);
        if (inputUnit.equals("Pound") && outputUnit.equals("Ounce"))
            return convertFromPoundToOunce(input);

        return input;
    }

    private double convertFromPoundToOunce(double input) {
        final double inputInKilogram = convertFromPoundToKilogram(input);
        return convertFromKilogramToOunce(inputInKilogram);
    }

    private double convertFromOunceToPound(double input) {
        final double inputInKilogram = convertFromOunceToKilogram(input);
        return convertFromKilogramToPound(inputInKilogram);
    }

    private double convertFromOunceToKilogram(double input) {
        return input / 35.274;
    }

    private double convertFromKilogramToOunce(double input) {
        return input * 35.274;
    }

    private double convertFromPoundToKilogram(double input) {
        return input / 2.20462;
    }

    private double convertFromKilogramToPound(double input) {
        return input * 2.20462;
    }
}
