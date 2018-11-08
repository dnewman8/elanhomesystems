<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <div class="content"<?php print $content_attributes; ?>>

        <?php print render($content['body']); ?>

        <div class="testimonial-name">
            – <?php print $title; ?><?php print !empty($content['field_testimonial_profession']) ? ', ' . $content['field_testimonial_profession'][0]['#markup'] : ''; ?>
        </div>

    </div> <!-- /.content -->

</article> <!-- /.node -->