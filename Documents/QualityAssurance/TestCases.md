# Test Cases for Project 3: Quickest Path Calculation between Landmarks

## 1. **Introduction**

This document lists all the test cases for verifying the functionality, performance, edge cases, and other aspects of the software solution. Each test case is documented with its unique ID, description, test data, expected results, and status.

---

## 2. **Test Cases**

### 2.1 **Functional Testing**

| **Test Case ID** | **Description**                                                                                           | **Input**                                   | **Expected Output**                                              | **Status** |
| ---------------- | --------------------------------------------------------------------------------------------------------- | ------------------------------------------- | ---------------------------------------------------------------- | ---------- |
| TC-FUNC-01       | Verify API returns the correct path, travel time, and landmark list for valid source and destination IDs. | Source: Landmark A, Destination: Landmark B | Path: [A -> B -> C], Travel Time: X                              | Not Tested |
| TC-FUNC-02       | Test API with invalid landmark IDs.                                                                       | Source: Invalid, Destination: Invalid       | Error Message: "Invalid Landmark IDs"                            | Not Tested |
| TC-FUNC-03       | Verify API supports both XML and JSON response formats.                                                   | Query with headers for XML and JSON         | Valid responses in both formats                                  | Not Tested |
| TC-FUNC-04       | Verify data validation tool validates the CSV file as a Directed Acyclic Graph (DAG).                     | Input: Sample CSV file                      | Output: "Graph is a DAG" or appropriate error messages           | Not Tested |
| TC-FUNC-05       | Verify data validation tool ensures graph connectivity (all landmarks are reachable).                     | Input: Sample CSV file                      | Output: "Graph is fully connected" or appropriate error messages | Not Tested |

---

### 2.2 **Performance Testing**

| **Test Case ID** | **Description**                                                                                | **Input**                                   | **Expected Output**                        | **Status** |
| ---------------- | ---------------------------------------------------------------------------------------------- | ------------------------------------------- | ------------------------------------------ | ---------- |
| TC-PERF-01       | Load test API response time under typical conditions.                                          | Multiple concurrent queries                 | Response Time < 1 second                   | Not Tested |
| TC-PERF-02       | Verify returned path duration is within 10% of the shortest path duration for different pairs. | Source: Landmark X, Destination: Landmark Y | Path duration <= 110% of shortest duration | Not Tested |

---

### 2.3 **Algorithm Testing**

| **Test Case ID** | **Description**                                         | **Input**                                   | **Expected Output**            | **Status** |
| ---------------- | ------------------------------------------------------- | ------------------------------------------- | ------------------------------ | ---------- |
| TC-ALG-01        | Verify correctness of the pathfinding algorithm.        | Source: Landmark A, Destination: Landmark B | Correct path: [A -> B -> C]    | Not Tested |
| TC-ALG-02        | Verify algorithm handles disconnected nodes gracefully. | Source: Isolated Node, Destination: Any     | Error Message: "No path found" | Not Tested |

---

### 2.4 **Edge Case Testing**

| **Test Case ID** | **Description**                                                                                  | **Input**                                       | **Expected Output**                                                  | **Status** |
| ---------------- | ------------------------------------------------------------------------------------------------ | ----------------------------------------------- | -------------------------------------------------------------------- | ---------- |
| TC-EDGE-01       | Test for invalid source and destination pairs that do not exist in the dataset.                  | Source: Invalid Node, Destination: Invalid Node | Error Message: "Invalid Landmark IDs"                                | Not Tested |
| TC-EDGE-02       | Test the behavior when one or more nodes are isolated (disconnected from the rest of the graph). | Input: Graph with isolated nodes                | Output: "Graph contains isolated nodes" or appropriate error message | Not Tested |
| TC-EDGE-03       | Perform a stress test with the full dataset (24 million nodes) and verify system performance.    | Input: Full dataset                             | System handles without performance degradation                       | Not Tested |

---

### 2.5 **Test Status**

| **Status**     | **Description**                                                        |
| -------------- | ---------------------------------------------------------------------- |
| **Not Tested** | The test case has not been executed yet.                               |
| **Pass**       | The test case has been executed successfully, meeting expected output. |
| **Fail**       | The test case did not produce the expected output or behavior.         |

---

## 3. **Conclusion**

This document provides a comprehensive list of test cases for verifying all aspects of the project. The results of the test executions will be updated in the **Status** column as testing progresses.
