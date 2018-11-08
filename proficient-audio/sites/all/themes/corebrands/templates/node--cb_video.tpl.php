<?php
    hide($content['links']);
    hide($content['field_video_url']);
?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <div class="content"<?php print $content_attributes; ?>>
        <a href="#video-<?php print $node->nid; ?>" class="colorbox-load image-wrapper">
            <?php print render($content['field_video_image']); ?>
            <div class="icon icon-play-circle"></div>
        </a>
        <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
        <?php print render($content); ?>

        <div class="hidden">
            <div id="video-<?php print $node->nid; ?>">
                <?php print render($content['field_video_url']); ?>
            </div>
        </div>

    </div> <!-- /.content -->


</article> <!-- /.node -->