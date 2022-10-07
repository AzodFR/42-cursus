function Sully(i) {
    const fs = require('fs');
    fs.writeFileSync('Sully_' + i + '.js', Sully.toString() +"\n" + main.toString() + "\nmain(" + (i) + ");");
    const exec = require('child_process').exec;
    if (i > 0) {
        exec('node Sully_' + i + '.js');
    }
}
function main(i) {
    Sully(--i)
}
main(5);