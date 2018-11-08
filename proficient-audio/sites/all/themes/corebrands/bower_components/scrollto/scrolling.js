var elanScrolling = (function($) {

    var isAutoScrolling = false,
        scrollToTimer,
        layoutSize;

    /**
     * Determine what size of layout we are in from the content value applied
     * to pseudo-elements on the <body>
     */
    function getLayout() {
        var layout = window.getComputedStyle(document.querySelector('body'), ':after').getPropertyValue('content').replace(/\"/g, '');

        return layout;
    };

    /**
     * Work out the window offset so when we scroll to the next section
     * it always appears in the middle of the screen
     */
    function getScrollCenter($el) {

        var scrollCenter = 0,
            elTop = $el.offset().top,
            elHeight = $el.outerHeight(),
            windowHeight = $(window).height();

        scrollCenter = elTop + ((elHeight - windowHeight) / 2);

        return scrollCenter;
    };

    /**
     * Throttle the execution of functionality during scrolling to
     * improve performance
     */
    var throttleScrolling = {

        options: {
            throttle: 300,
            enabledInLayoutSize: 'large'
        },

        watchTimer: undefined,
        previousScrollTop: $(window).scrollTop(),

        /**
         * Is the user scrolling up or down?
         */
        _getScrollingDirection: function(scrollTop, previousScrollTop) {

            var self = this,
                direction;

            if (scrollTop > previousScrollTop) {
                direction = 'down';
            } else if (scrollTop < previousScrollTop) {
                direction = 'up';
            } else {
                direction = self.previousDirection;
            }

            self.previousDirection = direction;

            return direction;
        },

        /**
         * Stop the watch() event when scrolling stops
         */
        _scrollingStopped: function(scrollTop) {
            var self = this,
                scrollingStopped = false;

            if (scrollTop === self.previousScrollTop) {
                clearInterval(self.watchTimer);
                self.watchTimer = undefined;
                scrollingStopped = true;
            }

            return scrollingStopped;
        },

        /**
         * Determine if the user is scrolling by monitoring scroll position
         */
        _isScrolling: function(onScroll, onScrollStopped) {

            var self = throttleScrolling,
                scrollTop = $(window).scrollTop(),
                direction = self._getScrollingDirection(scrollTop, self.previousScrollTop);

            if (self._scrollingStopped(scrollTop) === false) {
                onScroll(scrollTop, self.previousScrollTop, direction);
            } else {
                onScrollStopped(scrollTop, direction);
            }

            self.previousScrollTop = scrollTop;
        },

        /**
         * Watch scrolling to determine direction
         * Uses a timer to throttle functionality and improve performance
         */
        _watch: function(onScroll, onScrollStopped, throttle) {

            var self = this;

            // Only watch once per scroll event
            if (self.watchTimer !== undefined) {
                return;
            }

            // Throttle scrolling functionality for better performance
            self.watchTimer = setInterval(function() {

                self._isScrolling(onScroll, onScrollStopped);
            }, throttle);
        },

        init: function(callbacks) {

            var self = this;

            $(window).scroll(function() {

                if (layoutSize === 'large' && isAutoScrolling === false) {
                    self._watch(callbacks.onScroll, callbacks.onScrollStopped, self.options.throttle);
                }
            });
        }
    };

    /**
     * When a sticky section is in view, automatically scroll to the one that is
     * most inview
     */
    var stickySections = {
        $el: undefined,
        $sections: undefined,
        enabled: false,

        options: {
            // Add an offset to the top and bottom of the sticky section container
            // relative to the window height
            // 40% (the container must be 60% inview before sticky sections take effect)
            bounds: .4,

            // How long to delay autoScroll for? Required to prevent auto scroll from
            // taking over if the user is still holding the down arrow on their
            // keyboard for example
            autoScrollDelay: 400
        },

        /**
         * Get the positions of each section
         */
        _getPositions: function($els) {

            var self = this,
                positions = [];

            $els.each(function() {
                positions.push($(this).offset().top);
            });

            return positions;
        },

        /**
         * Is the scrollbar inside the bounds? Defined by the element's height and
         * additional bounds option
         */
        _isInside: function(scrollTop, elTop, elBottom, windowHeight, bounds) {

            var isInside = false,
                bounds = windowHeight * bounds,
                topBound = elTop - bounds,
                bottomBound = (elBottom - windowHeight) + bounds;

            if (scrollTop >= topBound && scrollTop <= bottomBound) {
                isInside = true;
            }

            return isInside;
        },

        /**
         * Get the ID of the nearest section
         */
        _getNearestId: function(scrollTop, sectionTops) {

            var self = this,
                distance,
                nearestDistance = undefined,
                nearestSectionId = undefined;

            // Run through each section position and see which the user is closest to
            $.each(sectionTops, function(index, value) {
                distance = Math.abs(scrollTop - value);

                if (nearestDistance === undefined || distance < nearestDistance) {
                    nearestDistance = distance;
                    nearestSectionId = index;
                }
            });

            return nearestSectionId;
        },

        /**
         * Watch during scrolling to see where the scroll position is and scroll to
         * a section element if inside the section container
         */
        watch: function(scrollTop) {

            var self = this,
                $el = self.$el,
                windowHeight = $(window).height(),
                elHeight = $el.outerHeight(),
                elTop = $el.offset().top,
                elBottom = elHeight + elTop,
                sectionTops = self._getPositions(self.$sections),
                $nearestSection,
                nearestSectionId,
                sectionCenter;

            // If inside the section container, get the nearest section ID and
            // scroll to it
            if (self._isInside(scrollTop, elTop, elBottom, windowHeight, self.options.bounds) && isAutoScrolling === false) {
                nearestSectionId = self._getNearestId(scrollTop, sectionTops);
                $nearestSection = self.$sections.eq(nearestSectionId);

                clearTimeout(scrollToTimer);

                // Begin autoscroll after a delay to be certain the user has stopped scrolling
                scrollToTimer = setTimeout(function() {
                    isAutoScrolling = true;

                    sectionCenter = getScrollCenter($nearestSection);

                    $(window).scrollTo(sectionCenter, 300, {
                        onAfter: function() {
                            isAutoScrolling = false;
                            throttleScrolling.previousScrollTop = $(window).scrollTop();
                        }
                    });
                }, self.options.autoScrollDelay);
            }
        },

        init: function() {

            var self = this;

            self.$el = $('#block-views-rotatos-block-moment-static');
            self.$sections = self.$el.find('.view-mode-full');

            if (self.$el.length > 0 && self.$sections.length > 0) {
                self.enabled = true;
            }
        }
    };

    /**
     * Hide/show the navigation menu based on scroll direction
     */
    var menu = {

        hideTimer: undefined,
        isOpen: undefined,
        elHeight: undefined,
        headerBottom: undefined,

        getHeight: function($el) {

            var self = this;

            self.elHeight = $el.outerHeight();
        },

        /**
         * When the window is resized, determine what to do with the window
         * based on screen width
         */
        resize: function($body) {

            var self = this;

            self.getHeight(self.$el);

            if (layoutSize === 'small') {
                self.show(self.$el);
            } else {
                self.toggle(self.$el, $body, self.elHeight, 'down', $(window).scrollTop());
            }
        },

        /**
         * Show the menu
         */
        show: function($el) {

            self.isOpen = true;
            $el.removeClass('header--hide');
            $el.addClass('header--show');
        },

        /**
         * Hide the menu
         */
        hide: function($el) {
            if (self.isOpen === true) {

                self.isOpen = false;
                $el.addClass('header--hide');
            }
        },

        /**
         * Show/hide the menu based on direction
         */
        toggle: function($el, $body, elHeight, direction, scrollTop) {

            var self = this;

            // Don't manipulate the menu if the dropdown is open
            if (self.$headerRegion.is(':visible') === true) {
                return;
            }

            if (scrollTop > elHeight) {
                $body.addClass('dettached-header');
            }

            if (direction === 'up') {
                self.show(self.$el);
            } else if (scrollTop > elHeight) {

                // Use a small delay so the CSS transition isn't also applied to the
                // 'dettached-header' class when that is added
                setTimeout(function() {
                    self.hide(self.$el);
                }, 50);
            }

            if (scrollTop === 0) {
                $body.removeClass('dettached-header');
                $el.removeClass('header--show header--hide');
                self.isOpen = false;
            }
        },

        init: function() {

            var self = this;
            self.$el = $('#header');
            self.$headerRegion = $('#header-region');
            self.$trigger = $('#menu-trigger');

            self.headerBottom = self.$headerRegion.outerHeight() + self.$el.outerHeight();

            self.getHeight(self.$el);
        }
    };

    var waypoints = {

        options: {
            // Add an offset to the top and bottom of the element relative to the window
            bounds: .2,
        },
        windowHeight: 0,
        $els: $('.view-mode-full'),

        init: function() {

            var scrollTop = $(window).scrollTop();

            this.resize();
            this.watch(scrollTop);
        },

        /**
         * When the window is resized, get the window height and check to see if
         * a waypoint is active
         */
        resize: function() {
            this.windowHeight = $(window).height();

            var scrollTop = $(window).scrollTop();
            waypoints.watch(scrollTop);
        },

        activate: function($el) {

            if ($el.data('activated') !== true) {

                $el.addClass('section--activated');

                $el.data('activated', true);
            }
        },

        /**
         * Check to see if an element is inview and activate the waypoint
         */
        watch: function(scrollTop) {

            var isInside = false,
                elTop,
                elHeight,
                elBottom,
                windowHeight = this.windowHeight,
                bounds = this.options.bounds;

            if (this.$els.length === 0) {
                return;
            }

            this.$els.each(function() {

                elHeight = $(this).outerHeight();
                elTop = $(this).offset().top;
                elBottom = elTop + elHeight;

                // Is the element inside the viewport?
                isInside = waypoints._isInside(scrollTop, elTop, elBottom, windowHeight, bounds);

                if (isInside === true) {
                    // Remove the element from the list to save redundant loops
                    waypoints.$els = waypoints.$els.not($(this));

                    // Activate the waypoints
                    waypoints.activate($(this));
                }

            });
        },

        /**
         * Is the scrollbar inside the bounds? Defined by the element's height and
         * additional bounds option
         */
        _isInside: function(scrollTop, elTop, elBottom, windowHeight, bounds) {

            var isInside = false,
                bounds = windowHeight * bounds,
                topBound = elTop - bounds,
                bottomBound = (elBottom - windowHeight) + bounds;

            if (scrollTop >= topBound && scrollTop <= bottomBound) {
                isInside = true;
            }

            return isInside;
        },
    };

    /**
     * Setup next buttons for each moment, except the last
     */
    var nextButtons = function($moments) {

        var nextButtonHtml,
            $nextMoment,
            nextMomentId;

        $moments.each(function(index) {

            // Ignore the last moment as it doesn't need a next button
            if (index + 1 === $moments.length) {
                return;
            }

            // one-base
            index++;

            // Get the ID of the next moment
            $nextMoment = $moments.eq(index);
            nextMomentId = $nextMoment.prop('id');

            // Setup the next button's HTML
            nextButtonHtml = '<a href="#' + nextMomentId + '" class="next-moment">Next</a>';

            // Add the next button HTML
            $(this).find('.text-wrapper').append(nextButtonHtml);
        });

        // Add click events to the next buttons
        $('.next-moment').on('click', function(e) {
            e.preventDefault();

            // Get the ID of the next section
            var nextElId = $(this).prop('href').match(/#[^?&\/]*/g)[0],
                $nextEl = $(nextElId),
                scrollCenter = getScrollCenter($nextEl);

            $(window).scrollTo(scrollCenter, 500);
        });
    };

    $(document).ready(function() {

        var $body = $('body'),
            $moments = $('.view-mode-full');

        layoutSize = getLayout();

        stickySections.init();
        menu.init();
        menu.resize($body);
        waypoints.init();

        nextButtons($moments);

        throttleScrolling.init({

            // During scrolling (throttled)
            onScroll: function(scrollTop, previousScrollTop, direction) {

                clearTimeout(scrollToTimer);

                waypoints.watch(scrollTop);

                // Close the menu only if it is relative to the top of the page and the
                // user scrolls down far enough so that it goes out of view
                if (previousScrollTop < menu.headerBottom && scrollTop > menu.headerBottom && menu.$el.css('position') === 'relative') {
                    menu.$headerRegion.slideUp();
                    menu.$trigger.removeClass('open');
                    $body.addClass('dettached-header');
                }

                // Show the menu only in large layout and when the user scrolled
                if (layoutSize === 'large') {
                    menu.toggle(menu.$el, $body, menu.elHeight, direction, scrollTop);
                }
            },

            // When scrolling has stopped
            onScrollStopped: function(scrollTop, direction) {
                if (stickySections.enabled === true) {
                    // stickySections.watch(scrollTop);
                }
            }
        });

        $(window).resize(function() {
            layoutSize = getLayout();
            menu.resize($body);
            waypoints.resize();

            $(window).trigger('scroll');
        });
    });

})(jQuery);