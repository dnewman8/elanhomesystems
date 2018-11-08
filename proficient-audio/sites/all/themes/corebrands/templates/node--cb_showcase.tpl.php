<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <div class="content"<?php print $content_attributes; ?>>
        <?php if ($teaser): ?>
            <?php print render($content['field_showcase_image'][0]); ?>
            <?php hide($content['field_showcase_image']); ?>
            <h3<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h3>
        <?php else: ?>
            <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
        <?php endif ?>


        <?php print render($content); ?>

    </div> <!-- /.content -->

</article> <!-- /.node -->
