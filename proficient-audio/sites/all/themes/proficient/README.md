# Theme Development Notes

## Working with Grunt
See Grunt's website to learn more about the Grunt task runner. http://gruntjs.com/

Folder structure for Grunt tasks:

css/      : Processed SASS files automatically saved in this directory. 
            Use the file from this directory in theme INFO file.
styles/   : All custom SASS files should be kept in this directory. Any assets 
            from bower_components/ directory should be imported from sass/.
fonts/    : Webfonts
img/      : Images
js/       : Processed JavaScript files automatically saved in this directory. 
            Do not edit files in this directory, since they will likely be overwritten.
scripts/  : All custom JavaScript files should be kept in this directory.

### Install node dependencies
Navigate into directory where the Gruntfile.js is, then install dependencies.
```bash
$ npm install 
```

Run Grunt:
```bash
$ grunt
```

or

```bash
$ grunt default
```


