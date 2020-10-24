# Unit_Converter
Library that performs unit conversions.

Each type of measurement (Length, Mass, Temperature, etc.) is represented by an instantiatable class. Each one of these classes inherits from the abstract Unit class, which is templated to accept only integral or floating point values.

Each measurement utilizes a struct which defines three things:
* Measurement System .- This is usually one of the three common measurement systems
    * Metric
    * Imperial
    * US Customary
* Type .- This is the actual unit (metre, inch, feet, etc.)
* Prefix .- This is used by the metric system, but only in the main unit type (metre, litre, gram, etc.)

## Measurements
1. Length
2. Area
3. Volume
4. Mass
5. Temperature

## TO DO
1. Improve Documentation
2. Add more measurements

