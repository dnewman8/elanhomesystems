<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
$file = file_load($row->field_data_field_product_image_field_product_image_fid);
$image_data = $row->field_field_product_image[0]['rendered'];
$image_data['#item']['alt'] = $row->node_title;

$url = file_create_url($file->uri);

?>
<a class="image colorbox-load" href="<?php print $url; ?>" alt="image overlay"><?php print render($image_data); ?></a>
