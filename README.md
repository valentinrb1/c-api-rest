# C API RESTful using Ulfius

## Date - 2023

Basic web server that allows incrementing a counter and viewing its status through two endpoints. In addition, a client application is implemented to consume said endpoints.

### Authors:
- **Robledo, Valentín**

## Summary
In this project, a API REST is developed which has two requests available:
- POST: increments an internal counter for each call made.
- GET: returns the counter value.

The connection is made through an IPv4 socket which makes the requests. In addition, testing is performed using the curl command.

## How to clone this repository?
You can clone this repository to any directory you want using the following command:

```console
git clone https://github.com/valentinrb1/c-api-rest.git
```

## How to use?
First, we move to the project folder.

```console
cd c-api-rest
```

Inside the project directory we are going to create a folder called *build*.

```console
mkdir build
```

We move to that folder.
```console
cd build
```

We run the *cmake* command inside the *build* folder.
```console
cmake ..
```

We run the *make* command, to obtain the binary files that are saved inside the *bin* directory.
```console
make
```

Run API
```console
./bin/api
```

Run client
```console
./bin/client
```

---
## Operation
Within the client we can use two commands, *POST* and *GET*. To increase the internal API counter or to obtain its value, respectively.

On the API side, an instance is generated where both *endpoints* are created, one for *POST* and another for *GET*.

## Testing
To perform the testing, a *bash* file was used. One to perform *POST* tests and another to perform *GET* tests. Both use the *curl* command to make the requests.

To run the *POST* test file.
```console
./test_post.sh
```

To run the *GET* test file.
```console
./test_get.sh
```

Both in the *bash* directory.
