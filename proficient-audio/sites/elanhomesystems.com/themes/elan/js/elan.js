!function($){Drupal.behaviors.elan={attach:function(context,settings){$("#block-menu-menu-dealer-portal").find("ul").addClass("dealer-sub-menu"),$("#secondary-menu").find("ul").append($("#block-menu-menu-dealer-portal").find("ul")),$("#secondary-menu").find(".menu-610 a").on("click",function(e){$(this).closest("#secondary-menu").find(".dealer-sub-menu").hasClass("dealer-active")?($(this).closest("#secondary-menu").find(".dealer-sub-menu").removeClass("dealer-active"),$(this).closest("#secondary-menu").find(".dealer-sub-menu").slideUp(),$(this).removeClass("dealer-expanded")):($(this).closest("#secondary-menu").find(".dealer-sub-menu").addClass("dealer-active"),$(this).closest("#secondary-menu").find(".dealer-sub-menu").slideDown(),$(this).addClass("dealer-expanded")),e.preventDefault()}),"function"==typeof ga&&($("#cb-dealer-search-form").on("submit",function(){var name=$.trim($(this).find("#edit-name").val()),email=$.trim($(this).find("#edit-email").val()),zipCode=$.trim($(this).find("#edit-zip-code").val()),validEmail=/^([a-zA-Z0-9_.+-])+\@(([a-zA-Z0-9-])+\.)+([a-zA-Z0-9]{2,4})+$/,validZipCode=/(^\d{5}$)/;name.length>0&&validEmail.test(email)&&validZipCode.test(zipCode)&&ga("send","event","dealer","findDealer","form")}),$("#block-cb-dealer-cb-dealer-search-results a.phone",context).each(function(){$(this).click(function(){ga("send","event","dealer","findDealer","phoneCall")})}),$("#block-cb-dealer-cb-dealer-search-results a.email",context).each(function(){$(this).click(function(){ga("send","event","dealer","findDealer","email")})}),$("a",context).each(function(){var onClick=$(this).attr("onclick");void 0!==onClick&&!1!==onClick&&$(this).removeAttr("target")}))}}}(jQuery);
//# sourceMappingURL=elan.js.map