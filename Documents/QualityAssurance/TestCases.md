# Test Cases for Project 3: Quickest Path Calculation between Landmarks

## 1. **Introduction**

This document lists all the test cases for verifying the functionality, performance, edge cases, and other aspects of the software solution. Each test case is documented with its unique ID, description, test data, expected results, priority, steps, and status.

---

## 2. **Test Cases**

### 2.1 **Functional Testing**

| **Test Case ID** | **Description**                                                                                           | **Input**                                   | **Expected Output**                   | **Priority** | **Steps**                                                                                                                                               | **Status** |
| ---------------- | --------------------------------------------------------------------------------------------------------- | ------------------------------------------- | ------------------------------------- | ------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- |
| TC-FUNC-01       | Verify API returns the correct path, travel time, and landmark list for valid source and destination IDs. | Source: Landmark A, Destination: Landmark B | Path: [A -> B -> C], Travel Time: X   | High         | 1. Send a GET request to the API endpoint with valid source and destination IDs. <br> 2. Verify the response contains the correct path and travel time. | Not Tested |
| TC-FUNC-02       | Test API with invalid landmark IDs.                                                                       | Source: Invalid, Destination: Invalid       | Error Message: "Invalid Landmark IDs" | High         | 1. Send a GET request to the API endpoint with invalid landmark IDs. <br> 2. Verify the response returns the appropriate error message.                 | Not Tested |
| TC-FUNC-03       | Verify API supports both XML and JSON response formats.                                                   | Query with headers for XML and JSON         | Valid responses in both formats       | Medium       | 1. Send GET requests to the API endpoint with headers specifying XML and JSON formats. <br> 2. Verify responses match the respective formats.           | Not Tested |
| TC-FUNC-04       | Verify the data validation tool validates the CSV file as a Directed Acyclic Graph (DAG).                 | CSV File with valid/invalid graph data      | Validates whether the graph is a DAG  | Medium       | 1. Run the data validation tool with the provided CSV file. <br> 2. Verify the tool outputs the correct DAG validation result.                          | Not Tested |
| TC-FUNC-05       | Verify the data validation tool checks graph connectivity.                                                | CSV File with disconnected/connected data   | Outputs connectivity status           | Medium       | 1. Run the data validation tool with the provided CSV file. <br> 2. Verify the tool identifies whether all nodes are reachable.                         | Not Tested |

---

### 2.2 **Performance Testing**

| **Test Case ID** | **Description**                                                                     | **Input**                                   | **Expected Output**                                | **Priority** | **Steps**                                                                                                                                     | **Status** |
| ---------------- | ----------------------------------------------------------------------------------- | ------------------------------------------- | -------------------------------------------------- | ------------ | --------------------------------------------------------------------------------------------------------------------------------------------- | ---------- |
| TC-PERF-01       | Load test the API response time under typical conditions.                           | Multiple concurrent queries                 | Response Time < 1 second                           | High         | 1. Simulate multiple concurrent API requests using a load-testing tool. <br> 2. Measure the response time for each request.                   | Not Tested |
| TC-PERF-02       | Verify that the returned path duration is within 10% of the shortest path duration. | Source: Landmark A, Destination: Landmark B | Path duration within 10% of shortest path duration | High         | 1. Query the API for paths between various source-destination pairs. <br> 2. Compare the path duration with the known shortest path duration. | Not Tested |

---

### 2.3 **Algorithm Testing**

| **Test Case ID** | **Description**                                      | **Input**                                   | **Expected Output**   | **Priority** | **Steps**                                                                                                                 | **Status** |
| ---------------- | ---------------------------------------------------- | ------------------------------------------- | --------------------- | ------------ | ------------------------------------------------------------------------------------------------------------------------- | ---------- |
| TC-ALG-01        | Verify the correctness of the pathfinding algorithm. | Source: Landmark A, Destination: Landmark B | Correct path returned | High         | 1. Query the API with known source-destination pairs. <br> 2. Verify the returned path matches the expected correct path. | Not Tested |

---

### 2.4 **Edge Case Testing**

| **Test Case ID** | **Description**                                                                              | **Input**                                     | **Expected Output**                                    | **Priority** | **Steps**                                                                                                                                         | **Status** |
| ---------------- | -------------------------------------------------------------------------------------------- | --------------------------------------------- | ------------------------------------------------------ | ------------ | ------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- |
| TC-EDGE-01       | Test for invalid source and destination pairs that do not exist in the dataset.              | Source: Nonexistent, Destination: Nonexistent | Error Message: "Invalid Landmark IDs"                  | Medium       | 1. Query the API with nonexistent landmark IDs. <br> 2. Verify the error message matches the expected output.                                     | Not Tested |
| TC-EDGE-02       | Test the behavior when one or more nodes are isolated (disconnected from the graph).         | CSV file with isolated nodes                  | Error Message or no valid path returned                | Medium       | 1. Provide a CSV file with isolated nodes to the validation tool. <br> 2. Verify the tool detects disconnected nodes.                             | Not Tested |
| TC-EDGE-03       | Perform a stress test with the full dataset (24 million nodes) and verify system handles it. | Full dataset                                  | System handles dataset without performance degradation | High         | 1. Load the full dataset into the system. <br> 2. Query the API with various paths. <br> 3. Ensure no significant performance degradation occurs. | Not Tested |

---

## 3. **Conclusion**

This document provides a comprehensive list of test cases to ensure the functionality, performance, and reliability of the project. Each test case will be executed, and the results will be updated in the **Status** column.
