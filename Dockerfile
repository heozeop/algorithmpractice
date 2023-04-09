FROM rust:1.67

# These commands copy your files into the specified directory in the image
# and set that as the working location
COPY ./sites /usr/src/myapp
WORKDIR /usr/src/myapp

RUN cargo install --path .

CMD ["cargo", "run"]
