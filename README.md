# 2024 2025 - Project 3 Quickest Path - Team 3

## Team Members

| Picture                                                                                                        | Name                            | Role                              | GitHub                                                                                                                                    | LinkedIn                                                                                                                                                               |
| -------------------------------------------------------------------------------------------------------------- | ------------------------------- | --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| ![Salaheddine Namir](https://gravatar.com/avatar/fbb2631ed2b14d85006ea91fcf223680?size=128&d=mp)               | Salaheddine NAMIR               | Project Manager                   | [![GitHub](https://img.shields.io/badge/-GitHub-181717?logo=github&logoColor=white&style=flat-square)](https://github.com/T3rryc)         | [![LinkedIn](https://img.shields.io/badge/-LinkedIn-0077B5?logo=linkedin&logoColor=white&style=flat-square)](https://www.linkedin.com/in/salaheddine-namir-3402471b8/) |
| ![Alexis Lasselin](https://gravatar.com/avatar/00cd520ab1f478b76618fa55b56bc72f?size=128&d=mp)                 | Alexis LASSELIN                 | Program Manager/ Technical Leader | [![GitHub](https://img.shields.io/badge/-GitHub-181717?logo=github&logoColor=white&style=flat-square)](https://github.com/AlexisLasselin) | [![LinkedIn](https://img.shields.io/badge/-LinkedIn-0077B5?logo=linkedin&logoColor=white&style=flat-square)](https://www.linkedin.com/in/alexis-lasselin-318649251/)   |
| ![Vivien Bistrel Tsangue Choungou](https://gravatar.com/avatar/034e0d2085c38307d45a776165c8654d?size=128&d=mp) | Vivien Bistrel TSANGUE CHOUNGOU | Software Engineer                 | [![GitHub](https://img.shields.io/badge/-GitHub-181717?logo=github&logoColor=white&style=flat-square)](https://github.com/username4)      | [![LinkedIn](https://img.shields.io/badge/-LinkedIn-0077B5?logo=linkedin&logoColor=white&style=flat-square)](https://www.linkedin.com/in/bistrel-tsangue-603635261/)   |
| ![Vianney Polard](https://gravatar.com/avatar/8b5be17c773ca464680bcd6c5f42e2a8?size=128&d=mp)                  | Vianney POLARD                  | Software Engineer                 | [![GitHub](https://img.shields.io/badge/-GitHub-181717?logo=github&logoColor=white&style=flat-square)](https://github.com/4tinley)        | [![LinkedIn](https://img.shields.io/badge/-LinkedIn-0077B5?logo=linkedin&logoColor=white&style=flat-square)](https://www.linkedin.com/in/vianney-polard-44173a273/)    |
| ![Lucas Aubard](https://gravatar.com/avatar/dc3a8fc938e413abe9fb0053201896e7?size=128&d=mp)                    | Lucas AUBARD                    | Quality Assurance                 | [![GitHub](https://img.shields.io/badge/-GitHub-181717?logo=github&logoColor=white&style=flat-square)](https://github.com/Bistrel2002)    | [![LinkedIn](https://img.shields.io/badge/-LinkedIn-0077B5?logo=linkedin&logoColor=white&style=flat-square)](https://www.linkedin.com/in/lucas-aubard-596b37251/)      |
| ![Julian Reine](https://gravatar.com/avatar/bd28440bd4dc860f6c141b7529c0aaee?size=128&d=mp)                    | Julian REINE                    | Technical Writer                  | [![GitHub](https://img.shields.io/badge/-GitHub-181717?logo=github&logoColor=white&style=flat-square)](https://github.com/JulianREINE)    | [![LinkedIn](https://img.shields.io/badge/-LinkedIn-0077B5?logo=linkedin&logoColor=white&style=flat-square)](https://www.linkedin.com/in/julian-reine-b2952632a/)      |

## Project Description

The goal of this project, the third of the scholar year, is to develop a high-performance software solution that computes the quickest path between two landmarks in the United States. This solution must be implemented in C++ and accessed via a REST API with specific input-output formats.

## Project Structure

The project is divided into several directories, each containing a specific part of the project:

- `Documents/`: Contains all the documents related to the project (Specifications, Reports, etc.);
- `QuickPath/Src/`: Contains the source code of the project;

## How to build and run the project

> [!WARNING]
> The project needs CMake to be built. If you don't have it installed, you can download it [here](https://cmake.org/download/).

First, clone the repository by downloading the ZIP file once you click on the green "Code" button.

Extract it and put the `.csv` file in the `QuickPath/` directory.

Then, you open a terminal and navigate to the `QuickPath/` directory.

```bash
mkdir -p build && cd build
cmake ..
make
./QuickPath
```

The server will start and you can now access the API at `http://localhost:18080/`.

## How to use the API

We advise you to use [Postman](https://www.postman.com/) to test the API.

### Get the quickest path between two landmarks

To get the quickest path between two landmarks, you need to send a `GET` request to the `/path` endpoint with the following parameters:

- `source`: The name of the source landmark;
- `destination`: The name of the destination landmark.
- `format`: The format of the response. Can be `json` or `xml`. If not specified, the default format is `json`.

Here is an example of a request:

```postman
http://localhost:18080/quickestpath?source={source}&destination={destination}(&format={format})
```

The result will then be displayed in the format you specified.
