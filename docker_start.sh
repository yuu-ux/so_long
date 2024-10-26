docker run --rm -it -e DISPLAY=docker.for.mac.host.internal:0 -v $(pwd):/so_long -v /tmp/.X11-unix:/tmp/.X11-unix so_long2 bash
