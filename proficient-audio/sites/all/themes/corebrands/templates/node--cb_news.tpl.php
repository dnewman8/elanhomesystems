<?php
hide($content['links']);
?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <div class="content"<?php print $content_attributes; ?>>
        <?php if (!empty($content['field_news_image'])): ?>
            <?php print render($content['field_news_image']); ?>
        <?php endif ?>

        <div class="text-wrapper <?php print (!empty($content['field_news_image'])) ? '' : 'no-image'; ?>">
            <?php print render($content['field_news_date']); ?>
            <h2<?php print $title_attributes; ?>><a href="<?php print $node->field_news_url[LANGUAGE_NONE][0]['url']; ?>" target="_blank"><?php print $title; ?></a></h2>
            <?php print render($content); ?>
        </div>
    </div> <!-- /.content -->


</article> <!-- /.node -->
