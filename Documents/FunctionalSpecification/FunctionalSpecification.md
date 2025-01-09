# Functional specifications template

## Table of Contents

<details>
<summary> Click to expand </summary>

- [Functional specifications template](#functional-specifications-template)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
    - [Product description](#product-description)
    - [Product functional capabilities](#product-functional-capabilities)
    - [User Roles](#user-roles)
    - [Use Cases for all operations](#use-cases-for-all-operations)
      - [Use Case 1: Compute the shortest path](#use-case-1-compute-the-shortest-path)
      - [Use Case 2: Insert an invalid input ID](#use-case-2-insert-an-invalid-input-id)
    - [General constraints](#general-constraints)
    - [Assumptions](#assumptions)
    - [Other software](#other-software)
  - [Specific Function Descriptions](#specific-function-descriptions)
    - [Description](#description)
    - [Inputs](#inputs)
    - [Processing](#processing)
    - [Outputs](#outputs)
  - [External Interfaces](#external-interfaces)
    - [User Interfaces](#user-interfaces)
    - [Hardware Interfaces](#hardware-interfaces)
    - [Software Interfaces](#software-interfaces)
    - [Communication Interfaces](#communication-interfaces)
    - [Performance](#performance)
    - [Design Constraints](#design-constraints)
  - [Attributes](#attributes)
    - [Security](#security)
    - [Reliability, Availability, Maintainability](#reliability-availability-maintainability)
    - [Configurability and Compatibility](#configurability-and-compatibility)
    - [Installability](#installability)
    - [Usability](#usability)
  - [Additional Requirements](#additional-requirements)
    - [User documentation](#user-documentation)
    - [Other requirements](#other-requirements)
    - [Glossary](#glossary)

</details>

## Overview

### Product description

This software solution is a high-performance **REST API[^1]**, developped in **C++[^2]**, designed to compute the quickest path between two landmarks in the United States of America. The API is intented to handle a dataset with approximately 24 million nodes, ensuring resuls are within 1 second of response time for an average laptop.

The key features of the solution include:

- Pathfinding using efficient algorithms
- Data validation
- Support for the user-selectable response formats in **XML[^3]** and **JSON[^4]**
- Error handling by standard REST API practices

### Product functional capabilities

The primary functions of the software are:

1. **Pathfinding**: We must be able to find the quickest path between two landmarks based on a provided dataset (a csv file of american landmarks in this case).
2. **Data validation**: A separate utility will verify the integrity of the provided dataset, ensuring graph connectivity and absence of loops.
3. **Response format selection**: The system supports user-selectable response formats, offering both XML and JSON outputs.
4. **Error handling**: The API will return appropriate status codes and error messages based on standard REST API error handling practices.
5. **Performance**: Ensure response times of under 1 second for an average laptop.

### User Roles

Our current vision is for a single user role, the API user.

The API user will interact with the software through HTTP requests, and will be responsible for:

- Providing the API with the necessary input data
- Interpreting the API's response
- Handling any errors that may occur during the process

### Use Cases for all operations

#### Use Case 1: Compute the shortest path

- **Primary Actor**: API User
- **Description**: The user provides the ID of the starting and ending landmarks. The system calculates the quickest path and return the result in the user-selected format.
- **Preconditions**: The USA roads' dataset must be loaded and the local server must be running.
- **Postconditions**: The system returns the quickest path between the two landmarks in \***\*XML** or **JSON** format.
- **Normal Flow**:
  1. The user sends an HTTP request to the API with the source and destination IDs.
  2. The server processes the request and computes the quickest path.
  3. The server returns the result, including the travel time and ordered list of landmarks.

#### Use Case 2: Insert an invalid input ID

- **Primary Actor**: API User
- **Description**: The user provides an invalid ID as input. The system returns an error message.
- **Preconditions**: The USA roads' dataset must be loaded and the local server must be running.
- **Postconditions**: The system returns an error message.
- **Normal Flow**:
  1. The user sends an HTTP request to the API with an invalid ID.
  2. The server processes the request and returns an error message.

### General constraints

The software must be able to handle a dataset with approximately 24 million nodes, as it represent the number of landmarks in the United States of America.
The software must be able to return results within 1 second of response time for an average laptop.
For this project, only standard libraries (STL) and

### Assumptions

<!-- List any assumptions that were made in specifying the functional requirements. -->

### Other software

<!-- How does the program interact with other software, such as spreadsheets, word processing or presentation software? For example, can a user cut and paste from the application to other Windows software programs? Does the program import/export data to other software? Does the program use any communication, integration, or protocols to exchange data with other software? -->

## Specific Function Descriptions

<!-- This section is repeated for each function of the software. Some examples of functions are: engineering calculations, sorting or sequencing, other operations relating inputs to outputs, validity checks on inputs, error handling and recovery. -->

### Description

<!-- Describe the function and its role in the software. -->

### Inputs

<!-- Describe the inputs to the function. Where user interface (UI) elements are present, these are described. Examples of UI elements are check boxes, dropdown lists, and alphanumeric fields. Input validation strategy, allowed data types and value ranges are specified for each input. -->

### Processing

<!-- Describe what is done by the function. Where algorithms, equations, or other logic are used, they are described here. If calculations are done utilizing the methods of specific standards or references, these are cited. Database definitions are also included where relevant. -->

### Outputs

<!-- Describe the outputs of the function. Where a user interface description is relevant, it is included. Define any reports. -->

## External Interfaces

<!-- The interfaces in this section are specified by documenting: the name and description of each item, source or input, destination or output, ranges, accuracy and tolerances, units of measure, timing, display formats and organization, and data formats. -->

### User Interfaces

<!-- Describe all major screens, pages, forms, including any complex dialog boxes. This is usually best done via simulated, non-functioning screen shots, and may take the form of a separate document.

The navigation flow of the windows, menus, and options is described, along with the expected content of each window. Examples of items included are screen resolutions, color scheme, primary font type and size. Discussion also includes how input validation will be done, and how data will be protected from accidental changes. Specific items are described for each screen such as input fields, control buttons, sizing options, and menus. -->

### Hardware Interfaces

<!-- Describe the equipment needed to run the software, and also other output or input devices such as printers or handheld devices. -->

### Software Interfaces

<!-- Describe any software that will be required in order for the product to operate fully. Include any in-house software or commercial applications that customers will be utilizing together with the planned software. Also describes any software that the software product will interact with such as operating system platforms supported, file import and export, networking, automation, or scripting. Specify whether the users must provide the interfacing software themselves, and any special licensing requirements. -->

### Communication Interfaces

<!-- Describes how the software product will communicate with itself (for multi-platform applications) or other software applications, including items such as networking, email, intranet, and Internet communications. -->

### Performance

<!-- Discuss items such as response times, throughput requirements, data volume requirements, maximum data file size or problem complexity, maximum number of concurrent uses, and peak load requirements (for web-based applications). Includes expected response times for entering information, querying data files and databases, performing calculations of various complexities, and importing/exporting data. -->

### Design Constraints

<!-- Examples of constraints that affect software design choices are items such as memory constraints involving minimum and maximum RAM and hard disk space, and limitations arising from hardware, software or communications standards. -->

## Attributes

### Security

<!-- Describe any password-protected access levels such as operator, engineer/modeler, manager, database administrator-and which functionality will be accessible to each access level. If relevant, describes the planned approach to locking the software. -->

### Reliability, Availability, Maintainability

<!-- Describe requirements items such as days or weeks of continuous operation, strategy for data recovery, code structuring for ease of future modification. -->

### Configurability and Compatibility

<!-- Describe requirements such as those connected with individual customization or operation in specific computing environments. -->

### Installability

<!-- Describe the planned method for installation: done by the user independently, done by customer company internal IT services, done by an external contractor. Specifies the handling of such items as data transfer from prior releases, and the presence of software elements from prior releases. -->

### Usability

<!-- Describe items that will ensure the user-friendliness of the software. Examples include error messages that direct the user to a solution, input range checking as soon as entries are made, and order of choices and screens corresponding to user preferences. -->

## Additional Requirements

### User documentation

<!-- Describe the user documentation to be delivered with the software, including both hard copy and online requirements. -->

### Other requirements

<!-- Describe any other requirements not already covered above that need to be considered during the design of the software. -->

### Glossary

<!-- Define any terms that are specific to this document. -->

[^1]: REST API - Representational State Transfer Application Programming Interface [Source](https://en.wikipedia.org/wiki/Representational_state_transfer)
[^2]: C++ - A general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language, or "C with Classes". [Source](https://en.wikipedia.org/wiki/C%2B%2B)
[^3]: XML - Extensible Markup Language [Source](https://en.wikipedia.org/wiki/XML)
[^4]: JSON - JavaScript Object Notation [Source](https://en.wikipedia.org/wiki/JSON)
