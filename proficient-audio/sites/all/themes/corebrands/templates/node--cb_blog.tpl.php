<?php
    hide($content['links']);
?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <div class="content"<?php print $content_attributes; ?>>
        <?php if ($teaser): ?>

            <?php print render($content['field_blog_date']); ?>
            <div class="blog-author-name"><?php print t('By') . ' ' . $author_name; ?></div>
            <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
            <?php print render($content); ?>

        <?php else: ?>

            <?php if (!empty($content['field_blog_image'])): ?>
                <?php print render($content['field_blog_image']); ?>
            <?php endif ?>

            <div class="content-main">
                <a href="<?php print url('node/21'); ?>" class="back-link"><i class="icon icon-caret-left"></i>Back</a>
                <?php print render($content['field_blog_date']); ?>
                <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
                <?php print render($content); ?>
                <a href="<?php print url('node/21'); ?>" class="back-link"><i class="icon icon-caret-left"></i>Back</a>
            </div>

            <aside class="content-right">
                <div class="block blog-author">
                    <h3><?php print t('ELAN Blog Author'); ?></h3>
                    <?php print views_embed_view('blog', 'block_author'); ?>
                </div>

                <?php if (!empty($blog_related)): ?>
                    <div class="block blog-related">
                        <h3><?php print t('Related Blog Posts'); ?></h3>
                        <?php print $blog_related; ?>
                    </div>
                <?php endif ?>

            </aside>
        <?php endif; ?>
    </div> <!-- /.content -->


</article> <!-- /.node -->