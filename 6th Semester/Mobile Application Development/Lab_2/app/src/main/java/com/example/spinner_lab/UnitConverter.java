package com.example.spinner_lab;

import android.widget.ArrayAdapter;

public abstract class UnitConverter {
    abstract double convert(double input, String inputUnit, String outputUnit);
}
