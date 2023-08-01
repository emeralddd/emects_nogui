const { execFileSync } = require('child_process');
const { mkdirSync, readdirSync, renameSync, rmSync } = require('fs');

const compile = (sourcePath, executePath) => {
    execFileSync('g++', ['-g', '-std=c++14', sourcePath, '-o', executePath]);
}

const compileTestGen = async () => {
    compile('./code/inp.cpp', './debug/inp.exe');
    compile('./code/out.cpp', './debug/out.exe');
}

const numberTo3Char = (n) => {
    let str = String(n);
    while (str.length !== 3) str = "0" + str;
    return str;
}

const run = async () => {
    console.log(`Compiling files ...`);
    await compileTestGen();
    console.log(`OK!`);

    rmSync('./tests', { recursive: true, force: true });
    mkdirSync('./tests');

    const tests = 50;

    for (let i = 1; i <= tests; i++) {
        console.log(`Creating test ${i} ...`);

        execFileSync('inp.exe', [String(i)], { "cwd": "debug" });
        execFileSync('out.exe', { "cwd": "debug" });

        mkdirSync(`./tests/test${numberTo3Char(i)}`);

        let files = readdirSync(`./debug`);

        for (const file of files) {
            if (file.endsWith('.INP') || file.endsWith('.OUT')) {
                renameSync(`./debug/${file}`, `./tests/test${numberTo3Char(i)}/${file}`);
            }
        }
    }

    console.log(`OK!!`);
}

run();
