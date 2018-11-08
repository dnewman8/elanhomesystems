<?php
    hide($content['links']);
?>

<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

    <div class="content"<?php print $content_attributes; ?>>
        <div class="faq-question">
            <h3<?php print $title_attributes; ?>>
                <a href="#answer-<?php print $node->nid; ?>" class="slidedown-trigger clearfix">
                    <span class="title"><?php print $title; ?></span><span class="icon icon-plus"></span>
                </a>
            </h3>
        </div>

        <div id="answer-<?php print $node->nid; ?>" class="faq-answer">
            <?php print render($content); ?>
        </div>

    </div> <!-- /.content -->

</article> <!-- /.node -->