### Laboratorio 5 - Sistemas Operativos II
## Ingeniería en Computación - FCEFyN - UNC - 2023
# Embedded Systems

## Introduction
Embedded systems are often accessed remotely. There are different techniques to do so, one widely used way is the RESTful APIs. These provide a defined and robust interface for remote communication and manipulation of the embedded system. Defined for a Client-Server scheme, they are used in all verticals of the technology industry, from IoT applications to multiplayer games.

## Objective
The objective of this practical work is for the student to have an end-to-end view of a basic implementation of a RESTful API on an embedded system.
The student must implement it by interacting with all layers of the process, from functional testing (high level) to the C code of the service (low level).

### Development
In this first stage, it is requested that a framework that exposes a [REST API](https://en.wikipedia.org/wiki/Representational_state_transfer) be implemented: it is proposed to use [ulfius][ulfi]. The student can select another one, justifying the selection, or implement his/her own (not recommended).

It is requested that the following endpoints be implemented:
- `POST: http://localhost:8537/increment`: Increments an internal counter
- `GET: http://localhost:8537/imprimir`: Returns the value of the counter

The IPv4 client of Laboratory 2 must be used and adapted to send requests to both endpoints of the REST API. The [curl](https://curl.se/docs/manpage.html) command can also be used.

The system validation must be done by creating at least 100 processes that interact with the created endpoints.

## Delivery
The source files must be provided, as well as any other files associated with the compilation, CMAKE project files and the correctly documented code, all in the repository, where the Student must demonstrate progress week by week through _commits_.

A report must also be delivered, a _How to_ type guide, explaining step by step what was done (it can be a _Markdown_). The report must also contain the design of the solution with a detailed explanation of it. It must be assumed that the compilation tests will be carried out on a computer that has the typical console tools for developing programs (Example: gcc, make), and does NOT have "GUI" tools for compiling them (Example: eclipse).

### Correction Criteria
- The code must be compiled with the compilation flags:
`-Wall -Pedantic -Werror -Wextra -Wconversion -std=gnu11`
- Correct memory management.
- Divide the code into modules judiciously.
- Code style.
- Error handling
- The code must not contain errors or warnings.
- The code must not contain cppcheck errors.

## Evaluation
This practical work is individual and must be submitted before Friday, May 12, 2023 at 4:55 p.m. through the LEV. It will be corrected and then a date must be scheduled for the oral defense of it.

## References and help
- [Ulfius HTTP Framework](https://github.com/babelouest/ulfius)

[ulfi]: https://github.com/babelouest/ulfius
