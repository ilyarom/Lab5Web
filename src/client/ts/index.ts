const button: HTMLInputElement = document.getElementById("send") as HTMLInputElement;
const state: HTMLInputElement = document.getElementById("myonoffswitch") as HTMLInputElement;
const files: HTMLElement = document.getElementById("files");

function get(): void {
    const file: HTMLInputElement = document.getElementById("input") as HTMLInputElement;
    const fileName: string = file.value;
    const request: XMLHttpRequest = new XMLHttpRequest();
    const regex = /(?:\.([^.]+))?$/;
    const extension = regex.exec(fileName)[1];
    if (extension !== "txt" && extension !== "html" && extension !== "css" && extension !== "js") {
        request.responseType = "blob";
    }
    request.open("GET", encodeURI(fileName));
    request.send();
    request.onreadystatechange = (): void => {
        if (4 === request.readyState) {
            if (200 === request.status) {
                window.open(document.URL + file.value, "_blank");
            } else {
                alert(request.status + request.statusText);
            }
        }
    };
}

function drop(): void {
    const file: HTMLInputElement = document.getElementById("input") as HTMLInputElement;
    const fileName: string = file.value;
    const request: XMLHttpRequest = new XMLHttpRequest();
    request.open("DELETE", encodeURI(fileName));
    request.send();
    request.onreadystatechange = (): void => {
        if (request.readyState === 4) {
            if (request.status === 200) {
              getFiles();
            }
            alert(request.responseText);
        }
    };
}

function getFiles(): void {
    const request: XMLHttpRequest = new XMLHttpRequest();
    request.onreadystatechange = (): void => {
        if (request.readyState === 4 && request.status === 200) {
            const filesOnHost: any = JSON.parse(request.responseText);
            while (files.firstChild) {
                files.removeChild(files.firstChild);
            }
            for (const file in filesOnHost.elements) {
                if (filesOnHost.elements.hasOwnProperty(file)) {
                    const element: HTMLElement = document.createElement("li");
                    element.id = "element";
                    element.innerHTML = filesOnHost.elements[file];
                    files.appendChild(element);
                }
            }
        }
    };
    request.open("GET", "/files");
    request.send();
}

button.onclick = (): void => {
    if (state.value === "on") {
        get();
    } else {
        drop();
    }
};

state.onclick = (): void => {
    if (state.value === "on") {
        state.value = "off";
    } else {
        state.value = "on";
    }
};

window.onload = (): void => {
    getFiles();
};
