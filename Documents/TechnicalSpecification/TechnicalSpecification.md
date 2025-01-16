# Technical Specifications - Quickest Path

| **Authors** | Mathis PASCUCCI |
| --- | --- |
| **Team** | 3 |
| **Reviewer** | --- |
| **Created** | 01/06/2025 |
| **Last Modified** | 01/15/2025 |

---

<details>
<summary> Table of Contents </summary>

- [Technical Specifications - Quickest Path Project](#technical-specifications---quickest-path-project)
  - [Before Reading](#before-reading)
  - [I. Introduction](#i-introduction)
    - [Overview](#overview)
    - [Audience](#audience)
    - [Glossary](#glossary)
  - [II. Goals](#ii-goals)
    - [Performance Goals](#performance-goals)
      - [Response Time](#response-time)
      - [Scalability](#scalability)
      - [Resource Efficiency](#resource-efficiency)
      - [Stress Testing](#stress-testing)
    - [Project Folder Structure](#project-folder-structure)
  - [III. Constraints and Limitations](#iii-constraints-and-limitations)
  - [IV. Conventions](#iv-conventions)
    - [Naming Conventions](#naming-conventions)
    - [Folders & Files](#folders--files)
    - [Variables](#variables)
    - [Constants](#constants)
  - [V. Testing and Validation](#v-testing-and-validation)
    - [Validation Criteria](#validation-criteria)
    - [Test Plan and Test Cases](#test-plan-and-test-cases)
  - [VI. Requirements](#vi-requirements)
    - [Core Requirements](#core-requirements)
      - [REST API Implementation](#rest-api-implementation)
      - [Query Parameters](#query-parameters)
      - [Output Specification](#output-specification)
      - [Error Handling](#error-handling)
      - [Algorithm Implementation](#algorithm-implementation)
        - [Shortest Path Calculation](#shortest-path-calculation)
      - [Dataset Preprocessing](#dataset-preprocessing)
        - [Validation Tool](#validation-tool)
        - [Precomputed Data](#precomputed-data)
  - [IX. Setup Guide](#ix-setup-guide)
    - [IX.1 Prerequisites](#ix1-prerequisites)
    - [IX.2 Setup Instructions](#ix2-setup-instructions)
      - [macOS Setup](#macos-setup)
      - [Windows Setup](#windows-setup)
      - [Linux Setup](#linux-setup)

</details>

---

## Before Reading

Ensure you have reviewed the [Functional Specifications](/Documents/FunctionalSpecification/FunctionalSpecification.md) for this project, as it provides essential insights into the project's objectives and scope.

---

## I. Introduction

### Overview

The **Quickest Path** project aims to develop a high-performance software solution that calculates the most efficient route between two landmarks within the United States. The core of the project will be implemented using **C++**<sup><a href="#1">[1]</a></sup>, providing fast and scalable performance. The application will expose its functionality through a **REST API**<sup><a href="#2">[2]</a></sup>, allowing users to request route information via standard HTTP requests.

### Audience

This document is intended primarily for:

- **Software Engineers**: To understand technical requirements, guide design decisions, and ensure adherence to best practices in software development.
- **Program Managers**: To monitor the alignment between technical and functional specifications, ensuring customer satisfaction.
- **Quality Assurance (QA)**: To prepare and execute test plans, ensuring the system meets its expected performance criteria.
- **Project Managers**: To identify risks, dependencies, and resource allocation.

### Glossary

| Term | Definition | Source |
| ---- | ---------- | ------ |
| <a id="1">[1]</a> **C++** | A high-level programming language designed for system and application software. | [Wikipedia](https://en.wikipedia.org/wiki/C%2B%2B) |
| <a id="2">[2]</a> **REST API** | An architectural style for web services, enabling data communication through HTTP requests and responses. | [RedHat](https://www.redhat.com/en/topics/api/what-is-a-rest-api) |
| <a id="3">[3]</a> **OS** | System software that manages hardware and software resources. | [Wikipedia](https://en.wikipedia.org/wiki/Operating_system) |
| <a id="4">[4]</a> **Dataset**         | A structured collection of data points used for analysis or processing by the software.                 | [Wikipedia](https://en.wikipedia.org/wiki/Data_set) |
| <a id="5">[5]</a> **Stress Testing**  | A type of testing that evaluates a system's performance under extreme conditions or high loads.          | [Techopedia](https://www.techopedia.com/definition/14014/stress-testing) |
---

## II. Goals

### Performance Goals

#### Response Time
The API must process all valid queries within **1 second** on a typical laptop, even when handling large **datasets**<sup><a href="#4">[4]</a></sup>. Queries that do not result in valid paths should meet the same response time criteria.

#### Scalability
The system must handle **100 concurrent requests** without a significant drop in performance. As datasets grow—eventually expanding from regional to global coverage—the system should maintain usability.

#### Resource Efficiency
To accommodate systems with limited resources (e.g., low-end servers or laptops), **memory usage** and **CPU consumption** will be optimized. Techniques such as caching or indexing frequently requested routes will be applied to reduce runtime computations.

#### Stress Testing
The system will undergo **stress testing**<sup><a href="#5">[5]</a></sup> to assess its robustness under extreme conditions, including:
- **Burst traffic** with a sudden surge of requests.
- **Large-scale datasets** beyond typical operational limits.

Metrics like **average response time**, **maximum response time**, and **failure rates** will be tracked to ensure compliance with performance standards.

---

### Project Folder Structure

```folder
├── 2024-2025-project-3-quickest-path-team-3
|   ├── Documents
|   |   ├── FunctionalSpecification
|   |   |   ├── FunctionalSpecification.md
|   |   ├──Images
|   |   |   ├── API.png
|   |   ├── Management
|   |   |   ├── WeeklyReport
|   |   |   |   ├── Week1.md
|   |   |   |   ├── Week2.md
|   |   |   |   ├── Week3.md
|   |   |   |   ├── Week4.md
|   |   |   |   ├── Week5.md
|   |   |   |   ├── Week6.md
|   |   |   |   ├── Week7.md
|   |   |   ├── ProjectCharter.md
|   |   ├── QualityAssurance
|   |   |   ├── TestPlan.md
|   |   ├── TechnicalSpecification
|   |   |   ├── TechnicalSpecification.md
|   |   ├── UserManual
|   |   |   ├── UserManual.md
|   ├── .gitignore
|   ├── README.md
```

---

## III. Constraints and Limitations

The system will be implemented using **C++** for optimal performance in handling computationally intensive tasks. The application will be exposed through a **REST API**, allowing it to be easily integrated into various platforms. Given the project’s scale, it will be optimized to handle large datasets and ensure responses are provided in **1 second** or less.

---

## IV. Conventions

### Naming Conventions
To maintain consistency across the codebase and documentation, the following conventions will be observed:

- **Folders and Files**: Use `PascalCase`.
- **Variables and Functions**: Use `camelCase`.
- **Constants**: Use `UPPERCASE`.

---

## V. Testing and Validation

### Validation Criteria

1. The system must compute the shortest route between two landmarks in the United States in **under 1 second**.

2. The system should maintain **correct functionality** even when handling **large datasets** with millions of landmarks.

3. ...

### Test Plan and Test Cases

The detailed [test plan](/Documents/QualityAssurance/TestPlan.md) and [test cases](/Documents/QualityAssurance/TestCases.md) documents contain comprehensive descriptions of each test, including expected results and success criteria.

---

## VI. Requirements

### Core Requirements

These core requirements define the necessary features and capabilities of the software.


#### REST API Implementation

The system will implement a **REST API** to calculate the quickest route between two landmarks in the United States. 

- **Base URL**: `https://{domain}/{version}/{resource}`
- **Supported Response Formats**: `JSON`, `XML`

![diagram](/Documents/TechnicalSpecification/Images/ApiRequest.png)

#### Query Parameters

The API will accept the following query parameters:

| Parameter Name | Type   | Expected Value     | Description                              |
|----------------|--------|--------------------|------------------------------------------|
| `format`       | String | `"json"` or `"xml"`| Specifies the desired output format.    |
| `landmark_1`   | Integer| `1 to 24,000,000+`  | ID of the starting landmark.             |
| `landmark_2`   | Integer| `1 to 24,000,000+`  | ID of the destination landmark.          |

#### Output Specification

The response will include the route details in the specified format. Examples of output:

- **JSON Example**:  
```json
{ "start": "A", "end": "B", "path": [...] }
```
- **XML Example**:  
```xml
<response><start>A</start><end>B</end><path>...</path></response>
```

#### Error Handling

The API will adhere to standard **REST error handling** with relevant status codes and descriptive error messages. Examples:

| Error Case              | HTTP Code | Description                                     |
|-------------------------|-----------|-------------------------------------------------|
| **Invalid Landmark ID** | 404       | One or both landmarks do not exist.             |
| **Invalid Format**      | 400       | The requested format is not supported.          |
|**Missing Parameters**   |	400       |	Required parameters are missing in the request. |
---

### Algorithm Implementation

The system will calculate the shortest path using the given dataset of U.S. landmarks.

#### Shortest Path Calculation

An efficient pathfinding algorithm will be implemented to determine the quickest route between two landmarks.

---

### Dataset Preprocessing

A utility will validate the dataset to ensure that the graph is connected and free from loops.

#### Validation Tool

The tool will confirm that the dataset is complete and that all landmarks are reachable from each other.

#### Precomputed Data

Some data will be precomputed to optimize performance, such as common routes between landmarks.

---

## IX. Setup Guide

### IX.I Prerequisites

#### Software Prerequisites:
- macOS Sequoia
- Windows 11
- Linux Mint Wilma

#### Hardware Prerequisites:

| **Category**              | **Minimum Requirements** | **Recommended Requirements** |  
|---------------------------|--------------------------|------------------------------|  
| **CPU (macOS)**           | Intel Core 2 Duo SU9400, Apple M1 | x86_64 or ARM CPU (Apple Silicon), Apple M3 Chip |  
| **CPU (Windows / Linux)** | x86_32 CPU with SSE2 instructions, any x86_64 CPU, ARMv8 CPU, Intel(R) Core(TM) i7-1065G7 | Intel Core 2 Duo E8200, AMD Athlon XE |  
| **RAM (All systems)**     |  8 GB | 16 GB |
| **Storage (All systems)** | --- | --- |

---

### IX.II Setup Instructions

#### macOS Setup

For macOS, follow the instructions in this section to configure the environment and compile the code.

#### Windows Setup

For Windows, ensure you have installed the necessary dependencies using the guide.

#### Linux Setup

For Linux, use the terminal commands to set up the project.

--- 

