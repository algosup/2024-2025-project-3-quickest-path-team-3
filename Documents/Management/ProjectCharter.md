# Project Charter

## Project Title
Quickest Path Finder

## Project Description
The goal of this project is to develop a high-performance software solution that computes the quickest path between two landmarks in the United States. This solution will be implemented in C++ and accessed via a REST API with specific input-output formats. The software must handle a dataset with approximately 24 million nodes and ensure results within 1 second of response time on an average laptop.

## Project Objectives
- Develop a REST API in C++ to compute the quickest path between two landmarks.
- Ensure the API can handle a dataset with approximately 24 million nodes.
- Achieve response times of under 1 second on an average laptop.
- Support user-selectable response formats (XML and JSON).
- Implement robust error handling and data validation.

## Scope
**In Scope:**
- Development of the REST API in C++.
- Implementation of pathfinding algorithms.
- Data validation and error handling.
- Support for XML and JSON response formats.
- Performance optimization to meet response time requirements.

**Out of Scope:**
- Development of a graphical user interface (GUI).
- Integration with external software systems beyond common API testing tools.
- User authentication and authorization mechanisms.

## RACI Matrix
| Task | Project Manager |Program Manager| Technical Lead | Software Engineer | Quality Assurance | Technical Writer |
|------|-----------------|----------------|------------|-------------------|-------------------|------------------|
| Project Planning | 🔴 | 🟡 | 🟢 | 🟢 | 🟡 | 🟢|
| Functional Specification & User Manual | 🟠 | 🔴 | 🟢 | 🟢 | 🟡 |🔴|
| Technical Specification | 🟠 | 🟡 | 🔴 | 🟢| 🟡 |🟢|
| Code | 🟠 | 🟡 | 🟡 | 🔴 | 🟡 |🟢|
| Testing and Validation | 🟠 | 🟢 | 🟡 | 🟠 | 🔴 |🟢|
| Final Delivery | 🔴 | 🔴 | 🔴 | 🔴 | 🔴 |🔴|

- 🔴: **Responsible**
- 🟠: **Accountable**
- 🟡: **Consulted**
- 🟢: **Informed**



## Deliverables
- REST API source code and documentation.
- Functional and technical specifications.
- User manual and installation instructions.
- Test plan and test results.
- Weekly progress reports.

## Milestones
- Milestone 1: Project Kickoff - 01/10
- Milestone 2: Functional Specification Completion - 01/17
- Milestone 3: Technical Specification Completion - 01/24
- Milestone 4: API Development Completion - 01/31
- Milestone 5: Testing and Validation - 01/31
- Milestone 6: Final Delivery - 02/07

## Timeline
- Project Kickoff: 01/06
- Functional Specification: 01/11 - 01/17
- Technical Specification: 01/18 - 01/24
- API Development: 01/25 - 01/31
- Testing and Validation: 01/25 - 01/31
- Final Delivery: 02/07


## Stakeholders
- School: ALGOSUP
- Team Members: Alexis LASSELIN, Mathis PASCUCCI, Vivien Bistrel TSANGUE CHOUNGOU, Vianney POLARD, Lucas AUBARD, Julian REINE
- Project Manager: Salaheddine NAMIR
- Programe Manager: Alexis LASSELIN
- Software Engineer : Vivien Bistrel TSANGUE CHOUNGOU
- Software Engineer : Vianney POLARD
- Quality assurance : Lucas AUBARD
- Technical Writer : Julian REINE
- Technical Lead : Mathis PASCUCCI

## Risks and Assumptions
**Risks:**
- Delays in dataset availability.
- Performance issues with large datasets.
- Unforeseen technical challenges.

**Assumptions:**
- The dataset will be provided in a CSV file format.
- Users will interact with the system using standard REST API clients.
- Performance benchmarks are based on an average laptop.


