<!doctype html>
<html<?php print $html_attributes . $rdf_namespaces; ?>>
    <head>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title><?php print $head_title;?></title>
        <meta name="viewport" content="width=device-width, initial-scale=1">

        <?php print $head; ?>
        <?php print $styles; ?>
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
    </body>
</html>
