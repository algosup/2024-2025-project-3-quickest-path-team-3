# Test Plan for Project 3: Quickest Path Calculation between Landmarks

<details>
<summary>Table of Contents</summary>

- [Test Plan for Project 3: Quickest Path Calculation between Landmarks](#test-plan-for-project-3-quickest-path-calculation-between-landmarks)
  - [1. **Introduction**](#1-introduction)
    - [1.1 **Purpose**](#11-purpose)
    - [1.2 **Scope**](#12-scope)
    - [1.3 **Test Objectives**](#13-test-objectives)
  - [2. **Test Items**](#2-test-items)
    - [2.1 **Software Components to be Tested**](#21-software-components-to-be-tested)
    - [2.2 **Test Deliverables**](#22-test-deliverables)
  - [3. **Test Strategy**](#3-test-strategy)
    - [3.1 **Test Types**](#31-test-types)
  - [4. **Test Environment**](#4-test-environment)
    - [4.1 **Hardware**](#41-hardware)
    - [4.2 **Software**](#42-software)
    - [4.3 **Data**](#43-data)
  - [5. **Test Criteria**](#5-test-criteria)
    - [5.1 **Acceptance Criteria**](#51-acceptance-criteria)
    - [5.2 **Exit Criteria**](#52-exit-criteria)
  - [6. **Test Design**](#6-test-design)
    - [6.1 **Test Case Structure**](#61-test-case-structure)
    - [6.2 **Test Categories**](#62-test-categories)
      - [6.2.1 **Functional Testing**](#621-functional-testing)
      - [6.2.2 **Performance Testing**](#622-performance-testing)
      - [6.2.3 **Algorithm Testing**](#623-algorithm-testing)
      - [6.2.4 **Edge Case Testing**](#624-edge-case-testing)
      - [6.3 **Templates and Labels**](#63-templates-and-labels)
        - [6.3.1 **Issue Templates**](#631-issue-templates)
  - [7. **Test Schedule**](#7-test-schedule)
  - [8. **Resources**](#8-resources)
    - [8.1 **Test Tools**](#81-test-tools)
    - [8.2 **Personnel**](#82-personnel)
  - [9. **Risks and Mitigations**](#9-risks-and-mitigations)
    - [9.1 **Performance Risk**](#91-performance-risk)
    - [9.2 **Data Integrity Risk**](#92-data-integrity-risk)
  - [10. **Approval**](#10-approval)

</details>

## 1. **Introduction**

### 1.1 **Purpose**

This document outlines the test plan for the project "Quickest Path Calculation between Landmarks," which involves developing a software solution to calculate the shortest path between two landmarks in the United States, based on a provided road network dataset.

### 1.2 **Scope**

The scope of this test plan includes the testing of the software solution’s REST API, functionality, performance, data integrity, and algorithm correctness.

### 1.3 **Test Objectives**

- Ensure correctness of the shortest path calculation.
- Verify that the API meets performance requirements (response time under 1 second).
- Validate the integrity of the data from the CSV file.
- Ensure the pathfinding algorithm adheres to the 10% approximation rule.
- Test the response formats (XML and JSON).

---

## 2. **Test Items**

### 2.1 **Software Components to be Tested**

- **REST API** (GET endpoint for pathfinding)
- **Pathfinding Algorithm**
- **Data Validation Tool**
- **Performance and Load Testing**

### 2.2 **Test Deliverables**

- Test cases and test scripts.
- Test execution reports.
- Test summary report.

---

## 3. **Test Strategy**

### 3.1 **Test Types**

- **Functional Testing**: To ensure that all functions (pathfinding, data validation, API responses) work as expected.
- **Performance Testing**: To verify that the system meets the performance criteria (API response time within 1 second).
- **Data Integrity Testing**: To ensure the correctness of the input data and its validation.
- **Algorithm Testing**: To validate that the pathfinding algorithm is correct and produces paths within the 10% approximation constraint.
- **Edge Case Testing**: To test the behavior of the system with invalid or extreme inputs.

---

## 4. **Test Environment**

### 4.1 **Hardware**

- Typical laptop (as per the project’s performance requirement)
- Sufficient memory and processing power to handle 24 million nodes.

### 4.2 **Software**

- C++ compiler (compatible with the project's language requirement)
- HTTP server for running the REST API
- Tools for testing API responses (Postman, cURL, etc.)
- Load testing tools (e.g., Apache JMeter)

### 4.3 **Data**

- USA-roads.csv file containing the road network data (24 million nodes).

---

## 5. **Test Criteria**

### 5.1 **Acceptance Criteria**

- The REST API must return a correct path, travel time, and landmark list within 1 second.
- The pathfinding algorithm must return a result within 10% of the shortest path duration.
- The graph must be validated as a Directed Acyclic Graph (DAG).
- The API must support both XML and JSON response formats.

### 5.2 **Exit Criteria**

- All test cases are executed and passed.
- No critical or high-priority defects remain unresolved.
- Performance benchmarks (response time under 1 second) are met.

---

## 6. **Test Design**

### 6.1 **Test Case Structure**

| **Field**                 | **Description**                                                  |
| ------------------------- | ---------------------------------------------------------------- |
| **Test Case ID**          | Unique identifier for each test case.                            |
| **Test Case Description** | A brief description of what the test case is intended to verify. |
| **Input**                 | The test data or parameters that will be used in the test.       |
| **Expected Output**       | The expected result or behavior after executing the test case.   |
| **Test Steps**            | Detailed steps to execute the test case.                         |
| **Pass/Fail Criteria**    | The criteria that define a pass or failure of the test case.     |

### 6.2 **Test Categories**

#### 6.2.1 **Functional Testing**

| **Test Case ID** | **Test Case Description**                                                                                              |
| ---------------- | ---------------------------------------------------------------------------------------------------------------------- |
| **Test Case 1**  | Verify the API returns the correct path, travel time, and landmark list for valid source and destination landmark IDs. |
| **Test Case 2**  | Test the API with invalid landmark IDs, ensuring an appropriate error message is returned.                             |
| **Test Case 3**  | Verify that the API supports both XML and JSON response formats.                                                       |

#### 6.2.2 **Performance Testing**

| **Test Case ID** | **Test Case Description**                                                                                                       |
| ---------------- | ------------------------------------------------------------------------------------------------------------------------------- |
| **Test Case 6**  | Load test the API to ensure the response time for a pathfinding query does not exceed 1 second under typical laptop conditions. |
| **Test Case 7**  | Verify that the returned path duration is within 10% of the shortest path duration for different source and destination pairs.  |

#### 6.2.3 **Algorithm Testing**

| **Test Case ID** | **Test Case Description**                                                                           |
| ---------------- | --------------------------------------------------------------------------------------------------- |
| **Test Case 8**  | Verify the correctness of the pathfinding algorithm (ensure the correct path is returned).          |
| **Test Case 9**  | Verify that the heuristic used in the algorithm produces results within the 10% approximation rule. |

#### 6.2.4 **Edge Case Testing**

| **Test Case ID** | **Test Case Description**                                                                        |
| ---------------- | ------------------------------------------------------------------------------------------------ |
| **Test Case 10** | Test for invalid source and destination pairs that do not exist in the dataset.                  |
| **Test Case 11** | Test the behavior when one or more nodes are isolated (disconnected from the rest of the graph). |

| **Test Case ID** | **Test Case Description**                                                                                                           |
| ---------------- | ----------------------------------------------------------------------------------------------------------------------------------- |
| **Test Case 12** | Perform a stress test with the full dataset (24 million nodes) and verify the system can handle it without performance degradation. |

#### 6.3 **Templates and Labels**

##### 6.3.1 **Issue Templates**

Here are the screenshots of the issue templates used in the project:

- **Bug Report Template**:
    ![Bug Report Template](https://i.imgur.com/1Z2Z2Q4.png)

---

## 7. **Test Schedule**

| **Test Phase**              | **Start Date** | **End Date** | **Responsible Team Member** |
| --------------------------- | -------------- | ------------ | --------------------------- |
| Test Case Design            | YYYY-MM-DD     | YYYY-MM-DD   | Lucas AUBARD                |
| Test Execution              | YYYY-MM-DD     | YYYY-MM-DD   | Lucas AUBARD                |
| Performance Testing         | YYYY-MM-DD     | YYYY-MM-DD   | Lucas AUBARD                |
| Data Integrity Verification | YYYY-MM-DD     | YYYY-MM-DD   | Lucas AUBARD                |
| Algorithm Testing           | YYYY-MM-DD     | YYYY-MM-DD   | Lucas AUBARD                |
| Edge Case Testing           | YYYY-MM-DD     | YYYY-MM-DD   | Lucas AUBARD                |
| Test Reporting              | YYYY-MM-DD     | YYYY-MM-DD   | Lucas AUBARD                |

---

## 8. **Resources**

### 8.1 **Test Tools**

- Postman (for API testing)
- Apache JMeter (for load testing)
- C++ Compiler
- Data Validation Tool

### 8.2 **Personnel**

| Name                            | Role              |
| ------------------------------- | ----------------- |
| Salaheddine NAMIR               | Project Manager   |
| Alexis LASSELIN                 | Program Manager   |
| Mathis PASCUCCI                 | Technical Leader  |
| Vivien Bistrel TSANGUE CHOUNGOU | Software Engineer |
| Vianney POLARD                  | Software Engineer |
| Lucas AUBARD                    | Quality Assurance |
| Julian REINE                    | Technical Writer  |

---

## 9. **Risks and Mitigations**

### 9.1 **Performance Risk**

- **Risk**: The API may not meet the 1-second response time for large datasets.
- **Mitigation**: Use efficient data structures and algorithms; optimize the pathfinding algorithm.

### 9.2 **Data Integrity Risk**

- **Risk**: The graph may contain data errors (e.g., missing connections or isolated nodes).
- **Mitigation**: Implement robust data validation checks.

---

## 10. **Approval**

| Name                            | Role              | Date       | Signature |
| ------------------------------- | ----------------- | ---------- | --------- |
| Salaheddine NAMIR               | Project Manager   | YYYY-MM-DD |           |
| Alexis LASSELIN                 | Program Manager   | YYYY-MM-DD |           |
| Mathis PASCUCCI                 | Technical Leader  | YYYY-MM-DD |           |
| Vivien Bistrel TSANGUE CHOUNGOU | Software Engineer | YYYY-MM-DD |           |
| Vianney POLARD                  | Software Engineer | YYYY-MM-DD |           |
| Lucas AUBARD                    | Quality Assurance | YYYY-MM-DD |           |
| Julian REINE                    | Technical Writer  | YYYY-MM-DD |           |

---
