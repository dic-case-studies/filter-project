
#ifndef tests_hpp
#define tests_hpp

void shouldReturnAverageFilteredValuesWhenInputIsProvided();

void shouldReturnMedianFilteredValuesWhenInputIsProvided();

void shouldThrowErrorWhenFilterSizeIsGreaterThanInputSize();

void shouldThrowErrorWhenFilterSizeIsLessThanOrEqualToZero();

void shouldReturnPaddedAverageFilteredValuesWhenInputIsProvided();

void shouldReturnPaddedMedianFilteredValuesWhenInputIsProvided();

void shouldReturnPaddedMedianFilteredValuesWithNthSelectWhenInputIsProvided();

#endif /* tests_h */
