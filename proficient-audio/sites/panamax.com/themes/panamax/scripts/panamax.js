(function ($) {
    Drupal.behaviors.panamax = {
        attach: function (context, settings) {
            $('#block-menu-menu-dealer-portal').find('ul').addClass('dealer-sub-menu');
            $('#secondary-menu').find('ul').append($('#block-menu-menu-dealer-portal').find('ul'));

            $('#secondary-menu').find('.menu-610 a').on('click', function(e) {
                if ($(this).closest('#secondary-menu').find('.dealer-sub-menu').hasClass('dealer-active')) {
                    $(this).closest('#secondary-menu').find('.dealer-sub-menu').removeClass('dealer-active');
                    $(this).closest('#secondary-menu').find('.dealer-sub-menu').slideUp();
                    $(this).removeClass('dealer-expanded');
                } else {
                    $(this).closest('#secondary-menu').find('.dealer-sub-menu').addClass('dealer-active');
                    $(this).closest('#secondary-menu').find('.dealer-sub-menu').slideDown();
                    $(this).addClass('dealer-expanded');
                }

                e.preventDefault();
            });
        }
    };
}(jQuery));
