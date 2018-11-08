/**
 * @file
 * Grunt tasks to help assist building a theme.
 */
module.exports = function(grunt) {

  var themes = [
    'sites/all/themes/corebrands/',
    'sites/corebrands.com/themes/brands/',
    'sites/elanhomesystems.com/themes/elan/',
    'sites/furmanpower.com/themes/furman/',
    'sites/gefen.com/themes/gefen/',
    'sites/nilesaudio.com/themes/niles/',
    'sites/panamax.com/themes/panamax/',
    'sites/proficientaudio.com/themes/proficient/',
    'sites/speakercraft.com/themes/speakercraft/',
    'sites/sunfire.com/themes/sunfire/',
    'sites/xantech.com/themes/xantech/',
    'sites/2gig.com/themes/gig/'
  ];

  var watch_scripts_files = [];
  var watch_sass_files = [];
  var uglify_target_files = [];
  var sass_target_files = [];

  var line = grunt.util.repeat(80, '*');

  grunt.log.writeln(line['cyan'].bold);
  grunt.log.writeln('Following paths will be watched and processed during this session:'['blue'].bold);

  themes.forEach(function (dir, index) {
    grunt.log.writeln(index+1 + ' ' + dir);

    // JavaScript files.
    watch_scripts_files.push(dir + 'scripts/{,*/}*.js');
    uglify_target_files.push({
      expand: true,
      cwd: dir + 'scripts',
      src: '{,*/}*.js',
      dest: dir + 'js'
      // rename: function (dst, src) {
      //   return dst + '/script.js';
      // }
    });
    // Style-Sheet files.
    watch_sass_files.push(dir + 'sass/{,*/}*.{scss,sass}');
    sass_target_files.push({
      expand: true,
      cwd: dir + 'sass',
      src: ['*.scss', '*.sass'],
      dest: dir + 'css',
      ext: '.css'
    });
  });

  grunt.log.writeln(line['cyan'].bold);

  grunt.initConfig({
    pkg: grunt.file.readJSON('package.json'),
    watch: {
      scripts: {
        files: watch_scripts_files,
        tasks: ['uglify'],
        options: {
          spawn: false
        },
      },
      css: {
        files: watch_sass_files,
        tasks: ['sass'],
        options: {
          spawn: false
        }
      }
    },
    uglify: {
      options: {
        sourceMap: true,
        mangle: false
      },
      my_target: {
        files: uglify_target_files
      }
    },
    sass: {
      dist: {
        options: {
          style: 'compressed', // Output style. Can be `nested`, `compact`, `compressed`, `expanded`.
          precision: 10 // Default 5. How many digits of precision to use when outputting decimal numbers.
        },
        files: sass_target_files
      }
    },
    newer: {
      options: {
        cache: '.cache'
      }
    }
  });

  grunt.loadNpmTasks('grunt-contrib-uglify');
  grunt.loadNpmTasks('grunt-contrib-sass');
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-newer');
  grunt.loadNpmTasks('grunt-notify');
  // Now that we've loaded the package.json and the node_modules we set the base
  // path for the actual execution of the tasks
  // grunt.file.setBase('./')
  // This is where we tell Grunt what to do when we type "grunt" into the
  // terminal. Note: if you'd like to run and of the tasks individually you can
  // do so by typing 'grunt mytaskname' alternatively you can type 'grunt watch'
  // to automatically track your files for changes.
  grunt.registerTask('default', ['watch']);
};
