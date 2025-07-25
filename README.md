# Uncertainty-Aware Fusion Model for Flex Sensor Regression

**Authors:** Bhargavi Savani, William Luu

## Overview

This project presents an **uncertainty-aware fusion framework** designed to improve the reliability and interpretability of flex sensor angle predictions **without retraining base models**. It dynamically fuses outputs from five distinct regression models, weighting each prediction based on its estimated uncertainty.

## Motivation

In flex sensor applications—especially those requiring consistent, interpretable outputs—single-model predictions can be brittle and difficult to trust under ambiguous conditions. Our framework addresses this by:

- **Fusing predictions** from multiple models  
- **Dynamically adjusting trust** in each model per input  
- **Improving interpretability** via transparent weight breakdowns  

## Models Used

The fusion integrates predictions and uncertainties from the following regression models:

- Linear Regression  
- Polynomial Regression  
- Random Forest Regressor  
- XGBoost Regressor  
- Gaussian Process Regression
