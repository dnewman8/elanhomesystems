module.exports = function(grunt) {
  'use strict';

  require('load-grunt-tasks')(grunt);
  require('time-grunt')(grunt);

  grunt.initConfig({
    pkg: grunt.file.readJSON('package.json'),
    vendor: grunt.file.readJSON('.bowerrc').directory,

    // Project settings.
    project: {
      app: '.',
      css: '<%= project.app %>/css',
      styles: '<%= project.app %>/sass',
      js: '<%= project.app %>/js',
      scripts: '<%= project.app %>/scripts',
      img: '<%= project.app %>/img',
      fonts: '<%= project.app %>/fonts'
    },

    // These directories will be cleaned up before new files generated.
    clean: {
      options: {
        dot: true
      },
      css: {
        src: ['<%= project.css %>']
      },
      js: {
        src: ['<%= project.js %>']
      }
    },

    // Task for grunt-sass (much faster than grunt-contrib-sass)
    sass: {
      options: {
        outputStyle: 'nested', // nested, expanded, compact, compressed
        sourceMap: true,
        precision: 10,
        includePaths: []
      },
      dist: {
        files: [{
          expand: true,
          cwd: '<%= project.styles %>',
          src: ['*.scss'],
          dest: '<%= project.css %>',
          ext: '.css'
        }]
      }
    },

    // Concatenate JavaScript files before minimizing.
    concat: {
      options: {
        separator: ';'
      },
      dist: {
        src: ['<%= project.scripts %>/**/*.js'],
        dest: '<%= project.js %>/scripts.extra.js'
      }
    },

    // Minimize JavaScript files.
    uglify: {
      options: {
        preserveComments: 'some',
        sourceMap: true
      },
      dist: {
        files: {
          '<%= project.js %>/scripts.extra.min.js': ['<%= project.js %>/scripts.extra.js']
        }
      }
    },

    // Validate JavaScript files with JSHint. @see .jshintrc file for options.
    jshint: {
      options: {
        jshintrc: true,
        reporter: require('jshint-stylish')
      },
      scripts: ['<%= project.scripts %>/**/*.js'],
      gruntfile: ['Gruntfile.js']
    },

    // Remove console.log() messages.
    removelogging: {
      dist: {
        src: '<%= project.scripts %>/**/*.js'
      }
    },

    // Run tasks whenever watched files change.
    watch: {
      options: {
        dot: true
      },
      gruntfile: {
        files: 'Gruntfile.js',
        tasks: ['jshint:gruntfile']
      },
      styles: {
        files: ['<%= project.styles %>/**/*.scss'],
        tasks: ['clean:css', 'sass'],
        options: {
          livereload: true
        }
      },
      scripts: {
        files: ['<%= project.scripts %>/**/*.js'],
        tasks: ['clean:js', 'jshint:scripts', 'concat', 'uglify']
      }
    }
  });

  grunt.registerTask('default', [
    'clean',
    'sass',
    'jshint:scripts',
    // 'removelogging',
    'concat',
    'uglify',
    'watch'
  ]);
};
