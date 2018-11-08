<?php
    hide($content['links']);
?>
<?php $clean_id = preg_replace('@[^a-z0-9-]+@','-', strtolower($node->title));?>
<article id="node-<?php print $clean_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <div class="content"<?php print $content_attributes; ?>>

        <div class="text-wrapper">
            <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
            <?php print render($content['body']); ?>
        </div>

        <?php print render($content); ?>

    </div> <!-- /.content -->

</article> <!-- /.node -->
