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
        - [6.3.2 **Pull-Request Templates**](#632-pull-request-templates)
        - [6.3.3 **Labels**](#633-labels)
      - [6.4 **Bug Database**](#64-bug-database)
  - [7. **Test Schedule**](#7-test-schedule)
  - [8. **Resources**](#8-resources)
    - [8.1 **Test Tools**](#81-test-tools)
    - [8.2 **Personnel**](#82-personnel)
  - [9. **Risks and Mitigations**](#9-risks-and-mitigations)
    - [9.1 **Performance Risk**](#91-performance-risk)
    - [9.2 **Data Integrity Risk**](#92-data-integrity-risk)
  - [10. **Glossary**](#10-glossary)

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
  ![Bug Report Template](https://github.com/algosup/2024-2025-project-3-quickest-path-team-3/blob/document/Documents/QualityAssurance/Images/BugReportIssue.png)

- **Typo Report Template**:
  ![Typo Report Template](https://github.com/algosup/2024-2025-project-3-quickest-path-team-3/blob/document/Documents/QualityAssurance/Images/TypoReportIssue.png)
- **Feature Request Template**:
  ![Feature Request Template](https://github.com/algosup/2024-2025-project-3-quickest-path-team-3/blob/document/Documents/QualityAssurance/Images/FeatureRequest.png)

- **General Question Template**:
  ![General Question Template](https://github.com/algosup/2024-2025-project-3-quickest-path-team-3/blob/document/Documents/QualityAssurance/Images/GeneralQuestion.png)

##### 6.3.2 **Pull-Request Templates**

Here are the screenshots of the pull-request template used in the project:

- **Pull Request Template**:
  ![Pull Request Template](https://github.com/algosup/2024-2025-project-3-quickest-path-team-3/blob/document/Documents/QualityAssurance/Images/PullRequestTemplate.png)

##### 6.3.3 **Labels**

We chose to use labels to categorize issues and pull requests in the project. You can the labels used in the project [here](https://github.com/algosup/2024-2025-project-3-quickest-path-team-3/labels).

#### 6.4 **Bug Database**

You will be able to find the all the bugs in Github's issue tab. You will also be able to see it in a google sheet [here](https://docs.google.com/spreadsheets/d/1y3rJFKFBt53vgucQnEiByPjIO2DgxmkgcAVdG9xDjgM/edit?usp=sharing).

---

## 7. **Test Schedule**

| **Test Phase**              | **Start Date** | **End Date** | **Responsible Team Member** |
| --------------------------- | -------------- | ------------ | --------------------------- |
| Test Case Design            | 2025/01/22     | 2025/02/07   | Lucas AUBARD                |
| Test Execution              | 2025/01/22     | 2025/02/07   | Lucas AUBARD                |
| Performance Testing         | 2025/01/22     | 2025/02/07   | Lucas AUBARD                |
| Data Integrity Verification | 2025/01/22     | 2025/02/07   | Lucas AUBARD                |
| Algorithm Testing           | 2025/01/22     | 2025/02/07   | Lucas AUBARD                |
| Edge Case Testing           | 2025/01/22     | 2025/02/07   | Lucas AUBARD                |
| Test Reporting              | 2025/01/22     | 2025/02/07   | Lucas AUBARD                |

---

## 8. **Resources**

### 8.1 **Test Tools**

- Postman (for API testing)
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

## 10. **Glossary**

| **Term**                                    | **Definition**                                                                                                                                                                              |
| ------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **API (Application Programming Interface)** | A set of rules and protocols that allow different software applications to communicate with each other. In this project, the API is used to expose the pathfinding functionality.           |
| **REST (Representational State Transfer)**  | An architectural style for designing networked applications, using stateless communication (HTTP requests) to retrieve and manipulate data.                                                 |
| **DAG (Directed Acyclic Graph)**            | A type of graph where edges have a direction and there are no cycles (i.e., no paths that start and end at the same vertex). Used in this project to represent the road network.            |
| **Heuristic**                               | A problem-solving technique used to find an approximate solution when finding the exact solution is computationally expensive. In this project, heuristics are used to improve performance. |
| **Load Testing**                            | A type of performance testing that evaluates how the system performs under a high load (e.g., many concurrent users or large datasets).                                                     |
| **Big O Notation**                          | A mathematical notation used to describe the efficiency of algorithms in terms of time or space complexity. For example, O(n) represents linear time complexity.                            |
| **CSV (Comma-Separated Values)**            | A file format used to store tabular data where each value is separated by commas. In this project, it contains the road network data.                                                       |
| **Pathfinding Algorithm**                   | An algorithm designed to find the shortest or most efficient path between two points (landmarks) in a graph.                                                                                |
| **Stress Test**                             | A type of testing that checks the system's behavior under extreme conditions or a high volume of data to ensure it can handle the stress without failing.                                   |
| **Pull Request (PR)**                       | A method of submitting contributions to a project. After a developer makes changes, a pull request is created to review and merge the changes into the main codebase.                       |
| **Unit Testing**                            | A type of testing where individual components or functions of the software are tested in isolation to ensure they work as expected.                                                         |
| **Test Case**                               | A set of conditions or variables used to determine whether a software application functions as expected.                                                                                    |
| **Edge Case**                               | A test case that deals with extreme or unusual inputs to verify the system's behavior under these conditions.                                                                               |
| **Version Control**                         | A system that tracks changes to code over time, allowing multiple people to work on the same project without overwriting each other's work. Git is a popular version control system.        |

---
