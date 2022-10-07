function Grace() {
    /*
        this is a comment
    */
    const fs = require('fs'); fs.writeFileSync('Grace_kid.js', Grace.toString() + "\nGrace();");
}
Grace();