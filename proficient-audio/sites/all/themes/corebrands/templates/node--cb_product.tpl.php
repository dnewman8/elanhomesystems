<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="content"<?php print $content_attributes; ?>>
        <?php if ($teaser): ?>
            <div class="field field-name-field-product-featured-image field-type-image field-label-hidden">
                <a href="<?php print url('node/' . $node->nid); ?>">
                    <?php print render($content['field_product_featured_image']); ?>
                </a>
            </div>
            <h3<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h3>
        <?php else: ?>
            <div class="feature-wrapper clearfix">
                <div class="text-wrapper">
                    <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
                    <?php if (!empty($content['field_product_model'])): ?>
                        <?php print render($content['field_product_model']); ?>
                    <?php endif ?>
                </div>
                <?php $content['field_product_featured_image']['#alt'] = htmlspecialchars_decode($title);
                ?>
                <div class="field field-name-field-product-featured-image field-type-image field-label-hidden">
                    <?php print render($content['field_product_featured_image']); ?>
                </div>
            </div>

        <?php endif ?>

        <?php if (!empty($back_link)): ?>
            <div class="back-links">
                <a href="/" class="back-link"><?php print t('Home > '); ?></a>
                <span class="back-link"><?php print t('Products > '); ?></span>
                <a href="<?php print $back_link; ?>" class="back-link"><?php print t($back_link_label);?></a>
            </div>
        <?php endif; ?>

        <?php print render($content); ?>

    </div> <!-- /.content -->

</article> <!-- /.node -->
