## Project Overview

This project, named "Selkies," is a high-performance, low-latency WebRTC streaming platform for Linux desktops. It's designed for a variety of use cases, including AI research, high-performance computing (HPC), and cloud gaming. The core of the application is written in Python and utilizes GStreamer for video and audio streaming. The frontend is a web application served by NGINX. The entire application is designed to be run in a containerized environment using Docker.

The project is composed of several components:

*   **`selkies`**: The core Python application that handles WebRTC, input, and streaming.
*   **`gst-web`**: The web frontend, built with HTML, CSS, and JavaScript, and served by NGINX.
*   **`example`**: An example implementation that brings all the components together in a runnable Docker container.
*   **Addons**: Various other components, such as a TURN server, a dashboard, and a joystick interposer.

## Building and Running

The project is built and run using Docker and Docker Compose. The `docker-compose.yml` file defines the services and their configurations.

To build the entire project, you can run:

```bash
docker-compose build
```

This will build the `dist`, `web`, and `test` services. The `test` service is the main service for running the application.

To run the application, you can use the following command:

```bash
docker-compose run test
```

This will start the `test` service, which includes the Selkies Python application, the web frontend, and all the necessary dependencies. The application will be accessible at `http://localhost:8080`.

The `docker-compose.yml` file also defines a number of environment variables that can be used to configure the application. For example, you can enable basic authentication by setting the `SELKIES_ENABLE_BASIC_AUTH`, `SELKIES_BASIC_AUTH_USER`, and `SELKIES_BASIC_AUTH_PASSWORD` environment variables.

## Development Conventions

The project uses `setuptools` for Python packaging and `pip` for dependency management. The Python code is located in the `src/selkies` directory. The frontend code is located in the `addons/gst-web` directory.

The project uses `supervisord` to manage the processes within the `test` container. The `supervisord.conf` file in the `addons/example` directory defines the processes that are started when the container is run.

The project is designed to be extensible, with a number of addons that provide additional functionality. These addons are located in the `addons` directory. Each addon is a self-contained component that can be enabled or disabled as needed.
