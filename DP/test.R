# Load required packages
library(ggplot2)
library(dplyr)
library(tidyr)

# Create a sample dataset
set.seed(123)  # For reproducibility
time_series_data <- data.frame(
  Time = 1:100,
  Series_A = cumsum(rnorm(100, mean = 0.2, sd = 1)),
  Series_B = cumsum(rnorm(100, mean = 0.1, sd = 1)),
  Series_C = cumsum(rnorm(100, mean = -0.1, sd = 1))
)

# Convert data to long format for ggplot2
long_data <- time_series_data %>%
  pivot_longer(cols = -Time, names_to = "Series", values_to = "Value")

# Plot multiple time series
ggplot(long_data, aes(x = Time, y = Value, color = Series)) +
  geom_line(size = 1) +
  theme_minimal() +
  labs(title = "Multiple Time Series Plot",
       x = "Time",
       y = "Value",
       color = "Series") +
  theme(legend.position = "top")
