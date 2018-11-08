(function ($) {
    Drupal.behaviors.corebrands = {
        attach: function (context, settings) {

            // Enable main menu.
            $('#menu-trigger .icon', context).once('corebrands', function() {
                $(this).click(function(event) {
                    event.stopPropagation();

                    $(this).parent().toggleClass('open');
                    $('#header-region').slideToggle();
                });
            });

            $('#page', context).once('corebrands', function() {
                $(this).click(function (event) {
                    if (!$(event.target).closest('#header-region').length) {
                        if ($('#header-region').is(":visible")) {
                            $('#menu-trigger').toggleClass('open');
                            $('#header-region').slideToggle();
                        }
                    }
                });
            });


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

            // Enable slick slider.



            $('.slick-slider').each(function() {
                var options = {
                    dots: $(this).hasClass('with-dots') ? true : false,
                    speed: $(this).hasClass('with-arrows') ? 200 : 500,
                    swipe: true,
                    swipeToSlide: true,
                    autoplaySpeed: 4000,
                    arrows: $(this).hasClass('with-arrows') ? true : false,
                    autoplay: $(this).hasClass('with-autoplay') ? true : false,
                    cssEase: 'cubic-bezier(0.980, 0.010, 0.000, 1)'
                };

                if ($(this).hasClass('adaptive-height')) {
                    options.adaptiveHeight = true;
                }

                if ($(this).hasClass('multiple-items')) {
                    options.infinite = true;
                    options.slidesToShow = 3;
                    options.slidesToScroll = 3;
                    options.responsive = [
                        {
                            breakpoint: 1024,
                            settings: {
                                slidesToShow: 3,
                                slidesToScroll: 3
                            }
                        },
                        {
                            breakpoint: 900,
                            settings: {
                                slidesToShow: 2,
                                slidesToScroll: 2
                            }
                        },
                        {
                            breakpoint: 560,
                            settings: {
                                slidesToShow: 1,
                                slidesToScroll: 1
                            }
                        }];
                }

                if ($(this).hasClass('center-mode')) {
                    options.centerMode = true;
                    options.centerPadding = '15%';
                    options.slidesToShow = 1;
                    options.slidesToScroll = 1;
                    options.arrows = true;
                    options.asNavFor = '.thumb-nav';
                }

                if ($(this).hasClass('with-thumbs')) {
                    options.asNavFor = '.thumb-nav .view-content';
                }

                if ($(this).hasClass('eob')) {
                    options.easing = 'easeOutExpo';
                    options.cssEase = 'none';
                    options.speed = 500;
                }

                if ($(this).hasClass('thumb-nav')) {

                    options.slidesToShow = 8;
                    options.slidesToScroll = 1;
                    options.responsive = [
                        {
                            breakpoint: 1024,
                            settings: {
                                slidesToShow: 8,
                                slidesToScroll: 1
                            }
                        },
                        {
                            breakpoint: 900,
                            settings: {
                                slidesToShow: 6,
                                slidesToScroll: 1
                            }
                        },
                        {
                            breakpoint: 560,
                            settings: {
                                slidesToShow: 4,
                                slidesToScroll: 1
                            }
                        }];
                    options.arrows = false;
                    options.dots = false;
                    options.focusOnSelect = true;
                    options.asNavFor = '.with-thumbs .view-content';
                }


                if ($(this).hasClass('responsive-3')) {
                    options.slidesToShow = 3;
                    options.slidesToScroll = 3;
                    options.infinite = true;
                    options.dots = false;
                    options.responsive = [
                        {
                            breakpoint: 1024,
                            settings: {
                                slidesToShow: 3,
                                slidesToScroll: 3
                            }
                        },
                        {
                            breakpoint: 900,
                            settings: {
                                slidesToShow: 2,
                                slidesToScroll: 2
                            }
                        },
                        {
                            breakpoint: 560,
                            settings: {
                                slidesToShow: 1,
                                slidesToScroll: 1
                            }
                        }];
                }

                $(this).find('.view-content').slick(options);
            });

            /*$('.gallery-thumb .view-content').slick({
                slidesToShow: 3,
                slidesToScroll: 1,
                asNavFor: '.thumb-nav .view-content',
                arrows:false,
                dots: false,
                focusOnSelect: true
            });



            $('.thumb-nav .view-content').slick({
                slidesToShow: 3,
                slidesToScroll: 1,
                asNavFor: '.gallery-thumb .view-content',
                arrows:false,
                dots: false,
                focusOnSelect: true
            });*/





            // Enable video colorbox overlay.
            $('.node-cb-video .colorbox-load').click(function(e) {
                $.colorbox({
                    inline: true,
                    href: $(this).attr('href'),
                    width: 640,
                    height: 480,
                    scrolling: false
                });

                e.preventDefault();
            });

            $('.image.colorbox-load').colorbox({
                maxWidth: '80%',
                maxHeight: '80%'
            });


            // Slide down for FAQ
            $('.slidedown-trigger').click(function(e) {
                var target = $(this).attr('href');
                $(this).find('.icon').toggleClass('icon-plus');
                $(this).find('.icon').toggleClass('icon-minus');


                $(target).slideToggle();

                e.preventDefault();
            });


            //Set equal heights to various blocks

            $('#block-views-blog-block .view-content').each(function() {
                $(this).children('.views-row').matchHeight({ });
            });

            //Swap text position for main rotato
            $(window).load(function() {
                $('#block-views-rotatos-block-home-hero .views-row').each(function() {
                    $(this).find('.text-wrapper').insertAfter($(this).find('.field-type-image'));
                });
            });

            //Mobile menu

            function responsive_menu() {
                    //$(".menu-accordion .nolink").bind('click');
                    $("#block-menu-block-1 .nolink").click(function () {
                        $(this).toggleClass('open');
                        $(this).parent().find('ul.menu').slideToggle();
                    });
              }

            var added = false; // keep track of whether the element is added

            $(document).one('ready', function () {
                if ( $(window).width() <= 768 && added === false) {
                    responsive_menu();
                }

            });

            function checkSize() {
                if (!added && $(window).width() <= 768) {
                    responsive_menu();
                    added = true;
                }
                /*if ($(window).width() <= 420){
                    $(".menu-accordion .nolink").bind('click');
                }*/
                if ($(window).width() > 768){
                    $('.menu-accordion ul ul').slideDown();
                    //$(".menu-accordion .nolink").unbind('click');
                }
            }
            $(window).resize(checkSize);
            checkSize(); // check from the start

            $('body.front img').on('load', function() {
                $('body.front #page').css('visibility', 'visible');
                setTimeout(function(){
                    $('.pg-loading-screen').remove();
                }, 3000);
            });

        }
    };
}(jQuery));
