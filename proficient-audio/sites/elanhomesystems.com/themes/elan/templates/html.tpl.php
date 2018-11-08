<!doctype html>
<html<?php print $html_attributes . $rdf_namespaces; ?>>
    <head>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title><?php print $head_title;?></title>
        <meta name="viewport" content="width=device-width, initial-scale=1">

        <?php print $head; ?>
        <?php print $styles; ?>

        <!-- Google Schema -->
        <?php print $google_schema; ?>

    </head>
    <body class="<?php print $classes; ?>" <?php print $attributes; ?>>

        <?php if (defined('GA_CODE')): ?>
            <!-- Google Analytics -->
            <script>
                (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
                    (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
                    m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
                })(window,document,'script','//www.google-analytics.com/analytics.js','ga');

                ga('create', '<?php print GA_CODE; ?>', 'auto');
                ga('send', 'pageview');
            </script>
        <?php endif; ?>

        <!--[if lt IE 8]>
            <p class="browsehappy">You are using an <strong>outdated</strong> browser. Please <a href="http://browsehappy.com/">upgrade your browser</a> to improve your experience.</p>
        <![endif]-->
        <div id="skip">
            <a href="#main-menu"><?php print t('Jump to Navigation'); ?></a>
        </div>
        <?php print $page_top; ?>
        <?php print $page; ?>
        <?php print $page_bottom; ?>
        <?php print $scripts; ?>

        <?php if (defined('ADROLL_ADV_ID') && defined('ADROLL_PIX_ID')): ?>
            <!-- Adroll Pixel start -->
            <script type="text/javascript">
                adroll_adv_id = "<?php print ADROLL_ADV_ID; ?>";
                adroll_pix_id = "<?php print ADROLL_PIX_ID; ?>";
                /* OPTIONAL: provide email to improve user identification */
                /* adroll_email = "username@example.com"; */
                (function () {
                    var _onload = function(){
                        if (document.readyState && !/loaded|complete/.test(document.readyState)){setTimeout(_onload, 10);return}
                        if (!window.__adroll_loaded){__adroll_loaded=true;setTimeout(_onload, 50);return}
                        var scr = document.createElement("script");
                        var host = (("https:" == document.location.protocol) ? "https://s.adroll.com" : "http://a.adroll.com");
                        scr.setAttribute('async', 'true');
                        scr.type = "text/javascript";
                        scr.src = host + "/j/roundtrip.js";
                        ((document.getElementsByTagName('head') || [null])[0] ||
                        document.getElementsByTagName('script')[0].parentNode).appendChild(scr);
                    };
                    if (window.addEventListener) {window.addEventListener('load', _onload, false);}
                    else {window.attachEvent('onload', _onload)}
                }());
            </script>
            <!-- Adroll Pixel end -->
        <?php endif; ?>
    </body>
</html>
