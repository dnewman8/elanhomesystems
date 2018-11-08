<?php
hide($content['links']);

$brand_id = variable_get('ns_brand');
$brands = function_exists('cb_netsuite_getBrands') ? cb_netsuite_getBrands() : [];
$brand_name = (isset($brands[$brand_id]) && !empty($brands[$brand_id])) ? $brands[$brand_id] : '';
?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <div class="content"<?php print $content_attributes; ?>>
        <?php if ($teaser): ?>
            <?php if (!empty($content['field_press_image'])): ?>
                <?php print render($content['field_press_image']); ?>
            <?php endif ?>

            <div class="text-wrapper <?php print (!empty($content['field_press_image'])) ? '' : 'no-image'; ?>">
                <?php print render($content['field_press_date']); ?>
                <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
                <?php print render($content); ?>
            </div>
        <?php else: ?>


            <?php if (!empty($content['field_press_image'])): ?>
                <?php print render($content['field_press_image']); ?>
            <?php endif ?>

            <div class="content-main">
                <?php if (variable_get('cb_press_landing', '') !== ''): ?>
                    <a href="<?php print url(variable_get('cb_press_landing', '')); ?>" class="back-link"><i class="icon icon-caret-left"></i>Back</a>
                <?php endif; ?>
                <?php print render($content['field_press_date']); ?>
                <h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
                <?php print render($content); ?>
                <?php if (variable_get('cb_press_landing', '') !== ''): ?>
                    <a href="<?php print url(variable_get('cb_press_landing', '')); ?>" class="back-link"><i class="icon icon-caret-left"></i>Back</a>
                <?php endif; ?>
            </div>

            <aside class="content-right">
                <div class="block press-author">
                    <h3><?php print t('@name Press Contact', ['@name' => $brand_name]); ?></h3>
                    <?php print views_embed_view('press_releases', 'block_2'); ?>
                </div>

                <?php if (!empty($press_related)): ?>
                    <div class="block press-related">
                        <h3><?php print t('Related Press Releases'); ?></h3>
                        <?php print $press_related; ?>
                    </div>
                <?php endif ?>

            </aside>
        <?php endif; ?>
    </div> <!-- /.content -->


</article> <!-- /.node -->
