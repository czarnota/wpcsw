#!/usr/bin/env bash

read -rd '' STYLE <<'EOF'
<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>$title$</title>
    <style>
    html { -moz-text-size-adjust: none; -webkit-text-size-adjust: none; text-size-adjust: none; }
    * { box-sizing: border-box; }
    .level2, h1 { max-height: 92vh; margin: 1em auto; background: #fff;
                  font-size: 12px; aspect-ratio: 16 / 9; padding: 1.5em;
                  display: flex; flex-direction: column; overflow: hidden;
                  flex: 1 1 auto; box-shadow: 0 0 0.5em #ddd; color: #333; }
    h1 { align-items: center; flex-direction: row; padding: 0.75em; margin: 0.5em auto;}
    body { margin: 0; padding: 0; font-family: sans-serif;
           background: rgb(237, 237, 240); font-size: 200px; }
    h2 { font-size: 2em; color: #005; padding: 0; }
    img { display: block; margin: auto; width: 100%; height: 100%;
          overflow: hidden; object-fit: contain;}
    section > p, section > ul { line-height: 1.5em; }
    ul { padding-left: 1em; }
    h2 { margin: 0 0 0.4em 0; }

    @page { size: 16in 9in; margin: 0; }
    @media print {
        body { -webkit-print-color-adjust: exact; }
        .level2, h1 { max-height: 100vh; margin: 0; }
    }

    .language-console .gp { color: #6ec071; }

    /*

        Name:       Base16 Tomorrow Dark
        Author:     Chris Kempson (http://chriskempson.com)

        Pygments template by Jan T. Sott (https://github.com/idleberg)
        Created with Base16 Builder by Chris Kempson (https://github.com/chriskempson/base16-builder)

    */
    .sourceCode .hll { background-color: #373b41; }
    .sourceCode { background: #1d1f21; color: #ffffff; }
    .sourceCode .co { color: #969896; } /* Comment */
    .sourceCode .err { color: #cc6666; }

    /* Error */
    .sourceCode .kw { color: #b294bb; } /* Keyword */
    .sourceCode .cf { color: #b294bb; } /* Keyword */
    .sourceCode .l { color: #de935f; }

    /* Literal */
    .sourceCode .n { color: #ffffff; }

    /* Name */
    .sourceCode .ot { color: #8abeb7; } /* Operator */
    .sourceCode .op { color: #8abeb7; } /* Operator */
    .sourceCode .p { color: #ffffff; }

    /* Punctuation */
    .sourceCode .cm { color: #969896; }

    /* Comment.Multiline */
    .sourceCode .pp { color: #69AE69; } /* Comment.Preproc */
    .sourceCode .im { color: #69AE69; } /* Comment.Preproc */
    .sourceCode .c1 { color: #969896; }

    /* Comment.Single */
    .sourceCode .cs { color: #969896; }

    /* Comment.Special */
    .sourceCode .gd { color: #cc6666; }

    /* Generic.Deleted */
    .sourceCode .ge { font-style: italic; }

    /* Generic.Emph */
    .sourceCode .gh { color: #ffffff; font-weight: bold; }

    /* Generic.Heading */
    .sourceCode .gi { color: #b5bd68; }

    /* Generic.Inserted */
    .sourceCode .gp { color: #969896; font-weight: bold; }

    /* Generic.Prompt */
    .sourceCode .gs { font-weight: bold; } 
    /* Generic.Strong */
    .sourceCode .gu { color: #8abeb7; font-weight: bold; }

    /* Generic.Subheading */
    .sourceCode .kc { color: #b294bb; }

    /* Keyword.Constant */
    .sourceCode .kd { color: #b294bb; }

    /* Keyword.Declaration */
    .sourceCode .kn { color: #8abeb7; }

    /* Keyword.Namespace */
    .sourceCode .kp { color: #b294bb; }

    /* Keyword.Pseudo */
    .sourceCode .kr { color: #b294bb; }

    /* Keyword.Reserved */
    .sourceCode .dt { color: #f0c674; } /* Keyword.Type */
    .sourceCode .ld { color: #b5bd68; }

    /* Literal.Date */
    .sourceCode .m { color: #de935f; }

    /* Literal.Number */
    .sourceCode .s { color: #b5bd68; }

    /* Literal.String */
    .sourceCode .na { color: #81a2be; }

    /* Name.Attribute */
    .sourceCode .bu { color: #ffffff; } /* Name.Builtin */
    .sourceCode .nc { color: #f0c674; }

    /* Name.Class */
    .sourceCode .no { color: #cc6666; }

    /* Name.Constant */
    .sourceCode .nd { color: #8abeb7; }

    /* Name.Decorator */
    .sourceCode .ni { color: #ffffff; }

    /* Name.Entity */
    .sourceCode .ne { color: #cc6666; }

    /* Name.Exception */
    .sourceCode .fu { color: #81a2be; } /* Name.Function */

    /* Name.Label */
    .sourceCode .nn { color: #f0c674; }

    /* Name.Namespace */
    .sourceCode .nx { color: #81a2be; }

    /* Name.Other */
    .sourceCode .py { color: #ffffff; }

    /* Name.Property */
    .sourceCode .nt { color: #8abeb7; }

    /* Name.Tag */
    .sourceCode .va { color: #cc6666; } /* Name.Variable */
    .sourceCode .ow { color: #8abeb7; }

    /* Operator.Word */
    .sourceCode .w { color: #ffffff; }

    /* Text.Whitespace */
    .sourceCode .mf { color: #de935f; }

    /* Literal.Number.Float */
    .sourceCode .mh { color: #de935f; }

    /* Literal.Number.Hex */
    .sourceCode .dv { color: #de935f; }

    /* Literal.Number.Integer */
    .sourceCode .mo { color: #de935f; }

    /* Literal.Number.Oct */
    .sourceCode .sb { color: #b5bd68; }

    /* Literal.String.Backtick */
    .sourceCode .sc { color: #ffffff; }

    /* Literal.String.Char */
    .sourceCode .sd { color: #969896; }

    /* x Literal.String.Doc */
    .sourceCode .st { color: #b5bd68; }

    /* Literal.String.Double */
    .sourceCode .sc { color: #de935f; } 
    /* Literal.String.Escape */
    .sourceCode .sh { color: #b5bd68; }

    /* Literal.String.Heredoc */
    .sourceCode .si { color: #de935f; }

    /* Literal.String.Interpol */
    .sourceCode .sx { color: #b5bd68; }

    /* Literal.String.Other */
    .sourceCode .sr { color: #b5bd68; }

    /* Literal.String.Regex */
    .sourceCode .s1 { color: #b5bd68; }

    /* Literal.String.Single */
    .sourceCode .ss { color: #b5bd68; }

    /* Literal.String.Symbol */
    .sourceCode .bp { color: #ffffff; }

    /* Name.Builtin.Pseudo */
    .sourceCode .vc { color: #cc6666; }

    /* Name.Variable.Class */
    .sourceCode .vg { color: #cc6666; }

    /* Name.Variable.Global */
    .sourceCode .vi { color: #cc6666; }

    /* Name.Variable.Instance */
    .sourceCode .il { color: #de935f; }

    /* Literal.Number.Integer.Long */

    div.sourceCode { vertical-align: top; }

    pre { font-family: monospace; font-size: 0.8em; }

    .sourceCode a { color: #fff }

    .sourceCode pre { padding: 0; margin: 0; }

    pre code { display: block; padding: 1em 1.25em; overflow-x: auto; background: #1d1f21; color: #ffffff; }

    .sourceCode pre code::-webkit-scrollbar { -webkit-appearance: none; }
    .sourceCode pre code::-webkit-scrollbar:vertical { width: 10px; }
    .sourceCode pre code::-webkit-scrollbar:horizontal { height: 10px; }
    .sourceCode pre code::-webkit-scrollbar-thumb { background-color: #555; }
    .sourceCode pre code::-webkit-scrollbar-track { background-color: #333; }
    .sourceCode::selection { background: #fff; /* WebKit/Blink Browsers */ color: #000; }
    .sourceCode::-moz-selection { background: #fff; /* Gecko Browsers */ color: #000; }
    p > code, li > code { background: #fff; padding: 0.1em 0.2em; box-shadow: 0 2px 4px 0 #ddd; border: 1px solid #ddd; }

    div.sourceCode, pre, section > p, section > ul { margin: 0 0 0.7em 0; }

    </style>
    <link rel="stylesheet" href="assets/styles.css" />
  </head>
  <body>
$body$
  <script>
    /*!	
    * FitText.js 1.0 jQuery free version
    *
    * Copyright 2011, Dave Rupert http://daverupert.com 
    * Released under the WTFPL license 
    * http://sam.zoy.org/wtfpl/
    * Modified by Slawomir Kolodziej http://slawekk.info
    *
    * Date: Tue Aug 09 2011 10:45:54 GMT+0200 (CEST)
    */
    (function(){

      var addEvent = function (el, type, fn) {
        if (el.addEventListener)
          el.addEventListener(type, fn, false);
            else
                el.attachEvent('on'+type, fn);
      };
      
      var extend = function(obj,ext){
        for(var key in ext)
          if(ext.hasOwnProperty(key))
            obj[key] = ext[key];
        return obj;
      };

      window.fitText = function (el, kompressor, options) {

        var settings = extend({
          'minFontSize' : -1/0,
          'maxFontSize' : 1/0
        },options);

        var fit = function (el) {
          var compressor = kompressor || 1;

          var resizer = function () {
            el.style.fontSize = Math.max(Math.min(el.clientWidth / (compressor*10), parseFloat(settings.maxFontSize)), parseFloat(settings.minFontSize)) + 'px';
          };

          // Call once to set.
          resizer();

          // Bind events
          // If you have any js library which support Events, replace this part
          // and remove addEvent function (or use original jQuery version)
          addEvent(window, 'resize', resizer);
          addEvent(window, 'orientationchange', resizer);
        };

        if (el.length)
          for(var i=0; i<el.length; i++)
            fit(el[i]);
        else
          fit(el);

        // return set of elements
        return el;
      };
    })();

    fitText(document.querySelectorAll('.level2'), 5);
    fitText(document.querySelectorAll('h1'), 2.5);

    document.querySelectorAll('p > img').forEach(e => e.parentNode.style.overflow="hidden");

  </script>
  </body>
</html>
EOF

main () {
    local document="$1"; shift || return
    local out="$1"; shift || return

    local template_file="${document//.md/.template.html}"

    echo "$STYLE" > $template_file

    pandoc --metadata title=presentation \
           --section-divs \
           --template $template_file \
           -i "$document" \
           -t html \
           -o "$out"

    local ret="$?"

    rm $template_file

    return $ret
}

declare -A COMMANDS=(
    [main]=main
)

argparse () {
    ${COMMANDS[${1-main}]-${COMMANDS[main]}} "$@"
}

argparse "$@"
