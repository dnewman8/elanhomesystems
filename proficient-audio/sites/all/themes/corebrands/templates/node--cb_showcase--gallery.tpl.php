<?php

/**
 * @file
 * Gallery theme implementation to display a showcase node.
 */

?>

<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <a href="<?php print $node_url ;?>">
        <div class="content"<?php print $content_attributes; ?>>


                <picture>
                <?php
                    foreach ($images as $img) {
                        print $img;
                    }
                ?>
                </picture>


                <div class="text-wrapper">
                    <h4<?php print $title_attributes; ?>><?php print $title; ?></h4>
                </div>


        </div> <!-- /.content -->

        <div class="border"></div>
    </a>


</article> <!-- /.node -->





