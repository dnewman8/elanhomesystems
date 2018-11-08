<?php if (count($rows) == 5): ?>
    <div class="tile-group first">
        <div class="tile tile-1 tile-sq">
            <?php print $rows[0]; ?>
        </div>
        <div class="tile tile-2 tile-sq">
            <?php print $rows[1]; ?>
        </div>
    </div>

    <div class="tile-group">
        <div class="tile tile-3 tile-vr">
            <?php print $rows[2]; ?>
        </div>
    </div>

    <div class="tile-group last">
        <div class="tile tile-4 tile-sq label-gallery">
            <article>
                <div class="content">
                    <a href="/gallery">
                        <img src="/<?php print drupal_get_path('theme',$GLOBALS['theme']); ?>/img/bg-gallery-logo.jpg" alt="Background placeholder">
                        <div class="text-wrapper">
                            <h2><?php print t('Gallery'); ?></h2>
                        </div>
                    </a>
                </div>
                <div class="border"></div>

            </article>
        </div>
        <div class="tile tile-5 tile-sq">
            <?php print $rows[3]; ?>
        </div>
        <div class="tile tile-6 tile-hr">
            <?php print $rows[4]; ?>
        </div>
    </div>
<?php else: ?>
    <strong><?php print t('Not enough gallery items in the queue for this listing.'); ?></strong>
<?php endif; ?>