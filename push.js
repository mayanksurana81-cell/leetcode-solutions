const { execSync } = require("child_process");
const readline = require("readline");

let message = process.argv[2];

if (!message) {
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });

    rl.question("Enter commit message: ", (msg) => {
        runGit(msg);
        rl.close();
    });
} else {
    runGit(message);
}

function runGit(msg) {
    try {
        console.log("Adding files...");
        execSync("git add .", { stdio: "inherit" });

        console.log("Committing...");
        execSync(`git commit -m "${msg}"`, { stdio: "inherit" });

        console.log("Pushing...");
        execSync("git push", { stdio: "inherit" });

        console.log("✅ Done!");
    } catch (error) {
        console.error("❌ Error:", error.message);
    }
}