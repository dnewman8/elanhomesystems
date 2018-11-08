# ELAN - Scrolling Functionality Documentation

This documentation describes the implementation of the following functionality into the development build of the ELAN Home Systems web site:

- Parallax and "Sticky" scrolling applied to the moments section on the front page
- Fixed navigation that is revealed only when scrolling up
- Animated slider content on the front page
- Zoomable images in the gallery

Before implementing any of this functionality, please be certain that pre-existing JavaScript errors are fixed. In particular, errors relating to the Slick slider may prevent the Fixed navigation from working as intended.

## Implementation

The following files have been provided with this README that include the above mentioned functionality:

- `css` - CSS files pulled from development server
- `img` - images pulled from development server
- `js` - JavaScript pulled from development server
- `elan-scrolling.css` - Stand-alone styles
- `elan-scrolling.js` - Stand-alone functionality
- `index.html` - Reference file showing additional functionality
- `jquery-scrollto.js` - Script required for automatic window scrolling used by the "Sticky" scrolling functionality
- `scripts.js` - Reference file showing where to place code for Animated Slider Content

Only `elan-scrolling.css`, `elan-scrolling.js`, and `jquery-scrollto.js` need be implemented into the development build. `index.html` and `scripts.js` represent pre-existing files that require modification and have been included for reference only.

To the front page, please add a reference to `elan-scrolling.css`, ideally after all other CSS references:

`<link rel="stylesheet" type="text/css" href="elan-scrolling.css">`

`elan-scrolling.js` and `jquery-scrollto.js` should be added before the reference to `scripts.min.js` but after `jquery.min.js`:

```
<script src="jquery-scrollto.js"></script>
<script src="elan-scrolling.js"></script>
```

Alternatively, the contents of these files may be added to pre-existing files providing order is maintained.

With these files implemented, all but the Animated Slider Content should work out of the box. Please see the instructions in Animated Slider Content to complete implementation.

### Parallax and "Sticky" Scrolling

Parallax scrolling makes the images in the Moments container fixed via CSS. To make them fixed, they have been converted from `<img>` elements to `background-image` set on the `.field-item` element via CSS. Example:

```
.moments-static .views-row-1 .field-type-image .field-item {
  background-image: url('img/entertainment-everywhere-hero-1.jpg?itok=wX-UTdmY');
  background-position: -240px 50%;
}
```

It may not be appropriate to set images via CSS when integrated into the main build so instead, it is recommended these properties be set as inline styles. For example:

```
<div class="field-item" style="background-image: url('img/entertainment-everywhere-hero-1.jpg?itok=wX-UTdmY'); background-position: -240px 50%;">
</div>
```

"Sticky" scrolling adds functionality to the page that makes the window automatically scroll when the user is viewing one of the Moments on the front page. The window will automatically scroll so that the most visible moment is in full view.

Both Parallax and "Sticky" scrolling are only enabled when the screen width is greater than 1024px and height greater than 480px. This is achieved via the JavaScript function `getLayout` found in `elan-scrolling.js`. The `getLayout` function reads the content of a pseudo-element on the `<body>` element to determine whether the screen size is "small" or "large". Only when the screen width and height are greater than 1024px and 480px is the layout considered large.

CSS used to determine layout width via JS:

```
/**
 * Used to get layout size via JS
 */
body:after {
  content: "small";
  display: none;
}
@media only screen and (min-width: 1025px) and (min-height: 481px) {
  body:after {
    content: "large";
  }
}
```

### Fixed Navigation

As with Parallax and "Sticky" scrolling, the Fixed Navigation is only enabled when the screen size is considered "large".

When enabled, the navigation will initially be positioned relative at the top of the page. Once the user has scrolled more than 100px down the page (and the relative navigation element is no longer visible), the navigation will become fixed to the top of the viewport and fade in and out as the user scrolls up and down.

### Animated Slider Content

Animated Slider Content is an enhancement to the Slick slider shown on the front page; animating text content each time a slide becomes active. This functionality makes use of Slick's API, and as such, should be added to the same file where Slick is initiated.

In `scripts.min.js`, above the Slick initiation code, example:

```
// Enable slick slider.
$('.slick-slider').each(function() {
```

Please add the following:

```
// Slick content animation
$('#block-views-rotatos-block-home-hero .slick-slider').on({

  init: function(slick) {
    var $firstSlide = $(slick.target).find('.slick-slide').eq(1);

    $firstSlide.addClass('animate-in');
  },

  beforeChange: function(slick, currentSlide, nextSlide) {
    var previousSlideId = currentSlide.currentSlide,
        $previousSlide = $(currentSlide.$slides[previousSlideId]);

    // Remove the "animate-in" class once the current slide has
    // been navigated away from
    setTimeout(function() {
      $previousSlide.removeClass('animate-in');
    }, currentSlide.options.speed);
  },

  afterChange: function(slick, currentSlide) {
    var currentSlideId = currentSlide.currentSlide,
        $currentSlide = $(currentSlide.$slides[currentSlideId]);

    $currentSlide.addClass('animate-in');
  }
});
```

This functionality uses Slick's `beforeChange` and `afterChange` callbacks to add/remove a CSS class to the active/previous slide that triggers CSS transitions on the text content.

### Zoomable Gallery Images

The Gallery images on the front page will zoom-in when hovered over. This is achieved via CSS found in `elan-scrolling.css`.
