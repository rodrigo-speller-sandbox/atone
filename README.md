<img src="logo.svg" width="128" alt="Atone" /> 

> Atone is a Linux init-like *process supervisor*.

Atone is a tool for defining, running and monitoring *single/multi*-service Linux containers processes.
With Atone, you can use a YAML file to configure your container's services. Then, with a single command,
you start all the services from your configuration.
To learn more about all the features of Atone, see the list of features.

## Features

* Orphan-zombie process reaping
* Services spawn
* Single-service mode
* Multi-service mode
* Automatic service restart
* Signal forwarding

### Future features

* Service schedule

# How to install and use

To install Atone, you must to download a specific version from the [releases page](https://github.com/rodrigo-speller/atone/releases).

Or execute the following command to install the latest version:

```sh
curl -sSL https://github.com/rodrigo-speller/atone/releases/download/latest/atone-install.sh | sh
```

A specific version can be installed by executing the following command:

```sh
# Replace the version number with the desired version tag
curl -sSL https://github.com/rodrigo-speller/atone/releases/download/v0.0.5/atone-install.sh | sh
```

## How to use

Atone is a process supervisor. That is, it is responsible for starting and monitoring processes. To assume this role,
Atone must be executed as the main process of the container (PID 1 - *At One* 😉). To do this, sets the *command* or
the *entrypoint* of your container to starts `atone`. For example, if you are using Docker, you can set the `CMD` or
`ENTRYPOINT` to `atone`.

Atone uses a YAML file to configure the services that needs to be started and monitored on the container. The default
configuration file is `/etc/atone.yaml`. But, you can set a custom configuration file by setting the `--config=<file>`
command argument on the `atone` command.

```dockerfile
CMD ["atone", "--config=/etc/atone.yaml"]
```

You can also use the `--` argument to pass a single command to be executed by Atone. This is useful when you want to use
Atone as a *process supervisor* for a single service on the container. For example, if you want to use Atone to start
and monitor the `nginx` service, you can set the `CMD` or `ENTRYPOINT` to `atone` and pass the `nginx` command to be
executed by Atone.

```dockerfile
CMD ["atone" , "--", "nginx", "-g", "daemon off;"]
```

Execute `atone --help` to see all the available command arguments.

## Sample configuration file

```yaml
# Define the global settings for the container.
settings:
  # Set the working directory for the atone.
  workdir: /srv

# Define the services to be started and monitored by Atone.
services:

  # An example of a service that sleeps forever.
  sleeping-svc:
    # Set the command to be executed by the service.
    command: sleep infinity
    # Set the restart policy to restart the service.
    # Possible values: no, always, on-failure, unless-stopped.
    restart: always

  # An example of a service that sleeps for 5 seconds.
  five-seconds-svc:
    command: /bin/sh -c "echo 'Service 1'; sleep 5"
    restart: always

  # An example of a service that sleeps for 10 seconds.
  ten-seconds-svc:
    command: /bin/sh -c "echo 'Service 2'; sleep 10"
    restart: always
```

# How to code, build, run and debug

Atone project is written in C++ and uses the [Makefile](https://www.gnu.org/software/make/) build system. This project
is configured to be developed with [VS Code](https://code.visualstudio.com/) with
[C/C++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools). But you can use any other IDE
or text editor.

## How to build

Before building Atone, you need to install the following packages to build the project on your system:

### Debian/Ubuntu prerequisites

Install the following packages:

```sh
sudo apt install build-essential gdb
```

> Note: `gdb` is optional, but it is recommended to debug the program.

### Another Linux distributions prerequisites

On other Linux distributions, you need to install the following packages:

- GNU C Compiler (GCC)
- GNU C++ Compiler (G++)
- GNU Make

> If you want to contribute to the project, you can update this document, suggesting the packages to be installed in
your distribution via pull request.

## Build

Atone uses the [Makefile](https://www.gnu.org/software/make/) build system. To build the project, run the following
command with, optionally, the desired make flags:

```sh
make
```

Optional make flags:

* `DEBUG=1`: Enable debug symbols.
* `VERBOSE=1`: Enable verbose output.

## Run and debug

This project is configured to be developed with [VS Code](https://code.visualstudio.com/) by default. To run and debug
the project, you need to install the [C/C++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
and open the project folder in VS Code. After that, you can run and debug the project using the VS Code debugger normally.

# Bug Reports
If you find any bugs, please report them using the GitHub issue tracker.

# License
This software is distributed under the terms of the MIT license
(see [LICENSE.txt](LICENSE.txt)).
