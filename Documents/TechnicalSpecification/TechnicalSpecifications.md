# Technical Specifications

<details>
<summary>Table of Contents</summary>

- [Technical Specifications](#technical-specifications)
  - [Introduction](#introduction)
    - [Project Overview](#project-overview)
  - [Technical Requirements](#technical-requirements)
    - [REST API](#rest-api)

</details>

## Introduction

### Project Overview

This project aims to build a high-performance REST API designed to compute the quickest path between two landmarks in the United States. Developed in C++, the system will process a dataset containing up to 24 million nodes and deliver results within 1 second on an average laptop. The API supports user-selectable response formats (JSON or XML) and is designed to handle invalid inputs gracefully.

This project is really valuable because it will enable users to quickly find the shortest path between two landmarks in the United States. This is particularly useful for tourists, who can use the API to plan their trips more efficiently. The API can also be used by logistics companies to optimize their delivery routes, saving time and money.

## Technical Requirements

The software must be developed in C++, allowing for high performance and efficient memory management.

### REST API

The system must expose a REST API that accepts HTTP GET requests with the following parameters:

- `source`: The starting landmark
- `destination`: The ending landmark
- `format`: The desired response format (JSON or XML)
  - This is an optional parameter, with JSON being the default format if not specified

The API must return the quickest path between the two landmarks in the specified format. If the input is invalid (e.g., landmarks not found), the API should return an appropriate error message that will be explained later in this document.

However, if both the source and destination are valid landmarks, the API should return the quickest path between them with the following information:

- `time`: The time taken to travel between the two landmarks
- `path`: The sequence of landmarks to visit to reach the destination

Here an example of a GET request to the API:

> [!WARNING]  
> Data is not real and is used for illustrative purposes only.

```http
curl "http://localhost:18080/quickestpath?source=1&destination=12"
```
