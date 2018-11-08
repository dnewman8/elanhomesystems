<div id="page" class="<?php print $classes; ?>"<?php print $attributes; ?>>

    <header id="header" class="clearfix">
        <div class="container">

        <?php if ($logo): ?>
            <div id="logo">
                <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home">
                    <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/>
                </a>
            </div>
        <?php endif; ?>

        <?php if ($site_name): ?>
            <div id="site-name"><?php print $site_name; ?></div>
        <?php endif; ?>

        <?php if ($secondary_menu): ?>
            <div id="menu-trigger">
                <i class="icon open-menu icon-align-justify"></i>
                <i class="icon close-menu icon-cross-mark"></i>
                <div id="header-region">
                    <?php print render($page['header']); ?>
                </div>
            </div>
            <nav id="secondary-menu" class="menu navigation clearfix">
                <?php print theme('links', array('links' => $secondary_menu, 'attributes' => array('class' => array('links')))); ?>
            </nav>
        <?php endif; ?>

        <?php if ($main_menu): ?>
            <nav id="main-menu" class="menu navigation clearfix">
                <?php print theme('links', array('links' => $main_menu, 'attributes' => array('class' => array('links')))); ?>
            </nav>
        <?php endif; ?>

        </div>
    </header>

    <div id="main" class="clearfix" role="main">
        <div class="container">
            <?php if ($breadcrumb || $title|| $messages || $tabs || $action_links): ?>
                <div id="content-header">
                    <?php if ($page['highlighted']): ?>
                        <div id="highlighted"><?php print render($page['highlighted']) ?></div>
                    <?php endif; ?>

                    <?php if ($section_title): ?>
                        <div class="section-title"><?php print $section_title; ?></div>
                    <?php elseif ($title && !$is_front): ?>
                        <?php print render($title_prefix); ?>
                        <h1><?php print $title; ?></h1>
                        <?php print render($title_suffix); ?>
                        <?php if (isset($gallery_breadcrumbs)): ?>
                            <div class="back-links"><?php print $gallery_breadcrumbs; ?></div>
                        <?php endif; ?>
                    <?php endif; ?>

                    <?php if ($breadcrumb): ?>
                        <div id="breadcrumb" class="element-invisible"><?php print $breadcrumb; ?></div>
                    <?php endif; ?>

                    <?php if ($messages): ?>
                        <div id="messages"><?php print $messages; ?></div>
                    <?php endif; ?>

                    <?php if ($tabs): ?>
                        <div class="tabs"><?php print render($tabs); ?></div>
                    <?php endif; ?>

                    <?php if ($action_links): ?>
                        <ul class="action-links"><?php print render($action_links); ?></ul>
                    <?php endif; ?>
                </div>
            <?php endif; ?>
            <div id="content-wrapper">
                <section id="content">
                    <div id="content-area">
                        <?php print render($page['content']); ?>
                    </div>

                    <?php if ($page['sidebar_first']): ?>
                        <aside id="sidebar-first" class="column sidebar first">
                            <?php print render($page['sidebar_first']); ?>
                        </aside>
                    <?php endif; ?>
                </section>
            </div>
            <?php if ($page['sidebar_second']): ?>
                <aside id="sidebar-second" class="column sidebar second">
                    <?php print render($page['sidebar_second']); ?>
                </aside>
            <?php endif; ?>

        </div>
    </div>

    <?php if ($page['footer']): ?>
        <footer id="footer" class="clearfix">
            <div class="container">
                <div id="footer-top" class="clearfix">
                    <?php print render($page['footer_top']); ?>
                </div>

                <div id="footer-main" class="clearfix">
                    <?php print render($page['footer']); ?>
                </div>

            </div>
        </footer>
    <?php endif; ?>

</div>
