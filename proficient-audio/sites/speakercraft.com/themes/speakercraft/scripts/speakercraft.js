(function ($) {
    Drupal.behaviors.speakercraft = {
        attach: function (context, settings) {
            $(window).load(function() {
                $('.field-name-field-category-section .field-items').each(function() {
                    $(this).children('.field-item').matchHeight({byRow: false });
                });
            });
            $(window).resize(function(){
                $('.field-name-field-category-section .field-items').each(function() {
                    $(this).children('.field-item').matchHeight({byRow: false });
                });
            });

        }
    };
}(jQuery));