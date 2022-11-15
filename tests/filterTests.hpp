#ifndef tests_filterTests_hpp
#define tests_filterTests_hpp

void shouldReturnAverageFilteredValuesWhenInputIsProvided();

void shouldReturnMedianFilteredValuesWhenInputIsProvided();

void shouldThrowErrorWhenFilterSizeIsGreaterThanInputSize();

void shouldThrowErrorWhenFilterSizeIsLessThanOrEqualToZero();

void shouldReturnPaddedAverageFilteredValuesWhenInputIsProvided();

void shouldReturnPaddedMedianFilteredValuesWhenInputIsProvided();

void shouldReturnMedianFilteredValuesWithStdNthElementFunctionWhenInputIsProvided();

#endif /* tests_filterTests_hpp */
