(function ($) {
    Drupal.behaviors.brands = {
        attach: function (context, settings) {
        $('#block-views-brands-block .view-content').each(function() {
            $(this).children('.views-row').matchHeight({ });
        });

        $(window).load(function() {
           $('#block-views-brands-block-1 .views-row').each(function() {
                var h = $(this).find('.views-field-field-rotato-vertical .field-content img').height();
                $(this).height(h);
                $(this).find('.title').click(function() {
                    //$(this).find('span').text("-"); //window.alert("opened");
                    if($(this).find('span').text() === "+"){
                        $(this).find('span').text("-");
                    }else {
                        $(this).find('span').text("+");
                    }
                    $(this).closest('.views-row').children('.links').slideToggle('fast');
                    $(this).closest('.views-row').siblings('.views-row').find('.links:visible').slideToggle('fast');
                    if($(this).closest('.views-row').siblings('.views-row').find('.links').is(":visible") ){
                        $(this).closest('.views-row').siblings('.views-row').find('.title span').text("+");
                        $(this).closest('.views-row').parents('.view-content').addClass('active');
                    }else{
                        $(this).closest('.views-row').parents('.view-content').toggleClass('active');
                    }
                });
                $(this).find('.close').click(function() {
                    $(this).closest('.views-row').children('.links').slideToggle('fast');
                    $(this).closest('.views-row').find('.title span').text("+");
                    $(this).closest('.views-row').parents('.view-content').removeClass('active');
                });
                $(this).find('.logo').find('img').css('cursor', 'pointer');
                $(this).find('.logo').find('img').on('click', function() {
                    $(this).closest('.views-row').find('.close').click();
                });
            });
        });
        $(window).resize(function(){
            $('#block-views-brands-block .view-content').each(function() {
                $(this).children('.views-row').matchHeight({ });
            });
        });

            $('#block-views-brands-block-1').on('setPosition', function () {
                $(this).find('.slick-slide').height('auto');
                var slickTrack = $(this).find('.slick-track');
                var slickTrackHeight = $(slickTrack).height();
                $(this).find('.slick-slide').css('height', slickTrackHeight + 'px');
            });

        }
    };
}(jQuery));
