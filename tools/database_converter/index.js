let generate = data => {
    
    let dat = data.series
    let obj = data.iclist
    let len = Object.keys(obj).length

    let out = `#define SERIES_${data.series.code}_COUNT ${len}\n\n`

    console.clear();

    // tables
    Object.keys(obj).forEach(code => {
        console.warn(code)
        let ic = obj[code]
        out += `int T_${code}[] = { `
        // each row
        obj[code].table.forEach((line, n) => {
            let str = ``
            Array.from(line).forEach((char, i) => {
                let exc = [' ', 'G', 'V', 'X', 'Z']
                if(exc.indexOf(char) == -1) {
                    if(char === '0') { str += '0' }
                    if(char === '1') { str += '1' }
                    if(char === 'N') {
                        if(n === 0) { str += '1' }
                        if(n !== 0) { str += '0' }
                    }
                    if(char === 'I') { str += '1' }
                    if(char === 'O') { str += '0' }
                }
            })
            console.log(n, str)
            out += parseInt(str, 2);
            out += ', '
        })
        out = out.substr(0, out.length - 2)
        out += `, -1 };\n`
    })

    out += `\n`

    // images
    Object.keys(obj).forEach(code => {
        let ic = obj[code]
        out += `int I_${code}[] = { `
        // each row
        let n1 = ''
        let n2 = ''
        let n3 = ''
        let n4 = ''
        let n5 = ''
        let n6 = ''
        let n7 = ''
        let n8 = ''
        Array.from(obj[code].image[0] + obj[code].image[1]).forEach((d, k) => {
            let char = ''
            if(d === ' ') { char = '0' }
            if(d === '*') { char = '0' }

            if(d === '-') { char = '1' }
            if(d === '=') { char = '2' }
            if(d === '3') { char = '3' }
            if(d === '4') { char = '4' }
            if(d === '!') { char = '5' }
            
            if(d === 'A') { char = '6' }
            if(d === 'O') { char = '7' }
            if(d === 'N') { char = '8' }
            if(d === 'X') { char = '9' }

            if(k < 4) { n1 += char }
            if(k > 3 && k < 8) { n2 += char }
            if(k > 7 && k < 12) { n3 += char }
            if(k > 11 && k < 16) { n4 += char }
            if(k > 15 && k < 20) { n5 += char }
            if(k > 19 && k < 24) { n6 += char }
            if(k > 23 && k < 28) { n7 += char }
            if(k > 27 && k < 32) { n8 += char }
        })
        
        out += parseInt(n1) + ', '
        out += parseInt(n2) + ', '
        out += parseInt(n3) + ', '
        out += parseInt(n4) + ', '
        out += parseInt(n5) + ', '
        out += parseInt(n6) + ', '
        out += parseInt(n7) + ', '
        out += parseInt(n8)

        out += ` };\n`
    })

    out += `\n`

    // gates
    Object.keys(obj).forEach(code => {
        console.warn(code)
        let ic = obj[code]
        out += `int G_${code}[] = { `
        // each row
        obj[code].gates.reverse().forEach((line, i) => {
            //console.log(line)

            let arr = i == 0
                ? Array.from(line)
                : Array.from(line).reverse()

            let str = ``
            arr.forEach(e => {
                if(e === 'V') { return; }
                if(e === 'G') { return; }
                if(e === 'N') { str += '1'; return; }
                else {
                    str += (parseInt(e) + 1).toString()
                }
            })

            if(i === 0) {
                out += str.substr(0, 3) + ', ' + str.substr(3) + ', '
            } else {
                out += str.substr(0, 3) + ', ' + str.substr(3)
            }
        })
        out += ` };\n`
    })

    out += `\nIC SERIES_${data.series.code}[] = {\n`

    Object.keys(obj).forEach(code => {
        let ic = obj[code]
        out += '\t{'
        out += ` "${code}", I_${code}, T_${code}, G_${code}`
        out += ' },\n'
    })

    out = out.substr(0, out.length - 2)

    out += '\n};'

    document.querySelector('textarea').value = out

    return
}

let loadFile = input => {
    if(input.files.length === 0) { return }
    let reader = new FileReader();
    reader.onload = () => {
        generate(JSON.parse(reader.result))
    }
    reader.readAsText(input.files[0])
}