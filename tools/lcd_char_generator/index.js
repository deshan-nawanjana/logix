window.addEventListener('load', () => {
    let tray = document.querySelector('#tray')
    for(i = 0; i < 40; i++) {
        tray.innerHTML += `<div class="dot" onclick="update(event)"></div>`
    }
    generate()
})

let update = e => {
    e = e.target
    let k = e.hasAttribute('lang') ? parseInt(e.lang) : 0
    e.lang = 1 - k
    generate()
}

let generate = () => {
    let x = `byte sample_char[] = {`
    Array.from(document.querySelectorAll('.dot')).forEach((e, i) => {
        if(i % 5 == 0 && i != 0) { x += `,\n\tB` }
        if(i % 5 == 0 && i == 0) { x += `\n\tB` }
        x += e.lang == 1 ? '1' : '0'
    })
    x += `\n};\n\n`
    document.querySelector('textarea').value = x
}