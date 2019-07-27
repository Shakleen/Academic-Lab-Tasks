package com.example.spinner_lab;

/**
 * Class used for length unit conversion.
 */
public class LengthConverter extends UnitConverter {
    /**
     * Converts inputted value to an output of specific unit.
     * @param input the inputted value.
     * @param inputUnit the unit of the unit.
     * @param outputUnit the unit of the output.
     * @return output value.
     */
    @Override
    double convert(double input, String inputUnit, String outputUnit) {
        // Conversion between Foot and Inch units
        if (inputUnit.equals("Foot") && outputUnit.equals("Inch"))
            return convertFromFootToInch(input);
        if (inputUnit.equals("Inch") && outputUnit.equals("Foot"))
            return convertFromInchToFoot(input);

        // Conversion between Foot and Meter units
        if (inputUnit.equals("Foot") && outputUnit.equals("Meter"))
            return convertFromFootToMeter(input);
        if (inputUnit.equals("Meter") && outputUnit.equals("Foot"))
            return convertFromMeterToFoot(input);

        // Conversion between Meter and Inch units
        if (inputUnit.equals("Meter") && outputUnit.equals("Inch"))
            return convertFromMeterToInch(input);
        if (inputUnit.equals("Inch") && outputUnit.equals("Meter"))
            return convertFromInchToMeter(input);

        return input;
    }

    private double convertFromInchToMeter(double input) {
        final double inputInFoot = convertFromInchToFoot(input);
        return convertFromFootToMeter(inputInFoot);
    }

    private double convertFromMeterToInch(double input) {
        final double inputInFoot = convertFromMeterToFoot(input);
        return convertFromFootToInch(inputInFoot);
    }

    private double convertFromMeterToFoot(double input) {
        return input * 3.28084;
    }

    private double convertFromFootToMeter(double input) {
        return input / 3.28084;
    }

    private double convertFromInchToFoot(double input) {
        return input / 12;
    }

    private double convertFromFootToInch(double input) {
        return input * 12;
    }
}
