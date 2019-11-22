# Custom OpenFaaS templates

Non-official templates for OpenFaaS.

Template list:
 - C
 - C++

## Usage

Clone or copy the `template` folder in a directory. From this root directory you can create a new template in the current folder (e.g. function with name `func`):

```
$ faas-cli new --lang c func --prefix="<your-docker-username>"
```
or
```
$ faas-cli new --lang cpp func --prefix="<your-docker-username>"
```

Build, push and deploy function:

```
$ faas-cli up -f func.yml
```
