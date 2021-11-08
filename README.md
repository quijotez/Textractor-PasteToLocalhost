# Intended usage
I sometimes play VNs on my TV and looking up unknown words is annoying to write on a smartphone, so I made this to simply copy and paste them instead.

# How to install & use

1. Download [Textractor](https://github.com/Artikash/Textractor)
2. Download [node.js](https://nodejs.org/en/download/)
3. Download the [latest release](https://github.com/quijotez/Textractor-PasteToLocalhost/releases/latest) and drop it into the main Textractor folder (if there are issues you can try and build it)

![1](/pictures/1.png)

4. Load the extension in Textractor

![2](/pictures/2.png)

5. Run `app.js` (go to the `node` folder and type: ```node app.js```)

![3](/pictures/3.png)

You should be able to see the page under localhost:3000.
If you want to see the page from other device than the one you're running it on, use your private IP (For example 192.168.1.3:3000)

There's also a better way to code this (using Qt5 Network instead of Node.js), so you might try and do that
